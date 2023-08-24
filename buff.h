#pragma once
#include <string>
#include "item.h"
#include "types.h"
#include "corestats.h"
#include "statblock.h"


struct Buff {

	Buff(std::string n, uint16_t d = 1, bool is = false, stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0, stattype elemres = 0)
		: Name(n), Duration(d), isDebuff(is) {

		BuffedStats.Strength = s;
		BuffedStats.Intellect = i;
		BuffedStats.Agility = a;
		BuffedStats.Armor = arm;
		BuffedStats.ElementRes = elemres;

	};

	Buff(std::string n, CoreStats cs, uint16_t d = 1, bool is = false)
		: Name(n), Duration(d), isDebuff(is) {

		BuffedStats = cs;
	}
	
	std::string Name;
	uint16_t Duration;

	CoreStats BuffedStats;

	/*stattype Strenght;
	stattype Intellect;
	stattype Agility;
	stattype Armor;
	stattype ElementalResistance;*/

	bool isDebuff;
};
