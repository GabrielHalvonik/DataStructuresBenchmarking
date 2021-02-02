#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QVector>
#include <QPair>
#include <QProgressBar>
#include "ADSOperationWidget.h"

class ADSTestWidget : public QGroupBox {
	Q_OBJECT
public:
	explicit ADSTestWidget(const Structures::StructureADT, QWidget* parent = nullptr);
	virtual ~ADSTestWidget();

	QVector<int> getTestData() const;
	Structures::StructureADT getAdt() const;

signals:

public slots:
	void valueOfSliderChanged(int);

private:
	void createOperationWidgets();

private:
	QString name;
	QVBoxLayout* layout;
	QHBoxLayout* horLayout;
	QVector<ADSOperationWidget*> operationWidgets;
	QProgressBar* bar;
	Structures::StructureADT adt;
};

