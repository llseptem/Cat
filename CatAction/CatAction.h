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
	CatAction();
	virtual ~CatAction();

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
	bool doIt();

	void add(const Pointer& ad);
	void remove(const Pointer& rm);
	int count() const;
};

#endif // CATACTION_H
