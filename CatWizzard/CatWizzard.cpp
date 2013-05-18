#include "CatWizzard.h"
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QProcess>
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"
#include "../Cat/CatSolution.h"
#include "../Cat/CatPluginManager.h"
#include "../Cat/CatGroupSelector.h"

CatWizzard::CatWizzard(QWidget *parent)
	: QDialog(parent)
{
	setupWidget();
	myRunUI = new CatRunUI(this);
	mySolution = new CatSolution(this);
}

CatWizzard::~CatWizzard()
{

}

void CatWizzard::setupWidget()
{
	ui.setupUi(this);
	connect(ui.newBtn,SIGNAL(clicked()),this,SLOT(onNew()));
	QDir dir("./Solutions");
	const QFileInfoList& solutions = dir.entryInfoList(QStringList() << "*.catsln",QDir::Files);

	foreach(const QFileInfo& sln,solutions)
	{
		QCommandLinkButton* btn = new QCommandLinkButton(this);
		connect(btn,SIGNAL(clicked()),this,SLOT(onSolutionClicked()));
		btn->setText(sln.baseName());
		btn->setDescription(sln.absoluteFilePath());
		ui.verticalLayout->addWidget(btn);
	}
//	adjustSize();
}

void CatWizzard::onSolutionClicked()
{
	if(QCommandLinkButton* btn = qobject_cast<QCommandLinkButton*>(sender()))
	{
		if(mySolution->readFrom(btn->description()))
		{
			const QStringList& grps = mySolution->groups();
			CatGroupSelector selGrp;
			selGrp.addGroup(grps);
			if(selGrp.exec() != QDialog::Accepted)
			{
				return;
			}
			const QStringList& selGrps = selGrp.groups();
			if(selGrps.isEmpty())
			{
				return;
			}

			if(!CatDeviceManager::GetInstance().Initialize())
			{
				QMessageBox::information(this,tr("初始化设备失败"),
					tr("请检查设备与电脑连接情况与上电情况。"));
				CatDeviceManager::GetInstance().Uinitialize();
				return;
			}

			CatPluginManager* mgr = CatPluginManager::GetInstance();
			myRunUI->showMaximized();
			myRunUI->raise();
			myRunUI->activateWindow();
			myRunUI->checkBegin();
			myRunUI->setInformation(tr("Checking Begin"));
			bool needBreak = false;
			foreach(const QString& grp,selGrps)
			{
				myRunUI->setTitle(grp);
				myRunUI->setInformation(grp);
				myRunUI->wait(1);
				foreach(const QDomElement& cmd,mySolution->commands(grp))
				{
					if(!mgr->runAction(mySolution->commandID(cmd),cmd,myRunUI))
					{	
						myRunUI->setInformation(tr("Checking Stoped Because of Error."));
						needBreak = true;
						break;
					}
					if(myRunUI->wait(1))
					{
						myRunUI->setInformation(tr("User Canceled"));
						needBreak = true;
						break;
					}
				}
				if(needBreak) break;
			}
			myRunUI->setInformation(tr("Checking Finished"));
			myRunUI->checkFinished();
			CatDeviceManager::GetInstance().Uinitialize();
		}
	}
}

void CatWizzard::onNew()
{
	QProcess::execute("./Cat.exe");
}
