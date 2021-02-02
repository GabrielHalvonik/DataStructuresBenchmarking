#pragma once

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QGroupBox>
#include <QVBoxLayout>
#include "DSStructureTypes.h"

class ADSOperationWidget : public QWidget {
	Q_OBJECT
public:
	explicit ADSOperationWidget(const QString&, QWidget* parent = nullptr);
	~ADSOperationWidget();

	int getValue();

signals:
	void sliderValueChanged(int);
public slots:
	void setValueText(int);

private:
	QLabel text;
	QSlider* slider;
	QVBoxLayout* layout;
	QString name;
};

