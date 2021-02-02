#include "ADSTestWidget.h"
#include "Tests/TestOperationTypes.h"
#include "UIRoutines.h"

ADSTestWidget::ADSTestWidget(const Structures::StructureADT adt, QWidget* parent) : QGroupBox(parent), bar(new QProgressBar(this)), adt(adt) {
	this->layout = new QVBoxLayout;
	this->horLayout = new QHBoxLayout(this);
	this->name = QString::fromStdString(UIRoutines::convertStructureADTToStr(adt));
	this->bar->setRange(0, 100);
	this->createOperationWidgets();
	this->bar->setOrientation(Qt::Orientation::Vertical);
	this->horLayout->setSpacing(10);
	this->horLayout->setMargin(0);
	this->horLayout->addLayout(this->layout);
	this->horLayout->addWidget(this->bar);
	this->layout->setMargin(0);
	this->bar->setTextVisible(false);
	this->setLayout(this->horLayout);
}

ADSTestWidget::~ADSTestWidget() {
	for (ADSOperationWidget* item : this->operationWidgets) {
		delete item;
		item = nullptr;
	}
	delete this->layout;
	this->layout = nullptr;
	delete this->horLayout;
	this->horLayout = nullptr;
	delete this->bar;
	this->bar = nullptr;
}

QVector<int> ADSTestWidget::getTestData() const {
	QVector<int> testData;

	for (ADSOperationWidget* temp : this->operationWidgets) {
		testData.append(temp->getValue());
	}

	return testData;
}

Structures::StructureADT ADSTestWidget::getAdt() const {
	return this->adt;
}

void ADSTestWidget::valueOfSliderChanged(int) {
	int val = 0;
	for (auto temp : this->operationWidgets) {
		val += temp->getValue();
	}
	bar->setValue(val);
}

void ADSTestWidget::createOperationWidgets() {
	std::vector<std::string> ops = Structures::TestOperationMapper<int>::getADTOperationsStr(this->name.toStdString());
	for (const std::string& temp : ops) {
		ADSOperationWidget* newOpWidget = new ADSOperationWidget(QString::fromStdString(temp));
		QObject::connect(newOpWidget, &ADSOperationWidget::sliderValueChanged, this, &ADSTestWidget::valueOfSliderChanged);
		this->operationWidgets.push_back(newOpWidget);
		this->layout->addWidget(newOpWidget);
	}
}
