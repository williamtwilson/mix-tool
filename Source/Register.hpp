#ifndef REGISTER_H
#define REGISTER_H

#include <memory>
#include <string>
#include "Word.hpp"

class Register {
public:
    Register();

    long contentsToLong();

    std::string description();
    void load(Word &w);
    Word read();
private:
    Word word;
};

#endif

