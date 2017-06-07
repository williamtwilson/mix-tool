#ifndef COMPARE_H
#define COMPARE_H

#include "Command.hpp"

template <unsigned short codeT, unsigned short registerLookup>
class Compare: public Command {
public:
    Compare(std::string &name);

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

template <unsigned short codeT, unsigned short registerLookup>
Compare<codeT, registerLookup>::Compare(std::string &name): Command(name, codeT) {}

template <unsigned short codeT, unsigned short registerLookup>
void Compare<codeT, registerLookup>::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    machine.performOperationOnRegister(registerLookup, [&] (Register &reg) {
	    std::shared_ptr<Word> cell = machine.lookupMemoryCell(address);

	    unsigned short f = firstFieldIndex(field);
	    unsigned short l = secondFieldIndex(field);

	    long rValue = 0;
	    long cellValue = 0;

	    bool setSign = f == 0;

	    if (f == 0) {
		++f;
	    }

	    for (int i = f; i <= l; ++i) {
		rValue *= 64;
		cellValue *= 64;

		rValue += reg.read().at(i);
		cellValue += cell->at(i);
	    }

	    if (setSign && reg.read().sign() == Sign::negative) {
		rValue = 0 - rValue;
	    }

	    if (setSign && cell->sign() == Sign::negative) {
		cellValue = 0 - cellValue;
	    }

	    if (rValue > cellValue) {
		machine.comparisonIndicator = Comparison::greater;
	    } else if (rValue < cellValue) {
		machine.comparisonIndicator = Comparison::less;
	    } else {
		machine.comparisonIndicator = Comparison::equal;
	    }

	    machine.incrementCycles(2);
	    machine.incrementCommandPointer();
	});
}
#endif
