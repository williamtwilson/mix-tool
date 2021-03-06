#ifndef RUNTIME_H
#define RUNTIME_H

#include "Commands/CommandStore.hpp"

class Runtime {
public:
    Machine machine;

    Runtime();

    void executeNextCommand();
    void executeWord(std::shared_ptr<Word>);
};

#endif
