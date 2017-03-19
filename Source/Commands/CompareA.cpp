#include "CompareA.hpp"

CompareA::CompareA(): Command("CMPA", 56) {}

void CompareA::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    std::shared_ptr<Word> cell = machine->lookupMemoryCell(address);

    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    long aValue = 0;
    long cellValue = 0;

    bool setSign = f == 0;
    
    if (f == 0) {
	++f;
    }
    
    for (int i = f; i <= l; ++i) {
	aValue *= 64;
	cellValue *= 64;

	aValue += machine->rA->read()->at(i);
	cellValue += cell->at(i);
    }

    if (setSign && machine->rA->read()->sign() == Sign::negative) {
	aValue = 0 - aValue;
    }

    if (setSign && cell->sign() == Sign::negative) {
	cellValue = 0 - cellValue;
    }
    
    if (aValue > cellValue) {
	machine->comparisonIndicator = Comparison::greater;
    } else if (aValue < cellValue) {
	machine->comparisonIndicator = Comparison::less;
    } else {
	machine->comparisonIndicator = Comparison::equal;
    }

    machine->incrementCycles(2);
    machine->incrementCommandPointer();
}
