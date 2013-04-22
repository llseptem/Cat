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
	void setPorts(const QString& pts);
	int waitTime() const;
	void setWaitTime(int t);
	void Clear();
private slots:
	void onAddPort();
	void onRemove();
private:
	Ui::CatScanDialog ui;
};

#endif // CATSCANDIALOG_H
