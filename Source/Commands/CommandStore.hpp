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
#include "Load1.hpp"
#include "Load2.hpp"
#include "Load3.hpp"
#include "Load4.hpp"
#include "Load5.hpp"
#include "Load6.hpp"
#include "LoadX.hpp"

#include "StoreA.hpp"
#include "Store1.hpp"
#include "Store2.hpp"
#include "Store3.hpp"
#include "Store4.hpp"
#include "Store5.hpp"
#include "Store6.hpp"
#include "StoreX.hpp"

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
    std::unique_ptr<Load1> load1(std::make_unique<Load1>());
    std::unique_ptr<Load2> load2(std::make_unique<Load2>());
    std::unique_ptr<Load3> load3(std::make_unique<Load3>());
    std::unique_ptr<Load4> load4(std::make_unique<Load4>());
    std::unique_ptr<Load5> load5(std::make_unique<Load5>());
    std::unique_ptr<Load6> load6(std::make_unique<Load6>());
    std::unique_ptr<LoadX> loadX(std::make_unique<LoadX>());

    std::unique_ptr<StoreA> storeA(std::make_unique<StoreA>());
    std::unique_ptr<Store1> store1(std::make_unique<Store1>());
    std::unique_ptr<Store2> store2(std::make_unique<Store2>());
    std::unique_ptr<Store3> store3(std::make_unique<Store3>());
    std::unique_ptr<Store4> store4(std::make_unique<Store4>());
    std::unique_ptr<Store5> store5(std::make_unique<Store5>());
    std::unique_ptr<Store6> store6(std::make_unique<Store6>());
    std::unique_ptr<StoreX> storeX(std::make_unique<StoreX>());
}

#endif

