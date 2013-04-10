#ifndef CATPLG_SCANCMD_H
#define CATPLG_SCANCMD_H

#include "../Cat/CatActionPlugin.h"

class CatScanDialog;
class CatPLG_ScanCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_ScanCmd(QObject* parent = 0);
	~CatPLG_ScanCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure();
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatScanDialog* myDlg;
};

#endif // CATPLG_SCANCMD_H
