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
	return tr("�����������");
}

QString CatPLG_ResistenceCmd::description() const
{
	return tr("�������ñ�Ϊ�������ģʽ");
}

bool CatPLG_ResistenceCmd::Configure()
{
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
		if(elem.attribute("Mode") == "FourWire")
		{
			ptr->Measurement->MeasurementFunction =  Agilent34410MeasurementFunctionFResistance;
			ptr->Resistance->Range = elem.attribute("Range").toInt();
		}
		else
		{
			ptr->Measurement->MeasurementFunction = Agilent34410MeasurementFunctionResistance;
			ptr->FResistance->Range = elem.attribute("Range").toInt();
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