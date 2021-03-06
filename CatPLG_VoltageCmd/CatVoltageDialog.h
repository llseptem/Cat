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
	void setACMode(bool ac = true);
	int vRange() const;
	void setRange(int v);
private:
	Ui::CatVoltageDialog ui;
};

#endif // CATVOLTAGEDIALOG_H
