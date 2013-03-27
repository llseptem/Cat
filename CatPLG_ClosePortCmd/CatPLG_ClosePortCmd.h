#ifndef CATPLG_CLOSEPORTCMD_H
#define CATPLG_CLOSEPORTCMD_H

#include "../Cat/CatActionPlugin.h"

class CatPortSelectDialog;
class CatPLG_ClosePortCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_ClosePortCmd(QObject* parent = 0);
	~CatPLG_ClosePortCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure();
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatPortSelectDialog* myDlg;
};

#endif // CATPLG_CLOSEPORTCMD_H
