#ifndef CATPLG_CURVECHECKCMD_H
#define CATPLG_CURVECHECKCMD_H

#include "../Cat/CatActionPlugin.h"

class CatCurveDialog;
class CatPLG_CurveCheckCmd : public CatActionPlugin
{
	Q_OBJECT
	Q_INTERFACES(CatActionPlugin)
public:
	CatPLG_CurveCheckCmd(QObject* parent = 0);
	~CatPLG_CurveCheckCmd();

	virtual QString title() const;
	virtual QString description() const;

	virtual bool Configure(const QDomElement& elem);
	virtual QUuid Identifier() const;
	virtual bool CreateAction(QDomElement& cmd);
	virtual bool RunAction(const QDomElement& elem,CatRunUI* ui);
private:
	CatCurveDialog* myDlg;
};

#endif // CATPLG_CURVECHECKCMD_H
