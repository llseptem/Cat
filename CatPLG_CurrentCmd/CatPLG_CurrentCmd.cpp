#include "CatPLG_CurrentCmd.h"
#include "CatCurrentDialog.h"
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"

CatPLG_CurrentCmd::CatPLG_CurrentCmd(QObject *parent)
{
	myDlg = new CatCurrentDialog();
}

CatPLG_CurrentCmd::~CatPLG_CurrentCmd()
{
	delete myDlg;
}

QString CatPLG_CurrentCmd::title() const
{
	return tr("电流测量命令");
}

QString CatPLG_CurrentCmd::description() const
{
	return tr("设置万用表测量模式为电流");
}

bool CatPLG_CurrentCmd::Configure(const QDomElement& elem)
{
	if(!elem.isNull())
	{
		myDlg->setACMode(elem.attribute("Mode") == "AC");
		myDlg->setRange(elem.attribute("Range").toInt());
	}
	return myDlg->exec() == QDialog::Accepted;
}

QUuid CatPLG_CurrentCmd::Identifier() const
{
	return QUuid("{67E6D6D2-3F91-42E7-B0D4-62C6EB8ED9FD}");
}

bool CatPLG_CurrentCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("Mode",myDlg->isAC() ? "AC" : "DC");
	cmd.setAttribute("Range",myDlg->cRange());
	return true;
}

bool CatPLG_CurrentCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();
//		ui->setInformation(tr("Config As %1 Current Mode").arg(elem.attribute("Mode")));
		if(elem.attribute("Mode") == "AC")
		{
			ptr->Measurement->MeasurementFunction =  Agilent34410MeasurementFunctionACCurrent;
			ptr->Current->ACCurrent->AutoRange = Agilent34410AutoRangeOn;
		}
		else
		{
			ptr->Measurement->MeasurementFunction = Agilent34410MeasurementFunctionDCCurrent;
			ptr->Current->DCCurrent->AutoRange = Agilent34410AutoRangeOn;
		}
		return true;
	}
	catch(_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()),true);
		return false;
	}
}

Q_EXPORT_PLUGIN(CatPLG_CurrentCmd)