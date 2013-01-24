#ifndef CATACTION_H
#define CATACTION_H

#include "cataction_global.h"

#include <QList>
#include <QString>
#include <QSharedPointer>

class CATACTION_EXPORT CatAction
{
public:
	typedef QSharedPointer<CatAction> Pointer;
	virtual ~CatAction() {}

	virtual bool doIt () =0;

	QString title() const;
	QString description() const;
	QString errorMessage() const;
protected:
	void setTitle(const QString& tt);
	void setDescription(const QString& desc);
	void setErrorMessage(const QString& msg);
private:
	QString myTitle;
	QString myDescription;
	QString myErrorMessage;
};

class CATACTION_EXPORT ActionGroup : public CatAction
{
	QList<Pointer> myActions;
public:
	bool doIt()
	{
		foreach(const Pointer& act,myActions)
		{
			if(!act->doIt())
				return false;
		}
		return true;
	}

	void add(const Pointer& ad) { myActions.append(ad); }
	void remove(const Pointer& rm) { myActions.removeAll(rm); }
	int count() const { return myActions.size(); }
};

class CATACTION_EXPORT Check : public CatAction
{
public:
	bool doIt()
	{
		if(myCond->doIt())
			return myResult->doIt();
		else
			return false;
	}

	void SetCondition(const Pointer& cond) {myCond = cond;}
	void SetResult(const Pointer& rst) {myResult = rst;}
private:
	Pointer myCond;
	Pointer myResult;
};
#endif // CATACTION_H
