#include "CatSolutionTree.h"
#include "CatPluginManager.h"
#include "CatSolution.h"
#include "../CatRunUI/CatRunUI.h"
#include "../CatDeviceManager/CatDeviceManager.h"
#include <QDomDocument>
#include <QStringList>
#include <QTreeWidgetItem>
#include <QHeaderView>
#include <QMessageBox>

CatSolutionTree::CatSolutionTree(QWidget *parent)
	: QTreeWidget(parent)
{
	QStringList labels;
	labels << tr("命令") << tr("描述");
	header()->setResizeMode(QHeaderView::Stretch);
	setHeaderLabels(labels);
	mySolution = new CatSolution(this);
	connect(this,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,
		SLOT(onCurrentChanged()));
	myRunUI = new CatRunUI(this);
}

CatSolutionTree::~CatSolutionTree()
{

}

QTreeWidgetItem* CatSolutionTree::addCommand( const QDomElement& cmd, QTreeWidgetItem* grp )
{
	CatPluginManager* mgr = CatPluginManager::GetInstance();
	const QUuid& uid = QUuid(mySolution->commandID(cmd));

	QTreeWidgetItem* cmdItem = createItem(mgr->pluginTitle(uid),mgr->pluginDescription(uid),
		grp);
	myCmdMap.insert(cmdItem,cmd);
	const QDomNamedNodeMap& attrs = cmd.attributes();
	for(int i=0; i<attrs.count(); ++i)
	{
		createItem(attrs.item(i).nodeName(),attrs.item(i).nodeValue(),cmdItem);
	}
	return cmdItem;
}

QTreeWidgetItem* CatSolutionTree::addGroup( const QString& grp )
{
	QTreeWidgetItem* grpItm = createItem("Group",grp);
	myGroups.insert(grpItm,grp);
	return grpItm;
}

void CatSolutionTree::createGroup(const QString& grp)
{
	if(mySolution->hasGroup(grp))
	{
		QMessageBox::information(this,tr("无法添加新组"),
			tr("已经存在名为%1的组").arg(grp));
		return;
	}
	mySolution->createGroup(grp);
	addGroup(grp);
	setWindowModified(true);
}

void CatSolutionTree::createCommand(const QUuid& uid)
{
	if(QTreeWidgetItem* grp = currentGroupItem())
	{
		CatPluginManager* mgr = CatPluginManager::GetInstance();
		if(mgr->configurePlugin(uid))
		{
			QDomElement cmd = mySolution->createCommand(uid);
			if(mgr->createAction(uid,cmd))
			{
				mySolution->appendCommand(cmd,myGroups.value(grp));
				addCommand(cmd,grp);
				setWindowModified(true);
			}
		}
	}
}

QTreeWidgetItem* CatSolutionTree::createItem( const QString& tt,const QString& desc, 
	QTreeWidgetItem* parentItem /*= 0*/ )
{
	if(!parentItem)
		parentItem = invisibleRootItem();

	QTreeWidgetItem* item = new QTreeWidgetItem(parentItem);
	item->setText(0,tt);
	item->setText(1,desc);
	return item;
}

QTreeWidgetItem* CatSolutionTree::currentGroupItem() const
{
	QTreeWidgetItem* itm = currentItem();
	while(itm)
	{
		if(myGroups.contains(itm))
			return itm;
		itm = itm->parent();
	}
	return NULL;
}

QTreeWidgetItem* CatSolutionTree::currentCommandItem() const
{
	QTreeWidgetItem* itm = currentItem();
	while(itm)
	{
		if(myCmdMap.contains(itm))
			return itm;
		itm = itm->parent();
	}
	return NULL;
}

void CatSolutionTree::removeCurrent()
{
	if(QTreeWidgetItem* grp = currentGroupItem())
	{
		if(QTreeWidgetItem* cmd = currentCommandItem())
		{
			mySolution->removeCommand(myCmdMap.value(cmd),
				myGroups.value(grp));
			removeCommand(cmd,grp);
			setWindowModified(true);
		}
		else
		{
			if(QMessageBox::question(this,tr("确认删除组"),
				tr("组%1将被完全删除，确认吗？").arg(myGroups.value(grp))
				,QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
			{
				mySolution->removeGroup(myGroups.value(grp));
				removeGroup(grp);
				setWindowModified(true);
			}
		}
	}
}

void CatSolutionTree::removeGroup( QTreeWidgetItem* grp )
{
	myGroups.remove(grp);
	invisibleRootItem()->removeChild(grp);
}

void CatSolutionTree::removeCommand( QTreeWidgetItem* cmd,QTreeWidgetItem* grp )
{
	myCmdMap.remove(cmd);
	grp->removeChild(cmd);
}

void CatSolutionTree::clearAll()
{
	myCmdMap.clear();
	myGroups.clear();
	clear();
}

void CatSolutionTree::save( const QString& fl )
{
	if(mySolution->writeTo(fl))
	{
		setWindowModified(false);
	}
}

void CatSolutionTree::read( const QString& fl )
{
	newDoc();
	if(mySolution->readFrom(fl))
	{
		foreach(const QString& grp,mySolution->groups())
		{
			QTreeWidgetItem* grpItm = addGroup(grp);
			foreach(const QDomElement& cmd,mySolution->commands(grp))
			{
				addCommand(cmd,grpItm);
			}
		}
	}
}

void CatSolutionTree::newDoc()
{
	clearAll();
	mySolution->newSolution();
}

void CatSolutionTree::onCurrentChanged()
{
	bool canAdd = currentGroupItem() != NULL;
	emit commandCanBeAdded(canAdd);
	emit currentCanBeDeleted(canAdd);
}

void CatSolutionTree::run()
{
	const QList<QDomElement>& cmds = mySolution->commands();
	if(cmds.empty()) return;

	CatPluginManager* mgr = CatPluginManager::GetInstance();
	myRunUI->show();
	myRunUI->raise();
	myRunUI->activateWindow();
	foreach(const QDomElement& cmd,cmds)
	{
		if(!mgr->runAction(mySolution->commandID(cmd),cmd,myRunUI))
			break;
		if(myRunUI->wait(1))
			break;
	}
}
