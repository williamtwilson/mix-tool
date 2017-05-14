#include "Register.hpp"

Register::Register(): word(Word()) {}

std::string Register::description() {
    return word.description();
}

long Register::contentsToLong() {
    return word.toLong();
}

void Register::load(Word &w) {
    word.setSign(w.sign());
    word.setAt(1, w.at(1));
    word.setAt(2, w.at(2));
    word.setAt(3, w.at(3));
    word.setAt(4, w.at(4));
    word.setAt(5, w.at(5));
}

Word Register::read() {
    return word;
}

