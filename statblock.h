#pragma once
#include <cstdint>

typedef std::uint16_t stattype;

class StatBlock {
	stattype Strenght;
	stattype Intellect;
	stattype Agility;
	stattype Armor;
	stattype ElementalResistance;

public:
	//StatBlock() : Strenght(1u), Intellect(1u), Agility(1u), Armor(0u), ElementalResistance(0u) {}

	explicit StatBlock(stattype s = 1u, stattype i = 1u, stattype a = 1u, stattype arm = 0u, stattype elemres = 0u) : Strenght(s), Intellect(i), Agility(a), Armor(arm), ElementalResistance(elemres) {}

	stattype getStr() { return Strenght; }
	stattype getInt() { return Intellect; }
	stattype getAgi() { return Agility; }
	stattype getArmor() { return Armor; }
	stattype getElementRes() { return ElementalResistance; }

protected:
	void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0, stattype elemres = 0) {
		Strenght += s;
		Intellect += i;
		Agility += a;
		Armor += arm;
		ElementalResistance += elemres;
	}
};
