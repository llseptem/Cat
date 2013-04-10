#ifndef CATVOLTAGEDIALOG_H
#define CATVOLTAGEDIALOG_H

#include <QDialog>
#include "ui_CatVoltageDialog.h"

class CatVoltageDialog : public QDialog
{
	Q_OBJECT

public:
	CatVoltageDialog(QWidget *parent = 0);
	~CatVoltageDialog();

	bool isAC() const;
	int vRange() const;
private:
	Ui::CatVoltageDialog ui;
};

#endif // CATVOLTAGEDIALOG_H
