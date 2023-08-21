#pragma once
#include <cstdint>
#include <vector>
#include "corestats.h"
#include "types.h"
#include "buff.h"



class StatBlock {
	/*stattype BaseStrenght;
	stattype BaseIntellect;
	stattype BaseAgility;
	stattype BaseArmor;
	stattype BaseElementalResistance;*/

	CoreStats BaseStats;

	/*stattype TotalStrenghtFromBuffs = 0;
	stattype TotalIntellectFromBuffs = 0;
	stattype TotalAgilityFromBuffs = 0;
	stattype TotalArmorFromBuffs = 0;
	stattype TotalElementalResistanceFromBuffs = 0;*/

	CoreStats StatsFromBuffs;

public:
	//StatBlock() : Strenght(1u), Intellect(1u), Agility(1u), Armor(0u), ElementalResistance(0u) {}

	explicit StatBlock(stattype s = 1u, stattype i = 1u, stattype a = 1u, stattype arm = 0u, stattype elemres = 0u) {
		BaseStats.Strenght = s;
		BaseStats.Intellect = i;
		BaseStats.Agility = a;
		BaseStats.Armor = arm;
		BaseStats.ElementalResistance = elemres;
	}

	stattype getBaseStr() { return        BaseStats.Strenght; }
	stattype getBaseInt() { return        BaseStats.Intellect; }
	stattype getBaseAgi() { return        BaseStats.Agility; }
	stattype getBaseArmor() { return      BaseStats.Armor; }
	stattype getBaseElementRes() { return BaseStats.ElementalResistance; }

	stattype getTotalStr() { return        BaseStats.Strenght +            StatsFromBuffs.Strenght; }
	stattype getTotalInt() { return        BaseStats.Intellect +           StatsFromBuffs.Intellect; }
	stattype getTotalAgi() { return        BaseStats.Agility +             StatsFromBuffs.Agility; }
	stattype getTotalArmor() { return      BaseStats.Armor + StatsFromBuffs.Armor; }
	stattype getTotalElementRes() { return BaseStats.ElementalResistance + StatsFromBuffs.ElementalResistance; }

protected:
	void addNewBuff(Buff b) {
		for (auto& buff : Buffs) {
			if (b.Name == buff.Name) {
				buff.Duration = b.Duration;
				return;
			}
		}
		Buffs.push_back(b);
		recalculateBuff();
	}
	std::vector<Buff> Buffs;
	void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0, stattype arm = 0, stattype elemres = 0) {
		BaseStats.Strenght += s;
		BaseStats.Intellect += i;
		BaseStats.Agility += a;
		BaseStats.Armor += arm;
		BaseStats.ElementalResistance += elemres;
	}
	void increaseStats(CoreStats cs) {
		BaseStats += cs;
	}

private:
	void recalculateBuff() {
		/*stattype totalstrenghtfrombuffs = 0;
		stattype totalintellectfrombuffs = 0;
		stattype totalagilityfrombuffs = 0;
		stattype totalarmorfrombuffs = 0;
		stattype totalelementalresistancefrombuffs = 0;*/

		CoreStats tmp;

		for (const auto& b : Buffs) {
			if (b.isDebuff) {
				tmp -= b.BuffedStats;				
			}
			else {
				tmp += b.BuffedStats;
			}
		}

		StatsFromBuffs = tmp;
		
	}
};
