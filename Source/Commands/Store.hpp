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
	    store(machine, reg, address, field);
	});
}

#endif
