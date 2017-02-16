#include "EnterX.hpp"

EnterX::EnterX(): Command("ENTX", 55) {}

void EnterX::execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field) {
    unsigned long aAddress = adjustedAddress(machine, address, index);

    std::shared_ptr<Word> w(std::make_shared<Word>(aAddress));
    machine->rX->load(w);
}

