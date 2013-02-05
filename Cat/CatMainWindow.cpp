#include "CatMainWindow.h"
#include "CatSolutionTree.h"
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
}

void CatMainWindow::setupConnection()
{

}

void CatMainWindow::addAction()
{

}

