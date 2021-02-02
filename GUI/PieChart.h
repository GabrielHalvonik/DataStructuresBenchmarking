#pragma once

#include <QPieSlice>
#include <QMetaObject>
#include "Chart.h"

class PieChart : public Chart {
    Q_OBJECT
public:
    PieChart(QWidget* parent = nullptr);

    void addSeries(QPieSeries*);
    void removeSeries(QPieSeries*);
signals:
    void sliceClicked(QPieSlice*);

private:
    QMetaObject::Connection connection;
};

