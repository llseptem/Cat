#ifndef CATMAINWINDOW_H
#define CATMAINWINDOW_H

#include <QMainWindow>
#include <QDomDocument>
#include "ui_CatMainWindow.h"

class CatSolutionTree;

class CatMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CatMainWindow(QWidget *parent = 0);
	~CatMainWindow();

private slots:
	void newSolution();
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
	CatSolutionTree* mySolutionTree;
	QDomDocument myDoc;
};

#endif // CATMAINWINDOW_H
