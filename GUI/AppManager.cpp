#include "AppManager.h"
#include "List/ArrayList.h"
#include "List/ArrayListRaw.h"
#include "List/LinkedList.h"
#include "List/DoublyLinkedList.h"
#include "Tests/TestOperationTypes.h"
#include "Tests/StructureInstances.h"
#include "Data/DataTypes.h"
#include "Tests/TestStructure.h"
#include "UIRoutines.h"
#include "Tests/TimeFileWriter.h"
#include <QBarSet>

#include "DSStructureFactory.h"

using namespace Structures;

AppManager::AppManager(ADSDock* dock, ChartWidget* chart, QObject* parent) : QObject(parent), adsDock(dock), chart(chart) {
	QObject::connect(this->chart->getControl(), &ChartControl::btnGenerateClicked, this, &AppManager::vygenerujGraf);
}

AppManager::~AppManager() {
}

void AppManager::vygenerujGraf(bool) {
	StructureInstances instances;
    QMap<QPair<StructureADS, AllStructureOperationType>, std::vector<OperationTimeInfo>> operationInfos;

	QVector<int> probs = this->adsDock->getOperationsProbabilities();
	ChartData chartData;

	switch (this->adsDock->getCurrentADTPanel()->getAdt()) {
		case Structures::adtLIST: {
			TestStructure<List<Data::DataType>*> scenary;
			std::vector<ListOperationType> types = TestOperationMapper<Data::DataType>::getListOperations();
            for (int i = 0; i < probs.size(); ++i) {
                if (probs[i] != 0) {
					scenary.addTestOperation(TestOperationMapper<Data::DataType>::getOperationPointer(types[i]), probs[i]);
					chartData.addOperationType(TestOperationMapper<Data::DataType>::getAllOperationType(types[i]));
                }
            }

            std::vector<OperationTimeInfo> lastSequence;
            for (const StructureADS ads : this->adsDock->getSelectedADS()) {
                MeasuredData data;
                if (this->chart->isCSVChecked()) {
                    TimeFileWriter::collectTimesToFile(QInputDialog::getText(this->chart, QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)), "File Name", QLineEdit::Normal).toStdString(), scenary, instances.getListInstance(ads), this->chart->getControl()->getCount());
                }

                if (lastSequence.size() == 0) {
                    lastSequence = data.measureStructures(scenary, instances.getListInstance(ads), ads, this->chart->getCount(), operationInfos);
                } else {
                    data.measureStructures(scenary, instances.getListInstance(ads), ads, lastSequence, operationInfos);
                }
                chartData.addData(data.getMeasuredData(), ads);
                chartData.addBarData(ads, data.getMeasuredOpsTimes());
                chartData.addPieData(data.getSum(), ads);
            }
            this->chart->addOperationInfos(operationInfos);
            this->chart->getChart()->addSerieses(chartData.getData());
            this->chart->getBarChart()->addBarSeries(chartData.getBarData(), chartData.getOperations());
            this->chart->getPieChart()->addSeries(chartData.getPieData());

			break;
		}
		case Structures::adtPRIORITY_QUEUE: {
			TestStructure<PriorityQueue<Data::DataType>*> scenary;
			std::vector<PriorityQueueOperationType> types = TestOperationMapper<Data::DataType>::getPriorityQueueOperations();
			for (int i = 0; i < probs.size(); ++i) {
				if (probs[i] != 0) {
					scenary.addTestOperation(TestOperationMapper<Data::DataType>::getOperationPointer(types[i]), probs[i]);
					chartData.addOperationType(TestOperationMapper<Data::DataType>::getAllOperationType(types[i]));
				}
			}

            std::vector<OperationTimeInfo> lastSequence;
			for (const StructureADS ads : this->adsDock->getSelectedADS()) {
				MeasuredData data;
				if (this->chart->isCSVChecked()) {
					TimeFileWriter::collectTimesToFile(QInputDialog::getText(this->chart, QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)), "File Name", QLineEdit::Normal).toStdString(), scenary, instances.getPriorityQueueInstance(ads), this->chart->getControl()->getCount());
				}
                if (lastSequence.size() == 0) {
                    lastSequence = data.measureStructures(scenary, instances.getPriorityQueueInstance(ads), ads, this->chart->getCount(), operationInfos);
				} else {
                    data.measureStructures(scenary, instances.getPriorityQueueInstance(ads), ads, lastSequence, operationInfos);
				}
				chartData.addData(data.getMeasuredData(), ads);
				chartData.addBarData(ads, data.getMeasuredOpsTimes());
				chartData.addPieData(data.getSum(), ads);
			}
            this->chart->addOperationInfos(operationInfos);
			this->chart->getChart()->addSerieses(chartData.getData());
			this->chart->getBarChart()->addBarSeries(chartData.getBarData(), chartData.getOperations());
			this->chart->getPieChart()->addSeries(chartData.getPieData());
			break;
		}
		case Structures::adtBITSET: {
			TestStructure<BitSet<Data::DataType>*> scenary;
			std::vector<BitSetOperationType> types = TestOperationMapper<Data::DataType>::getBitSetOperations();
			for (int i = 0; i < probs.size(); ++i) {
				if (probs[i] != 0) {
					scenary.addTestOperation(TestOperationMapper<Data::DataType>::getOperationPointer(types[i]), probs[i]);
					chartData.addOperationType(TestOperationMapper<Data::DataType>::getAllOperationType(types[i]));
				}
			}

            std::vector<OperationTimeInfo> lastSequence;
			for (const StructureADS ads : this->adsDock->getSelectedADS()) {
				MeasuredData data;
				if (this->chart->isCSVChecked()) {
					TimeFileWriter::collectTimesToFile(QInputDialog::getText(this->chart, QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)), "File Name", QLineEdit::Normal).toStdString(), scenary, instances.getBitSetInstance(ads), this->chart->getControl()->getCount());
				}
                if (lastSequence.size() == 0) {
                    lastSequence = data.measureStructures(scenary, instances.getBitSetInstance(ads), ads, this->chart->getCount(), operationInfos);
				} else {
                    data.measureStructures(scenary, instances.getBitSetInstance(ads), ads, lastSequence, operationInfos);
				}
				chartData.addData(data.getMeasuredData(), ads);

				chartData.addBarData(ads, data.getMeasuredOpsTimes());
				chartData.addPieData(data.getSum(), ads);
			}
            this->chart->addOperationInfos(operationInfos);
			this->chart->getChart()->addSerieses(chartData.getData());
			this->chart->getBarChart()->addBarSeries(chartData.getBarData(), chartData.getOperations());
			this->chart->getPieChart()->addSeries(chartData.getPieData());

			break;
		}
		case Structures::adtMATRIX: {
			TestStructure<Matrix<Data::DataType>*> scenary;
			std::vector<MatrixOperationType> types = TestOperationMapper<Data::DataType>::getMatrixOperations();
			for (int i = 0; i < probs.size(); ++i) {
				if (probs[i] != 0) {
					scenary.addTestOperation(TestOperationMapper<Data::DataType>::getOperationPointer(types[i]), probs[i]);
					chartData.addOperationType(TestOperationMapper<Data::DataType>::getAllOperationType(types[i]));
				}
			}

            std::vector<OperationTimeInfo> lastSequence;
			for (const StructureADS ads : this->adsDock->getSelectedADS()) {
				MeasuredData data;
				if (this->chart->isCSVChecked()) {
					TimeFileWriter::collectTimesToFile(QInputDialog::getText(this->chart, QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)), "File Name", QLineEdit::Normal).toStdString(), scenary, instances.getMatrixInstance(ads), this->chart->getControl()->getCount());
				}
                if (lastSequence.size() == 0) {
                    lastSequence = data.measureStructures(scenary, instances.getMatrixInstance(ads), ads, this->chart->getCount(), operationInfos);
				} else {
                    data.measureStructures(scenary, instances.getMatrixInstance(ads), ads, lastSequence, operationInfos);
				}
				chartData.addData(data.getMeasuredData(), ads);

				chartData.addBarData(ads, data.getMeasuredOpsTimes());
				chartData.addPieData(data.getSum(), ads);
			}
            this->chart->addOperationInfos(operationInfos);
			this->chart->getChart()->addSerieses(chartData.getData());
			this->chart->getBarChart()->addBarSeries(chartData.getBarData(), chartData.getOperations());
			this->chart->getPieChart()->addSeries(chartData.getPieData());
			break;
		}
