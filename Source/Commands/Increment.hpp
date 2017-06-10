#ifndef INCREMENT_H
#define INCREMENT_H

#include "Command.hpp"

template <unsigned short codeT, unsigned short registerLookup>
class Increment: public Command {
public:
    Increment(std::string &name);

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short) override;
};

template <unsigned short codeT, unsigned short registerLookup>
Increment<codeT, registerLookup>::Increment(std::string &name): Command(name, codeT) {}

template <unsigned short codeT, unsigned short registerLookup>
void Increment<codeT, registerLookup>::executeAdjusted(Machine &machine, unsigned long address, unsigned short) {
    machine.performOperationOnRegister(registerLookup, [&] (Register &reg) {
	    long sum = reg.contentsToLong() + address;
	    long fifthPower = 64 * 64 * 64 * 64 * 64;

	    if (sum > fifthPower) {
		machine.overflowToggle = Overflow::on;
		Word newValue = Word(sum % fifthPower);
		reg.load(newValue);
	    } else {
		Word newValue = Word(sum);
		reg.load(newValue);
	    }

	    machine.incrementCycles(1);
	    machine.incrementCommandPointer();
	});
}

#endif
