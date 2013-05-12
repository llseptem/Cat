#include "CatCheckDialog.h"
#include <QListWidgetItem>

CatCheckDialog::CatCheckDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.addBtn,SIGNAL(clicked()),this,SLOT(onAdd()));
	connect(ui.rmBtn,SIGNAL(clicked()),this,SLOT(onRemove()));
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
	if(ui.lowerBox->text().isEmpty() || ui.upperBox->text().isEmpty() || ui.tagEdit->text().isEmpty())
		return;

	ui.rangeList->addItem(ui.tagEdit->text() + ":" + cp + "," + ui.lowerBox->text() + "," + ui.upperBox->text());
}

QString CatCheckDialog::ranges() const
{
	QString list;
	if(ui.rangeList->count())
	{
		list = range(ui.rangeList->item(0)->text());
		for(int i=1; i<ui.rangeList->count(); ++i)
		{
			list.append(";");
			list.append(range(ui.rangeList->item(i)->text()));
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

void CatCheckDialog::setResultType( const QString& tp )
{
	foreach(QAbstractButton* btn, ui.buttonGroup->buttons())
	{
		if(btn->text() == tp)
		{
			btn->setChecked(true);
			break;
		}
	}
}

void CatCheckDialog::setRanges( const QString& tgs, const QString& rgs )
{
	Clear();

	const QStringList& tagList = tgs.split(";");
	const QStringList& rangeList = rgs.split(";");
	int sz = qMin(tagList.size(),rangeList.size());
	for(int i=0; i<sz; ++i)
	{
		ui.rangeList->addItem(tagList.at(i)+":"+rangeList.at(i));
	}
}

QString CatCheckDialog::tags() const
{
	QString list;
	if(ui.rangeList->count())
	{
		list = tag(ui.rangeList->item(0)->text());
		for(int i=1; i<ui.rangeList->count(); ++i)
		{
			list.append(";");
			list.append(tag(ui.rangeList->item(i)->text()));
		}
	}
	return list;
}

QString CatCheckDialog::tag( const QString& line ) const
{
	int	idx= line.indexOf(":");
	return line.left(idx);
}

QString CatCheckDialog::range( const QString& line ) const
{
	int	idx= line.indexOf(":");
	int	charSize = line.size();
	return line.right(charSize - idx - 1);
}
