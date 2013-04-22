#ifndef CATRESISTENCEDIALOG_H
#define CATRESISTENCEDIALOG_H

#include <QDialog>
#include "ui_CatResistenceDialog.h"

class CatResistenceDialog : public QDialog
{
	Q_OBJECT

public:
	CatResistenceDialog(QWidget *parent = 0);
	~CatResistenceDialog();

	bool isFourWire() const;
	void setFourWireMode(bool f = true);
	int rRange() const;
	void setRange(int r);
private:
	Ui::CatResistenceDialog ui;
};

#endif // CATRESISTENCEDIALOG_H
