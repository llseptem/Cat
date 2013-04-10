#ifndef CATPLG_CURRENTCMD_H
#define CATPLG_CURRENTCMD_H

#include "../Cat/CatActionPlugin.h"

class CatCurrentDialog;
class CatPLG_CurrentCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_CurrentCmd(QObject *parent = 0);
	~CatPLG_CurrentCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure();
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatCurrentDialog* myDlg;
};

#endif // CATPLG_CURRENTCMD_H
