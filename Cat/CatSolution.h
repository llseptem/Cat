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

private:
	QDomDocument myDoc;
	QDomElement myRootElement;
};

#endif // CATSOLUTION_H
