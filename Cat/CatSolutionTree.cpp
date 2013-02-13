#include "CatSolutionTree.h"
#include "CatPluginManager.h"
#include <QDomDocument>
#include <QStringList>
#include <QTreeWidgetItem>
#include <QHeaderView>

CatSolutionTree::CatSolutionTree(QWidget *parent)
	: QTreeWidget(parent)
{
	QStringList labels;
	labels << tr("ÃüÁî") << tr("ÃèÊö");
	header()->setResizeMode(QHeaderView::Stretch);
	setHeaderLabels(labels);
}

CatSolutionTree::~CatSolutionTree()
{

}

void CatSolutionTree::addCommand( const QDomElement& cmd )
{
	CatPluginManager* mgr = CatPluginManager::GetInstance();
	const QUuid& uid = QUuid(cmd.tagName());

	QTreeWidgetItem* cmdItem = createItem(mgr->pluginTitle(uid),mgr->pluginDescription(uid));
	myCmdMap.insert(cmdItem,cmd);
	const QDomNamedNodeMap& attrs = cmd.attributes();
	for(int i=0; i<attrs.count(); ++i)
	{
		createItem(attrs.item(i).nodeName(),attrs.item(i).nodeValue(),cmdItem);
	}
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

void CatSolutionTree::removeAllCommand()
{
	myCmdMap.clear();
	clear();
}

QDomElement CatSolutionTree::currentCommand()
{
	QTreeWidgetItem* item = currentItem();
	while(item)
	{
		if(myCmdMap.contains(item))
		{
			return myCmdMap.value(item);
		}
	}
	return QDomElement();
}
