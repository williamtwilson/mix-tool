#include "CommandStore.hpp"

std::shared_ptr<NoOperation> CommandStore::noOperation = std::make_shared<NoOperation>();
std::shared_ptr<Add> CommandStore::add = std::make_shared<Add>();

std::shared_ptr<LoadA> CommandStore::loadA = std::make_shared<LoadA>();
std::shared_ptr<Load1> CommandStore::load1 = std::make_shared<Load1>();
std::shared_ptr<Load2> CommandStore::load2 = std::make_shared<Load2>();
std::shared_ptr<Load3> CommandStore::load3 = std::make_shared<Load3>();
std::shared_ptr<Load4> CommandStore::load4 = std::make_shared<Load4>();
std::shared_ptr<Load5> CommandStore::load5 = std::make_shared<Load5>();
std::shared_ptr<Load6> CommandStore::load6 = std::make_shared<Load6>();
std::shared_ptr<LoadX> CommandStore::loadX = std::make_shared<LoadX>();

std::shared_ptr<LoadANegative> CommandStore::loadANegative = std::make_shared<LoadANegative>();
std::shared_ptr<Load1Negative> CommandStore::load1Negative = std::make_shared<Load1Negative>();
std::shared_ptr<Load2Negative> CommandStore::load2Negative = std::make_shared<Load2Negative>();
std::shared_ptr<Load3Negative> CommandStore::load3Negative = std::make_shared<Load3Negative>();
std::shared_ptr<Load4Negative> CommandStore::load4Negative = std::make_shared<Load4Negative>();
std::shared_ptr<Load5Negative> CommandStore::load5Negative = std::make_shared<Load5Negative>();
std::shared_ptr<Load6Negative> CommandStore::load6Negative = std::make_shared<Load6Negative>();
std::shared_ptr<LoadXNegative> CommandStore::loadXNegative = std::make_shared<LoadXNegative>();

std::shared_ptr<StoreA> CommandStore::storeA = std::make_shared<StoreA>();
std::shared_ptr<Store1> CommandStore::store1 = std::make_shared<Store1>();
std::shared_ptr<Store2> CommandStore::store2 = std::make_shared<Store2>();
std::shared_ptr<Store3> CommandStore::store3 = std::make_shared<Store3>();
std::shared_ptr<Store4> CommandStore::store4 = std::make_shared<Store4>();
std::shared_ptr<Store5> CommandStore::store5 = std::make_shared<Store5>();
std::shared_ptr<Store6> CommandStore::store6 = std::make_shared<Store6>();
std::shared_ptr<StoreX> CommandStore::storeX = std::make_shared<StoreX>();

std::shared_ptr<StoreJ> CommandStore::storeJ = std::make_shared<StoreJ>();
std::shared_ptr<StoreZero> CommandStore::storeZero = std::make_shared<StoreZero>();
std::shared_ptr<Jump> CommandStore::jump = std::make_shared<Jump>();
std::shared_ptr<JumpSaveJ> CommandStore::jumpSaveJ = std::make_shared<JumpSaveJ>();
std::shared_ptr<JumpOnOverflow> CommandStore::jumpOnOverflow = std::make_shared<JumpOnOverflow>();

std::shared_ptr<EnterA> CommandStore::enterA = std::make_shared<EnterA>();
std::shared_ptr<Enter1> CommandStore::enter1 = std::make_shared<Enter1>();
std::shared_ptr<Enter2> CommandStore::enter2 = std::make_shared<Enter2>();
std::shared_ptr<Enter3> CommandStore::enter3 = std::make_shared<Enter3>();
std::shared_ptr<Enter4> CommandStore::enter4 = std::make_shared<Enter4>();
std::shared_ptr<Enter5> CommandStore::enter5 = std::make_shared<Enter5>();
std::shared_ptr<Enter6> CommandStore::enter6 = std::make_shared<Enter6>();
std::shared_ptr<EnterX> CommandStore::enterX = std::make_shared<EnterX>();

std::shared_ptr<Command> CommandStore::lookupCommandByCode(unsigned short code, unsigned short field) {
    switch (code) {
        case 0:
            return noOperation;
            break;

        case 1:
            return add;
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


        case 16:
            return loadANegative;
            break;

        case 17:
            return load1Negative;
            break;

        case 18:
            return load2Negative;
            break;

        case 19:
            return load3Negative;
            break;

        case 20:
            return load4Negative;
            break;

        case 21:
            return load5Negative;
            break;

        case 22:
            return load6Negative;
            break;

        case 23:
            return loadXNegative;
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


        case 32:
            return storeJ;
            break;

        case 33:
            return storeZero;
            break;

        case 39:
            switch (field) {
                case 0:
                    return jump;
                    break;
                case 1:
                    return jumpSaveJ;
                    break;
                case 2:
                    return jumpOnOverflow;
                    break;
            }
            break;


        case 48:
            switch (field) {
                case 2:
                    return enterA;
                    break;
            }
            break;

        case 49:
            switch (field) {
                case 2:
                    return enter1;
                    break;
            }
            break;

        case 50:
            switch (field) {
                case 2:
                    return enter2;
                    break;
            }
            break;

        case 51:
            switch (field) {
                case 2:
                    return enter3;
                    break;
            }
            break;

        case 52:
            switch (field) {
                case 2:
                    return enter4;
                    break;
            }
            break;

        case 53:
            switch (field) {
                case 2:
                    return enter5;
                    break;
            }
            break;

        case 54:
            switch (field) {
                case 2:
                    return enter6;
                    break;
            }
            break;

        case 55:
            switch (field) {
                case 2:
                    return enterX;
                    break;
            }
            break;
    }
    return noOperation;
}

