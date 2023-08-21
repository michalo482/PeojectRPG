#include <iostream>
#include "playerCharacter.h"

int main() {

	PlayerCharacter pc1(new Warrior());

	for (int i = 0; i < 2; i++) {
		std::cout << pc1.getClassName() << '\n'
			<< "-Level: " << pc1.getLevel() << '\n'
			<< "-EXP: " << pc1.getCurrentEXP() << '/' << pc1.getEXPToNextLevel() << '\n'
			<< "-HP: " << pc1.getCurrentHP() << '/' << pc1.getMaxHP() << '\n'
			<< "-MP: " << pc1.getCurrentMP() << '/' << pc1.getMaxMP() << '\n'
			<< "-Str: " << pc1.getTotalStr() << '\n'
			<< "-Int: " << pc1.getTotalInt() << '\n'
			<< "-Agi: " << pc1.getTotalAgi() << '\n'
			<< "-Armor: " << pc1.getTotalArmor() << '\n'
			<< "-Elemental Res: " << pc1.getTotalElementRes() << '\n';

		auto Abilities = pc1.getAbilities();
		for (auto& abil : Abilities) {
			std::cout << " - " << abil.name << '\n';
		}

		pc1.gainEXP(1000u);

		if (i < 1) {
			
			Buff arm_buff("Shield", 10, false, 0, 0, 0, 5, 0);
			pc1.applyBuff(arm_buff);
		}
	}

	return 0;
}