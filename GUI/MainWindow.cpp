#include "MainWindow.h"

#include "ChartData.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), chartWidget(new ChartWidget(this)), adsDock(new ADSDock(this)), central(new QWidget), layout(new QHBoxLayout) {
	this->layout->setSpacing(0);
	this->layout->setMargin(0);
	this->layout->addWidget(this->adsDock);
	this->layout->addWidget(this->chartWidget);
	this->central->setLayout(this->layout);
	this->setCentralWidget(this->central);
	QPalette pal;
    pal.setBrush(QPalette::Window, { QColor(8,6,14)} );
    pal.setBrush(QPalette::Text, { QColor(240, 240, 240)} );
    pal.setBrush(QPalette::ButtonText, { QColor(240, 240, 240)} );


	this->setPalette(pal);
	this->appManager = new AppManager(this->adsDock, this->chartWidget);
}

MainWindow::~MainWindow() {
	delete this->layout;
	this->layout = nullptr;
	delete this->adsDock;
	this->adsDock = nullptr;
	delete this->chartWidget;
	this->chartWidget = nullptr;
	delete this->central;
	this->central = nullptr;
	delete this->appManager;
	this->appManager = nullptr;
}

