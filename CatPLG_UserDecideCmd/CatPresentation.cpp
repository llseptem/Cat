#include "CatPresentation.h"
#include <QFileDialog>

CatPresentation::CatPresentation(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setupConnect();
}

CatPresentation::~CatPresentation()
{

}

void CatPresentation::onSelectImage()
{
	const QString& img = QFileDialog::getOpenFileName(this,tr("Ñ¡ÔñÊ¾ÒâÍ¼"),
		QDir::currentPath(),"Images (*.jpg *.png *.bmp *.tiff)");
	if(!img.isEmpty())
	{
		ui.imagePrev->setPixmap(QPixmap(img));
		ui.imgPath->setText(img);
	}
}

void CatPresentation::onAccepted()
{
	const QString& txt = ui.imgPath->text();
	QPalette p = ui.groupBox_2->palette();
	p.setColor(QPalette::Text,txt.isEmpty() ? Qt::red : Qt::black);
	ui.groupBox_2->setPalette(p);

	const QString& desc = ui.description->toPlainText();
	QPalette p2 = ui.groupBox->palette();
	p.setColor(QPalette::Text,desc.isEmpty() ? Qt::red : Qt::black);
	ui.groupBox->setPalette(p2);

	if(!txt.isEmpty() && !desc.isEmpty())
	{
		accept();
	}
}

void CatPresentation::setupConnect()
{
	connect(ui.selImageBtn,SIGNAL(clicked()),this,SLOT(onSelectImage()));
	connect(ui.okBtn,SIGNAL(clicked()),this,SLOT(onAccepted()));
	connect(ui.cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
}

QString CatPresentation::imagePath() const
{
	return ui.imgPath->text();
}

QString CatPresentation::description() const
{
	return ui.description->toPlainText();
}

void CatPresentation::SetImagePath( const QString& pth )
{
	ui.imgPath->setText(pth);
	ui.imagePrev->setPixmap(QPixmap(pth));
}

void CatPresentation::SetDescription( const QString& desc )
{
	ui.description->clear();
	ui.description->textCursor().insertText(desc);
}
