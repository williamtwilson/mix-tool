#include "headers.hpp"

int main() {
    std::unique_ptr<Machine> machine(new Machine());
    std::unique_ptr<EnterA> enterA(new EnterA());

    machine->rI1->load(new Word(2));

    unsigned long something = 60 + (30 * 64) + (2 * 64 * 64) + (3 * 64 * 64 * 64) + (4 * 64 * 64 * 64 * 64);
    enterA->execute(machine.get(), something, 1, 2);

    std::unique_ptr<StoreA> storeA(new StoreA());
    storeA->execute(machine.get(), 0000, 0, 5);

    std::cout << machine->rA->description() << "\n";

    std::shared_ptr<Word> newM = machine->lookupMemoryCell(0000);
    std::cout << newM->description() << "\n";
}

