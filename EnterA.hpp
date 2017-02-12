#include "Command.hpp"

#ifndef ENTERA_H
#define ENTERA_H

class EnterA: public Command {
    public:
        EnterA();
        void execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) override;
};

#endif
