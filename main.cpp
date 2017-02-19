#include "headers.hpp"

int main() {
    unsigned long secondByte = 64;
    unsigned long thirdByte = 64 * 64;
    unsigned long fourthByte = 64 * 64 * 64;
    unsigned long fifthByte = 64 * 64 * 64 * 64;
    unsigned long something = 0 - (60 + (30 * secondByte) + (2 * thirdByte) + (3 * fourthByte) + (4 * fifthByte));

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

    std::unique_ptr<Enter4> enter4(std::make_unique<Enter4>());
    enter4->execute(machine, something - (3 * thirdByte), 0, 2);

    std::unique_ptr<Enter5> enter5(std::make_unique<Enter5>());
    enter5->execute(machine, something - (2 * fifthByte), 0, 2);

    std::unique_ptr<Enter6> enter6(std::make_unique<Enter6>());
    enter6->execute(machine, something - (10 * fifthByte), 0, 2);

    machine->showRegisters();
    machine->showCells(0, 20);
}

