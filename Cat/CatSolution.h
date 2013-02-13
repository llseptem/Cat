#ifndef CATSOLUTION_H
#define CATSOLUTION_H

#include <QObject>
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
	QDomElement createCommand();
	void appendCommand(const QDomElement& cmd);
	void removeCommand(const QDomElement& cmd);
private:
	QDomDocument myDoc;
};

#endif // CATSOLUTION_H
