#include "CatActionPlugin.h"

CatActionPlugin::CatActionPlugin(QObject *parent)
	: QObject(parent)
{

}

CatActionPlugin::~CatActionPlugin()
{

}

QString CatActionPlugin::title() const
{
	return myTitle;
}

QString CatActionPlugin::description() const
{
	return myDescription;
}
