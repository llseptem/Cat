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
	void setResultType(const QString& tp);
	QString ranges() const;
	QString tags() const;
	void setRanges(const QString& tgs, const QString& rgs);
	void Clear();
private slots:
	void onAdd();
	void onRemove();
private:
	QString tag(const QString& line) const;
	QString range(const QString& line) const;
	Ui::CatCheckDialog ui;
};

#endif // CATCHECKDIALOG_H
