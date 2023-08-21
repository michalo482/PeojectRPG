#pragma once
#include "statblock.h"
#include "types.h"

struct CoreStats {
	stattype Strenght = 1;
	stattype Intellect = 1;
	stattype Agility = 1;
	stattype Armor = 0;
	stattype ElementalResistance = 0;

	CoreStats& operator+=(const CoreStats& rhs) {
		this->Strenght += rhs.Strenght;
		this->Intellect += rhs.Intellect;
		this->Agility += rhs.Agility;
		this->Armor += rhs.Armor;
		this->ElementalResistance += rhs.ElementalResistance;

		return *this;
	}

	CoreStats& operator-=(const CoreStats& rhs) {


		if (this->Strenght > rhs.Strenght) {
			this->Strenght -= rhs.Strenght;
		}
		else {
			this->Strenght = 0u;
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
		if (this->ElementalResistance > rhs.ElementalResistance) {
			this->ElementalResistance -= rhs.ElementalResistance;
		}
		else {
			this->ElementalResistance = 0u;
		}
		/*this->Strenght -= rhs.Strenght;
		this->Intellect -= rhs.Intellect;
		this->Agility -= rhs.Agility;
		this->Armor -= rhs.Armor;
		this->ElementalResistance -= rhs.ElementalResistance;*/

		return *this;
	}

	CoreStats& operator=(const stattype& rhs) {
		this->Strenght = rhs;
		this->Intellect = rhs;
		this->Agility = rhs;
		this->Armor = rhs;
		this->ElementalResistance = rhs;

		return *this;
	}
};
