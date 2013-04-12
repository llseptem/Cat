#include "CatGroupSelector.h"

CatGroupSelector::CatGroupSelector(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.allBox,SIGNAL(clicked(bool)),this,SLOT(allClicked(bool)));
}

CatGroupSelector::~CatGroupSelector()
{

}

void CatGroupSelector::addGroup( const QStringList& grps )
{
	QVBoxLayout* vbl = qobject_cast<QVBoxLayout*>(ui.groupBox->layout());
	foreach(QCheckBox* box,grpBoxes)
	{
		vbl->removeWidget(box);
		box->deleteLater();
	}
	grpBoxes.clear();

	foreach(const QString& tt,grps)
	{
		QCheckBox* box = new QCheckBox(tt,this);
		vbl->addWidget(box);
		grpBoxes.append(box);
	}
	adjustSize();
}

void CatGroupSelector::allClicked( bool checked )
{
	foreach(QCheckBox* box, grpBoxes)
	{
		box->setChecked(checked);
	}
}

QStringList CatGroupSelector::groups() const
{
	QStringList selectGrps;
	foreach(QCheckBox* box,grpBoxes)
	{
		if(box->isChecked())
			selectGrps.append(box->text());
	}
	return selectGrps;
}
