#pragma once

#include "Chart.h"
#include "BarChart.h"
#include "PieChart.h"
#include "ChartControl.h"
#include "Tests/OperationTimeInfo.h"
#include "Table/SortedSequenceTable.h"
#include <QPair>
#include <QMap>
#include <QScatterSeries>

using Structures::SortedSequenceTable;
using Structures::AllStructureOperationType;
using Structures::StructureADS;

class ChartWidget : public QWidget {
	Q_OBJECT
public:
	ChartWidget(QWidget* parent = nullptr);
	virtual ~ChartWidget() override;

	Chart* getChart() const;
	BarChart* getBarChart() const;
    PieChart* getPieChart() const;
	ChartControl* getControl() const;

	inline bool isCSVChecked() const { return this->csvCheck; }

	void addSeries(QAbstractSeries*);
    void addPieSeries(QPieSeries*);

    void addOperationInfos(QMap<QPair<StructureADS, AllStructureOperationType>, std::vector<OperationTimeInfo>>&);

	bool getAverage() const;
	uint32_t getCount() const;

public slots:
	void clearChart(bool);
	void csvCheckChange(int);
	void countChange(int);
    void visualizeOperation(const QString&, const QString&);
    void visualizeAll(QPieSlice*);

protected:
	void keyPressEvent(QKeyEvent* event) override;

private:
	Chart* chart;
    Chart* chartOps;
	BarChart* barChart;
    PieChart* pieChart;
	ChartControl* control;
	QVBoxLayout* layout;
	bool csvCheck;
	uint32_t count;
	bool isStretched;

    QMap<QPair<StructureADS, AllStructureOperationType>, std::vector<OperationTimeInfo>> timeInfos;

	QVBoxLayout* subChartLayout;
	QHBoxLayout* chartsLayout;
};


