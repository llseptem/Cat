#ifndef CATCHECKDIALOG_H
#define CATCHECKDIALOG_H

#include <QDialog>
#include "ui_CatCheckDialog.h"

class CatCheckDialog : public QDialog
{
	Q_OBJECT

public:
	CatCheckDialog(QWidget *parent = 0);
	~CatCheckDialog();

	QString resultType() const;
	int lowerBound() const;
	int upperBound() const;
private:
	Ui::CatCheckDialog ui;
};

#endif // CATCHECKDIALOG_H
