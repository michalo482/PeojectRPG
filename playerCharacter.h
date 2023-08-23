#pragma once
#include <cstdint>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include "statblock.h"
#include "pointwell.h"
#include "ability.h"
#include "types.h"
#include "equipment.h"


class PlayerCharacterDelegate : public StatBlock {

public:
	static const exptype EXPTOLEVEL2 = 100u;

	PlayerCharacterDelegate() :
		CurrentLevel(1u), CurrentEXP(0u), EXPToNextLevel(EXPTOLEVEL2), StatBlock(0u, 0u, 0u) {
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

	void applyBuff(Buff b) {
		
		addNewBuff(b);
	}

	virtual void levelUp() = 0;
	virtual std::string getClassName() = 0;

	std::unique_ptr<PointWell> HP;
	std::unique_ptr<PointWell> MP;

	std::vector<Ability> Abilities;

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

#define PCCONSTRUCT \
HP->setMax(BASEHP);\
HP->increase(BASEHP);\
if (MP) {\
 MP->setMax(BASEMP);\
 MP->increase(BASEMP);\
}\
increaseStats(BASESTR, BASEINT, BASEAGI);


#define LEVELUP \
HP->setMax((welltype)((BASEHP / 2.f) + HP->getMax()));\
HP->increase((welltype)((BASEHP / 2.f)));\
if (MP) {\
 MP->setMax((welltype)((BASEMP / 2.f) + MP->getMax()));\
 MP->increase((welltype)((BASEMP / 2.f)));\
}\
increaseStats(((stattype)((BASESTR + 1u) / 2.f)), ((stattype)((BASEINT + 1u) / 2.f)), ((stattype)((BASEAGI + 1u) / 2.f)));


//#define CHARACTERCLASS(classname, basehp, basestr, baseint, baseagi)\
//class classname : public PlayerCharacterDelegate {\
//public:\
//	static const welltype BASEHP = (welltype)basehp;\
//	static const stattype BASESTR = (stattype)basestr;\
//	static const stattype BASEINT = (stattype)baseint;\
//	static const stattype BASEAGI = (stattype)baseagi;\
//	classname() PCCONSTRUCT\
//		std::string getClassName() override {return std::string(#classname);\
//	}\
//private:\
//	LEVELUP\
//};

//CHARACTERCLASS(Cleric, 14, 3, 3, 1);
//CHARACTERCLASS(Rogue, 14, 3, 3, 5);
//CHARACTERCLASS(Warrior, 20, 5, 1, 2);
//CHARACTERCLASS(Wizard, 10, 2, 4, 1);

class Cleric : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)14u;
	static const welltype BASEMP = (welltype)10u;
	static const stattype BASESTR = (stattype)3u;
	static const stattype BASEINT = (stattype)5u;
	static const stattype BASEAGI = (stattype)1u;

	std::string getClassName() override {
		return std::string("Cleric");
	}

	Cleric() : PlayerCharacterDelegate() {
		MP = std::make_unique<PointWell>();

		PCCONSTRUCT
			
		Abilities.emplace_back("Heal", 2u, 1u, ABILITYTARGET::ALLY, ABILITYSCALER::INT, 2u);
	}

private:
	void levelUp() override {
		LEVELUP
			if (CurrentLevel == 2) {
				Abilities.emplace_back("Smite", 2u, 1u, ABILITYTARGET::ENEMY, ABILITYSCALER::INT, 4u);
		}
	}
};

class Wizard : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)10;
	static const welltype BASEMP = (welltype)13;
	static const stattype BASESTR = (stattype)1;
	static const stattype BASEINT = (stattype)6;
	static const stattype BASEAGI = (stattype)2;

	std::string getClassName() override {
		return std::string("Wizard");
	}

	Wizard() : PlayerCharacterDelegate() {
		MP = std::make_unique<PointWell>();

		PCCONSTRUCT

			Abilities.emplace_back("Firebolt", 2u, 1u, ABILITYTARGET::ENEMY, ABILITYSCALER::INT, 4u);
	}

private:
	void levelUp() override {
		LEVELUP
			if (CurrentLevel == 2) {
				Abilities.emplace_back("Icebolt", 3u, 1u, ABILITYTARGET::ENEMY, ABILITYSCALER::INT, 6u);

				increaseStats(0, 1);

				MP->setMax(1u + MP->getMax());
				MP->increase(1u);

			}
	}
};


class Warrior : public PlayerCharacterDelegate {
public:
	static const welltype BASEHP = (welltype)18;
	static const welltype BASEMP = (welltype)0;
	static const stattype BASESTR = (stattype)6;
	static const stattype BASEINT = (stattype)1;
	static const stattype BASEAGI = (stattype)2;

	std::string getClassName() override {
		return std::string("Warrior");
	}

	Warrior() : PlayerCharacterDelegate() {
		//MP = std::make_unique<PointWell>();

		PCCONSTRUCT		
	}

private:
	void levelUp() override {
		LEVELUP
			if (CurrentLevel == 2) {
				Abilities.emplace_back("PowerAttack", 0u, 3u, ABILITYTARGET::ENEMY, ABILITYSCALER::STR, 4u);

			}
	}
};


class PlayerCharacter {
private:

