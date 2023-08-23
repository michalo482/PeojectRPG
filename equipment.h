#pragma once
#include <string>
#include <typeinfo>
#include "corestats.h"
#include "types.h"

class Equipment {
public:
	//std::string getName() { return Name; }
	//CoreStats getStats() { return Stats; }
	std::string Name;
	CoreStats Stats;

	virtual const char* getEquipmentType() = 0;
private:
	
protected:
	Equipment(std::string n, CoreStats s) : Name(n), Stats(s) {}

};

enum class ARMORSLOTS { HELMET, CHEST, LEGS, BOOTS, GLOVES, RING1, RING2, NECK, NUM_SLOT };
enum class WEAPONTYPES { MELEE, RANGE, NUM_SLOT };

class Armor final : public Equipment {
public:
	Armor() = delete;
	Armor(const Armor&) = delete;
	Armor(const Armor&&) = delete;

	Armor(std::string n, CoreStats s, ARMORSLOTS slt) : Equipment(n, s), Slot(slt) {}

	const char* getEquipmentType() override {
		return typeid(*this).name();
	}

	ARMORSLOTS Slot;

private:
	
};

class Weapon final : public Equipment {
public:
	WEAPONTYPES Slot;
	damagetype MinDamage;
	damagetype MaxDamage;
	bool is2H = false;
	Weapon(std::string n, CoreStats s, WEAPONTYPES wpn, damagetype min, damagetype max, bool is2h = false) : Equipment(n, s), MinDamage(min), MaxDamage(max), Slot(wpn), is2H(is2h) {

	}

	const char* getEquipmentType() override {
		return typeid(*this).name();
	}

	Weapon() = delete;
	Weapon(const Weapon&) = delete;
	Weapon(const Weapon&&) = delete;
private:

};