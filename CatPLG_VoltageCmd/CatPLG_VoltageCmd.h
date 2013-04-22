#ifndef CATPLG_VOLTAGECMD_H
#define CATPLG_VOLTAGECMD_H

#include "../Cat/CatActionPlugin.h"

class CatVoltageDialog;
class CatPLG_VoltageCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_VoltageCmd(QObject *parent = 0);
	~CatPLG_VoltageCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure(const QDomElement& elem);
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatVoltageDialog* myDlg;
};

#endif // CATPLG_VOLTAGECMD_H
