#include "CatSolution.h"
#include <QFile>
#include <QTextStream>

CatSolution::CatSolution(QObject *parent)
	: QObject(parent)
{
	newSolution();
}

CatSolution::~CatSolution()
{

}

QDomElement CatSolution::createCommand()
{
	return myDoc.createElement("Unnamed");
}

void CatSolution::appendCommand( const QDomElement& cmd )
{
	QDomElement root = myDoc.documentElement();
	root.appendChild(cmd);
}

bool CatSolution::writeTo( const QString& pth )
{
	QFile fl(pth);
	if(fl.open(QFile::WriteOnly))
	{
		QTextStream ots(&fl);
		ots << myDoc.toString();
		return true;
	}
	return false;
}

bool CatSolution::readFrom( const QString& pth )
{
	QFile fl(pth);
	if(fl.open(QFile::ReadOnly))
	{
		bool success = myDoc.setContent(&fl);
		if(!success){myDoc.clear();}
		return success;
	}
	return false;
}

QList<QDomElement> CatSolution::commands() const
{
	QList<QDomElement> cmds;
	QDomElement root = myDoc.documentElement();
	QDomElement cmd = root.firstChildElement();
	while(!cmd.isNull())
	{
		cmds.append(cmd);
		cmd = cmd.nextSiblingElement();
	}
	return cmds;
}

void CatSolution::newSolution()
{
	myDoc.clear();
	QDomElement root = myDoc.createElement("Solution");
	myDoc.appendChild(root);
}

void CatSolution::removeCommand( const QDomElement& cmd )
{
	QDomElement root = myDoc.documentElement();
	root.removeChild(cmd);
}

