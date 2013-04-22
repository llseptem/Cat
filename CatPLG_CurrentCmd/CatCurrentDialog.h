#ifndef CATCURRENTDIALOG_H
#define CATCURRENTDIALOG_H

#include <QDialog>
#include "ui_CatCurrentDialog.h"

class CatCurrentDialog : public QDialog
{
	Q_OBJECT

public:
	CatCurrentDialog(QWidget *parent = 0);
	~CatCurrentDialog();

	bool isAC() const;
	void setACMode(bool ac = true);
	int cRange() const;
	void setRange(int c);
private:
	Ui::CatCurrentDialog ui;
};

#endif // CATCURRENTDIALOG_H
