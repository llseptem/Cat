#ifndef CATSOLUTIONTREE_H
#define CATSOLUTIONTREE_H

#include <QTreeWidget>
#include <QDomDocument>
#include <QMap>

class QUuid;
class CatSolutionTree : public QTreeWidget
{
	Q_OBJECT

public:
	CatSolutionTree(QWidget *parent = 0);
	~CatSolutionTree();

	void readSolution(const QString& fp);
	void writeSolution(const QString& fp);

	void addCommand(const QUuid& uid);
	void removeCurrentCommand();
private:
	QTreeWidgetItem* createItem(const QString& tt,const QString& desc,
		QTreeWidgetItem* parentItem = 0);
	QTreeWidgetItem* createItem(const QDomElement& cmd,QTreeWidgetItem* parentItem = 0);
private:
	QMap<QTreeWidgetItem*,QDomElement> myCmdMap;
	QDomDocument myDoc;
	QDomElement myRoot;
};

#endif // CATSOLUTIONTREE_H
