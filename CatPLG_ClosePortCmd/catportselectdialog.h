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

	bool isOpen() const;
	QString Ports() const;
	void Clear();
private slots:
	void onAdd();
	void onRemove();
private:
	Ui::CatPortSelectDialog ui;
	void addPort(const QString& pt);
};

#endif // CATPORTSELECTDIALOG_H
