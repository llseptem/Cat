#include "CatCurveDialog.h"

CatCurveDialog::CatCurveDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CatCurveDialog::~CatCurveDialog()
{

}

QString CatCurveDialog::type() const
{
	return ui.buttonGroup->checkedButton()->text();
}

void CatCurveDialog::setType( const QString& tt )
{
	foreach(QAbstractButton* btn,ui.buttonGroup->buttons())
	{
		if(btn->text() == tt)
		{
			btn->setChecked(true);
			break;
		}
	}
}

QString CatCurveDialog::tag() const
{
	return ui.tagEdit->text();
}

void CatCurveDialog::setTag( const QString& tg )
{
	ui.tagEdit->setText(tg);
}
