#pragma once

#include <QListWidget>
#include <QWidget>
#include <QMap>
#include "UIRoutines.h"
#include "DSStructureTypes.h"
#include "ADSListItem.h"


class ADSList : public QListWidget {
//	Q_OBJECT
public:
	explicit ADSList(const Structures::StructureADT, QWidget* parent = nullptr);
	virtual ~ADSList();
	void addADSs();
	QList<Structures::StructureADS> getSelected() const;

public slots:
	void itemSelectChange(QListWidgetItem*);

private:
	Structures::StructureADT adt;
	QList<ADSListItem*> adsList;
};

