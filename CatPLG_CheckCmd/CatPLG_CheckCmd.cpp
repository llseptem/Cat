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
	return myDlg->exec() == QDialog::Accepted;
}

QUuid CatPLG_CheckCmd::Identifier() const
{
	return QUuid("{794A5A57-01E9-42AF-8A23-16291AD6E3AE}");
}

bool CatPLG_CheckCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("Result",myDlg->resultType());
	cmd.setAttribute("Lower",myDlg->lowerBound());
	cmd.setAttribute("Upper",myDlg->upperBound());
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
		double val = saData1.GetAt(0);
		int lower = elem.attribute("Lower").toInt();
		int upper = elem.attribute("Upper").toInt();
		QString disp = tr("%1:%2 Range:(%3,%4) %5");
		ui->setInformation(disp.arg(elem.attribute("Result")).arg(val).arg(lower).arg(upper).arg((val>lower && val<upper) ? "Pass" : "Failed"));
		return true;
	}
	catch (_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
}

Q_EXPORT_PLUGIN(CatPLG_CheckCmd)