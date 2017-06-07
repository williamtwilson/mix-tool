#ifndef ENTER_H
#define ENTER_H

#include "Command.hpp"

template <unsigned short codeT, unsigned short registerLookup>
class Enter: public Command {
public:
    Enter(std::string &name);

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

template <unsigned short codeT, unsigned short registerLookup>
Enter<codeT, registerLookup>::Enter(std::string &name): Command(name, codeT) {}

template <unsigned short codeT, unsigned short registerLookup>
void Enter<codeT, registerLookup>::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    machine.performOperationOnRegister(registerLookup, [&] (Register &reg) {
	    enter(machine, reg, address);
	});
}

#endif