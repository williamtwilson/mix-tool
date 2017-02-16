#include "headers.hpp"

int main() {
    std::shared_ptr<Machine> machine(std::make_shared<Machine>());
    std::shared_ptr<EnterA> enterA(std::make_shared<EnterA>());

    machine->rI1->load(std::make_shared<Word>(2));

    unsigned long something = 0 - (60 + (30 * 64) + (2 * 64 * 64) + (3 * 64 * 64 * 64) + (4 * 64 * 64 * 64 * 64));
    enterA->execute(machine, something, 1, 2);

    std::unique_ptr<Enter1> enter1(new Enter1());
    enter1->execute(machine, something, 0, 2);

    std::cout << machine->rI1->description() << "\n";

    std::shared_ptr<StoreA> storeA(std::make_shared<StoreA>());
    storeA->execute(machine, 0000, 0, Command::fieldForIndexes(2, 4));

    std::cout << machine->rA->description() << "\n";

    std::shared_ptr<Word> newM = machine->lookupMemoryCell(0000);
    std::cout << newM->description() << "\n";
}

