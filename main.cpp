#include "headers.hpp"

int main() {
    unsigned long something = 0 - (60 + (30 * 64) + (2 * 64 * 64) + (3 * 64 * 64 * 64) + (4 * 64 * 64 * 64 * 64));

    std::shared_ptr<Machine> machine(std::make_shared<Machine>());

    std::unique_ptr<Enter1> enter1(std::make_unique<Enter1>());
    enter1->execute(machine, something, 0, 2);

    std::unique_ptr<Enter2> enter2(std::make_unique<Enter2>());
    enter2->execute(machine, something - 1, 0, 2);

    std::unique_ptr<Enter3> enter3(std::make_unique<Enter3>());
    enter3->execute(machine, something - 2, 0, 2);

    std::shared_ptr<EnterA> enterA(std::make_shared<EnterA>());
    enterA->execute(machine, something, 1, 2);

    std::shared_ptr<StoreA> storeA(std::make_shared<StoreA>());
    storeA->execute(machine, 0000, 0, Command::fieldForIndexes(2, 4));

    enterA->execute(machine, something, 0, 2);
    storeA->execute(machine, 0001, 0, Command::fieldForIndexes(0, 5));

    std::unique_ptr<LoadA> loadA(std::make_unique<LoadA>());
    loadA->execute(machine, 0001, 0, Command::fieldForIndexes(0, 3));

    std::unique_ptr<LoadX> loadX(std::make_unique<LoadX>());
    loadX->execute(machine, 0001, 0, Command::fieldForIndexes(0, 1));

    machine->showRegisters();
    machine->showCells(0, 20);
}

