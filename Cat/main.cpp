#include <QtGui/QApplication>
#include <QTextCodec>
#include "CatMainWindow.h"
#include "CatPluginManager.h"

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
	QApplication a(argc, argv);

	CatPluginManager::GetInstance()->LoadPlugins();
	CatMainWindow w;
	w.showMaximized();

	int returnCode = a.exec();
	CatPluginManager::GetInstance()->UnloadPlugins();
	return returnCode;
}
