#ifndef CATPORTSELECTDIALOG_H
#define CATPORTSELECTDIALOG_H

#include <QDialog>
#include "ui_catportselectdialog.h"

class CatPortSelectDialog : public QDialog
{
	Q_OBJECT

public:
	CatPortSelectDialog(QWidget *parent = 0);
	~CatPortSelectDialog();

	QStringList Ports() const;
private slots:
	void onAdd();
private:
	Ui::CatPortSelectDialog ui;
	void addPort(const QString& pt);
};

#endif // CATPORTSELECTDIALOG_H
