#include "CatAbout.h"
#include <QMessageBox>

CatAbout::CatAbout(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.aboutQtBtn,SIGNAL(clicked()),this,SLOT(onAboutQt()));
}

CatAbout::~CatAbout()
{

}

void CatAbout::onAboutQt()
{
	QMessageBox::aboutQt(this);
}
