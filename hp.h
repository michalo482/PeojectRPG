#pragma once
#include "hptype.h"

class hp {
public:
	hp() {
		CurrentHP = 1;
		MaxHP = 1;
	}

	hp(hptype mHP) {
		MaxHP = mHP;
		CurrentHP = MaxHP;
	}

	bool setMaxHP(hptype newMaxHP) {
		if (newMaxHP < 1) {
			return false;
		}

		MaxHP = newMaxHP;

		if (CurrentHP > MaxHP){
			CurrentHP = MaxHP;
		}

		return true;
	}

	hptype getMaxHP() {
		return MaxHP;
	}

	hptype getCurrentHP() {
		return CurrentHP;
	}

	void takeDamage(hptype damage) {
		if (damage > CurrentHP) {
			CurrentHP = 0;
			return;
		}

		CurrentHP -= damage;
	}

	void heal(hptype amountHealed) {
		if (amountHealed + CurrentHP > MaxHP) {
			CurrentHP = MaxHP;
			return;
		}

		CurrentHP += amountHealed;
	}

private:
	hptype ShieldHP;
	hptype CurrentHP;
	hptype MaxHP;

};
