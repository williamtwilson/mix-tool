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
	    loadNegative(machine, reg, address, field);
	});
}

#endif
