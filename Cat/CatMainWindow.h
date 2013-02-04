#ifndef CATMAINWINDOW_H
#define CATMAINWINDOW_H

#include <QMainWindow>
#include "ui_CatMainWindow.h"

class QDomElement;
class CatSolutionTree;

class CatMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CatMainWindow(QWidget *parent = 0);
	~CatMainWindow();

private slots:
	void addAction();
	void addActionGroup();
private:
	void setupWidget();
	void setupConnection();
private:
	Ui::CatMainWindow ui;
	CatSolutionTree* mySolutionTree;
};

#endif // CATMAINWINDOW_H
