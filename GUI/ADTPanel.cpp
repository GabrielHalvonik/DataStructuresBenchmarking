#include "ADTPanel.h"

ADTPanel::ADTPanel(const Structures::StructureADT adt, QWidget* parent) : QWidget(parent), adt(adt), box(new QGroupBox(this)),
adsList(new ADSList(adt, this)), adsTest(new ADSTestWidget(adt, this)), layout(new QVBoxLayout(this)) {

	this->layout->setMargin(8);
	this->layout->setSpacing(20);
	this->layout->addWidget(this->adsList);
	this->layout->addWidget(this->adsTest);
	this->adsTest->setStyleSheet("QGroupBox { padding: 4px 0px 4px 4px; border: 2px solid gray;}");
	this->layout->addStretch();
	this->adsList->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);
	this->adsTest->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Maximum);
}

ADTPanel::~ADTPanel() {
	delete this->layout;
	this->layout = nullptr;
	delete this->box;
	this->box = nullptr;
	delete this->adsList;
	this->adsList = nullptr;
	delete this->adsTest;
	this->adsTest = nullptr;
}

Structures::StructureADT ADTPanel::getAdt() const {
	return this->adt;
}

QVector<int> ADTPanel::getOperationProbabilities() const {
	return this->adsTest->getTestData();
}

QList<Structures::StructureADS> ADTPanel::getAdsList() const {
	return this->adsList->getSelected();
}
