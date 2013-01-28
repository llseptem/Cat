#include <QtGui/QApplication>
#include "CatMainWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CatMainWindow w;
	w.show();

	return a.exec();
}
