#ifndef LOAD_NEGATIVE_H
#define LOAD_NEGATIVE_H

#include "Command.hpp"

template <unsigned short codeT, unsigned short registerLookup>
class LoadNegative: public Command {
public:
    LoadNegative(std::string &name);

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

template <unsigned short codeT, unsigned short registerLookup>
LoadNegative<codeT, registerLookup>::LoadNegative(std::string &name): Command(name, codeT) {}

template <unsigned short codeT, unsigned short registerLookup>
void LoadNegative<codeT, registerLookup>::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    machine.performOperationOnRegister(registerLookup, [&] (Register &reg) {
	    unsigned short f = firstFieldIndex(field);
	    unsigned short l = secondFieldIndex(field);

	    if (address <= 4000) {
		std::shared_ptr<Word> m = machine.lookupMemoryCell(address);

		Word tmp = Word();

		if (f == 0) {
		    if (m->sign() == Sign::positive) {
			tmp.setSign(Sign::negative);
		    } else {
			tmp.setSign(Sign::positive);
		    }
		    f = 1;
		}

		for (int i = 5; l >= f; i--, l--) {
		    tmp.setAt(i, m->at(l));
		}

		reg.load(tmp);
		machine.incrementCycles(2);
	    }
	    machine.incrementCommandPointer();
	});
}

#endif
