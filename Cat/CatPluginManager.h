#ifndef CATPLUGINMANAGER_H
#define CATPLUGINMANAGER_H

#include <QUuid>
#include <QDomDocument>
#include <QList>
#include <QMap>
#include "../CatAction/CatAction.h"

class CatActionPlugin;

class CatPluginManager : public QObject
{
	Q_OBJECT

public:
	static CatPluginManager* GetInstance();
	~CatPluginManager();

	void LoadPlugins();
	void UnloadPlugins();

	QList<QUuid> plugins() const;
	QString pluginTitle(const QUuid& id) const;
	QString pluginDescription(const QUuid& id) const;

	bool configurePlugin(const QUuid& id);//maybe ui
	void createAction(const QUuid& id, QDomElement& cmd) const;
	bool runAction(const QDomElement& cmd) const;//maybe ui
private:
	CatPluginManager(QObject *parent = 0);
	QMap<QUuid,CatActionPlugin*> myPlugins;
};

#endif // CATPLUGINMANAGER_H
