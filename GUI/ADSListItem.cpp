#include "ADSListItem.h"
#include "UIRoutines.h"

ADSListItem::ADSListItem(const Structures::StructureADS ads, QListWidget* view) : QListWidgetItem(view), ads(ads) {
	this->setText(QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)));
	this->setSizeHint(QSize(28, 28));
}

ADSListItem::~ADSListItem() {
}
