#include "CatPLG_CheckCmd.h"
#include "CatCheckDialog.h"
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"
#include <atlsafe.h>

CatPLG_CheckCmd::CatPLG_CheckCmd(QObject *parent)
{
	myDlg = new CatCheckDialog();
}

CatPLG_CheckCmd::~CatPLG_CheckCmd()
{
	delete myDlg;
}

QString CatPLG_CheckCmd::title() const
{
	return tr("检查命令");
}

QString CatPLG_CheckCmd::description() const
{
	return tr("读取测量结果并比对");
}

bool CatPLG_CheckCmd::Configure()
{
	myDlg->Clear();
	if(myDlg->exec() == QDialog::Accepted)
	{
		return !myDlg->ranges().isEmpty();
	}
	return false;
}

QUuid CatPLG_CheckCmd::Identifier() const
{
	return QUuid("{794A5A57-01E9-42AF-8A23-16291AD6E3AE}");
}

bool CatPLG_CheckCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("Result",myDlg->resultType());
	cmd.setAttribute("Ranges",myDlg->ranges());
	return true;
}

bool CatPLG_CheckCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();
		SAFEARRAY* psaData1 = ptr->Measurement->Fetch();
		CComSafeArray<double> saData1;
		saData1.Attach(psaData1);
		const QStringList& rgs = elem.attribute("Ranges").split(";");
		for(int i=0; i<saData1.GetCount(); ++i)
		{
			double val = saData1.GetAt(i);
			QString disp = tr("%1:%2 %3:(%4,%5) %6");
			disp = disp.arg(elem.attribute("Result"));
			disp = disp.arg(val);
			if(i<rgs.size())
			{
				const QStringList& rg = rgs[i].split(",");
				if(rg.size()==3)
				{
					int lower = rg[1].toInt();
					int upper = rg[2].toInt();
					disp = disp.arg(rg[0]).arg(lower).arg(upper);
					if(rg[0]=="Lower")
					{
						ui->setInformation(disp.arg(val > lower ? "Pass" : "Failed"));
					}
					else if(rg[0]=="Upper")
					{
						ui->setInformation(disp.arg(val < upper ? "Pass" : "Failed"));
					}
					else
					{
						ui->setInformation(disp.arg((val > lower && val < upper) ? "Pass" : "Failed"));
					}
				}
			}
		}
		return true;
	}
	catch (_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
}

Q_EXPORT_PLUGIN(CatPLG_CheckCmd)