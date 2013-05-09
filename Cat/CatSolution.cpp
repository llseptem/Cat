#include "CatSolution.h"
#include <QFile>
#include <QUuid>
#include <QStringList>
#include <QTextCodec>
#include <QDebug>

CatSolution::CatSolution(QObject *parent)
	: QObject(parent)
{
	newSolution();
}

CatSolution::~CatSolution()
{

}

QDomElement CatSolution::createCommand(const QUuid& uid)
{
	QDomElement cmd = myDoc.createElement("Command");
	QDomElement id = myDoc.createElement("UID");
	QDomText uuidStr = myDoc.createTextNode(uid.toString());
	id.appendChild(uuidStr);
	cmd.appendChild(id);
	return cmd;
}

QUuid CatSolution::commandID( const QDomElement& cmd ) const
{
	QDomElement uid = cmd.firstChildElement("UID");
	if(!uid.isNull())
	{
		return QUuid(uid.text());
	}
	return QUuid();
}

bool CatSolution::writeTo( const QString& pth )
{
	QFile fl(pth);
	if(fl.open(QFile::WriteOnly))
	{
		QTextStream ots(&fl);
		ots.setCodec(QTextCodec::codecForLocale());
//		ots << myDoc.toString();
		myDoc.save(ots,1);
		return true;
	}
	return false;
}

bool CatSolution::readFrom( const QString& pth )
{
	bool success;
	QFile fl(pth);
	if(success = fl.open(QFile::ReadOnly))
	{
		QString msg;
		int line,col;
		if(success = myDoc.setContent(&fl,false,&msg,&line,&col))
		{
			QDomElement grp = myDoc.documentElement().firstChildElement();
			while(!grp.isNull())
			{
				if(hasGroup(grp.tagName()))
				{
					success = false;
					break;
				}
				myGroups.append(grp.tagName());
				grp = grp.nextSiblingElement();
			}
		}
		qDebug() << msg;
	}
	if(!success)
	{
		newSolution();
	}
	return success;
}

QList<QDomElement> CatSolution::commands() const
{
	QList<QDomElement> cmds;
	foreach(const QString& grp,myGroups)
	{
		cmds.append(commands(grp));
	}
	return cmds;
}

QList<QDomElement> CatSolution::commands( const QString& grp ) const
{
	QList<QDomElement> cmds;
	if(hasGroup(grp))
	{
		QDomElement grpNode = myDoc.documentElement().firstChildElement(grp);
		QDomElement cmd = grpNode.firstChildElement();
		while(!cmd.isNull())
		{
			cmds.append(cmd);
			cmd = cmd.nextSiblingElement();
		}
	}
	return cmds;
}

void CatSolution::newSolution()
{
	myGroups.clear();
	myDoc.clear();
	QDomElement root = myDoc.createElement("Solution");
	myDoc.appendChild(root);
}

void CatSolution::createGroup( const QString& grpName )
{
	if(hasGroup(grpName)) {return;}
	QDomElement grp = myDoc.createElement(grpName);
	if(!grp.isNull())
	{
		QDomElement root = myDoc.documentElement();
		root.appendChild(grp);
		myGroups.append(grpName);
	}
}

void CatSolution::removeGroup( const QString& grpName )
{
	if(!hasGroup(grpName)) {return;}
	QDomElement grp = myDoc.documentElement().firstChildElement(grpName);
	myDoc.documentElement().removeChild(grp);
	myGroups.removeAll(grpName);
}

bool CatSolution::hasGroup( const QString& grp ) const
{
	return myGroups.contains(grp);
}

void CatSolution::appendCommand( const QDomElement& cmd, const QString& grp )
{
	if(!hasGroup(grp)) return;
	QDomElement grpNode = myDoc.documentElement().firstChildElement(grp);
	grpNode.appendChild(cmd);
}

void CatSolution::removeCommand( const QDomElement& cmd, const QString& grp )
{
	if(!hasGroup(grp)) {return;}

	QDomElement grpNode = myDoc.documentElement().firstChildElement(grp);
	grpNode.removeChild(cmd);
}

QStringList CatSolution::groups() const
{
	return myGroups;
}

void CatSolution::renameGroup( const QString& oldName,const QString& newName )
{
	QDomElement grpNode = myDoc.documentElement().firstChildElement(oldName);
	if(!grpNode.isNull())
	{
		grpNode.setTagName(newName);
		myGroups.replace(myGroups.indexOf(oldName),newName);
	}
}


