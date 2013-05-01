#include "CatPLG_CurveCheckCmd.h"
#include "CatCurveDialog.h"
#include "../CatDeviceManager/CatDeviceManager.h"
#include "../CatRunUI/CatRunUI.h"
#include <atlsafe.h>

CatPLG_CurveCheckCmd::CatPLG_CurveCheckCmd(QObject *parent)
{
	myDlg = new CatCurveDialog();
}

CatPLG_CurveCheckCmd::~CatPLG_CurveCheckCmd()
{
	delete myDlg;
}

QString CatPLG_CurveCheckCmd::title() const
{
	return tr("连续读取命令");
}

QString CatPLG_CurveCheckCmd::description() const
{
	return tr("读取连续扫描的所有点，并绘制曲线");
}

bool CatPLG_CurveCheckCmd::Configure( const QDomElement& elem )
{
	if(!elem.isNull())
	{
		myDlg->setType(elem.attribute("Type"));
	}
	return myDlg->exec() == QDialog::Accepted;
}

QUuid CatPLG_CurveCheckCmd::Identifier() const
{
	return QUuid("{0F92C0DA-5287-4461-8AAE-ADA0FE3DFE83}");
}

bool CatPLG_CurveCheckCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("Type",myDlg->type());
	return true;
}

bool CatPLG_CurveCheckCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	try
	{
		ui->curveMode();
		ui->setInformation(tr("Now drawing the %1 Curve").arg(elem.attribute("Type")));

		IAgilent34410Ptr ptr = CatDeviceManager::GetInstance().Get34411();

		long count = ptr->Trigger->SampleCount;
		double interval = ptr->Trigger->SampleInterval;
		int totalRead = 0;
		int dataPts = 0;
		SAFEARRAY* psaData;
		CComSafeArray<double> saData;
		QPolygonF pts;
			
		while (totalRead < count)
		{
			if(dataPts = ptr->Measurement->GetReadingCount(Agilent34410MemoryTypeReadingMemory))
			{
				psaData = ptr->Measurement->RemoveReadings(dataPts);

				if(totalRead)
				{
					saData.Add(psaData);
				}
				else
				{
					saData.Attach(psaData);
				}

				
				QString info("Read:");
				if(totalRead < saData.GetCount())
				{
					info.append(tr("%1").arg(saData.GetAt(totalRead)));
					pts << QPointF(static_cast<double>(totalRead)*interval, saData.GetAt(totalRead));
				}
				for(int i = totalRead+1; i < saData.GetCount(); ++i)
				{
					info.append(tr(",%1").arg(saData.GetAt(i)));
					pts << QPointF(static_cast<double>(i)*interval, saData.GetAt(i));
				}
				ui->setInformation(info);
				ui->drawCurve(elem.attribute("Type"),pts);

				totalRead += dataPts;
				if(ui->wait(1))
				{
					return false;
				}
			}
		}
		ui->setInformation(tr("波形正常吗？"));
		return ui->waitForDecition();
	}
	catch(_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
}

Q_EXPORT_PLUGIN(CatPLG_CurveCheckCmd)