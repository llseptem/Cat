#ifndef CATPLUGINMANAGER_H
#define CATPLUGINMANAGER_H

#include <QObject>
#include <QList>
#include <QMap>

class QUuid;
class CatActionPlugin;

class CatPluginManager : public QObject
{
	Q_OBJECT

public:
	CatPluginManager(QObject *parent = 0);
	~CatPluginManager();

	void LoadPlugins();
	void UnloadPlugins();
	CatActionPlugin* plugin(const QUuid& uuid);
	QList<CatActionPlugin*> plugins() const;
private:
	QMap<QUuid,CatActionPlugin*> myPlugins;
};

#endif // CATPLUGINMANAGER_H
