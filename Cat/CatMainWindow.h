#ifndef CATMAINWINDOW_H
#define CATMAINWINDOW_H

#include <QMainWindow>
#include "ui_CatMainWindow.h"

class CatMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CatMainWindow(QWidget *parent = 0);
	~CatMainWindow();

private:
	Ui::CatMainWindow ui;
};

#endif // CATMAINWINDOW_H
