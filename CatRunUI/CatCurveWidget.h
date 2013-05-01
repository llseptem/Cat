#ifndef CATCURVEWIDGET_H
#define CATCURVEWIDGET_H

#include <Qwt/Qwt_Plot.h>

class QwtPlotCurve;
class CatCurveWidget : public QwtPlot
{
	Q_OBJECT

public:
	CatCurveWidget(QWidget *parent = 0);
	~CatCurveWidget();

	void setCurveData(const QPolygonF& dats);
	void setLabel(const QString& lb);
private:
	QwtPlotCurve* myCurve;
};

#endif // CATCURVEWIDGET_H
