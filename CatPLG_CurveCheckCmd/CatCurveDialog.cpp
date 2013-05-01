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
