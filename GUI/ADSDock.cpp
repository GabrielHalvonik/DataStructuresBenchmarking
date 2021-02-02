#include "ADSDock.h"

ADSDock::ADSDock(QWidget* parent) : QDockWidget(parent, Qt::Widget | Qt::FramelessWindowHint), combo(new ADTComboBox(this)), actual(1) {

	this->setFeatures(QDockWidget::NoDockWidgetFeatures);

	this->setTitleBarWidget(this->combo);

	this->createADTPanels();
	this->setWidget(this->adtPanels[this->combo->currentIndex()]);

	this->setContentsMargins(10, 10, 2, 10);
	this->setFixedWidth(208);
    this->setStyleSheet("QWidget { color: white; background-color: rgb(30, 24, 40); border-radius: 10px; }");

//	QObject::connect(this->combo, &ADTComboBox::currentIndexChanged, this, &ADSDock::changePanel);
	QObject::connect(this->combo, SIGNAL(activated(int)), this, SLOT(changePanel(int)));
}

ADSDock::~ADSDock() {
	for (ADTPanel* temp : this->adtPanels) {
		delete temp;
		temp = nullptr;
	}
}

QList<Structures::StructureADS> ADSDock::getSelectedADS() const {
	return this->adtPanels[actual]->getAdsList();
}

ADTPanel* ADSDock::getCurrentADTPanel() const {
	return this->adtPanels[this->actual];
}

QVector<int> ADSDock::getOperationsProbabilities() const {
	return this->adtPanels[this->actual]->getOperationProbabilities();
}

Structures::StructureADT ADSDock::getCurrentADT() const {
	return this->adtPanels[this->actual]->getAdt();
}

void ADSDock::changePanel(int order) {
	this->actual = order;
	this->setWidget(this->adtPanels[order]);
}

void ADSDock::createADTPanels() {
	for (const Structures::StructureADT& temp : Structures::TestOperationMapper<int>::getADTTypes()) {
		ADTPanel* adtPan = new ADTPanel(temp);
		this->adtPanels.push_back(adtPan);
	}
}

