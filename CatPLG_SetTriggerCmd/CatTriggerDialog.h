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
	int triggerTimes() const;
private:
	Ui::CatTriggerDialog ui;
};

#endif // CATTRIGGERDIALOG_H
