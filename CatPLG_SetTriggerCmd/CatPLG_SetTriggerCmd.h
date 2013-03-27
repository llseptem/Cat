#ifndef CATPLG_SETTRIGGERCMD_H
#define CATPLG_SETTRIGGERCMD_H

#include "../Cat/CatActionPlugin.h"

class CatTriggerDialog;
class CatPLG_SetTriggerCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_SetTriggerCmd(QObject *parent = NULL);
	~CatPLG_SetTriggerCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure();
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatTriggerDialog* myDlg;
};

#endif // CATPLG_SETTRIGGERCMD_H
