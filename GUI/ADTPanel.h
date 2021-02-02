#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include "ADSList.h"
#include "ADSTestWidget.h"
#include "DSStructureTypes.h"

class ADTPanel : public QWidget {
public:
	ADTPanel(const Structures::StructureADT, QWidget* parent = nullptr);
	virtual ~ADTPanel();

	Structures::StructureADT getAdt() const;
	QVector<int> getOperationProbabilities() const;

	QList<Structures::StructureADS> getAdsList() const;

private:
	Structures::StructureADT adt;
	QGroupBox* box;
	ADSList* adsList;
	ADSTestWidget* adsTest;
	QVBoxLayout* layout;
};

