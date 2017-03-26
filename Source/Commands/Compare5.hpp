#ifndef COMPARE5_H
#define COMPARE5_H

#include "Command.hpp"

class Compare5: public Command {
public:
    Compare5();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif
