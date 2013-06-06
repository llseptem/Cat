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

bool CatPLG_CheckCmd::Configure(const QDomElement& elem)
{
	myDlg->Clear();
	if(!elem.isNull())
	{
		myDlg->setResultType(elem.attribute("Result"));
		myDlg->setRanges(elem.attribute("Tags"),elem.attribute("Ranges"));
	}
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
	cmd.setAttribute("Tags",myDlg->tags());
	cmd.setAttribute("Ranges",myDlg->ranges());
	return true;
}

bool CatPLG_CheckCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		ui->digitMode();
		ui->clearDigits();

		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();
		SAFEARRAY* psaData1 = ptr->Measurement->Fetch();
		CComSafeArray<double> saData1;
		saData1.Attach(psaData1);
		const QStringList& rgs = elem.attribute("Ranges").split(";");
		const QStringList& tgs = elem.attribute("Tags").split(";");
		bool allPass = true;
		for(int i=0; i<saData1.GetCount(); ++i)
		{
			QString tag = i<tgs.size() ? tgs.at(i) : tr("Result %1").arg(i);
			double val = saData1.GetAt(i);
			ui->displayDigit(tag,val);
			QString disp = tr("%1:%2 %3:(%4,%5) %6");
			disp = disp.arg(tag);//elem.attribute("Result"));
			disp = disp.arg(val);
			if(i<rgs.size())
			{
				const QStringList& rg = rgs[i].split(",");
				if(rg.size()==3)
				{
					int lower = rg[1].toInt();
					int upper = rg[2].toInt();
					disp = disp.arg(rg[0]).arg(lower).arg(upper);
					if(rg[0]=="Lower" && val < lower)
					{
						ui->setInformation(disp.arg("Failed"),true);
						allPass = false;
					}
					else if(rg[0]=="Upper" && val > upper)
					{
						ui->setInformation(disp.arg("Failed"),true);
						allPass = false;
					}
					else if(rg[0] == "Range" && (val < lower || val > upper))
					{
						ui->setInformation(disp.arg("Failed"),true);
						allPass = false;
					}
				}
			}
		}
		if (allPass)
		{
			ui->setInformation("Pass");
		}
		return true;
	}
	catch (_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()),true);
		return false;
	}
}

Q_EXPORT_PLUGIN(CatPLG_CheckCmd)