#include "ADTComboBox.h"
#include "UIRoutines.h"

ADTComboBox::ADTComboBox(QWidget* parent) : QComboBox(parent) {
	this->addADTs();
	this->setCurrentIndex(1);
	this->setFixedWidth(206);
	this->setStyleSheet("QComboBox { background-color: rgb(30, 24, 40); height: 20px; margin : 12px 0px 10px 10px; border: 2px solid gray; border-radius: 6px; padding: 0 0 0 5; }"
						"QComboBox::drop-down { border: 0px; background: transparent; border-bottom-right-radius: 0px; }"
						"QComboBox::down-arrow { image: url(/Users/gabrielhalvonik/Desktop/arrow.png); width:14px; height:14px; padding: 0px 10px 0px 0px;}"
						);
}

Structures::StructureADT ADTComboBox::getCurrentADT() const {
	return this->adts[this->currentIndex()];
}

void ADTComboBox::addADTs() {
	for (const Structures::StructureADT& temp : Structures::TestOperationMapper<int>::getADTTypes()) {
		this->addItem(QString::fromStdString(UIRoutines::convertStructureADTToStr(temp)));
		this->adts.push_back(temp);
	}
}
