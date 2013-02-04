#include "CatSolutionTree.h"
#include "CatPluginManager.h"
#include <QDomDocument>
#include <QStringList>
#include <QTreeWidgetItem>
#include <QHeaderView>

CatSolutionTree::CatSolutionTree(QWidget *parent)
	: QTreeWidget(parent),myDoc("MySolution")
{
	QStringList labels;
	labels << tr("ÃüÁî") << tr("ÃèÊö");
	header()->setResizeMode(QHeaderView::Stretch);
	setHeaderLabels(labels);

	myRoot = myDoc.createElement("CatSolution");
	myDoc.appendChild(myRoot);
}

CatSolutionTree::~CatSolutionTree()
{

}

void CatSolutionTree::addCommand( const QUuid& uid )
{
	CatPluginManager* mgr = CatPluginManager::GetInstance();
	if(mgr->configurePlugin(uid))
	{
		QDomElement cmd = myDoc.createElement(uid.toString());
		mgr->createAction(uid,cmd);
		myRoot.appendChild(cmd);

		QTreeWidgetItem* cmdItem = createItem(mgr->pluginTitle(uid),mgr->pluginDescription(uid));
		myCmdMap.insert(cmdItem,cmd);
		const QDomNamedNodeMap& attrs = cmd.attributes();
		for(int i=0; i<attrs.count(); ++i)
		{
			createItem(attrs.item(i).nodeName(),attrs.item(i).nodeValue(),cmdItem);
		}
	}
}

QTreeWidgetItem* CatSolutionTree::createItem( const QDomElement& cmd,QTreeWidgetItem* parentItem /*= 0*/ )
{
	CatPluginManager* mgr = CatPluginManager::GetInstance();
	QTreeWidgetItem* item = 0;
	if(parentItem)
	{
		item = new QTreeWidgetItem(parentItem);
	}
	else
	{
		item = new QTreeWidgetItem(this);
	}
	myCmdMap.insert(item,cmd);

	QUuid uid(cmd.tagName());
	item->setText(0,mgr->pluginTitle(uid));
	item->setText(1,mgr->pluginDescription(uid));

	const QDomNamedNodeMap& attrs = cmd.attributes();
	for(int i=0; i<attrs.count(); ++i)
	{
		QTreeWidgetItem* attrItm  = new QTreeWidgetItem(item);
		attrItm->setText(0,attrs.item(i).nodeName());
		attrItm->setText(1,attrs.item(i).nodeValue());
	}

	return item;
}

QTreeWidgetItem* CatSolutionTree::createItem( const QString& tt,const QString& desc, QTreeWidgetItem* parentItem /*= 0*/ )
{
	QTreeWidgetItem* item = 0;
	if(parentItem)
	{
		item = new QTreeWidgetItem(parentItem);
	}
	else
	{
		item = new QTreeWidgetItem(this);
	}

	item->setText(0,tt);
	item->setText(1,desc);
	return item;
}

void CatSolutionTree::removeCurrentCommand()
{
	QTreeWidgetItem* item = currentItem();
	while(item)
	{
		if(myCmdMap.contains(item))
		{
			invisibleRootItem()->removeChild(item);
			myCmdMap.remove(item);
			break;
		}
		else
		{
			item = item->parent();
		}
	}
}
