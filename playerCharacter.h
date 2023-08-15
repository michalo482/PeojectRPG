#pragma once
#include <cstdint>
#include <memory>
#include <iostream>
#include <string>
#include "statblock.h"
#include "pointwell.h"

typedef std::uint16_t leveltype;
typedef std::uint64_t exptype;

class PlayerCharacterDelegate : public StatBlock {

public:
	static const exptype EXPTOLEVEL2 = 100u;

	PlayerCharacterDelegate() :
		CurrentLevel(1u), CurrentEXP(0u), EXPToNextLevel(EXPTOLEVEL2), StatBlock(0u, 0u) {

		HP = std::make_unique<PointWell>();
	}

	void gainEXP(exptype gainedExp) {
		CurrentEXP += gainedExp;
		while (checkIfLevelUp()) {}
	}

	leveltype getLevel() {
		return CurrentLevel;
	}

	exptype getCurrentEXP() {
		return CurrentEXP;
	}

	exptype getEXPToNextLevel() {
		return EXPToNextLevel;
	}

	virtual void levelUp() = 0;
	virtual std::string getClassName() = 0;

	std::unique_ptr<PointWell> HP;

protected:
	leveltype CurrentLevel;
	exptype CurrentEXP;
	exptype EXPToNextLevel;

	bool checkIfLevelUp() {		
		static const leveltype levelmultipler = 2u;

		if (CurrentEXP >= EXPToNextLevel) {
			CurrentLevel++;
			levelUp();
			EXPToNextLevel *= levelmultipler;
			return true;
		}
		return false;
		
	}
};

#define PCCONSTRUCT : PlayerCharacterDelegate() {\
HP->setMax(BASEHP);\
HP->increase(BASEHP);\
increaseStats(BASESTR, BASEINT);\
}

#define LEVELUP void levelUp() override {\
HP->setMax((welltype)((BASEHP / 2.f) + HP->getMax()));\
HP->increase((welltype)((BASEHP / 2.f)));\
increaseStats(((stattype)((BASESTR + 1u) / 2.f)), (stattype)((BASEINT + 1u) / 2.f));\
}


class Cleric : public PlayerCharacterDelegate {
public:

	static const welltype BASEHP = (welltype)14u;
	static const stattype BASESTR = (stattype)2u;
	static const stattype BASEINT = (stattype)3u;

	
	Cleric() PCCONSTRUCT
	

	std::string getClassName() override {
		return std::string("Cleric");
	}

private:
	LEVELUP
};

class Rogue : public PlayerCharacterDelegate {
public:

	static const welltype BASEHP = (welltype)12u;
	static const stattype BASESTR = (stattype)3u;
	static const stattype BASEINT = (stattype)2u;


	Rogue() PCCONSTRUCT

	std::string getClassName() override {
		return std::string("Rogue");
	}

private:
	LEVELUP
};

class Warrior : public PlayerCharacterDelegate {
public:

	static const welltype BASEHP = (welltype)18u;
	static const stattype BASESTR = (stattype)4u;
	static const stattype BASEINT = (stattype)1u;


	Warrior() PCCONSTRUCT

	std::string getClassName() override {
		return std::string("Warrior");
	}

private:
	LEVELUP
};

class Wizard : public PlayerCharacterDelegate {
public:

	static const welltype BASEHP = (welltype)10u;
	static const stattype BASESTR = (stattype)1u;
	static const stattype BASEINT = (stattype)4u;


	Wizard() PCCONSTRUCT

	std::string getClassName() override {
		return std::string("Wizard");
	}

private:
	LEVELUP
};

class PlayerCharacter {
private:

	PlayerCharacterDelegate* pcclass;

public:
	
	PlayerCharacter() = delete;
	
	PlayerCharacter(PlayerCharacterDelegate* pc) 
		: pcclass(pc) {}

	~PlayerCharacter() { delete pcclass; pcclass = nullptr; }

	std::string getClassName() { return pcclass->getClassName(); }
	leveltype getLevel() { return pcclass->getLevel(); }
	exptype getCurrentEXP() { return pcclass->getCurrentEXP(); }
	exptype getEXPToNextLevel() { return pcclass->getEXPToNextLevel(); }
	welltype getMaxHP() { return pcclass->HP->getMax(); }
	welltype getCurrentHP() { return pcclass->HP->getCurrent(); }
	stattype getStr() { return pcclass->getStr(); }
	stattype getInt() { return pcclass->getInt(); }

	void gainEXP(exptype gained) { pcclass->gainEXP(gained); }
	void takeDamage(welltype damage) { pcclass->HP->reduce(damage); }
	void heal(welltype amt) { pcclass->HP->increase(amt); }

};


