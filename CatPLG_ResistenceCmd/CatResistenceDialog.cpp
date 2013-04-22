#include "CatResistenceDialog.h"

CatResistenceDialog::CatResistenceDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CatResistenceDialog::~CatResistenceDialog()
{

}

bool CatResistenceDialog::isFourWire() const
{
	return ui.fourWire->isChecked();
}

int CatResistenceDialog::rRange() const
{
	return ui.rRange->value();
}

void CatResistenceDialog::setFourWireMode( bool f /*= true*/ )
{
	QRadioButton* btn = f ? ui.fourWire : ui.twoWire;
	btn->setChecked(true);
}

void CatResistenceDialog::setRange( int r )
{
	ui.rRange->setValue(r);
}
