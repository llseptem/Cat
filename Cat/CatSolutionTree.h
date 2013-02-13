#ifndef CATSOLUTIONTREE_H
#define CATSOLUTIONTREE_H

#include <QTreeWidget>
#include <QDomElement>
#include <QMap>

class CatSolutionTree : public QTreeWidget
{
	Q_OBJECT

public:
	CatSolutionTree(QWidget *parent = 0);
	~CatSolutionTree();

	void addCommand(const QDomElement& cmd);
	void removeCurrentCommand();
	void removeAllCommand();
	QDomElement currentCommand();
private:
	QTreeWidgetItem* createItem(const QString& tt,const QString& desc,
		QTreeWidgetItem* parentItem = 0);
private:
	QMap<QTreeWidgetItem*,QDomElement> myCmdMap;
};

#endif // CATSOLUTIONTREE_H
