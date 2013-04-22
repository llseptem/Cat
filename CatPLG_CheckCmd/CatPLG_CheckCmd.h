#ifndef CATPLG_CHECKCMD_H
#define CATPLG_CHECKCMD_H

#include "../Cat/CatActionPlugin.h"

class CatCheckDialog;
class CatPLG_CheckCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_CheckCmd(QObject *parent = 0);
	~CatPLG_CheckCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure(const QDomElement& elem);
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatCheckDialog* myDlg;
};

#endif // CATPLG_CHECKCMD_H
