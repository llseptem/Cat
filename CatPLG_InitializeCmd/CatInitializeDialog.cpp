#include "CatInitializeDialog.h"

CatInitializeDialog::CatInitializeDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CatInitializeDialog::~CatInitializeDialog()
{

}

QString CatInitializeDialog::Adr34980() const
{
	return ui.adr34980->text();
}

QString CatInitializeDialog::Adr34411() const
{
	return ui.adr34411->text();
}
