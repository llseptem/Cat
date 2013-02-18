#ifndef CATSOLUTION_H
#define CATSOLUTION_H

#include <QObject>
#include <QSet>
#include <QDomDocument>

class CatSolution : public QObject
{
	Q_OBJECT

public:
	CatSolution(QObject *parent);
	~CatSolution();

	bool writeTo(const QString& pth);
	bool readFrom(const QString& pth);

	void newSolution();

	QList<QDomElement> commands() const;
	QList<QDomElement> commands(const QString& grp) const;
	QStringList groups() const;
	bool hasGroup(const QString& grp) const;

	QDomElement createCommand();
	void appendCommand(const QDomElement& cmd, const QString& grp);
	void removeCommand(const QDomElement& cmd, const QString& grp);

	void createGroup(const QString& grpName);
	void removeGroup(const QString& grpName);
private:
	QDomDocument myDoc;
	QSet<QString> myGroups;
};

#endif // CATSOLUTION_H
