#ifndef STORE_H
#define STORE_H

#include "Command.hpp"

template <unsigned short codeT, unsigned short registerLookup>
class Store: public Command {
public:
    Store(std::string &name);

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

template <unsigned short codeT, unsigned short registerLookup>
Store<codeT, registerLookup>::Store(std::string &name): Command(name, codeT) {}

template <unsigned short codeT, unsigned short registerLookup>
void Store<codeT, registerLookup>::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    machine.performOperationOnRegister(registerLookup, [&] (Register &reg) {
	    unsigned short f = firstFieldIndex(field);
	    unsigned short l = secondFieldIndex(field);

	    if (address <= 4000) {
		std::shared_ptr<Word> m = machine.lookupMemoryCell(address);
		Word regWord = reg.read();

		if (f == 0) {
		    m->setSign(regWord.sign());
		    f = 1;
		}

		for (int i = l; i >= f; i--) {
		    m->setAt(i, regWord.at(5 - (l - i)));
		}
		machine.incrementCycles(2);
	    }
	    machine.incrementCommandPointer();
	});
}

#endif
