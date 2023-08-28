#pragma once
#include "types.h"


struct CoreStats {
    stattype Strength = 0;
    stattype Intellect = 0;
    stattype Agility = 0;
    stattype Armor = 0;
    stattype ElementRes = 0;

	CoreStats() {
	stattype Strength = 0;
	stattype Intellect = 0;
	stattype Agility = 0;
	stattype Armor = 0;
	stattype ElementRes = 0;
	}

	CoreStats(stattype s, stattype i, stattype ag, stattype arm, stattype eres) 
		: Strength(s), Intellect(i), Agility(ag), Armor(arm), ElementRes(eres) {}


    CoreStats& operator+=(const CoreStats& rhs) {
        this->Strength += rhs.Strength;
        this->Intellect += rhs.Intellect;
        this->Agility += rhs.Agility;
        this->Armor += rhs.Armor;
        this->ElementRes += rhs.ElementRes;
        return *this;
    };

    CoreStats& operator-=(const CoreStats& rhs) {
        CoreStats tmp = *this;


		if (this->Strength > rhs.Strength) {
			this->Strength -= rhs.Strength;
		}
		else {
			this->Strength = 0u;
		}
		if (this->Intellect > rhs.Intellect) {
			this->Intellect -= rhs.Intellect;
		}
		else {
			this->Intellect = 0u;
		}
		if (this->Agility > rhs.Agility) {
			this->Agility -= rhs.Agility;
		}
		else {
			this->Agility = 0u;
		}
		if (this->Armor > rhs.Armor) {
			this->Armor -= rhs.Armor;
		}
		else {
			this->Armor = 0u;
		}
		if (this->ElementRes > rhs.ElementRes) {
			this->ElementRes -= rhs.ElementRes;
		}
		else {
			this->ElementRes = 0u;
		}

        return *this;
    };

    CoreStats& operator=(const stattype& rhs) {
        this->Strength = rhs;
        this->Intellect = rhs;
        this->Agility = rhs;
        this->Armor = rhs;
        this->ElementRes = rhs;
        return *this;
    }
};