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
	return tr("��������");
}

QString CatPLG_SetTriggerCmd::description() const
{
	return tr("�������ܱ��Ĵ���ģʽ");
}

bool CatPLG_SetTriggerCmd::Configure()
{
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
		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();
		ptr->Trigger->TriggerCount = elem.attribute("TriggerTimes").toInt();
		if(elem.attribute("TriggerSource") == "Ext")
		{
			ptr->Trigger->TriggerSource = Agilent34410TriggerSourceExternal;
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