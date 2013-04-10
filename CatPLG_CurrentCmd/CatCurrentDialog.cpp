#include "CatCurrentDialog.h"

CatCurrentDialog::CatCurrentDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CatCurrentDialog::~CatCurrentDialog()
{

}

bool CatCurrentDialog::isAC() const
{
	return ui.cAC->isChecked();
}

int CatCurrentDialog::cRange() const
{
	return ui.cRange->value();
}
