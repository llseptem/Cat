#ifndef CATPLG_RESISTENCECMD_H
#define CATPLG_RESISTENCECMD_H

#include "../Cat/CatActionPlugin.h"

class CatResistenceDialog;
class CatPLG_ResistenceCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_ResistenceCmd(QObject *parent = 0);
	~CatPLG_ResistenceCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure();
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatResistenceDialog* myDlg;
};

#endif // CATPLG_RESISTENCECMD_H
