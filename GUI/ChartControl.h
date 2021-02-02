#pragma once

#include <QPushButton>
#include <QCheckBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QGroupBox>

class ChartControl : public QGroupBox {
	Q_OBJECT
public:
	ChartControl(QWidget* parent = nullptr);
	virtual ~ChartControl();

	int getCount() const;

signals:
	void btnGenerateClicked(bool);
	void btnClearClicked(bool);
	void countChanged(int);
	void btnCsvCheckChanged(int);

private:
	QPushButton* generateChart;
	QPushButton* clearChart;
	QCheckBox* csvCheck;
	QSlider* count;
	QHBoxLayout* layout;
};

