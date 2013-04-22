#include "CatTriggerDialog.h"

CatTriggerDialog::CatTriggerDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CatTriggerDialog::~CatTriggerDialog()
{

}

bool CatTriggerDialog::isExtMode() const
{
	return ui.extMode->isChecked();
}

int CatTriggerDialog::triggerTimes() const
{
	return ui.triggerNum->value();
}

void CatTriggerDialog::setExtMode( bool ext /*= true*/ )
{
	QRadioButton* btn = ext ? ui.extMode : ui.instanceMode;
	btn->setChecked(true);
}

void CatTriggerDialog::setTriggerTimes( int t )
{
	ui.triggerNum->setValue(t);
}
