#include "CatDigitList.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>

class CatDigitItem : public QWidget
{
public:
	CatDigitItem(int wireNum, double val, QWidget* parent = 0)
		:QWidget(parent)
	{
		QHBoxLayout* lay = new QHBoxLayout();
		lay->addWidget(new QLabel(tr("ÏßºÅ:%1").arg(wireNum)));
		QLCDNumber* digits = new QLCDNumber();
		digits->setSegmentStyle(QLCDNumber::Flat);
		digits->setNumDigits(8);
		digits->setDigitCount(8);
		digits->display(val);
		lay->addWidget(digits,1);

		setLayout(lay);
	}
	~CatDigitItem(){}
};

CatDigitList::CatDigitList(QWidget *parent)
	: QWidget(parent)
{
	setLayout(new QVBoxLayout());
}

CatDigitList::~CatDigitList()
{

}

void CatDigitList::RemoveAll()
{
	QVBoxLayout* lay = qobject_cast<QVBoxLayout*>(layout());
	foreach(CatDigitItem* itm,myDigits)
	{
		lay->removeWidget(itm);
		itm->deleteLater();
	}
	myDigits.clear();
}

void CatDigitList::DisplayInfo( int wireNo,double val )
{
	CatDigitItem* itm = new CatDigitItem(wireNo,val,this);
	myDigits.append(itm);
	qobject_cast<QVBoxLayout*>(layout())->addWidget(itm);
}
