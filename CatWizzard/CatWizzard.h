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
	void onRerun();
private:
	Ui::CatWizzard ui;
	CatRunUI* myRunUI;
	CatSolution* mySolution;
	QString myCheckID;
	QString mySolutionPath;

	void runGroups(const QStringList& grps);
	void setupWidget();
	void writeLog(const QString& pth,const QString& checkid);
};

#endif // CATWIZZARD_H
