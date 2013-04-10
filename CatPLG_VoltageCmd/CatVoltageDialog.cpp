#include "CatVoltageDialog.h"

CatVoltageDialog::CatVoltageDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CatVoltageDialog::~CatVoltageDialog()
{

}

bool CatVoltageDialog::isAC() const
{
	return ui.ac->isChecked();
}

int CatVoltageDialog::vRange() const
{
	return ui.vRange->value();
}
