#ifndef CATACTIONPLUGIN_H
#define CATACTIONPLUGIN_H

#include <QObject>
#include <QUuid>
#include <QtPlugin>
#include <QDomElement>
#include "../CatAction/CatAction.h"

/************************************************************************/
/* Format: Tag:Uuid,Attribe:anyInfo you need							*/
/************************************************************************/

class CatActionPlugin : public QObject
{
	Q_OBJECT

public:
	CatActionPlugin(QObject* parent = 0);
	~CatActionPlugin();

	virtual QUuid Identifier() const =0;
	virtual CatAction::Pointer CreateAction() =0;
	virtual bool RunAction(const QDomElement& elem) =0;
	virtual CatAction::Pointer RestoreAction(const QDomElement& elem) =0;
	virtual void WriteAction(const CatAction::Pointer& ins,QDomElement& elem) =0;

	QString title() const;
	QString description() const;
protected:
	QString myTitle;
	QString myDescription;
};

Q_DECLARE_INTERFACE(CatActionPlugin,"cat.action.plugin/1.0")

#endif // CATACTIONPLUGIN_H
