#pragma once
#include "hp.h"
#include "statblock.h"
#include "levelup.h"

class Wizard : public hp, public StatBlock, public LevelSystem {
public:
	static const hptype HPGROWTH = (hptype)5u;
	static const stattype STRGROWTH = (stattype)1u;
	static const stattype INTGROWTH = (stattype)2u;


	static const hptype BASEHP = (hptype)10u;
	static const stattype BASESTR = (stattype)1u;
	static const stattype BASEINT = (stattype)4u;
	Wizard() : hp(BASEHP), StatBlock(BASESTR, BASEINT) {

	}

private:
	void LevelUp() override {
		setMaxHP(HPGROWTH + getMaxHP());
		increaseStats(STRGROWTH, INTGROWTH);
	}
};