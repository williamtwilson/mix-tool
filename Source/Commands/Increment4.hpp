#ifndef INCREMENT4_H
#define INCREMENT4_H

#include "Command.hpp"

class Increment4: public Command {
public:
    Increment4();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif
