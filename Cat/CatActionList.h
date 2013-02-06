#ifndef CATACTIONLIST_H
#define CATACTIONLIST_H

#include <QDialog>
#include <QUuid>
#include <QMap>
#include "ui_CatActionList.h"


class CatActionList : public QDialog
{
	Q_OBJECT

public:
	CatActionList(QWidget *parent = 0);
	~CatActionList();

	QUuid selectedCommand() const;
private slots:
	void onSelectionChange(int idx);
private:
	Ui::CatActionList ui;
	QMap<QUuid,QString> myDescriptions;

	void initialList();
	void setDescription(const QString& desc);
};

#endif // CATACTIONLIST_H
