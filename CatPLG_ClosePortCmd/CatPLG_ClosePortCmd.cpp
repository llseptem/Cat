#include "CatPLG_ClosePortCmd.h"
#include "catportselectdialog.h"
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"

CatPLG_ClosePortCmd::CatPLG_ClosePortCmd(QObject *parent)
{
	myDlg = new CatPortSelectDialog();
}

CatPLG_ClosePortCmd::~CatPLG_ClosePortCmd()
{
	delete myDlg;
}

QString CatPLG_ClosePortCmd::title() const
{
	return tr("打开关闭端口命令");
}

QString CatPLG_ClosePortCmd::description() const
{
	return tr("永久打开或关闭指定的一个或多个端口");
}

bool CatPLG_ClosePortCmd::Configure(const QDomElement& elem)
{
	myDlg->Clear();
	if(!elem.isNull())
	{
		myDlg->setOpenMode(elem.attribute("Operator")=="Open");
		myDlg->SetPorts(elem.attribute("Ports"));
	}
	myDlg->exec();
	return !myDlg->Ports().isEmpty();
}

QUuid CatPLG_ClosePortCmd::Identifier() const
{
	return QUuid("{4129641B-D4C6-46F7-8D1C-95677D40E7A9}");
}

bool CatPLG_ClosePortCmd::CreateAction( QDomElement& cmd )
{
	const QString& ports = myDlg->Ports();
	cmd.setAttribute("Operator", myDlg->isOpen() ? "Open" : "Close");
	cmd.setAttribute("Ports",myDlg->Ports());
	return true;
}

bool CatPLG_ClosePortCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		IAgilent34980A2Ptr ptr = CatDeviceManager::GetInstance().Get34980();
//		ui->setInformation(QString("%1 Port:%2").arg(elem.attribute("Operator")).arg(elem.attribute("Ports")));
		if(elem.attribute("Operator") == "Open")
		{
			ptr->Route->Close(elem.attribute("Ports").toStdString().c_str());
		}
		else
		{
			ptr->Route->Open(elem.attribute("Ports").toStdString().c_str());
		}
	}
	catch (_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
	return true;
}

Q_EXPORT_PLUGIN(CatPLG_ClosePortCmd)