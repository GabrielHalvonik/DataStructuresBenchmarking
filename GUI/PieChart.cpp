#include "PieChart.h"

PieChart::PieChart(QWidget* parent) : Chart(parent) {
}

void PieChart::addSeries(QPieSeries* series) {
    this->chart->addSeries(series);
    series->attachAxis(this->axisX);
    series->attachAxis(this->axisY);
    this->connection = QObject::connect(series, &QPieSeries::doubleClicked, this, &PieChart::sliceClicked);
}

void PieChart::removeSeries(QPieSeries* series) {
    this->chart->removeSeries(series);
    series->detachAxis(this->axisX);
    series->detachAxis(this->axisY);
    QObject::disconnect(this->connection);
}