	PlayerCharacterDelegate* pcclass;
	Equipment* EquipedArmors[(unsigned long long)ARMORSLOTS::NUM_SLOT];
	Equipment* EquipedWeapons[(unsigned long long)WEAPONTYPES::NUM_SLOT];

public:
	
	PlayerCharacter() = delete;
	PlayerCharacter(const PlayerCharacter&) = delete;
	PlayerCharacter(const PlayerCharacter&&) = delete;
	
	PlayerCharacter(PlayerCharacterDelegate* pc) 
		: pcclass(pc){

		for (int i = 0; i < (unsigned long long)ARMORSLOTS::NUM_SLOT; i++) {
			EquipedArmors[i] = nullptr;
		}

		for (int i = 0; i < (unsigned long long)WEAPONTYPES::NUM_SLOT; i++) {
			EquipedWeapons[i] = nullptr;
		}
	
	}

	~PlayerCharacter() { 
		delete pcclass;
		pcclass = nullptr;

		for (int i = 0; i < (unsigned long long)ARMORSLOTS::NUM_SLOT; i++) {
			if (EquipedArmors[i]) {
				delete EquipedArmors[i];
				EquipedArmors[i] = nullptr;
			}
		}

		for (int i = 0; i < (unsigned long long)WEAPONTYPES::NUM_SLOT; i++) {
			if (EquipedWeapons[i]) {
				delete EquipedWeapons[i];
				EquipedWeapons[i] = nullptr;
			} 
		}
	}

	std::string getClassName() { return pcclass->getClassName(); }
	leveltype getLevel() { return pcclass->getLevel(); }
	exptype getCurrentEXP() { return pcclass->getCurrentEXP(); }
	exptype getEXPToNextLevel() { return pcclass->getEXPToNextLevel(); }
	welltype getMaxHP() { return pcclass->HP->getMax(); }

	welltype getMaxMP() { 
		if (pcclass->MP)
			return pcclass->MP->getMax();
		else
			return 0;
	}
	welltype getCurrentHP() { return pcclass->HP->getCurrent(); }

	welltype getCurrentMP() { 
		if (pcclass->MP)
			return pcclass->MP->getCurrent();
		else
			return 0;
	}
	stattype getBaseStr() { return pcclass->getBaseStr(); }
	stattype getBaseInt() { return pcclass->getBaseInt(); }
	stattype getBaseAgi() { return pcclass->getBaseAgi(); }
	stattype getBaseArmor() { return pcclass->getBaseArmor(); }
	stattype getBaseElementRes() { return pcclass->getBaseElementRes(); }

	stattype getTotalStr() { return pcclass->getTotalStr() ; }
	stattype getTotalInt() { return pcclass->getTotalInt(); }
	stattype getTotalAgi() { return pcclass->getTotalAgi(); }
	stattype getTotalArmor() { 
		
		stattype armor_from_armor = 0;
		for (int i = 0; i < (unsigned long long)ARMORSLOTS::NUM_SLOT; i++) {
			if (EquipedArmors[i]) {
				armor_from_armor += EquipedArmors[i]->Stats.Armor;
			}
		}
		
		return pcclass->getTotalArmor() + armor_from_armor;
	}
	stattype getTotalElementRes() { 
		
		stattype res_from_armor = 0;
		for (int i = 0; i < (unsigned long long)ARMORSLOTS::NUM_SLOT; i++) {
			if (EquipedArmors[i]) {
				res_from_armor += EquipedArmors[i]->Stats.ElementalResistance;
			}
		}

		return pcclass->getTotalElementRes() + res_from_armor;
	}

	Equipment* getEquipedArmorAt(unsigned long long i) { return EquipedArmors[i]; }
	Equipment* getEquipedWeaponAt(unsigned long long i) { return EquipedWeapons[i]; }

	std::vector<Ability> getAbilities() { return pcclass->Abilities; }

	void gainEXP(exptype gained) { pcclass->gainEXP(gained); }
	void takeDamage(welltype damage) { pcclass->HP->reduce(damage); }
	void heal(welltype amt) { pcclass->HP->increase(amt); }

	void applyBuff(Buff b) { pcclass->applyBuff(b); }

	bool equip(Equipment* equipment) {
		Armor* armor = dynamic_cast<Armor*>(equipment);
		if (armor) {

			unsigned long long arm_slot = (unsigned long long)armor->Slot;
			if (EquipedArmors[arm_slot]) {
				delete EquipedArmors[arm_slot];
				EquipedArmors[arm_slot] = nullptr;
				EquipedArmors[arm_slot] = armor;
			}
			else {
				EquipedArmors[arm_slot] = armor;
			}
			return true;
		}

		Weapon* weapon = dynamic_cast<Weapon*>(equipment);
		if (weapon) {
			unsigned long long wpn_slot = (unsigned long long)weapon->Slot;
			if (EquipedWeapons[wpn_slot]) {
				delete EquipedWeapons[wpn_slot];
				EquipedWeapons[wpn_slot] = nullptr;
				EquipedWeapons[wpn_slot] = weapon;
			}
			else {
				EquipedWeapons[wpn_slot] = weapon;
			}
			return true;
		}
		return false;
	}

};


