#pragma once
#include "stattype.h"

class StatBlock {
	stattype Strenght;
	stattype Intellect;
public:
	StatBlock() : Strenght(1u), Intellect(1u) {}
	explicit StatBlock(stattype s, stattype i) {
		Strenght = s;
		Intellect = i;
	}

	stattype getStr() { return Strenght; }
	stattype getInt() { return Intellect; }
protected:
	void increaseStats(stattype s, stattype i) {
		Strenght += s;
		Intellect += i;
	}
};
