#pragma once

#include <QObject>
#include <QWidget>
#include <QDockWidget>
#include "ADTComboBox.h"
#include "ADTPanel.h"
#include "DSStructureTypes.h"

class ADSDock : public QDockWidget {
	Q_OBJECT
public:
	ADSDock(QWidget* parent = nullptr);
	virtual ~ADSDock();

	QList<Structures::StructureADS> getSelectedADS() const;
	ADTPanel* getCurrentADTPanel() const;
	QVector<int> getOperationsProbabilities() const;
	Structures::StructureADT getCurrentADT() const;

public slots:
	void changePanel(int);

private:
	void createADTPanels();

private:
	QVector<ADTPanel*> adtPanels;
	ADTComboBox* combo;
	uint8_t actual;
};

