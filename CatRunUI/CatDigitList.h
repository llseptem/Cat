#ifndef CATDIGITLIST_H
#define CATDIGITLIST_H

#include <QWidget>

class CatDigitItem;
class CatDigitList : public QWidget
{
	Q_OBJECT

public:
	CatDigitList(QWidget *parent = 0);
	~CatDigitList();

	void RemoveAll();
	void DisplayInfo(const QString& tag,double val);
private:
	QList<CatDigitItem*> myDigits;
};

#endif // CATDIGITLIST_H
