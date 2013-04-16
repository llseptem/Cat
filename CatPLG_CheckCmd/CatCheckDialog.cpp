#include "CatCheckDialog.h"
#include <QListWidgetItem>

CatCheckDialog::CatCheckDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.addBtn,SIGNAL(clicked()),this,SLOT(onAdd()));
	connect(ui.addBtn,SIGNAL(clicked()),this,SLOT(onRemove()));
}

CatCheckDialog::~CatCheckDialog()
{

}

QString CatCheckDialog::resultType() const
{
	return ui.buttonGroup->checkedButton()->text();
}

void CatCheckDialog::onAdd()
{
	const QString& cp = ui.buttonGroup_2->checkedButton()->text();
	if(ui.lowerBox->text().isEmpty() || ui.upperBox->text().isEmpty())
		return;

	ui.rangeList->addItem(cp + "," + ui.lowerBox->text() + "," + ui.upperBox->text());
}

QString CatCheckDialog::ranges() const
{
	QString list;
	if(ui.rangeList->count())
	{
		list = ui.rangeList->item(0)->text();
		for(int i=1; i<ui.rangeList->count(); ++i)
		{
			list.append(";");
			list.append(ui.rangeList->item(i)->text());
		}
	}
	return list;
}

void CatCheckDialog::Clear()
{
	ui.rangeList->clear();
}

void CatCheckDialog::onRemove()
{
	QListWidgetItem* sel = ui.rangeList->takeItem(ui.rangeList->currentRow());
	if(sel)
	{
		delete sel;
	}
}
