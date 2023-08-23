#include <iostream>
#include "playerCharacter.h"

int main() {

	PlayerCharacter pc1(new Warrior());

	{
		CoreStats plate_armor_stats;
		plate_armor_stats.Armor = 10;
		plate_armor_stats.ElementalResistance = 5;

		Armor* PlateMail = new Armor("FullPlateArmor", plate_armor_stats, ARMORSLOTS::CHEST);

		if (pc1.equip(PlateMail)) {
			std::cout << "zalozone!\n";
		} 
		else {
			std::cout << "cos sie zepsulo w itemach\n";
		}
	}

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
		std::cout << "-Abilities: \n";

		for (auto& abil : Abilities) {
			std::cout << " - " << abil.name << '\n';
		}
		
		std::cout << "-Armor: \n";

		for (auto i = 0; i < (unsigned long long)ARMORSLOTS::NUM_SLOT; i++) {
			const Armor* tmp = dynamic_cast<Armor*>(pc1.getEquipedArmorAt(i));

			if (tmp) {
				std::cout << " - " << tmp->Name << '\n';
			}
			
		}

		pc1.gainEXP(1000u);

		if (i < 1) {			
			Buff arm_buff("Shield", 10, false, 0, 0, 0, 5, 0);
			pc1.applyBuff(arm_buff);
		}
	}

	return 0;
}