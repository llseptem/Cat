#include "CatCheckDialog.h"

CatCheckDialog::CatCheckDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CatCheckDialog::~CatCheckDialog()
{

}

QString CatCheckDialog::resultType() const
{
	return ui.buttonGroup->checkedButton()->text();
}

int CatCheckDialog::lowerBound() const
{
	return ui.lowerBox->value();
}

int CatCheckDialog::upperBound() const
{
	return ui.upperBox->value();
}
