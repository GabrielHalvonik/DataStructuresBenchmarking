#include "Chart.h"
#include <QGesture>
#include <QAbstractAxis>
#include <QPanGesture>

Chart::Chart(QWidget* parent) : QChartView(parent), chart(new QChart), axisX(new QValueAxis), axisY(new QValueAxis) {
	this->chart->legend()->setMarkerShape(QLegend::MarkerShape::MarkerShapeCircle);
	this->labelVisible = true;
	QColor lightGray(120, 120, 140);
	this->axisX->setLabelFormat("%.0f");
	this->axisY->setLabelFormat("%.0f");
	this->axisX->setLineVisible(false);
	this->axisY->setLineVisible(false);
	this->axisX->setLabelsColor(lightGray);
	this->axisY->setLabelsColor(lightGray);
	this->axisX->setGridLineColor(lightGray);
	this->axisY->setGridLineColor(lightGray);
	this->axisX->setShadesVisible(false);
	this->axisY->setShadesVisible(false);
	this->axisX->setLabelsVisible(false);
	this->axisY->setLabelsVisible(false);
	this->chart->setAcceptHoverEvents(true);

	this->chart->addAxis(this->axisX, Qt::AlignmentFlag::AlignBottom);
	this->chart->addAxis(this->axisY, Qt::AlignmentFlag::AlignLeft);
	this->chart->setTheme(QChart::ChartTheme::ChartThemeDark);
	this->setChart(chart);
    this->grabGesture(Qt::GestureType::PinchGesture);
    this->grabGesture(Qt::GestureType::PanGesture);
    this->grabGesture(Qt::GestureType::SwipeGesture);
	this->chart->setBackgroundRoundness(12);
	this->chart->setDropShadowEnabled(false);
//	this->chart->setBackgroundBrush(QColor(41, 40, 45));
	this->chart->setBackgroundBrush((QColor(30, 24, 40, 255)));
	this->setRenderHint(QPainter::RenderHint::Antialiasing);
}

Chart::~Chart() {
	this->removeAllSeries();
	delete this->axisX;
	this->axisX = nullptr;
	delete this->axisY;
	this->axisY = nullptr;
	delete this->chart;
	this->chart = nullptr;
}

void Chart::addSeries(QAbstractSeries* series) {
	if (this->labelVisible) {
		this->axisX->setLabelsVisible(true);
		this->axisY->setLabelsVisible(true);
	}
	this->chart->addSeries(series);
	series->attachAxis(this->axisX);
	series->attachAxis(this->axisY);

	QObject::connect(this->chart->legend()->markers(series).last(), &QLegendMarker::clicked, this, &Chart::handleMarkerClicked);
}

//void Chart::addSeries(QPieSeries* series) {
//	this->chart->addSeries(series);
//	series->attachAxis(this->axisX);
//	series->attachAxis(this->axisY);
//}

void Chart::addSerieses(std::map<Structures::StructureADS, QAbstractSeries*> serieses) {
    this->serieses = serieses;
	if (this->labelVisible) {
		this->axisX->setLabelsVisible(true);
		this->axisY->setLabelsVisible(true);
	}
	for (auto temp : serieses) {
		this->chart->addSeries(temp.second);
		temp.second->attachAxis(this->axisX);
		temp.second->attachAxis(this->axisY);
		QObject::connect(this->chart->legend()->markers(temp.second).last(), &QLegendMarker::clicked, this, &Chart::handleMarkerClicked);
	}
}

void Chart::removeSeries(QAbstractSeries* series) {
	this->chart->removeSeries(series);
	series->detachAxis(this->axisX);
	series->detachAxis(this->axisY);
	QObject::disconnect(this->chart->legend()->markers(series).last(), &QLegendMarker::clicked, this, &Chart::handleMarkerClicked);
}

void Chart::removeAllSeries() {
	this->chart->removeAllSeries();
}

void Chart::clear() {
	this->chart->removeAllSeries();
	this->axisX->setLabelsVisible(false);
	this->axisY->setLabelsVisible(false);
}

void Chart::hideLabels() {
	this->labelVisible = false;
	this->axisX->setLabelsVisible(false);
	this->axisY->setLabelsVisible(false);
}

void Chart::hideLegend() {
	this->chart->legend()->hide();
}

void Chart::hideAxis() {
	this->axisX->hide();
	this->axisY->hide();
//	this->axisX->setLineVisible(false);
//	this->axisY->setLineVisible(false);
}

void Chart::showAxis() {
	this->axisX->show();
	this->axisY->show();
}

void Chart::handleMarkerClicked() {
	QLegendMarker* marker = qobject_cast<QLegendMarker*>(sender());
	marker->series()->setVisible(!marker->series()->isVisible());
	marker->setVisible(true);
}

//void Chart::mousePressEvent(QMouseEvent* event) {

//	QChartView::mousePressEvent(event);
//}

bool Chart::event(QEvent* event) {
	if (event->type() == QEvent::Gesture) {
		if (QGesture* gesture = dynamic_cast<QGestureEvent*>(event)->gesture(Qt::GestureType::PinchGesture)) {
			QPinchGesture* pinch = dynamic_cast<QPinchGesture*>(gesture);
//			if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged) {
			pinch->setChangeFlags(QPinchGesture::ChangeFlag::ScaleFactorChanged);
			this->chart->zoom(pinch->scaleFactor());
//			}
        } /*else if (QGesture* gesture = dynamic_cast<QGestureEvent*>(event)->gesture(Qt::GestureType::SwipeGesture)) {
            QSwipeGesture* pan = dynamic_cast<QSwipeGesture*>(gesture);
            //			if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged) {
//            pinch->setChangeFlags(QPinchGesture::ChangeFlag::ScaleFactorChanged);
            this->chart->scroll(pan->verti, pan->offset().y());
            //			}
        }*/
	}
	return QChartView::event(event);
}

void Chart::wheelEvent(QWheelEvent* event) {
	QPoint anglePoint = event->angleDelta();
    this->chart->scroll(-anglePoint.x(), anglePoint.y());

    QChartView::wheelEvent(event);
}

void Chart::mouseMoveEvent(QMouseEvent* event) {
    #ifdef Q_OS_ANDROID
    this->chart->scroll(event->x(), event->y());
    QChartView::mouseMoveEvent(event);
    #else
    #endif
}

std::map<Structures::StructureADS, QAbstractSeries*> Chart::getSerieses() const {
    return this->serieses;
}

void Chart::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key::Key_Up) {
        this->axisY->setRange(0, this->axisY->max() / 2);
	} else if (event->key() == Qt::Key::Key_Down) {
		this->axisY->setRange(0, this->axisY->max() * 2);
	} else if (event->key() == Qt::Key::Key_R) {
		this->chart->zoomReset();
	} /*else if (event->key() >= Qt::Key::Key_A && event->key() <= Qt::Key::Key_H) {
		int pos = event->key() - Qt::Key::Key_A;
		if (event->key() <= this->chart->series().count()) {
			this->chart->series().takeAt(pos)->setVisible(!this->chart->series().takeAt(pos)->isVisible());
		}
//		this->chart->series().
	}*/
	QChartView::keyPressEvent(event);
}


