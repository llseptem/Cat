#include "CatMainWindow.h"
#include "CatAbout.h"
#include "CatSolutionTree.h"
#include "CatActionList.h"
#include <QFileDialog>
#include <QInputDialog>
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
}

void CatMainWindow::setupConnection()
{
	connect(ui.actionNewSolution,SIGNAL(triggered()),this,SLOT(newSolution()));
	connect(ui.actionSave,SIGNAL(triggered()),this,SLOT(saveSolution()));
	connect(ui.actionSaveAs,SIGNAL(triggered()),this,SLOT(saveAsSolution()));
	connect(ui.actionOpen,SIGNAL(triggered()),this,SLOT(openSolution()));

	connect(ui.actionNewAction,SIGNAL(triggered()),this,SLOT(addAction()));
	connect(ui.actionNewGroup,SIGNAL(triggered()),this,SLOT(addGroup()));
	connect(ui.actionRemoveAction,SIGNAL(triggered()),mySolutionTree,SLOT(removeCurrent()));

	connect(ui.actionGo,SIGNAL(triggered()),mySolutionTree,SLOT(run()));

	connect(ui.actionAbout,SIGNAL(triggered()),this,SLOT(about()));

	connect(mySolutionTree,SIGNAL(currentCanBeDeleted(bool)),
		ui.actionRemoveAction,SLOT(setEnabled(bool)));
	connect(mySolutionTree,SIGNAL(commandCanBeAdded(bool)),
		ui.actionNewAction,SLOT(setEnabled(bool)));
}

void CatMainWindow::addAction()
{
	if(myActionList->exec() == QDialog::Accepted)
	{
		const QUuid& uid = myActionList->selectedCommand();
		if(!uid.isNull())
		{
			mySolutionTree->createCommand(uid);
		}
	}
}

void CatMainWindow::addGroup()
{
	const QString& grp = QInputDialog::getText(this,tr("添加新组"),
		tr("请输入组名"));
	if(!grp.isEmpty())
	{
		mySolutionTree->createGroup(grp);
	}
}

bool CatMainWindow::maybeSave()
{
	if(mySolutionTree->isWindowModified())
	{
		int code = QMessageBox::question(this,tr("提示"),tr("是否保存现在方案?"),
			QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
		if(code == QMessageBox::Yes)
		{
			return saveSolution();
		}

		return code != QMessageBox::Cancel;
	}
	return true;
}

void CatMainWindow::newSolution()
{
	if(maybeSave())
	{
		mySolutionTree->newDoc();
		solutionPath.clear();
	}
}

bool CatMainWindow::saveSolution()
{
	if(solutionPath.isEmpty())
	{
		solutionPath = QFileDialog::getSaveFileName(this,tr("保存方案"),
			QDir::currentPath(),"Cat Solution (*.catsln)");
	}
	if(!solutionPath.isEmpty())
	{
		mySolutionTree->save(solutionPath);
	}
	return !solutionPath.isEmpty();
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

void CatMainWindow::about()
{
	myAbout->exec();
}

void CatMainWindow::openSolution()
{
	if(!maybeSave()) return;

	solutionPath = QFileDialog::getOpenFileName(this,tr("打开方案"),
		QDir::currentPath(),"Cat Solution (*.catsln)");
	if(!solutionPath.isEmpty())
	{
		mySolutionTree->read(solutionPath);
	}
}

