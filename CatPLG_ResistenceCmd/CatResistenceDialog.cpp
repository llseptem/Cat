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
