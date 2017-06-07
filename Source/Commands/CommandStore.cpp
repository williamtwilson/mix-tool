#include "CommandStore.hpp"

auto CommandStore::noOperation = std::make_shared<NoOperation>();
auto CommandStore::add = std::make_shared<Add>();

std::string CommandStore::loadAName = "LDA";
auto CommandStore::loadA = std::make_shared<Load<9, 7> >(CommandStore::loadAName);
std::string CommandStore::load1Name = "LD1";
auto CommandStore::load1 = std::make_shared<Load<9, 1> >(CommandStore::load1Name);
std::string CommandStore::load2Name = "LD2";
auto CommandStore::load2 = std::make_shared<Load<9, 2> >(CommandStore::load2Name);
std::string CommandStore::load3Name = "LD3";
auto CommandStore::load3 = std::make_shared<Load<9, 3> >(CommandStore::load3Name);
std::string CommandStore::load4Name = "LD4";
auto CommandStore::load4 = std::make_shared<Load<9, 4> >(CommandStore::load4Name);
std::string CommandStore::load5Name = "LD5";
auto CommandStore::load5 = std::make_shared<Load<9, 5> >(CommandStore::load5Name);
std::string CommandStore::load6Name = "LD6";
auto CommandStore::load6 = std::make_shared<Load<9, 6> >(CommandStore::load6Name);
std::string CommandStore::loadXName = "LDX";
auto CommandStore::loadX = std::make_shared<Load<9, 8> >(CommandStore::loadXName);

std::string CommandStore::loadANegativeName = "LDAN";
auto CommandStore::loadANegative = std::make_shared<LoadNegative<16, 7> >(CommandStore::loadANegativeName);
std::string CommandStore::load1NegativeName = "LD1N";
auto CommandStore::load1Negative = std::make_shared<LoadNegative<16, 1> >(CommandStore::load1NegativeName);
std::string CommandStore::load2NegativeName = "LD2N";
auto CommandStore::load2Negative = std::make_shared<LoadNegative<16, 2> >(CommandStore::load2NegativeName);
std::string CommandStore::load3NegativeName = "LD3N";
auto CommandStore::load3Negative = std::make_shared<LoadNegative<16, 3> >(CommandStore::load3NegativeName);
std::string CommandStore::load4NegativeName = "LD4N";
auto CommandStore::load4Negative = std::make_shared<LoadNegative<16, 4> >(CommandStore::load4NegativeName);
std::string CommandStore::load5NegativeName = "LD5N";
auto CommandStore::load5Negative = std::make_shared<LoadNegative<16, 5> >(CommandStore::load5NegativeName);
std::string CommandStore::load6NegativeName = "LD6N";
auto CommandStore::load6Negative = std::make_shared<LoadNegative<16, 6> >(CommandStore::load6NegativeName);
std::string CommandStore::loadXNegativeName = "LDXN";
auto CommandStore::loadXNegative = std::make_shared<LoadNegative<16, 8> >(CommandStore::loadXNegativeName);

std::string CommandStore::storeAName = "STA";
auto CommandStore::storeA = std::make_shared<Store<25, 7> >(CommandStore::storeAName);
std::string CommandStore::store1Name = "ST1";
auto CommandStore::store1 = std::make_shared<Store<25, 1> >(CommandStore::store1Name);
std::string CommandStore::store2Name = "ST2";
auto CommandStore::store2 = std::make_shared<Store<25, 2> >(CommandStore::store2Name);
std::string CommandStore::store3Name = "ST3";
auto CommandStore::store3 = std::make_shared<Store<25, 3> >(CommandStore::store3Name);
std::string CommandStore::store4Name = "ST4";
auto CommandStore::store4 = std::make_shared<Store<25, 4> >(CommandStore::store4Name);
std::string CommandStore::store5Name = "ST5";
auto CommandStore::store5 = std::make_shared<Store<25, 5> >(CommandStore::store5Name);
std::string CommandStore::store6Name = "ST6";
auto CommandStore::store6 = std::make_shared<Store<25, 6> >(CommandStore::store6Name);
std::string CommandStore::storeXName = "STX";
auto CommandStore::storeX = std::make_shared<Store<25, 8> >(CommandStore::storeXName);

