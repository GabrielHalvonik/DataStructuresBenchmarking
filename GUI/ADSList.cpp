#include "ADSList.h"
#include "Tests/TestOperationTypes.h"

ADSList::ADSList(const Structures::StructureADT adt, QWidget* parent) : QListWidget(parent), adt(adt) {
	this->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);

	this->addADSs();

	this->setGridSize(QSize(50, 32));
	this->setStyleSheet("QListWidget::item { border-radius: 6px; border: 2px solid gray; }"
						"QListWidget::item:selected { background-color: rgb(14,80,200); }");

	QPalette pal;
	pal.setBrush(QPalette::ColorRole::Text, {QColor(220,220,220)});
	pal.setBrush(QPalette::ColorRole::Base, {QColor(14,10,20)});
	this->setPalette(pal);

	QObject::connect(this, &QListWidget::itemClicked, this, &ADSList::itemSelectChange);
}

ADSList::~ADSList() {
	for (ADSListItem* listItem : this->adsList) {
		delete listItem;
		listItem = nullptr;
	}
}

void ADSList::addADSs() {
	std::vector<Structures::StructureADS> adss = Structures::TestOperationMapper<int>::getADSsTypesOfADT(this->adt);
	for (const Structures::StructureADS& temp : adss) {
		ADSListItem* adsItem = new ADSListItem(temp);
		this->adsList.append(adsItem);
		this->addItem(adsItem);
	}
	this->setMaximumHeight(33 * this->adsList.size());
}

QList<Structures::StructureADS> ADSList::getSelected() const {
	QList<Structures::StructureADS> selected;
	for (QListWidgetItem* temp : this->selectedItems()) {
		selected.append(dynamic_cast<ADSListItem*>(temp)->getAds());
	}
	return selected;
}

void ADSList::itemSelectChange(QListWidgetItem* item) {
//	std::cout << UIRoutines::convertStructureADSToStr(dynamic_cast<ADSListItem*>(item)->getAds()) << std::endl;
}
