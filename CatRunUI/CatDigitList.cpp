#include "CatDigitList.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>

class CatDigitItem : public QWidget
{
	QLabel* myLabel;
	QLCDNumber* mydigit;
public:
	CatDigitItem(int wireNum, double val, QWidget* parent = 0)
		:QWidget(parent)
	{
		QHBoxLayout* lay = new QHBoxLayout();
		myLabel = new QLabel(tr("ÏßºÅ:%1").arg(wireNum));
		lay->addWidget(myLabel);
		mydigit = new QLCDNumber();
		mydigit->setSegmentStyle(QLCDNumber::Flat);
		mydigit->setNumDigits(8);
		mydigit->setDigitCount(8);
		mydigit->display(val);
		lay->addWidget(mydigit,1);

		setLayout(lay);
	}
	~CatDigitItem(){}

	void display(double val) {mydigit->display(val);}
	void setLabel(int wireNo) {myLabel->setText(tr("ÏßºÅ:%1").arg(wireNo));}
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
//	QVBoxLayout* lay = qobject_cast<QVBoxLayout*>(layout());
	foreach(CatDigitItem* itm,myDigits)
	{
		itm->setVisible(false);
//		lay->removeWidget(itm);
//		itm->deleteLater();
	}
//	myDigits.clear();
}

void CatDigitList::DisplayInfo( int wireNo,double val )
{
	foreach(CatDigitItem* itm,myDigits)
	{
		if(!itm->isVisible())
		{
			itm->setLabel(wireNo);
			itm->display(val);
			itm->setVisible(true);
			return;
		}
	}

	CatDigitItem* itm = new CatDigitItem(wireNo,val,this);
	myDigits.append(itm);
	qobject_cast<QVBoxLayout*>(layout())->addWidget(itm);
}
