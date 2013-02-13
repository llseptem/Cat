#ifndef CATMAINWINDOW_H
#define CATMAINWINDOW_H

#include <QMainWindow>
#include "ui_CatMainWindow.h"

class CatSolutionTree;
class CatActionList;
class CatSolution;
class CatAbout;

class CatMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CatMainWindow(QWidget *parent = 0);
	~CatMainWindow();

private slots:
	void newSolution();
	void onOpenSolution();
	void saveSolution();
	void saveAsSolution();
	void addAction();
	void removeAction();
	void runActions();
	void about();
private:
	void setupWidget();
	void setupConnection();
	bool maybeSave();
private:
	Ui::CatMainWindow ui;
	QString solutionPath;
	CatSolutionTree* mySolutionTree;
	CatActionList* myActionList;
	CatSolution* mySolution;
	CatAbout* myAbout;
};

#endif // CATMAINWINDOW_H
