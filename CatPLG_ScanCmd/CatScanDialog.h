#ifndef CATSCANDIALOG_H
#define CATSCANDIALOG_H

#include <QDialog>
#include "ui_CatScanDialog.h"

class CatScanDialog : public QDialog
{
	Q_OBJECT

public:
	CatScanDialog(QWidget *parent = 0);
	~CatScanDialog();

	QString ports() const;
	int waitTime() const;
	void Clear();
private slots:
	void onAddPort();
private:
	Ui::CatScanDialog ui;
};

#endif // CATSCANDIALOG_H
