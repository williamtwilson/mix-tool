#include "Register.hpp"

Register::Register(): word(new Word()) {}

std::string Register::description() {
    return word->description();
}

long Register::contentsToLong() {
    return word->toLong();
}

void Register::load(Word *w) {
    word->setSign(w->sign());
    word->setAt(0, w->at(0));
    word->setAt(1, w->at(1));
    word->setAt(2, w->at(2));
    word->setAt(3, w->at(3));
    word->setAt(4, w->at(4));
}

std::shared_ptr<Word> Register::read() {
    return word;
}

