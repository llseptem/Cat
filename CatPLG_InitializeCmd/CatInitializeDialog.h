#ifndef CATINITIALIZEDIALOG_H
#define CATINITIALIZEDIALOG_H

#include <QDialog>
#include "ui_CatInitializeDialog.h"

class CatInitializeDialog : public QDialog
{
	Q_OBJECT

public:
	CatInitializeDialog(QWidget *parent = 0);
	~CatInitializeDialog();

	QString Adr34980() const;
	QString Adr34411() const;
	bool isUninitial() const;
private:
	Ui::CatInitializeDialog ui;
};

#endif // CATINITIALIZEDIALOG_H
