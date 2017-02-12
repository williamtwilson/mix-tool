#include <string>
#ifndef SIGN_H
#define SIGN_H

enum class Sign {
    positive,
    negative
};

std::string signDescription(Sign);

#endif

