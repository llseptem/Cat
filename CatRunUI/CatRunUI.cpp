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
#include <QScrollArea>
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

void CatRunUI::setInformation( const QString& info, bool err )
{
	const QString& tm = QDateTime::currentDateTime().toString(Qt::ISODate);
	QString fmtMsg = tm + " " + info;
	if(!fmtMsg.endsWith("\n")) {fmtMsg += "\n";}

	QTextCharFormat fmt;
	fmt.setForeground( err ? Qt::red : Qt::darkBlue);
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
	QPrintDialog prtDlg(this);
	if(prtDlg.exec() == QDialog::Accepted)
	{
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
	font.setPointSize(14);
	ui->textEdit->setFont(font);
//	ui->textEdit->setBackgroundRole(QPalette::Dark);
	connect(ui->printBtn,SIGNAL(clicked()),this,SLOT(print()));
	connect(ui->continueBtn,SIGNAL(clicked()),this,SIGNAL(reRun()));

	myCurve  = new CatCurveWidget();
	myDigits = new CatDigitList();
	myDigitsContainer = new QScrollArea();
	myDigitsContainer->setWidget(myDigits);
	myDigitsContainer->setBackgroundRole(QPalette::Dark);
	myDigitsContainer->setWidgetResizable(true);

	ui->resultGrp->setLayout(new QVBoxLayout());
	ui->resultGrp->layout()->addWidget(myDigitsContainer);
	ui->resultGrp->layout()->addWidget(myCurve);
	digitMode();
}

void CatRunUI::enablePrint(bool able)
{
	ui->printBtn->setVisible(able);
}

void CatRunUI::reset()
{
	ui->imgLabel->clear();
	ui->titleLabel->clear();
	ui->textEdit->clear();
	digitMode();
	clearDigits();
	enablePrint(false);
	enableRerun(false);
}

void CatRunUI::digitMode()
{
	myDigitsContainer->setVisible(true);
	myCurve->setVisible(false);
}

void CatRunUI::curveMode()
{
	myDigitsContainer->setVisible(false);
	myCurve->setVisible(true);
}

void CatRunUI::clearDigits()
{
	myDigits->RemoveAll();
}

void CatRunUI::displayDigit( const QString& tag,double val )
{
	myDigits->DisplayInfo(tag,val);
}

void CatRunUI::drawCurve( const QString& lb, const QPolygonF& pts )
{
	myCurve->setLabel(lb);
	myCurve->setCurveData(pts);
	myCurve->replot();
}

void CatRunUI::setMessage( const QString& msg )
{
	const QString& tt = ui->titleLabel->text();
	ui->titleLabel->setText(tt + "---" + msg);
}

void CatRunUI::clearMessage()
{
	int pos = ui->titleLabel->text().indexOf("---");
	const QString& tt = ui->titleLabel->text().left(pos);
	ui->titleLabel->setText(tt);
}

bool CatRunUI::writeLog( const QString& xml )
{
	QFile log(QDateTime::currentDateTime().toString(Qt::ISODate)+".html");
	if(log.open(QIODevice::WriteOnly))
	{
		QTextStream tos(&log);
		tos << ui->textEdit->toHtml();
	}
	return log.isOpen();
}

void CatRunUI::enableRerun( bool able )
{
	ui->continueBtn->setVisible(able);
}
