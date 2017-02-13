#include "headers.hpp"

int main() {
    std::unique_ptr<Machine> machine(new Machine());
    std::unique_ptr<EnterA> enterA(new EnterA());

    machine->rI1->load(new Word(2));

    enterA->execute(machine.get(), 2063, 1, 2);

    std::unique_ptr<EnterX> enterX(new EnterX());
    enterX->execute(machine.get(), 2000, 1, 2);

    std::cout << machine->rA->description() << "\n";
    std::cout << machine->rX->description() << "\n";
}

