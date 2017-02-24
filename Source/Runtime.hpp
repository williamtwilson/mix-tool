#ifndef RUNTIME_H
#define RUNTIME_H

#include "Commands/CommandStore.hpp"

class Runtime {
    public:
        std::shared_ptr<Machine> machine;

        Runtime();

        void executeWord(std::shared_ptr<Word>);
};

#endif
