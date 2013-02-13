#ifndef CATABOUT_H
#define CATABOUT_H

#include <QDialog>
#include "ui_CatAbout.h"

class CatAbout : public QDialog
{
	Q_OBJECT

public:
	CatAbout(QWidget *parent = 0);
	~CatAbout();

private slots:
	void onAboutQt();
private:
	Ui::CatAbout ui;
};

#endif // CATABOUT_H
