#ifndef CATTRIGGERDIALOG_H
#define CATTRIGGERDIALOG_H

#include <QDialog>
#include "ui_CatTriggerDialog.h"

class CatTriggerDialog : public QDialog
{
	Q_OBJECT

public:
	CatTriggerDialog(QWidget *parent = 0);
	~CatTriggerDialog();

	bool isExtMode() const;
	void setExtMode(bool ext = true);
	int triggerTimes() const;
	void setTriggerTimes(int t);
private:
	Ui::CatTriggerDialog ui;
};

#endif // CATTRIGGERDIALOG_H
