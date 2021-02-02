#pragma once

#include "DSStructureTypes.h"
#include "Structure.h"
#include "Tests/ListOperations.h"
#include <string>
#include <map>

class UIRoutines {
public:
	UIRoutines() = delete;

	static std::string convertStructureADTToStr(const Structures::StructureADT);
	static std::string convertStructureADSToStr(const Structures::StructureADS);
	static std::string convertOperationTypeToStr(const Structures::ListOperationType);
	static std::string convertOperationTypeToStr(const Structures::PriorityQueueOperationType);
	static std::string convertOperationTypeToStr(const Structures::MatrixOperationType);
	static std::string convertOperationTypeToStr(const Structures::BitSetOperationType);
	static std::string convertOperationTypeToStr(const Structures::TableOperationType);
	static std::string convertOperationTypeToStr(const Structures::AllStructureOperationType);

	static const std::string& getColorOfADS(const Structures::StructureADS);
    static Structures::StructureADS getAdsOfStr(const std::string&);
    static Structures::AllStructureOperationType getAllOpsOfStr(const std::string&);

private:
    static std::map<Structures::StructureADS, std::string> colorsOfADS;
    static std::map<std::string, Structures::StructureADS> adsOfStr;
    static std::map<std::string, Structures::AllStructureOperationType> allOpsOfStr;
};


