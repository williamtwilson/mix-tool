#ifndef LOAD_H
#define LOAD_H

#include "Command.hpp"

template <unsigned short codeT, unsigned short registerLookup>
class Load: public Command {
public:
    Load(std::string &name);

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

template <unsigned short codeT, unsigned short registerLookup>
Load<codeT, registerLookup>::Load(std::string &name): Command(name, codeT) {}

template <unsigned short codeT, unsigned short registerLookup>
void Load<codeT, registerLookup>::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    machine.performOperationOnRegister(registerLookup, [&] (Register &reg) {
	    load(machine, reg, address, field);
	});
}

#endif
