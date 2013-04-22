#include "CatPLG_ScanCmd.h"
#include "CatScanDialog.h"
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"

CatPLG_ScanCmd::CatPLG_ScanCmd(QObject *parent)
{
	myDlg = new CatScanDialog();
}

CatPLG_ScanCmd::~CatPLG_ScanCmd()
{
	delete myDlg;
}

QString CatPLG_ScanCmd::title() const
{
	return tr("扫描端口命令");
}

QString CatPLG_ScanCmd::description() const
{
	return tr("设置扫描端口与等待时间");
}

bool CatPLG_ScanCmd::Configure(const QDomElement& elem)
{
	myDlg->Clear();
	if(!elem.isNull())
	{
		myDlg->setWaitTime(elem.attribute("WaitTime").toInt());
		myDlg->setPorts(elem.attribute("Ports"));
	}
	if(myDlg->exec() == QDialog::Accepted)
	{
		return (!myDlg->ports().isEmpty());
	}
	return false;
}

QUuid CatPLG_ScanCmd::Identifier() const
{
	return QUuid("{8E4EDB0F-38AE-4E7C-9B17-9E6E4D61ACBC}");
}

bool CatPLG_ScanCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("Ports",myDlg->ports());
	cmd.setAttribute("WaitTime",myDlg->waitTime());
	return true;
}

bool CatPLG_ScanCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		ui->setInformation(tr("Scan Ports: %1").arg(elem.attribute("Ports")));
		IAgilent34980A2Ptr ptr = CatDeviceManager::GetInstance().Get34980();
		ptr->Scan->ScanList = elem.attribute("Ports").toStdWString().c_str();
		ptr->System->IO->IO->WriteString("ROUT:CHAN:ADV:SOUR EXT");
		ptr->Measurement->Initiate();
		ptr->System->WaitForOperationComplete(elem.attribute("WaitTime").toInt());
		return true;
	}
	catch(_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
}

Q_EXPORT_PLUGIN(CatPLG_ScanCmd)
