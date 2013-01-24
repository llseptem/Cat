#ifndef CATACTIONPLUGIN_H
#define CATACTIONPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include "../CatAction/CatAction.h"

class CatActionPlugin : public QObject
{
	Q_OBJECT

public:
	CatActionPlugin(QObject* parent = 0);
	~CatActionPlugin();

	virtual CatAction::Pointer CreateAction() =0; 

	QString title() const;
	QString description() const;
protected:
	QString myTitle;
	QString myDescription;
};

Q_DECLARE_INTERFACE(CatActionPlugin,"cat.action.plugin/1.0")

#endif // CATACTIONPLUGIN_H
