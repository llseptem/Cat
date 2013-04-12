#include "CatPLG_VoltageCmd.h"
#include "CatVoltageDialog.h"
#include "../CatRunUI/CatRunUI.h"
#include "../CatDeviceManager/CatDeviceManager.h"

CatPLG_VoltageCmd::CatPLG_VoltageCmd(QObject *parent)
{
	myDlg = new CatVoltageDialog();
}

CatPLG_VoltageCmd::~CatPLG_VoltageCmd()
{
	delete myDlg;
}

QString CatPLG_VoltageCmd::title() const
{
	return tr("电压测量命令");
}

QString CatPLG_VoltageCmd::description() const
{
	return tr("设置万用表测量模式为电压");
}

bool CatPLG_VoltageCmd::Configure()
{
	return myDlg->exec() == QDialog::Accepted;
}

QUuid CatPLG_VoltageCmd::Identifier() const
{
	return QUuid("{41A8ECF8-C30F-4E4A-98E0-1C98308B1AFF}");
}

bool CatPLG_VoltageCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("Mode",myDlg->isAC() ? "AC" : "DC");
	cmd.setAttribute("Range",myDlg->vRange());
	return true;
}

bool CatPLG_VoltageCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();
		if(elem.attribute("Mode") == "AC")
		{
			ptr->Measurement->MeasurementFunction =  Agilent34410MeasurementFunctionACVoltage;
			ptr->Voltage->ACVoltage->AutoRange = Agilent34410AutoRangeOn;
		}
		else
		{
			ptr->Measurement->MeasurementFunction = Agilent34410MeasurementFunctionDCVoltage;
			ptr->Voltage->DCVoltage->AutoRange = Agilent34410AutoRangeOn;
		}
		return true;
	}
	catch(_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
}

Q_EXPORT_PLUGIN(CatPLG_VoltageCmd)
