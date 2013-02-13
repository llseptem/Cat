#include "CatUserDecideCmd.h"

CatUserDecideCmd::CatUserDecideCmd(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CatUserDecideCmd::~CatUserDecideCmd()
{

}

void CatUserDecideCmd::setShowImage( const QString& img )
{
	ui.imgLabel->setPixmap(QPixmap(img));
	adjustSize();
}

void CatUserDecideCmd::setQuestion( const QString& qst )
{
	ui.askLabel->setText(qst);
}
