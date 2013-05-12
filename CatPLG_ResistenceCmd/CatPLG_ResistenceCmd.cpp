#include "CatPLG_ResistenceCmd.h"
#include "CatResistenceDialog.h"
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"

CatPLG_ResistenceCmd::CatPLG_ResistenceCmd(QObject *parent)
{
	myDlg = new CatResistenceDialog();
}

CatPLG_ResistenceCmd::~CatPLG_ResistenceCmd()
{
	delete myDlg;
}

QString CatPLG_ResistenceCmd::title() const
{
	return tr("电阻测量命令");
}

QString CatPLG_ResistenceCmd::description() const
{
	return tr("设置外用表为电阻测量模式");
}

bool CatPLG_ResistenceCmd::Configure(const QDomElement& elem)
{
	if(!elem.isNull())
	{
		myDlg->setFourWireMode(elem.attribute("Mode") == "FourWire");
		myDlg->setRange(elem.attribute("Range").toInt());
	}
	return myDlg->exec() == QDialog::Accepted;
}

QUuid CatPLG_ResistenceCmd::Identifier() const
{
	return QUuid("{9A4989D8-31B8-4EF9-BD2C-84DD3CD25499}");
}

bool CatPLG_ResistenceCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("Mode",myDlg->isFourWire() ? "FourWire" : "TwoWire");
	cmd.setAttribute("Range",myDlg->rRange());
	return true;
}

bool CatPLG_ResistenceCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();
//		ui->setInformation(tr("Config As %1 Resistance Mode").arg(elem.attribute("Mode")));
		if(elem.attribute("Mode") == "FourWire")
		{
			ptr->Measurement->MeasurementFunction =  Agilent34410MeasurementFunctionFResistance;
			ptr->Resistance->AutoRange = Agilent34410AutoRangeOn;
		}
		else
		{
			ptr->Measurement->MeasurementFunction = Agilent34410MeasurementFunctionResistance;
			ptr->FResistance->AutoRange = Agilent34410AutoRangeOn;
		}
		return true;
	}
	catch(_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
}
Q_EXPORT_PLUGIN(CatPLG_ResistenceCmd)