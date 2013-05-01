#include "CatCurveWidget.h"
#include <Qwt/qwt_legend.h>
#include <Qwt/qwt_plot_curve.h>
#include <Qwt/qwt_plot_grid.h>
#include <Qwt/qwt_symbol.h>

CatCurveWidget::CatCurveWidget(QWidget *parent)
	: QwtPlot(parent)
{
	setTitle( "Scan Curve" );
	setCanvasBackground( Qt::white );
//	setAxisScale( QwtPlot::yLeft, 0.0, 10.0 );
	insertLegend( new QwtLegend() );
	setAxisTitle(yLeft,"Values");
	setAxisTitle(xBottom,"Seconds");

	QwtPlotGrid *grid = new QwtPlotGrid();
	grid->setPen(QPen(Qt::gray,1,Qt::DashLine));
	grid->attach(this);

	myCurve = new QwtPlotCurve();
	myCurve->setTitle( "Voltage Curve" );
	myCurve->setPen( QPen( Qt::blue, 2 ) ),
	myCurve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

	QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
		QBrush( Qt::yellow ), QPen( Qt::red, 1 ), QSize( 8, 8 ) );
	myCurve->setSymbol( symbol );
	myCurve->attach( this );
}

CatCurveWidget::~CatCurveWidget()
{

}

/*
QPolygonF points;
points << QPointF( 0.0, 4.4 ) << QPointF( 1.0, 3.0 )
<< QPointF( 2.0, 4.5 ) << QPointF( 3.0, 6.8 )
<< QPointF( 4.0, 7.9 ) << QPointF( 5.0, 7.1 );
myCurve->setSamples( points );
*/
void CatCurveWidget::setCurveData( const QPolygonF& dats )
{
	myCurve->setSamples(dats);
}

void CatCurveWidget::setLabel( const QString& lb )
{
	setAxisTitle(yLeft,lb);
	myCurve->setTitle(lb);
}
