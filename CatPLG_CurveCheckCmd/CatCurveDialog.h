#ifndef CATCURVEDIALOG_H
#define CATCURVEDIALOG_H

#include <QDialog>
#include "ui_CatCurveDialog.h"

class CatCurveDialog : public QDialog
{
	Q_OBJECT

public:
	CatCurveDialog(QWidget *parent = 0);
	~CatCurveDialog();

	QString type() const;
	void setType(const QString& tt);

	QString tag() const;
	void setTag(const QString& tg);
private:
	Ui::CatCurveDialog ui;
};

#endif // CATCURVEDIALOG_H
