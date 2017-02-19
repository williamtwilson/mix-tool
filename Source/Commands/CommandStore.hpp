#ifndef COMMAND_STORE_H
#define COMMAND_STORE_H

#include "EnterA.hpp"
#include "Enter1.hpp"
#include "Enter2.hpp"
#include "Enter3.hpp"
#include "Enter4.hpp"
#include "Enter5.hpp"
#include "Enter6.hpp"
#include "EnterX.hpp"

#include "LoadA.hpp"
#include "LoadX.hpp"

#include "StoreA.hpp"

namespace CommandStore {
    std::unique_ptr<EnterA> enterA(std::make_unique<EnterA>());
    std::unique_ptr<Enter1> enter1(std::make_unique<Enter1>());
    std::unique_ptr<Enter2> enter2(std::make_unique<Enter2>());
    std::unique_ptr<Enter3> enter3(std::make_unique<Enter3>());
    std::unique_ptr<Enter4> enter4(std::make_unique<Enter4>());
    std::unique_ptr<Enter5> enter5(std::make_unique<Enter5>());
    std::unique_ptr<Enter6> enter6(std::make_unique<Enter6>());
    std::unique_ptr<EnterX> enterX(std::make_unique<EnterX>());

    std::unique_ptr<LoadA> loadA(std::make_unique<LoadA>());
    std::unique_ptr<LoadX> loadX(std::make_unique<LoadX>());

    std::unique_ptr<StoreA> storeA(std::make_unique<StoreA>());
}

#endif

