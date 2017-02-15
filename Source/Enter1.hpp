#include "Command.hpp"

#ifndef ENTER1_H
#define ENTER1_H

class Enter1: public Command {
    public:
        Enter1();
    void execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) override;
};

#endif

