#include "CatPluginManager.h"
#include "CatActionPlugin.h"
#include <QSharedPointer>
#include <QPluginLoader>
#include <QApplication>
#include <QDebug>
#include <QDir>

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

QStringList CatPluginManager::getPlugins() const
{
	QDir curDir = qApp->applicationDirPath();
	QStringList plgs;
	if(!curDir.cd("Plugins")) 
	{
		qDebug() << tr("Plugin Directory does not exists.");
		return plgs;
	}

	foreach(const QString& plg,curDir.entryList(QStringList() << "*.dll"))
	{
		plgs << curDir.absoluteFilePath(plg);
	}

	return plgs;
}
void CatPluginManager::LoadPlugins()
{
	foreach(const QString& plg,getPlugins())
	{
		QPluginLoader loader(plg);
		if(CatActionPlugin* plug = qobject_cast<CatActionPlugin*>(loader.instance()))
		{
			myPlugins.insert(plug->Identifier(),plug);
		}
		else
		{
			qDebug() << loader.errorString();
		}
	}
}

void CatPluginManager::UnloadPlugins()
{
	myPlugins.clear();
}

QList<QUuid> CatPluginManager::plugins() const
{
	return myPlugins.keys();
}

QString CatPluginManager::pluginTitle( const QUuid& id ) const
{
	CatActionPlugin* plg = myPlugins.value(id,0);
	return plg ? plg->title() : QString("");
}

QString CatPluginManager::pluginDescription( const QUuid& id ) const
{
	CatActionPlugin* plg = myPlugins.value(id,0);
	return plg ? plg->description() : QString("");
}

bool CatPluginManager::configurePlugin( const QUuid& id, const QDomElement& elem )
{
	CatActionPlugin* plg = myPlugins.value(id,0);
	return plg ? plg->Configure(elem) : false;
}

bool CatPluginManager::createAction( const QUuid& id, QDomElement& cmd ) const
{
	CatActionPlugin* plg = myPlugins.value(id,0);
	return plg ? plg->CreateAction(cmd) : false;
}

bool CatPluginManager::runAction( const QUuid& id, const QDomElement& cmd, CatRunUI* ui ) const
{
	CatActionPlugin* plg = myPlugins.value(id,0);
	return plg ? plg->RunAction(cmd,ui) : false;
}

