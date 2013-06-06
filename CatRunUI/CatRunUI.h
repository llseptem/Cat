#ifndef CATRUNUI_H
#define CATRUNUI_H

#include <QDialog>
#include "catrunui_global.h"

namespace Ui
{
	class CatRunUI;
}

class CatCurveWidget;
class CatDigitList;
class QScrollArea;
class CATRUNUI_EXPORT CatRunUI : public QDialog
{
	Q_OBJECT

public:
	CatRunUI(QWidget *parent = 0);
	~CatRunUI();
	
	void setTitle(const QString& tt);
	void setMessage(const QString& msg);
	void clearMessage();
	void setInformation(const QString& info, bool err = false);
	void setImage(const QImage& img);
	void setImage(const QString& pth);
	bool waitForDecition();
	bool wait(int sec);
	void reset();
	void enablePrint(bool able);
	void enableRerun(bool able);

	void digitMode();
	void curveMode();
	void clearDigits();
	void displayDigit(const QString& tag,double val);
	void drawCurve(const QString& lb, const QPolygonF& pts);

	bool writeLog(const QString& xml);
signals:
	void reRun();
private slots:
	void print();
private:
	Ui::CatRunUI* ui;
	CatCurveWidget* myCurve;
	CatDigitList* myDigits;
	QScrollArea* myDigitsContainer;

	void setupWidget();
};

#endif // CATRUNUI_H
