#include <QtGui/QApplication>
#include <QTextCodec>
#include "CatMainWindow.h"

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QApplication a(argc, argv);

	CatMainWindow w;
	w.show();

	return a.exec();
}
