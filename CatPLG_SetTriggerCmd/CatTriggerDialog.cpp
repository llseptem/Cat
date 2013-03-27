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
