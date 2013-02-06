#include "CatMainWindow.h"
#include "CatSolutionTree.h"
#include "CatActionList.h"
#include "CatPluginManager.h"
#include <QDomDocument>
#include <QStringList>

CatMainWindow::CatMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setupWidget();
	setupConnection();
}

CatMainWindow::~CatMainWindow()
{

}

void CatMainWindow::setupWidget()
{
	ui.setupUi(this);
	mySolutionTree = new CatSolutionTree(this);
	setCentralWidget(mySolutionTree);

	myActionList = new CatActionList();
	myActionList->setParent(this,Qt::Dialog);
}

void CatMainWindow::setupConnection()
{
	connect(ui.actionNewAction,SIGNAL(clicked()),this,SLOT(addAction()));
}

void CatMainWindow::addAction()
{
	if(myActionList->exec() == QDialog::Accepted)
	{
		const QUuid& uid = myActionList->selectedCommand();
		if(!uid.isNull())
		{
			CatPluginManager* mgr = CatPluginManager::GetInstance();
			if(mgr->configurePlugin(uid))
			{
			}
		}
	}
}

void CatMainWindow::initialDoc()
{

}

