#include "Sign.hpp"

std::string signDescription(Sign sign) {
    if (sign == Sign::positive) {
        return "+";
    } else {
        return "-";
    }
}

