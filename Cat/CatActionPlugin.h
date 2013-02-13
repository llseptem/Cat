#ifndef CATACTIONPLUGIN_H
#define CATACTIONPLUGIN_H

#include <QObject>
#include <QUuid>
#include <QtPlugin>
#include <QDomElement>

/************************************************************************/
/* Format: Tag:Uuid,Attribe:anyInfo you need							*/
/************************************************************************/

class CatActionPlugin : public QObject
{
public:
	CatActionPlugin() {}
	~CatActionPlugin(){}

	virtual QUuid Identifier() const =0;
	virtual bool CreateAction(QDomElement& cmd) =0;
	virtual bool RunAction(const QDomElement& elem) =0;
	virtual bool Configure() =0;

	virtual QString title() const =0;
	virtual QString description() const =0;
};

Q_DECLARE_INTERFACE(CatActionPlugin,"cat.action.plugin/1.0")

#endif // CATACTIONPLUGIN_H
