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

void CatCurrentDialog::setACMode( bool ac /*= true*/ )
{
	QRadioButton* btn = ac ? ui.cAC : ui.cDC;
	btn->setChecked(true);
}

void CatCurrentDialog::setRange( int c )
{
	ui.cRange->setValue(c);
}
