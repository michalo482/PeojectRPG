#include <iostream>
#include "playerCharacter.h"

int main() {

	PlayerCharacter pc1(new Wizard());

	


	for (int i = 0; i < 2; i++) {
		std::cout << pc1.getClassName() << '\n'
			<< "-Level: " << pc1.getLevel() << '\n'
			<< "-EXP: " << pc1.getCurrentEXP() << '/' << pc1.getEXPToNextLevel() << '\n'
			<< "-HP: " << pc1.getCurrentHP() << '/' << pc1.getMaxHP() << '\n'
			<< "-Str: " << pc1.getStr() << '\n'
			<< "-Int: " << pc1.getInt() << '\n';
			
		pc1.gainEXP(100u);
	}


	return 0;
}