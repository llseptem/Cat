#ifndef CATWIZZARD_H
#define CATWIZZARD_H

#include <QDialog>
#include "ui_CatWizzard.h"

class CatWizzard : public QDialog
{
	Q_OBJECT

public:
	CatWizzard(QWidget *parent = 0);
	~CatWizzard();

private:
	Ui::CatWizzard ui;
};

#endif // CATWIZZARD_H
