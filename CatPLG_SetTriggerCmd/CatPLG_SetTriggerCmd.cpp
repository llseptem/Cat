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
		myDlg->setSampleInterval(elem.attribute("SampleInterval").toDouble());
		myDlg->setSampleCount(elem.attribute("SampleCount").toInt());
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
	cmd.setAttribute("SampleCount",myDlg->sampleCount());
	cmd.setAttribute("SampleInterval",myDlg->sampleInterval());
	return true;
}

bool CatPLG_SetTriggerCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();
		if(elem.attribute("TriggerSource") == "Ext")
		{
// 			ui->setInformation(
// 				tr("Config Trigger As %1 Mode,%2 times")
// 				.arg(elem.attribute("TriggerSource"))
// 				.arg(elem.attribute("TriggerTimes").toInt()));

			ptr->Trigger->TriggerSource = Agilent34410TriggerSourceExternal;
			ptr->Trigger->TriggerCount = elem.attribute("TriggerTimes").toInt();
			ptr->Trigger->SampleCount = 1;
			ptr->Measurement->Initiate();
		}
		else
		{
// 			ui->setInformation(
// 				tr("Config Trigger As %1 Mode,%2 Counts,%3 Interval")
// 				.arg(elem.attribute("TriggerSource"))
// 				.arg(elem.attribute("SampleCount").toInt())
// 				.arg(elem.attribute("SampleInterval").toDouble()));

			ptr->Trigger->TriggerSource = Agilent34410TriggerSourceImmediate;
			ptr->Trigger->TriggerCount = 1;
			ptr->Trigger->SampleCount = elem.attribute("SampleCount").toInt();
			ptr->Trigger->SampleInterval = elem.attribute("SampleInterval").toDouble();
			ptr->Trigger->SampleSource = Agilent34410SampleSourceTimer;
			ptr->DataFormat->DataFormat = Agilent34410DataFormatReal64;
			ptr->Measurement->Initiate();
		}
	}
	catch(_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()),true);
		return false;
	}
	return true;
}

Q_EXPORT_PLUGIN(CatPLG_SetTriggerCmd)
