#ifndef SIGN_H
#define SIGN_H

#include <string>

enum class Sign {
    positive,
    negative
};

std::string signDescription(Sign);

#endif

