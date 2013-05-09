#ifndef CATSOLUTION_H
#define CATSOLUTION_H

#include <QObject>
#include <QList>
#include <QDomDocument>

class QUuid;
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

	QDomElement createCommand(const QUuid& uid);
	void appendCommand(const QDomElement& cmd, const QString& grp);
	void removeCommand(const QDomElement& cmd, const QString& grp);
	QUuid commandID(const QDomElement& cmd) const;

	void createGroup(const QString& grpName);
	void removeGroup(const QString& grpName);
	void renameGroup(const QString& oldName,const QString& newName);
private:
	QDomDocument myDoc;
	QList<QString> myGroups;
};

#endif // CATSOLUTION_H
