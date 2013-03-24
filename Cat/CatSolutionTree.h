#ifndef CATSOLUTIONTREE_H
#define CATSOLUTIONTREE_H

#include <QTreeWidget>
#include <QDomElement>
#include <QMap>

class QUuid;
class CatSolution;
class CatRunUI;
class CatSolutionTree : public QTreeWidget
{
	Q_OBJECT

public:
	CatSolutionTree(QWidget *parent = 0);
	~CatSolutionTree();

	void setupConnect(QAction* addGrp,QAction* addCmd,QAction* rmCurrent);
	void save(const QString& fl);//op tree and doc
	void read(const QString& fl);
	void newDoc();

	void createCommand(const QUuid& uid);
	void createGroup(const QString& grp);
public slots:
	void removeCurrent();
	void run();
signals:
	void currentCanBeDeleted(bool);
	void commandCanBeAdded(bool);
private slots:
	void onCurrentChanged();
private://op tree
	QTreeWidgetItem* createItem(const QString& tt,const QString& desc,
		QTreeWidgetItem* parentItem = 0);
	QTreeWidgetItem* addCommand(const QDomElement& cmd,QTreeWidgetItem* grp);
	QTreeWidgetItem* addGroup(const QString& grp);
	void removeGroup(QTreeWidgetItem* grp);
	void removeCommand(QTreeWidgetItem* cmd,QTreeWidgetItem* grp);
	QTreeWidgetItem* currentGroupItem() const;
	QTreeWidgetItem* currentCommandItem() const;
	void clearAll();
private:
	CatSolution* mySolution;//doc ops
	CatRunUI* myRunUI;
	QMap<QTreeWidgetItem*,QDomElement> myCmdMap;
	QMap<QTreeWidgetItem*,QString> myGroups;
};

#endif // CATSOLUTIONTREE_H
