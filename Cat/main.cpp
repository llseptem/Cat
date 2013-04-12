#include <QtGui/QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QTextCodec>
#include "CatMainWindow.h"
#include "CatPluginManager.h"

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
	QApplication a(argc, argv);
	QTranslator translator;
	if(translator.load("qt_zh_cn",QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
	{
		a.installTranslator(&translator);
	}

	CatPluginManager::GetInstance()->LoadPlugins();
	CatMainWindow w;
	w.showMaximized();

	int returnCode = a.exec();
	CatPluginManager::GetInstance()->UnloadPlugins();
	return returnCode;
}
