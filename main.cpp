#include "headers.hpp"

int main() {
    std::unique_ptr<Machine> machine(new Machine());
    std::unique_ptr<Word> w(new Word(Sign::positive, 1, 2, 3, 4, 5));
    machine->rA->load(w.get());
    std::shared_ptr<Word> w2(machine->rA->read());
    std::cout << w2->description() << "\n";
    std::unique_ptr<EnterA> enterA(new EnterA());
    machine->rI1->load(new Word(2));
    enterA->execute(machine.get(), 2063, 1, 8);
}

