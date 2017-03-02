#include "headers.hpp"

int main() {
    std::shared_ptr<Runtime> runtime = std::make_shared<Runtime>();

    CommandStore::enterA->execute(runtime->machine, 623487, 0, 2);
    CommandStore::lookupCommandByCode(0, 0)->execute(runtime->machine, 0, 0, 0);
    CommandStore::noOperation->execute(runtime->machine, 0, 0, 0);
    runtime->machine->showRegisters();
}

