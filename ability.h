#pragma once
#include <string>

enum class ABILITYTARGET { SELF, ALLY, ENEMY };
enum class ABILITYSCALER { NONE, STR, AGI, INT };

struct Ability {

	Ability(std::string n, unsigned int c, unsigned int cd, ABILITYTARGET t, ABILITYSCALER s, unsigned int hpe) 
		: name(n), cost(c), cooldown(cd), target(t), scaler(s), hpEffect(hpe) {}

	std::string name = "unnamed";
	unsigned int cost = 0;
	unsigned int cooldown = 1;
	ABILITYTARGET target = ABILITYTARGET::SELF;
	ABILITYSCALER scaler = ABILITYSCALER::NONE;
	unsigned int hpEffect = 1;
};