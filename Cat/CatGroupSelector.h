#ifndef CATGROUPSELECTOR_H
#define CATGROUPSELECTOR_H

#include <QDialog>
#include "ui_CatGroupSelector.h"

class CatGroupSelector : public QDialog
{
	Q_OBJECT

public:
	CatGroupSelector(QWidget *parent = 0);
	~CatGroupSelector();

	void addGroup(const QStringList& grps);
	QStringList groups() const;
private slots:
	void allClicked(bool checked);
private:
	Ui::CatGroupSelector ui;
	QList<QCheckBox*> grpBoxes;
};

#endif // CATGROUPSELECTOR_H
