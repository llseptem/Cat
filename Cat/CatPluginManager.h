#ifndef CATPLUGINMANAGER_H
#define CATPLUGINMANAGER_H

#include <QObject>
#include <QUuid>
#include <QDomDocument>
#include <QList>
#include <QMap>

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
	bool createAction(const QUuid& id, QDomElement& cmd) const;
	bool runAction(const QDomElement& cmd) const;//maybe ui
private:
	CatPluginManager(QObject *parent = 0);
	QStringList getPlugins() const;
	QMap<QUuid,CatActionPlugin*> myPlugins;
};

#endif // CATPLUGINMANAGER_H
