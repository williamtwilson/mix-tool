#include "EnterX.hpp"

EnterX::EnterX(): Command("ENTX", 55) {}

void EnterX::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    std::shared_ptr<Word> w(std::make_shared<Word>(address));
    machine->rX->load(w);
}

