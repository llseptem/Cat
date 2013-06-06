#include "CatWizzard.h"
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QProcess>
#include <QInputDialog>
#include <QFileInfo>
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"
#include "../Cat/CatSolution.h"
#include "../Cat/CatPluginManager.h"
#include "../Cat/CatGroupSelector.h"

CatWizzard::CatWizzard(QWidget *parent)
	: QDialog(parent)
{
	setupWidget();
}

CatWizzard::~CatWizzard()
{

}

void CatWizzard::setupWidget()
{
	ui.setupUi(this);
	myRunUI = new CatRunUI(this);
	mySolution = new CatSolution(this);
	connect(ui.newBtn,SIGNAL(clicked()),this,SLOT(onNew()));
	connect(myRunUI,SIGNAL(reRun()),this,SLOT(onRerun()));

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
			mySolutionPath = btn->description();
			const QString& checkID = QInputDialog::getText(this,tr("输入流水号"),tr("流水号"));
			if(checkID.isEmpty()) return;

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

			myRunUI->showMaximized();
			myRunUI->raise();
			myRunUI->activateWindow();
			myRunUI->reset();
			myRunUI->setInformation(tr("检测流水号:") + checkID);
//			myRunUI->setInformation(tr("Checking Begin"));
			runGroups(selGrps);
//			myRunUI->setInformation(tr("Checking Finished"));
		}
	}
}

void CatWizzard::onNew()
{
	QProcess::execute("./Cat.exe");
}

void CatWizzard::writeLog( const QString& pth,const QString& checkid )
{
	QDir dir("D:/");
	dir.mkdir("log"),dir.cd("log");

	QFileInfo inf(pth);
	dir.mkdir(inf.baseName()),dir.cd(inf.baseName());

	myRunUI->writeLog(dir.absoluteFilePath(checkid));
}

void CatWizzard::runGroups( const QStringList& grps )
{
	if(!CatDeviceManager::GetInstance().Initialize())
	{
		QMessageBox::information(this,tr("初始化设备失败"),
			tr("请检查设备与电脑连接情况与上电情况。"));
		CatDeviceManager::GetInstance().Uinitialize();
		return;
	}

	myRunUI->enablePrint(false);
	myRunUI->enableRerun(false);
	CatPluginManager* mgr = CatPluginManager::GetInstance();
	bool needBreak = false;
	foreach(const QString& grp,grps)
	{
		myRunUI->setTitle(grp);
		myRunUI->setInformation(grp);
		myRunUI->wait(1);
		foreach(const QDomElement& cmd,mySolution->commands(grp))
		{
			if(!mgr->runAction(mySolution->commandID(cmd),cmd,myRunUI))
			{	
				myRunUI->setInformation(tr("Checking Stoped Because of Error."),true);
				needBreak = true;
				break;
			}
			if(myRunUI->wait(1))
			{
				myRunUI->setInformation(tr("User Canceled"),true);
				needBreak = true;
				break;
			}
		}
		if(needBreak) break;
	}
	myRunUI->setInformation(tr("Checking Finished"));
	myRunUI->enablePrint(true);
	myRunUI->enableRerun(true);
	writeLog(mySolutionPath,myCheckID);
	CatDeviceManager::GetInstance().Uinitialize();
}

void CatWizzard::onRerun()
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

	runGroups(selGrps);
}
