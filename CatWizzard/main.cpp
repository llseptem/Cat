#include "catwizzard.h"
#include "../Cat/CatPluginManager.h"
#include <QTranslator>
#include <QLibraryInfo>
#include <QTextCodec>
#include <QtGui/QApplication>

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
	CatWizzard w;
	w.show();
	int returnCode = a.exec();
	CatPluginManager::GetInstance()->UnloadPlugins();
	return returnCode;
}