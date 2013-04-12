#include "CatPLG_InitializeCmd.h"
#include "CatInitializeDialog.h"
#include "../CatDeviceManager/CatDeviceManager.h"

CatPLG_InitializeCmd::CatPLG_InitializeCmd(QObject *parent)
{
	myInitDlg = new CatInitializeDialog();
}

CatPLG_InitializeCmd::~CatPLG_InitializeCmd()
{
	delete myInitDlg;
}

QString CatPLG_InitializeCmd::title() const
{
	return tr("设备初始化命令");
}

QString CatPLG_InitializeCmd::description() const
{
	return tr("初始化主机与万用表");
}

QUuid CatPLG_InitializeCmd::Identifier() const
{
	return QUuid("{25C68539-94C4-4724-9491-E358C1298C1A}");
}

bool CatPLG_InitializeCmd::Configure()
{
	myInitDlg->exec();
	return (!myInitDlg->Adr34980().isEmpty()) && (!myInitDlg->Adr34411().isEmpty());
}

bool CatPLG_InitializeCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("Adr34980",myInitDlg->Adr34980());
	cmd.setAttribute("Adr34411",myInitDlg->Adr34411());
	return true;
}

static const char* strStandardInitOptions = "Cache=true, InterchangeCheck=false, QueryInstrStatus=true, RangeCheck=true, RecordCoercions=false, Simulate=false";
bool CatPLG_InitializeCmd::RunAction( const QDomElement& elem,CatRunUI* ui )
{
	ui->setInformation(tr("Now Initialize Devices"));
	try
	{
		IAgilent34980A2Ptr ptr34980 = CatDeviceManager::GetInstance().Get34980();
		ptr34980->Initialize(elem.attribute("Adr34980").toStdString().c_str(), VARIANT_FALSE, VARIANT_TRUE, strStandardInitOptions);
		ptr34980->Status->Clear();

		IAgilent34410Ptr ptr34411 = CatDeviceManager::GetInstance().Get34411();
		ptr34411->Initialize(elem.attribute("Adr34411").toStdString().c_str(), VARIANT_FALSE, VARIANT_TRUE, strStandardInitOptions);
		ptr34411->Status->Clear();

		return true;
	}
	catch(_com_error& e)
	{
		ui->setInformation(QString::fromWCharArray(e.ErrorMessage()) + ":\n" + QString::fromWCharArray(e.Description()));
		return false;
	}
}

Q_EXPORT_PLUGIN(CatPLG_InitializeCmd)