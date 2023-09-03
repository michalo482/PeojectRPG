#pragma once
#include "corestats.h"
#include "item.h"
#include "armor.h"
#include "weapon.h"

class Potion;
class Armor;
class Weapon;
class PlayerCharacter;

class ItemManager {
public:
	static Item* CreateArmor(std::string name, CoreStats cstats, ARMORSLOT slot);

	// out will be nullptr if this cast fails
	static void CastItemToArmor(const Item* in, Armor*& out);

	static bool IsItemArmor(const Item* in);

	static Item* CreateWeapon(std::string name, CoreStats cstats, WEAPONSLOT slot, damagetype min, damagetype max, bool twohanded = false);

	static void CastItemToWeapon(const Item* in, Weapon*& out);

	static bool IsItemWeapon(const Item* in);

	static Item* CreatePotion(std::string name, welltype Heal = 1u, itemcount qaunt = 1u, Buff* _buff = nullptr);

	static void CastItemToPotion(const Item* in, Potion*& out);

	static bool IsItemPotion(const Item* in);

	static bool Equip(Item* item_to_equip, PlayerCharacter* p_char);

	static bool Use(Item* item_to_use, PlayerCharacter* p_char);

	static bool MoveToBackpack(Item* item_to_move, PlayerCharacter* p_char);

	static void DeleteItem(Item*& item_to_delete/*, std::vector<Item*>& pack_to_delete_from*/);
};