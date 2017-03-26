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
std::shared_ptr<JumpOnNoOverflow> CommandStore::jumpOnNoOverflow = std::make_shared<JumpOnNoOverflow>();

std::shared_ptr<EnterA> CommandStore::enterA = std::make_shared<EnterA>();
std::shared_ptr<IncrementA> CommandStore::incrementA = std::make_shared<IncrementA>();
std::shared_ptr<Enter1> CommandStore::enter1 = std::make_shared<Enter1>();
std::shared_ptr<Increment1> CommandStore::increment1 = std::make_shared<Increment1>();
std::shared_ptr<Enter2> CommandStore::enter2 = std::make_shared<Enter2>();
std::shared_ptr<Increment2> CommandStore::increment2 = std::make_shared<Increment2>();
std::shared_ptr<Enter3> CommandStore::enter3 = std::make_shared<Enter3>();
std::shared_ptr<Increment3> CommandStore::increment3 = std::make_shared<Increment3>();
std::shared_ptr<Enter4> CommandStore::enter4 = std::make_shared<Enter4>();
std::shared_ptr<Increment4> CommandStore::increment4 = std::make_shared<Increment4>();
std::shared_ptr<Enter5> CommandStore::enter5 = std::make_shared<Enter5>();
std::shared_ptr<Increment5> CommandStore::increment5 = std::make_shared<Increment5>();
std::shared_ptr<Enter6> CommandStore::enter6 = std::make_shared<Enter6>();
std::shared_ptr<Increment6> CommandStore::increment6 = std::make_shared<Increment6>();
std::shared_ptr<EnterX> CommandStore::enterX = std::make_shared<EnterX>();
std::shared_ptr<IncrementX> CommandStore::incrementX = std::make_shared<IncrementX>();

std::shared_ptr<CompareA> CommandStore::compareA = std::make_shared<CompareA>();
std::shared_ptr<Compare1> CommandStore::compare1 = std::make_shared<Compare1>();
std::shared_ptr<Compare2> CommandStore::compare2 = std::make_shared<Compare2>();
std::shared_ptr<Compare3> CommandStore::compare3 = std::make_shared<Compare3>();
std::shared_ptr<Compare4> CommandStore::compare4 = std::make_shared<Compare4>();
std::shared_ptr<Compare5> CommandStore::compare5 = std::make_shared<Compare5>();
std::shared_ptr<Compare6> CommandStore::compare6 = std::make_shared<Compare6>();
std::shared_ptr<CompareX> CommandStore::compareX = std::make_shared<CompareX>();

std::shared_ptr<Command> CommandStore::lookupCommandByCode(unsigned short code, unsigned short field) {
    switch (code) {
    case 0:
	return noOperation;

    case 1:
	return add;

    case 8:
	return loadA;

    case 9:
	return load1;

    case 10:
	return load2;

    case 11:
	return load3;

    case 12:
	return load4;

    case 13:
	return load5;

    case 14:
	return load6;

    case 15:
	return loadX;

    case 16:
	return loadANegative;

    case 17:
	return load1Negative;

    case 18:
	return load2Negative;

    case 19:
	return load3Negative;

    case 20:
	return load4Negative;

    case 21:
	return load5Negative;

    case 22:
	return load6Negative;

    case 23:
	return loadXNegative;

    case 24:
	return storeA;

    case 25:
	return store1;

    case 26:
	return store2;

    case 27:
	return store3;

    case 28:
	return store4;

    case 29:
	return store5;

    case 30:
	return store6;

    case 31:
	return storeX;
	
    case 32:
	return storeJ;

    case 33:
	return storeZero;

    case 39:
	switch (field) {
	case 0:
	    return jump;
	    
	case 1:
	    return jumpSaveJ;
	    
	case 2:
	    return jumpOnOverflow;
	    
	case 3:
	    return jumpOnNoOverflow;
	}
	
    case 48:
	switch (field) {
	case 0:
	    return incrementA;
	      
	case 2:
	    return enterA;
	}

    case 49:
	switch (field) {
	case 0:
	    return increment1;
	    
	case 2:
	    return enter1;
	}

    case 50:
	switch (field) {
	case 0:
	    return increment2;
	    
	case 2:
	    return enter2;
	}

    case 51:
	switch (field) {
	case 0:
	    return increment3;
	    
	case 2:
	    return enter3;
	}

    case 52:
	switch (field) {
	case 0:
	    return increment4;
	    
	case 2:
	    return enter4;
	}

    case 53:
	switch (field) {
	case 0:
	    return increment5;
	    
	case 2:
	    return enter5;
	}

    case 54:
	switch (field) {
	case 0:
	    return increment6;
	    
	case 2:
	    return enter6;
	}

    case 55:
	switch (field) {
	case 0:
	    return incrementX;
	    
	case 2:
	    return enterX;
	}

    case 56:
	return compareA;

    case 57:
	return compare1;

    case 58:
	return compare2;

    case 59:
	return compare3;

    case 60:
	return compare4;

    case 61:
	return compare5;

    case 62:
	return compare6;

    case 63:
	return compareX;
    }
    return noOperation;
}

