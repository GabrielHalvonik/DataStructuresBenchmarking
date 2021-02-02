#include "BarChart.h"
#include <QBarSet>

#include "UIRoutines.h"

BarChart::BarChart(QWidget* parent) : Chart(parent), axis(new QBarCategoryAxis(this)), valueAxis(new QValueAxis(this)), series(new QStackedBarSeries(this)) {
	this->chart->removeAxis(this->axisX);
	this->chart->removeAxis(this->axisY);
	this->axis->setLineVisible(false);
	this->valueAxis->setLineVisible(false);
	this->valueAxis->hide();
	this->axis->setGridLineVisible(false);
	this->valueAxis->setGridLineVisible(false);
	this->axis->hide();
    this->chart->legend()->setVisible(false);
}

BarChart::~BarChart() {
//	this->removeAllSeries();
	delete this->axis;
	this->axis= nullptr;
	delete this->valueAxis;
	this->valueAxis = nullptr;
}

void BarChart::toggleStretch(bool toggle) {
	if (toggle) {
		this->chart->legend()->show();
		this->axis->show();
	} else {
		this->chart->legend()->hide();
		this->axis->hide();
	}
}

int BarChart::getBarCount() const {
	return this->barCount;
}

void BarChart::addBarSeries(QList<QBarSet*>* sets, const QList<Structures::AllStructureOperationType>& opTypes) {
	QStringList operations;
	this->barCount = opTypes.count();

	for (Structures::AllStructureOperationType temp : opTypes) {
		operations.append(QString::fromStdString(UIRoutines::convertOperationTypeToStr(temp)));
	}
	this->axis->append(operations);

	if (this->labelVisible) {
		this->axis->setLabelsVisible(true);
	}
	this->series->append(*sets);

	if (this->chart->series().isEmpty()) {
        this->chart->addSeries(this->series);
        this->connection = QObject::connect(this->series, &QAbstractBarSeries::doubleClicked, this, &BarChart::barSetPressed);
		this->chart->addAxis(this->axis, Qt::AlignBottom);
		this->series->attachAxis(this->axis);
		this->chart->addAxis(this->valueAxis, Qt::AlignLeft);
		this->series->attachAxis(this->valueAxis);
	}


	delete sets;
	sets = nullptr;
}

void BarChart::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key::Key_Up) {
		this->valueAxis->setRange(0, this->valueAxis->max() / 2);
	} else if (event->key() == Qt::Key::Key_Down) {
		this->valueAxis->setRange(0, this->valueAxis->max() * 2);
	} else if (event->key() == Qt::Key::Key_R) {
		this->chart->zoomReset();
	}
	QWidget::keyPressEvent(event);
}

void BarChart::clear() {
    QObject::disconnect(this->connection);
	this->chart->removeAxis(this->axis);
	this->chart->removeAxis(this->valueAxis);
	this->series->clear();
    this->chart->removeSeries(this->series);
}

void BarChart::barSetPressed(int i, QBarSet* set) {
    Q_UNUSED(set)
    emit this->opClicked(set->label(), this->axis->at(i));
}
