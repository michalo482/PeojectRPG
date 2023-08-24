#pragma once
#include "item.h"
#include <string>

class ItemManager {
public:
	static Item* CreateArmor(std::string n, CoreStats s, ARMORSLOTS slt) {
		Item* temp_item = new Item(new Armor(n, s, slt));
		return temp_item;
	}

	static Item* CreateWeapon(std::string n, CoreStats s, WEAPONTYPES wpn, damagetype min, damagetype max, bool is2h = false) {
		Item* temp_item = new Item(new Weapon(n, s, wpn, min, max, is2h));
		return temp_item;
	}

};