auto CommandStore::storeJ = std::make_shared<StoreJ>();
auto CommandStore::storeZero = std::make_shared<StoreZero>();
auto CommandStore::jump = std::make_shared<Jump>();
auto CommandStore::jumpSaveJ = std::make_shared<JumpSaveJ>();
auto CommandStore::jumpOnOverflow = std::make_shared<JumpOnOverflow>();
auto CommandStore::jumpOnNoOverflow = std::make_shared<JumpOnNoOverflow>();

std::string CommandStore::enterAName = "ENTA";
auto CommandStore::enterA = std::make_shared<Enter<48, 7> >(CommandStore::enterAName);
std::string CommandStore::incrementAName = "INCA";
auto CommandStore::incrementA = std::make_shared<Increment<48, 7> >(CommandStore::incrementAName);
std::string CommandStore::enter1Name = "ENT1";
auto CommandStore::enter1 = std::make_shared<Enter<48, 1> >(CommandStore::enter1Name);
std::string CommandStore::increment1Name = "INC1";
auto CommandStore::increment1 = std::make_shared<Increment<48, 1> >(CommandStore::increment1Name);
std::string CommandStore::enter2Name = "ENT2";
auto CommandStore::enter2 = std::make_shared<Enter<48, 2> >(CommandStore::enter2Name);
std::string CommandStore::increment2Name = "INC2";
auto CommandStore::increment2 = std::make_shared<Increment<48, 2> >(CommandStore::increment2Name);
std::string CommandStore::enter3Name = "ENT3";
auto CommandStore::enter3 = std::make_shared<Enter<48, 3> >(CommandStore::enter3Name);
std::string CommandStore::increment3Name = "INC3";
auto CommandStore::increment3 = std::make_shared<Increment<48, 3> >(CommandStore::increment3Name);
std::string CommandStore::enter4Name = "ENT4";
auto CommandStore::enter4 = std::make_shared<Enter<48, 4> >(CommandStore::enter4Name);
std::string CommandStore::increment4Name = "INT4";
auto CommandStore::increment4 = std::make_shared<Increment<48, 4> >(CommandStore::increment4Name);
std::string CommandStore::enter5Name = "ENT5";
auto CommandStore::enter5 = std::make_shared<Enter<48, 5> >(CommandStore::enter5Name);
std::string CommandStore::increment5Name = "INC5";
auto CommandStore::increment5 = std::make_shared<Increment<48, 5> >(CommandStore::increment5Name);
std::string CommandStore::enter6Name = "ENT6";
auto CommandStore::enter6 = std::make_shared<Enter<48, 6> >(CommandStore::enter6Name);
std::string CommandStore::increment6Name = "INC6";
auto CommandStore::increment6 = std::make_shared<Increment<48, 6> >(CommandStore::increment6Name);
std::string CommandStore::enterXName = "ENTX";
auto CommandStore::enterX = std::make_shared<Enter<48, 8> >(CommandStore::enterXName);
std::string CommandStore::incrementXName = "INCX";
auto CommandStore::incrementX = std::make_shared<Increment<48, 8> >(CommandStore::incrementXName);

std::string CommandStore::compareAName = "CMPA";
auto CommandStore::compareA = std::make_shared<Compare<56, 7> >(CommandStore::compareAName);
std::string CommandStore::compare1Name = "CMP1";
auto CommandStore::compare1 = std::make_shared<Compare<56, 1> >(CommandStore::compare1Name);
std::string CommandStore::compare2Name = "CMP2";
auto CommandStore::compare2 = std::make_shared<Compare<56, 2> >(CommandStore::compare2Name);
std::string CommandStore::compare3Name = "CMP3";
auto CommandStore::compare3 = std::make_shared<Compare<56, 3> >(CommandStore::compare3Name);
std::string CommandStore::compare4Name = "CMP4";
auto CommandStore::compare4 = std::make_shared<Compare<56, 4> >(CommandStore::compare4Name);
std::string CommandStore::compare5Name = "CMP5";
auto CommandStore::compare5 = std::make_shared<Compare<56, 5> >(CommandStore::compare5Name);
std::string CommandStore::compare6Name = "CMP6";
auto CommandStore::compare6 = std::make_shared<Compare<56, 6> >(CommandStore::compare6Name);
std::string CommandStore::compareXName = "CMPX";
auto CommandStore::compareX = std::make_shared<Compare<56, 8> >(CommandStore::compareXName);

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

