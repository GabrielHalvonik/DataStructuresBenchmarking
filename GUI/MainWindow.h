#pragma once

#include <QMainWindow>
#include <QPushButton>
#include "AppManager.h"
#include "ChartWidget.h"
#include "ADSDock.h"

class MainWindow : public QMainWindow {
public:
	MainWindow(QWidget* parent = nullptr);
	virtual ~MainWindow() override;

private:
	ChartWidget* chartWidget;
	ADSDock* adsDock;
	QWidget* central;
	QHBoxLayout* layout;
	AppManager* appManager;
};
