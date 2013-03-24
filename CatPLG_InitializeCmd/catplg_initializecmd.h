#ifndef CATPLG_INITIALIZECMD_H
#define CATPLG_INITIALIZECMD_H

#include "../Cat/CatActionPlugin.h"

class CatInitializeDialog;
class CatPLG_InitializeCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_InitializeCmd(QObject *parent = 0);
	~CatPLG_InitializeCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure();
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatInitializeDialog* myInitDlg;
};

#endif // CATPLG_INITIALIZECMD_H
