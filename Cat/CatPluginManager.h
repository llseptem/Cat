#ifndef CATPLUGINMANAGER_H
#define CATPLUGINMANAGER_H

#include <QObject>
#include <QDomDocument>
#include <QList>
#include <QMap>
#include "../CatAction/CatAction.h"

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

	QList<QUuid> plugins() const;
	QString pluginTitle(const QUuid& id) const;
	QString pluginDescription(const QUuid& id) const;
	CatAction::Pointer createAction(const QUuid& id) const;
	CatAction::Pointer restoreAction(const QDomElement& elem) const;
	void writeAction(const CatAction::Pointer& act, QDomElement& elem) const;
private:
	QMap<QUuid,CatActionPlugin*> myPlugins;
};

#endif // CATPLUGINMANAGER_H
