#include "CatRunUI.h"
#include "ui_CatRunUI.h"
#include <QEventLoop>
#include <QTimer>
#include <QFont>
#include <QPrintDialog>
#include <QInputDialog>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include "CatCurveWidget.h"
#include "CatDigitList.h"

CatRunUI::CatRunUI(QWidget *parent)
	: QDialog(parent),ui(new Ui::CatRunUI())
{
	setupWidget();
}

CatRunUI::~CatRunUI()
{
	delete ui;
	delete myCurve;
	delete myDigits;
}

void CatRunUI::setInformation( const QString& info )
{
	const QString& tm = QDateTime::currentDateTime().toString(Qt::ISODate);
	QString fmtMsg = tm + "\n" + info;
	if(!fmtMsg.endsWith("\n")) {fmtMsg += "\n";}

	QTextCharFormat fmt;
	fmt.setForeground(Qt::darkBlue);
	ui->textEdit->moveCursor(QTextCursor::End);
	ui->textEdit->textCursor().insertText(fmtMsg,fmt);
	ui->textEdit->ensureCursorVisible();
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

void CatRunUI::setTitle( const QString& tt )
{
	ui->titleLabel->setText(tt);
}

void CatRunUI::print()
{
	const QString& checkID = QInputDialog::getText(this,tr("输入流水号"),tr("流水号"));
	if(checkID.isEmpty()) return;

	QPrintDialog prtDlg(this);
	if(prtDlg.exec() == QDialog::Accepted)
	{
		setInformation(tr("检测流水号:") + checkID);
		ui->textEdit->print(prtDlg.printer());
	}
}

void CatRunUI::setupWidget()
{
	ui->setupUi(this);
	ui->yesBtn->setVisible(false);
	ui->noBtn->setVisible(false);
	ui->printBtn->setVisible(false);
	QFont font;
	font.setFamily("Courier");
	font.setFixedPitch(true);
	font.setPointSize(10);
	ui->textEdit->setFont(font);
	connect(ui->printBtn,SIGNAL(clicked()),this,SLOT(print()));

	myCurve  = new CatCurveWidget();
	myDigits = new CatDigitList();

	ui->resultGrp->setLayout(new QVBoxLayout());
	ui->resultGrp->layout()->addWidget(myDigits);
	ui->resultGrp->layout()->addWidget(myCurve);
	digitMode();
}

void CatRunUI::checkFinished()
{
	ui->printBtn->setVisible(true);

	QFile log(QDateTime::currentDateTime().toString(Qt::ISODate)+".log");
	if(log.open(QIODevice::WriteOnly))
	{
		QTextStream tos(&log);
		tos << ui->textEdit->toHtml();
	}
}

void CatRunUI::checkBegin()
{
	ui->imgLabel->clear();
	ui->titleLabel->clear();
	ui->textEdit->clear();
	digitMode();
	clearDigits();
	ui->printBtn->setVisible(false);
}

void CatRunUI::digitMode()
{
	myDigits->setVisible(true);
	myCurve->setVisible(false);
}

void CatRunUI::curveMode()
{
	myDigits->setVisible(false);
	myCurve->setVisible(true);
}

void CatRunUI::clearDigits()
{
	myDigits->RemoveAll();
}

void CatRunUI::displayDigit( int wireNum,double val )
{
	myDigits->DisplayInfo(wireNum,val);
}

void CatRunUI::drawCurve( const QString& lb, const QPolygonF& pts )
{
	myCurve->setLabel(lb);
	myCurve->setCurveData(pts);
	myCurve->replot();
}
