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

void CatVoltageDialog::setACMode( bool ac /*= true*/ )
{
	QRadioButton* btn = ac ? ui.ac : ui.dc;
	btn->setChecked(true);
}

void CatVoltageDialog::setRange( int v )
{
	ui.vRange->setValue(v);
}
