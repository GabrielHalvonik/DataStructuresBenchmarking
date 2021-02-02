#include "ChartWidget.h"
#include "UIRoutines.h"

ChartWidget::ChartWidget(QWidget* parent) : QWidget(parent), chart(new Chart), chartOps(new Chart), barChart(new BarChart(this)),
pieChart(new PieChart(this)), control(new ChartControl(this)), layout(new QVBoxLayout(this)), csvCheck(false), count(0), isStretched(false) {

	this->pieChart->hideLegend();
	this->pieChart->hideAxis();
	this->pieChart->hideLabels();

	this->subChartLayout = new QVBoxLayout;
	this->chartsLayout = new QHBoxLayout;

	this->subChartLayout->addWidget(this->barChart);
	this->subChartLayout->addWidget(this->pieChart);

	this->chartsLayout->addWidget(this->chart);
	this->chartsLayout->addLayout(this->subChartLayout);
	this->barChart->setMaximumSize(260, 600);
	this->pieChart->setMaximumSize(260, 260);

	this->layout->addLayout(this->chartsLayout);
	this->layout->setSpacing(0);
	this->layout->setMargin(0);
	this->layout->addWidget(this->control);

	QObject::connect(this->control, &ChartControl::btnClearClicked, this, &ChartWidget::clearChart);
	QObject::connect(this->control, &ChartControl::btnCsvCheckChanged, this, &ChartWidget::csvCheckChange);
    QObject::connect(this->control, &ChartControl::countChanged, this, &ChartWidget::countChange);
    QObject::connect(this->barChart, &BarChart::opClicked, this, &ChartWidget::visualizeOperation);
    QObject::connect(this->pieChart, &PieChart::sliceClicked, this, &ChartWidget::visualizeAll);
}

ChartWidget::~ChartWidget() {
//	this->clearChart(true);
	delete this->subChartLayout;
	this->subChartLayout = nullptr;
	delete this->chartsLayout;
	this->chartsLayout = nullptr;
	delete this->layout;
	this->layout = nullptr;
	delete this->control;
	this->control = nullptr;
	delete this->chart;
	this->chart = nullptr;
	delete this->barChart;
	this->barChart = nullptr;
	delete this->pieChart;
	this->pieChart = nullptr;
}

void ChartWidget::clearChart(bool) {
    this->chartOps->clear();
	this->chart->clear();
	this->barChart->clear();
	this->pieChart->clear();
}

void ChartWidget::csvCheckChange(int state) {
	this->csvCheck = state;
}

void ChartWidget::countChange(int count) {
    this->count = count;
}

void ChartWidget::visualizeOperation(const QString& opAds, const QString& opName) {
    if (!this->chart->isHidden()) {
        this->chart->hide();
        this->chartsLayout->replaceWidget(this->chart, this->chartOps);
        this->chartOps->show();
    }
    QPair pair = { UIRoutines::getAdsOfStr(opAds.toStdString()), UIRoutines::getAllOpsOfStr(opName.toStdString()) };

    QScatterSeries* series = new QScatterSeries;
    series->setMarkerSize(4);
    series->setUseOpenGL(true);
    series->setName(QString::fromStdString(UIRoutines::convertStructureADSToStr(pair.first)));
    series->setColor(UIRoutines::getColorOfADS(pair.first).c_str());

    for (const OperationTimeInfo& temp : this->timeInfos[pair]) {
        series->append(temp.structureSize, temp.time.count());
    }
    this->chartOps->addSeries(series);
}

void ChartWidget::visualizeAll(QPieSlice*) {
    if (!this->chartOps->isHidden()) {
        this->chartOps->hide();
        this->chartsLayout->replaceWidget(this->chartOps, this->chart);
        this->chart->show();
    }
}

uint32_t ChartWidget::getCount() const {
	return this->count;
}

bool ChartWidget::getAverage() const {
	return this->csvCheck;
}

ChartControl* ChartWidget::getControl() const {
	return this->control;
}

void ChartWidget::addSeries(QAbstractSeries* series) {
	this->chart->addSeries(series);
}

void ChartWidget::addPieSeries(QPieSeries* series) {
    this->pieChart->addSeries(series);
}

void ChartWidget::addOperationInfos(QMap<QPair<StructureADS, AllStructureOperationType>, std::vector<OperationTimeInfo>>& infos) {
    this->timeInfos = infos;
}

Chart* ChartWidget::getChart() const {
	return this->chart;
}

BarChart* ChartWidget::getBarChart() const {
	return this->barChart;
}

PieChart* ChartWidget::getPieChart() const {
	return this->pieChart;
}

void ChartWidget::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key::Key_Space) {
		if (isStretched) {
			this->chart->show();
			this->pieChart->show();
			this->barChart->toggleStretch(false);
			this->barChart->setFixedSize(260, 600);
		} else {
			this->chart->hide();
			this->pieChart->hide();
			this->barChart->setMaximumSize(2000, 1000);
			this->barChart->toggleStretch(true);
		}
		isStretched = !isStretched;
	}
	QWidget::keyPressEvent(event);
}

