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
	    compare(machine, reg, address, field);
	});
}
#endif