//		case Structures::adtTABLE: {
//			TestStructure<Table<Data::DataType, Data::DataType>*> scenary;
//			std::vector<TableOperationType> types = TestOperationMapper<Data::DataType>::getTableOperations();
//			for (int i = 0; i < probs.size(); ++i) {
//				if (probs[i] != 0) {
//					scenary.addTestOperation(TestOperationMapper<Data::DataType>::getOperationPointer(types[i]), probs[i]);
//					chartData.addOperationType(TestOperationMapper<Data::DataType>::getAllOperationType(types[i]));
//				}
//			}

//            std::vector<OperationTimeInfo> lastSequence;
//			for (const StructureADS ads : this->adsDock->getSelectedADS()) {
//				MeasuredData data;
//				if (this->chart->isCSVChecked()) {
//					TimeFileWriter::collectTimesToFile(QInputDialog::getText(this->chart, QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)), "File Name", QLineEdit::Normal).toStdString(), scenary, instances.getTableInstance(ads), this->chart->getControl()->getCount());
//				}
//                if (lastSequence.size() == 0) {
//                    lastSequence = data.measureStructures(scenary, instances.getTableInstance(ads), ads, this->chart->getCount(), operationInfos);
//				} else {
//                    data.measureStructures(scenary, instances.getTableInstance(ads), ads, lastSequence, operationInfos);
//				}
//				chartData.addData(data.getMeasuredData(), ads);

//				chartData.addBarData(ads, data.getMeasuredOpsTimes());
//				chartData.addPieData(data.getSum(), ads);
//			}
//            this->chart->addOperationInfos(operationInfos);
//			this->chart->getChart()->addSerieses(chartData.getData());
//			this->chart->getBarChart()->addBarSeries(chartData.getBarData(), chartData.getOperations());
//			this->chart->getPieChart()->addSeries(chartData.getPieData());
//			break;
//		}
		default:
			break;
	}
}
