#ifndef COMMAND_STORE_H
#define COMMAND_STORE_H

#include <utility>

#include "NoOperation.hpp"


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
    std::shared_ptr<NoOperation> noOperation(std::make_shared<NoOperation>());

    std::shared_ptr<LoadA> loadA(std::make_shared<LoadA>());
    std::shared_ptr<Load1> load1(std::make_shared<Load1>());
    std::shared_ptr<Load2> load2(std::make_shared<Load2>());
    std::shared_ptr<Load3> load3(std::make_shared<Load3>());
    std::shared_ptr<Load4> load4(std::make_shared<Load4>());
    std::shared_ptr<Load5> load5(std::make_shared<Load5>());
    std::shared_ptr<Load6> load6(std::make_shared<Load6>());
    std::shared_ptr<LoadX> loadX(std::make_shared<LoadX>());

    std::shared_ptr<StoreA> storeA(std::make_shared<StoreA>());
    std::shared_ptr<Store1> store1(std::make_shared<Store1>());
    std::shared_ptr<Store2> store2(std::make_shared<Store2>());
    std::shared_ptr<Store3> store3(std::make_shared<Store3>());
    std::shared_ptr<Store4> store4(std::make_shared<Store4>());
    std::shared_ptr<Store5> store5(std::make_shared<Store5>());
    std::shared_ptr<Store6> store6(std::make_shared<Store6>());
    std::shared_ptr<StoreX> storeX(std::make_shared<StoreX>());

    std::shared_ptr<EnterA> enterA(std::make_shared<EnterA>());
    std::shared_ptr<Enter1> enter1(std::make_shared<Enter1>());
    std::shared_ptr<Enter2> enter2(std::make_shared<Enter2>());
    std::shared_ptr<Enter3> enter3(std::make_shared<Enter3>());
    std::shared_ptr<Enter4> enter4(std::make_shared<Enter4>());
    std::shared_ptr<Enter5> enter5(std::make_shared<Enter5>());
    std::shared_ptr<Enter6> enter6(std::make_shared<Enter6>());
    std::shared_ptr<EnterX> enterX(std::make_shared<EnterX>());

    std::shared_ptr<Command> lookupCommandByCode(unsigned short code) {
        switch (code) {
            case 0:
                return noOperation;
                break;


            case 8:
                return loadA;
                break;

            case 9:
                return load1;
                break;

            case 10:
                return load2;
                break;

            case 11:
                return load3;
                break;

            case 12:
                return load4;
                break;

            case 13:
                return load5;
                break;

            case 14:
                return load6;
                break;

            case 15:
                return loadX;
                break;


            case 24:
                return storeA;
                break;

            case 25:
                return store1;
                break;

            case 26:
                return store2;
                break;

            case 27:
                return store3;
                break;

            case 28:
                return store4;
                break;

            case 29:
                return store5;
                break;

            case 30:
                return store6;
                break;

            case 31:
                return storeX;
                break;


            case 48:
                return enterA;
                break;

            case 49:
                return enter1;
                break;

            case 50:
                return enter2;
                break;

            case 51:
                return enter3;
                break;

            case 52:
                return enter4;
                break;

            case 53:
                return enter5;
                break;

            case 54:
                return enter6;
                break;

            case 55:
                return enterX;
                break;
        }

        return noOperation;
    }
}

#endif

