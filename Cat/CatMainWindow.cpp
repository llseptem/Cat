#include "CatMainWindow.h"
#include "CatAbout.h"
#include "CatSolutionTree.h"
#include "CatSolution.h"
#include "CatActionList.h"
#include "CatPluginManager.h"
#include <QDomDocument>
#include <QFileDialog>
#include <QMessageBox>
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

	myAbout = new CatAbout();
	myAbout->setParent(this,Qt::Dialog);

	mySolution = new CatSolution(this);
}

void CatMainWindow::setupConnection()
{
	connect(ui.actionNewAction,SIGNAL(triggered()),this,SLOT(addAction()));
	connect(ui.actionAbout,SIGNAL(triggered()),this,SLOT(about()));
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
				QDomElement cmd = mySolution->createCommand();
				if(mgr->createAction(uid,cmd))
				{
					mySolution->appendCommand(cmd);
					mySolutionTree->addCommand(cmd);
					setWindowModified(true);
				}
			}
		}
	}
}

bool CatMainWindow::maybeSave()
{
	if(isWindowModified())
	{
		int code = QMessageBox::question(this,tr("提示"),tr("是否保存现在方案?"),
			QMessageBox::Ok,QMessageBox::No,QMessageBox::Cancel);
		if(code == QMessageBox::Ok)
		{
			saveSolution();
			return !solutionPath.isEmpty();
		}

		return code != QMessageBox::Cancel;
	}
	return true;
}

void CatMainWindow::newSolution()
{
	if(maybeSave())
	{
		mySolutionTree->removeAllCommand();
		mySolution->newSolution();
	}
}

void CatMainWindow::saveSolution()
{
	if(solutionPath.isEmpty())
	{
		solutionPath = QFileDialog::getSaveFileName(this,tr("保存方案"),
			QDir::currentPath(),"Cat Solution (*.catsln)");
	}
	if(!solutionPath.isEmpty())
	{
		mySolution->writeTo(solutionPath);
		setWindowModified(false);
	}
}

void CatMainWindow::saveAsSolution()
{
	const QString& fl = QFileDialog::getSaveFileName(this,tr("保存方案"),
		QDir::homePath(),"Cat Solution (*.catsln)");
	if(!fl.isEmpty())
	{
		QString oldPth = solutionPath;
		solutionPath = fl;
		saveSolution();
		solutionPath = oldPth;
	}
}

void CatMainWindow::removeAction()
{
	const QDomElement& cmd = mySolutionTree->currentCommand();
	if(!cmd.isNull())
	{
		mySolutionTree->removeCurrentCommand();
		mySolution->removeCommand(cmd);
		setWindowModified(true);
	}
}

void CatMainWindow::runActions()
{

}

void CatMainWindow::about()
{
	myAbout->exec();
}

void CatMainWindow::onOpenSolution()
{
	if(!maybeSave()) return;

	solutionPath = QFileDialog::getOpenFileName(this,tr("打开方案"),
		QDir::currentPath(),"Cat Solution (*.catsln)");
	if(!solutionPath.isEmpty())
	{
		mySolutionTree->removeAllCommand();
		mySolution->readFrom(solutionPath);
		foreach(const QDomElement& cmd, mySolution->commands())
		{
			mySolutionTree->addCommand(cmd);
		}
	}
}

