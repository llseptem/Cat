#include "catportselectdialog.h"
#include <QListWidgetItem>

CatPortSelectDialog::CatPortSelectDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.addBtn,SIGNAL(clicked()),this,SLOT(onAdd()));
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

QStringList CatPortSelectDialog::Ports() const
{
	QStringList ports;
	for(int i=0; i<ui.portList->count(); ++i)
	{
		ports << ui.portList->item(i)->text();
	}
	return ports;
}
