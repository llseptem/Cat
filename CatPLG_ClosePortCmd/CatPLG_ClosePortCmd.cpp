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
	return tr("关闭端口命令");
}

QString CatPLG_ClosePortCmd::description() const
{
	return tr("关闭指定的一个或多个端口");
}

bool CatPLG_ClosePortCmd::Configure()
{
	myDlg->exec();
	return !myDlg->Ports().isEmpty();
}

QUuid CatPLG_ClosePortCmd::Identifier() const
{
	return QUuid("{4129641B-D4C6-46F7-8D1C-95677D40E7A9}");
}

bool CatPLG_ClosePortCmd::CreateAction( QDomElement& cmd )
{
	const QStringList& ports = myDlg->Ports();
	for(int i=0; i<ports.size(); ++i)
	{
		cmd.setAttribute(QString("Port%1").arg(i),ports[i]);
	}
	return true;
}

bool CatPLG_ClosePortCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	const QDomNamedNodeMap& ports = elem.attributes();
	IAgilent34980A2Ptr ptr = CatDeviceManager::GetInstance().Get34980();
	for(int i=0; i<ports.size(); ++i)
	{
		QDomNode nd = ports.namedItem(QString("Port%1").arg(i));
		if(nd.isNull())
			break;
		else
		{
			try
			{
				ui->setInformation(QString("Close Port:%1").arg(nd.nodeValue()));
				ptr->Route->Close(nd.nodeValue().toStdString().c_str());
			}
			catch (_com_error& e)
			{
				ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
				return false;
			}
		}
	}
	return true;
}

Q_EXPORT_PLUGIN(CatPLG_ClosePortCmd)