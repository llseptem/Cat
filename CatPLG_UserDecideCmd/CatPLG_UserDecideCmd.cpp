#include "CatPLG_UserDecideCmd.h"
#include "CatPresentation.h"

CatPLG_UserDecideCmd::CatPLG_UserDecideCmd(QObject *parent)
{
	myDlg = new CatPresentation();
}

CatPLG_UserDecideCmd::~CatPLG_UserDecideCmd()
{
	delete myDlg;
}

bool CatPLG_UserDecideCmd::Configure(const QDomElement& elem)
{
	if(!elem.isNull())
	{
		myDlg->SetImagePath(elem.attribute("ImagePath"));
		myDlg->SetDescription(elem.attribute("Description"));
		myDlg->setBreakOnFalse(elem.attribute("BreakOnFalse").toInt());
	}
	return myDlg->exec() == QDialog::Accepted;
}

QUuid CatPLG_UserDecideCmd::Identifier() const
{
	return QUuid("{251B757F-F5EA-48F5-B0EF-384A6FE666A4}");
}

bool CatPLG_UserDecideCmd::CreateAction( QDomElement& cmd )
{
	cmd.setAttribute("ImagePath",myDlg->imagePath());
	cmd.setAttribute("Description",myDlg->description());
	cmd.setAttribute("BreakOnFalse",myDlg->breakOnFalse());
	return true;
}

bool CatPLG_UserDecideCmd::RunAction( const QDomElement& elem, CatRunUI* ui )
{
	bool bof = elem.attribute("BreakOnFalse").toInt();
	ui->setImage(elem.attribute("ImagePath"));
	ui->setMessage(elem.attribute("Description"));
	bool rst =  ui->waitForDecition();
	if(!bof)
	{ui->setInformation(elem.attribute("Description") + "?" + (rst ? "Yes" : "No"), !rst);}
	ui->clearMessage();
	return bof ? rst : true;
}

QString CatPLG_UserDecideCmd::title() const
{
	return tr("用户判别命令");
}

QString CatPLG_UserDecideCmd::description() const
{
	return tr("由用户判别执行成功与否的被动式命令");
}

Q_EXPORT_PLUGIN(CatPLG_UserDecideCmd)