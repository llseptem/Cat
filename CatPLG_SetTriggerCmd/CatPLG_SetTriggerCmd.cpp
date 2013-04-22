#include "CatPLG_SetTriggerCmd.h"
#include "CatTriggerDialog.h"
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"

CatPLG_SetTriggerCmd::CatPLG_SetTriggerCmd(QObject *parent)
{
	myDlg = new CatTriggerDialog();
}

CatPLG_SetTriggerCmd::~CatPLG_SetTriggerCmd()
{
	delete myDlg;
}

QString CatPLG_SetTriggerCmd::title() const
{
	return tr("触发命令");
}

QString CatPLG_SetTriggerCmd::description() const
{
	return tr("设置万能表的触发模式");
}

bool CatPLG_SetTriggerCmd::Configure(const QDomElement& elem)
{
	if(!elem.isNull())
	{
		myDlg->setExtMode(elem.attribute("TriggerSource") == "Ext");
		myDlg->setTriggerTimes(elem.attribute("TriggerTimes").toInt());
	}
	return myDlg->exec() == QDialog::Accepted;
}

QUuid CatPLG_SetTriggerCmd::Identifier() const
{
	return QUuid("{CE0DF1B2-E670-4204-9C0E-21AC0486CE54}");
}

bool CatPLG_SetTriggerCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("TriggerSource",myDlg->isExtMode() ? "Ext" : "Immediate");
	cmd.setAttribute("TriggerTimes",myDlg->triggerTimes());
	return true;
}

bool CatPLG_SetTriggerCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		ui->setInformation(
			tr("Config Trigger As %1 Mode,%2 times")
			.arg(elem.attribute("TriggerSource"))
			.arg(elem.attribute("TriggerTimes").toInt()));
		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();
		if(elem.attribute("TriggerSource") == "Ext")
		{
			ptr->Trigger->TriggerSource = Agilent34410TriggerSourceExternal;
			ptr->Trigger->TriggerCount = elem.attribute("TriggerTimes").toInt();
			ptr->Measurement->Initiate();
		}
		else
		{
			ptr->Trigger->TriggerSource = Agilent34410TriggerSourceImmediate;
		}
	}
	catch(_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
	return true;
}

Q_EXPORT_PLUGIN(CatPLG_SetTriggerCmd)
