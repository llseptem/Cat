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
	CatDigitItem(const QString& tag, double val, QWidget* parent = 0)
		:QWidget(parent)
	{
		QHBoxLayout* lay = new QHBoxLayout();
		myLabel = new QLabel(tag);
		QFont font;
		font.setFamily("Courier");
		font.setFixedPitch(true);
		font.setPointSize(14);
		myLabel->setFont(font);
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
	void setLabel(const QString& tag) {myLabel->setText(tag);}
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

void CatDigitList::DisplayInfo( const QString& tag,double val )
{
	foreach(CatDigitItem* itm,myDigits)
	{
		if(!itm->isVisible())
		{
			itm->setLabel(tag);
			itm->display(val);
			itm->setVisible(true);
			return;
		}
	}

	CatDigitItem* itm = new CatDigitItem(tag,val,this);
	myDigits.append(itm);
	qobject_cast<QVBoxLayout*>(layout())->addWidget(itm);
	itm->setVisible(true);
}
