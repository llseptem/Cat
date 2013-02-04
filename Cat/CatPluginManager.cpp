#include "CatPluginManager.h"
#include <QSharedPointer>
#include <QPluginLoader>

CatPluginManager::CatPluginManager(QObject *parent)
	: QObject(parent)
{

}

CatPluginManager::~CatPluginManager()
{

}

CatPluginManager* CatPluginManager::GetInstance()
{
	static QSharedPointer<CatPluginManager> instance(new CatPluginManager());

	return instance.data();
}

void CatPluginManager::LoadPlugins()
{

}
