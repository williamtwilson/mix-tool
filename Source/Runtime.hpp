#ifndef RUNTIME_H
#define RUNTIME_H

#include "Machine.hpp"

class Runtime {
    public:
        std::shared_ptr<Machine> machine;

        Runtime();
};

#endif
