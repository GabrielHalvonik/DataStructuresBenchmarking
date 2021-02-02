#pragma once

#include <QListWidgetItem>
#include "DSStructureTypes.h"

class ADSListItem : public QListWidgetItem {
//	Q_OBJECT
public:
	explicit ADSListItem(const Structures::StructureADS, QListWidget* view = nullptr);
	~ADSListItem();

	Structures::StructureADS getAds() const { return this->ads; }

private:
	Structures::StructureADS ads;
};

