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
			<< "-Str: " << pc1.getStr() << '\n'
			<< "-Int: " << pc1.getInt() << '\n'
			<< "-Agi: " << pc1.getAgi() << '\n'
			<< "-Armor: " << pc1.getArmor() << '\n'
			<< "-Elemental Res: " << pc1.getElementRes() << '\n';

		auto Abilities = pc1.getAbilities();
		for (auto& abil : Abilities) {
			std::cout << " - " << abil.name << '\n';
		}
			
		pc1.gainEXP(100u);
	}


	return 0;
}