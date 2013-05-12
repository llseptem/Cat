#ifndef CATWIZZARD_H
#define CATWIZZARD_H

#include <QDialog>
#include "ui_CatWizzard.h"

class CatRunUI;
class CatSolution;
class CatWizzard : public QDialog
{
	Q_OBJECT

public:
	CatWizzard(QWidget *parent = 0);
	~CatWizzard();

private slots:
	void onSolutionClicked();
	void onNew();
private:
	Ui::CatWizzard ui;
	CatRunUI* myRunUI;
	CatSolution* mySolution;

	void setupWidget();
};

#endif // CATWIZZARD_H
