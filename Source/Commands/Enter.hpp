#ifndef ENTER_H
#define ENTER_H

#include "Command.hpp"

template <unsigned short codeT, unsigned short registerLookup>
class Enter: public Command {
public:
    Enter(std::string &name);

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short) override;
};

template <unsigned short codeT, unsigned short registerLookup>
Enter<codeT, registerLookup>::Enter(std::string &name): Command(name, codeT) {}

template <unsigned short codeT, unsigned short registerLookup>
void Enter<codeT, registerLookup>::executeAdjusted(Machine &machine, unsigned long address, unsigned short) {
    machine.performOperationOnRegister(registerLookup, [&] (Register &reg) {
	    Word w = Word(address);
	    reg.load(w);
	    machine.incrementCycles(1);
	    machine.incrementCommandPointer();
	});
}

#endif
