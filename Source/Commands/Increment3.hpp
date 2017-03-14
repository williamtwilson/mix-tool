#ifndef INCREMENT3_H
#define INCREMENT3_H

#include "Command.hpp"

class Increment3: public Command {
    public:
        Increment3();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif
