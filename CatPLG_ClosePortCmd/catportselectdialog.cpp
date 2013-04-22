#include "catportselectdialog.h"
#include <QListWidgetItem>

CatPortSelectDialog::CatPortSelectDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.addBtn,SIGNAL(clicked()),this,SLOT(onAdd()));
	connect(ui.rmBtn,SIGNAL(clicked()),this,SLOT(onRemove()));
}

CatPortSelectDialog::~CatPortSelectDialog()
{

}

void CatPortSelectDialog::onAdd()
{
	const QString& pt = ui.portEdit->text();
	if(!pt.isEmpty())
	{
		addPort(pt);
		ui.portEdit->clear();
	}
}

void CatPortSelectDialog::addPort( const QString& pt )
{
	ui.portList->addItem(pt);
}

QString CatPortSelectDialog::Ports() const
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

void CatPortSelectDialog::Clear()
{
	ui.portEdit->clear();
	ui.portList->clear();
}

bool CatPortSelectDialog::isOpen() const
{
	return ui.isOpenBtn->isChecked();
}

void CatPortSelectDialog::onRemove()
{
	QListWidgetItem* sel = ui.portList->takeItem(ui.portList->currentRow());
	if(sel)
	{
		delete sel;
	}
}

void CatPortSelectDialog::setOpenMode( bool op /*= true*/ )
{
	ui.isOpenBtn->setChecked(op);
}

void CatPortSelectDialog::SetPorts( const QString& ports )
{
	ui.portList->addItems(ports.split(","));
}
