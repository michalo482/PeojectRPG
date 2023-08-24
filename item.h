#pragma once
#include "corestats.h"
#include <string>
#include <typeinfo>


class ItemDelegate {
public:
	std::string Name;
	virtual const char* getEquipmentType() = 0;
protected:
	ItemDelegate(std::string name) : Name(name) {}
};

class Item {
public:
	const ItemDelegate* GetData() { return _data; }
	~Item() {
		delete _data;
		_data = nullptr;
	}
private:
	ItemDelegate* _data;
	Item(ItemDelegate* item) : _data(item) {}
	friend class ItemManager;
	friend class PlayerCharacter;
};

class EquipmentDelegate : public ItemDelegate {
public:
	CoreStats Stats;
	const std::uint32_t UniqueId;	
private:

protected:
	EquipmentDelegate(std::string n, CoreStats s);
};

enum class ARMORSLOTS { HELMET, CHEST, LEGS, BOOTS, GLOVES, RING1, RING2, NECK, NUM_SLOT };
enum class WEAPONTYPES { MELEE, RANGE, NUM_SLOT };

class Armor final : public EquipmentDelegate {
public:
	const char* getEquipmentType() override {
		return typeid(*this).name();
	}

	ARMORSLOTS Slot;

private:
	Armor() = delete;
	Armor(const Armor&) = delete;
	Armor(const Armor&&) = delete;

	Armor(std::string n, CoreStats s, ARMORSLOTS slt) : EquipmentDelegate(n, s), Slot(slt) {}

	friend class ItemManager;

};

class Weapon final : public EquipmentDelegate {
public:
	WEAPONTYPES Slot;
	damagetype MinDamage;
	damagetype MaxDamage;
	bool is2H = false;
	

	const char* getEquipmentType() override {
		return typeid(*this).name();
	}

	
private:
	Weapon(std::string n, CoreStats s, WEAPONTYPES wpn, damagetype min, damagetype max, bool is2h = false) : EquipmentDelegate(n, s), MinDamage(min), MaxDamage(max), Slot(wpn), is2H(is2h) {}

	Weapon() = delete;
	Weapon(const Weapon&) = delete;
	Weapon(const Weapon&&) = delete;

	friend class ItemManager;
};

