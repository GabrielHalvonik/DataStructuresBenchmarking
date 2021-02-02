#pragma once

#include <QComboBox>
#include <QVector>
#include "Tests/TestOperationTypes.h"

class ADTComboBox : public QComboBox {
public:
	explicit ADTComboBox(QWidget* parent = nullptr);

	Structures::StructureADT getCurrentADT() const;
private:
	void addADTs();

private:
	QVector<Structures::StructureADT> adts;
};

