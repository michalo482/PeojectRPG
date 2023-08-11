#include <iostream>
#include "allclasses.h"

int main() {

	Warrior warr1;
	Wizard wiz1;
	Rogue rog1;
	Cleric cler1;

	warr1.takeDamage(10);

	std::cout << "MaxHP: " << warr1.getMaxHP() << "\n" << "CurrHP: " << warr1.getCurrentHP() << "\n" << "Str: " << warr1.getStr() << "\n" << "Int: " << warr1.getInt() << "\n";

	warr1.heal(4);

	std::cout << "MaxHP: " << warr1.getMaxHP() << "\n" << "CurrHP: " << warr1.getCurrentHP() << "\n" << "Str: " << warr1.getStr() << "\n" << "Int: " << warr1.getInt() << "\n";


	for (int i = 0; i < 2; i++) {
		std::cout << "Cleric:\n"
			<< "-MaxHP: " << cler1.getMaxHP() << '\n'
			<< "-Str: " << cler1.getStr() << '\n'
			<< "-Int: " << cler1.getInt() << '\n'
			<< "-Level: " << cler1.GetLevel() << '\n'
			<< "-EXP: " << cler1.GetCurrentEXP() << '\n';

		cler1.gainEXP(1000u);
	}


	return 0;
}