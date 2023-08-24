#include <iostream>
#include "playerCharacter.h"
#include "itemManager.h"

int main() {

	PlayerCharacter pc1(new Warrior());

	{
		CoreStats plate_armor_stats;
		plate_armor_stats.Armor = 10;
		plate_armor_stats.ElementRes = 5;

		Item* PlateMail = ItemManager::CreateArmor("FullPlateArmor", plate_armor_stats, ARMORSLOTS::CHEST);
		if (pc1.equip(PlateMail)) {
			std::cout << "zalozone!\n";
		} 
		else {
			std::cout << "cos sie zepsulo w itemach\n";
		}
	}

	{
		Item* LongSword = ItemManager::CreateWeapon("Long Sword", CoreStats(), WEAPONTYPES::MELEE, 3, 7, false);
		if (pc1.equip(LongSword)) {
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

		auto AllBuffs = pc1.getBuffList();
		std::cout << "-Buffs: \n";
		for (auto& buff : AllBuffs) {
			std::cout << " - " << buff.Name << '\n';
		}
		
		std::cout << "-Armor: \n";

		for (auto i = 0; i < (unsigned long long)ARMORSLOTS::NUM_SLOT; i++) {
			const Armor* tmp = dynamic_cast<Armor*>(pc1.getEquipedArmorAt(i));

			if (tmp) {
				std::cout << " - " << tmp->Name << '\n';
			}
			
		}


		std::cout << "-Weapon: \n";

		for (auto i = 0; i < (unsigned long long)WEAPONTYPES::NUM_SLOT; i++) {
			const Weapon* tmp = dynamic_cast<Weapon*>(pc1.getEquipedWeaponAt(i));

			if (tmp) {
				std::cout << " - " << tmp->Name << '\n';
				std::cout << " - dmg min " << tmp->MinDamage << '\n';
				std::cout << " - dmg " << tmp->MaxDamage << '\n';
				std::cout << " - id " << tmp->UniqueId << '\n';
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