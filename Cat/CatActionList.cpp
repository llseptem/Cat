#include "CatActionList.h"
#include "CatPluginManager.h"

CatActionList::CatActionList(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initialList();
}

CatActionList::~CatActionList()
{

}

void CatActionList::initialList()
{
	CatPluginManager* mgr = CatPluginManager::GetInstance();

	foreach(const QUuid& uid,mgr->plugins())
	{
		ui.actionList->addItem(mgr->pluginTitle(uid),uid.toString());
		myDescriptions.insert(uid,mgr->pluginDescription(uid));
	}

	connect(ui.actionList,SIGNAL(currentIndexChanged(int)),this,SLOT(onSelectionChange(int)));
	if(ui.actionList->count())
	{
		ui.actionList->setCurrentIndex(0);
		onSelectionChange(0);
	}
}

void CatActionList::setDescription( const QString& desc )
{
	ui.actionDescription->setText(tr("ÃèÊö£º\n%1").arg(desc));
}

void CatActionList::onSelectionChange(int idx)
{
	if(idx != -1)
	{
		QUuid uid(ui.actionList->itemData(idx).toString());
		setDescription(myDescriptions.value(uid,""));
	}
}

QUuid CatActionList::selectedCommand() const
{
	int idx = ui.actionList->currentIndex();
	if(idx != -1)
		return QUuid(ui.actionList->itemData(idx).toString());
	else
		return QUuid();
}
