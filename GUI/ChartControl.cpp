#include "ChartControl.h"

ChartControl::ChartControl(QWidget* parent) : QGroupBox(parent), generateChart(new QPushButton("Generate")),
clearChart(new QPushButton("Clear")), csvCheck(new QCheckBox("CSV")), count(new QSlider(Qt::Orientation::Horizontal)) {

	this->count->setRange(0, 1000000);
	this->layout = new QHBoxLayout;
	this->layout->addWidget(this->csvCheck);
	this->layout->addWidget(this->generateChart);
	this->layout->addWidget(this->clearChart);
	this->layout->addWidget(this->count);

	this->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
	this->setStyleSheet("QGroupBox { background-color: rgb(30, 24, 40); border-radius : 10px; margin: 0px 10px 10px 10px;}");
//	this->setPalette(QColor(41, 40, 45));

	this->setLayout(this->layout);

//	QObject::connect(this->generateChart, SIGNAL(clicked(bool)), this, SIGNAL(btnGenerateClicked(bool)));
	QObject::connect(this->generateChart, &QPushButton::clicked, this, &ChartControl::btnGenerateClicked);
	QObject::connect(this->clearChart, &QPushButton::clicked, this, &ChartControl::btnClearClicked);
    QObject::connect(this->count, &QSlider::valueChanged, this, &ChartControl::countChanged);
	QObject::connect(this->csvCheck, &QCheckBox::stateChanged, this, &ChartControl::btnCsvCheckChanged);
}

ChartControl::~ChartControl() {
	delete this->generateChart;
	this->generateChart	= nullptr;
	delete this->clearChart;
	this->clearChart = nullptr;
	delete this->csvCheck;
	this->csvCheck = nullptr;
	delete this->count;
	this->count = nullptr;
	delete this->layout;
	this->layout = nullptr;
}

int ChartControl::getCount() const {
    return this->count->value();
}



