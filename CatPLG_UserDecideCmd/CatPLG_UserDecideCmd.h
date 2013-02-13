#ifndef CATPLG_USERDECIDECMD_H
#define CATPLG_USERDECIDECMD_H

#include "../Cat/CatActionPlugin.h"

class CatPresentation;

class CatPLG_UserDecideCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_UserDecideCmd(QObject *parent = 0);
	~CatPLG_UserDecideCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure();
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem);
private:
	CatPresentation* myDlg;
};

#endif // CATPLG_USERDECIDECMD_H
