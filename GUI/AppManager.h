#pragma once

#include <QObject>
#include "ADSDock.h"
#include "ChartWidget.h"
#include "ChartData.h"
#include "AppData/MeasuredData.h"

class AppManager : public QObject {
public:
	AppManager(ADSDock*, ChartWidget*, QObject* parent = nullptr);
	virtual ~AppManager();

public slots:
	void vygenerujGraf(bool);

private:
	ADSDock* adsDock;
	ChartWidget* chart;
};

