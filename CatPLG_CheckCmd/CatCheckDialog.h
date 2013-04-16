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
	QString ranges() const;
	void Clear();
private slots:
	void onAdd();
	void onRemove();
private:
	Ui::CatCheckDialog ui;
};

#endif // CATCHECKDIALOG_H
