#include "CatScanDialog.h"
#include <QListWidgetItem>

CatScanDialog::CatScanDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.addBtn,SIGNAL(clicked()),this,SLOT(onAddPort()));
	connect(ui.rmBtn,SIGNAL(clicked()),this,SLOT(onRemove()));
}

CatScanDialog::~CatScanDialog()
{

}

void CatScanDialog::onAddPort()
{
	const QString& txt = ui.portBox->text();
	if(!txt.isEmpty())
	{
		ui.portList->addItem(txt);
	}
}

QString CatScanDialog::ports() const
{
	QString list;
	if(ui.portList->count())
	{
		list = ui.portList->item(0)->text();
		for(int i=1; i<ui.portList->count(); ++i)
		{
			list.append(",");
			list.append(ui.portList->item(i)->text());
		}
	}
	return list;
}

int CatScanDialog::waitTime() const
{
	return ui.waitBox->value();
}

void CatScanDialog::Clear()
{
	ui.portList->clear();
}

void CatScanDialog::onRemove()
{
	QListWidgetItem* sel = ui.portList->takeItem(ui.portList->currentRow());
	if(sel)
	{
		delete sel;
	}
}
