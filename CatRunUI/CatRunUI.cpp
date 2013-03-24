#include "CatRunUI.h"
#include "ui_CatRunUI.h"
#include <QEventLoop>
#include <QTimer>

CatRunUI::CatRunUI(QWidget *parent)
	: QDialog(parent),ui(new Ui::CatRunUI())
{
	ui->setupUi(this);
}

CatRunUI::~CatRunUI()
{
	delete ui;
}

void CatRunUI::setInformation( const QString& info )
{
	ui->textLabel->setText(info);
}

void CatRunUI::setImage( const QImage& img )
{
	ui->imgLabel->setPixmap(QPixmap::fromImage(img));
}

void CatRunUI::setImage( const QString& pth )
{
	 QImage img(pth);
	 if(!img.isNull())
	 {
		 setImage(img);
	 }
}

bool CatRunUI::waitForDecition()
{
	ui->yesBtn->setVisible(true);
	ui->yesBtn->setChecked(false);
	ui->noBtn->setVisible(true);

	QEventLoop loop;
	connect(ui->yesBtn,SIGNAL(clicked()),&loop,SLOT(quit()));
	connect(ui->noBtn,SIGNAL(clicked()),&loop,SLOT(quit()));
	connect(this,SIGNAL(rejected()),&loop,SLOT(quit()));
	loop.exec();

	ui->yesBtn->setVisible(false);
	ui->noBtn->setVisible(false);
	return ui->yesBtn->isChecked();
}

bool CatRunUI::wait( int sec )
{
	QEventLoop loop;
	QTimer timer;
	timer.setSingleShot(true);
	connect(&timer,SIGNAL(timeout()),&loop,SLOT(quit()));
	connect(this,SIGNAL(rejected()),&loop,SLOT(quit()));

	timer.start(sec*1000);
	loop.exec();

	return timer.isActive();
}
