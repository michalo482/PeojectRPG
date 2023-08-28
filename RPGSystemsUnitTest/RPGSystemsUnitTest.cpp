#include "pch.h"
#include "CppUnitTest.h"
#include "playerCharacter.h"
#include "itemManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RPGSystemsUnitTest
{
	TEST_CLASS(RPGSystemsUnitTest)
	{
	public:
		
		TEST_METHOD(WarriorTest)
		{
			PlayerCharacter pc1(new Warrior());
			Assert::AreEqual((welltype)Warrior::BASEHP, pc1.getMaxHP());
			welltype maxHp = pc1.getMaxHP();
			pc1.gainEXP(100u);
			Assert::AreEqual((leveltype)2, pc1.getLevel());
			Assert::AreEqual((std::string)"PowerAttack", pc1.getAbilityList().front().Name);
			Assert::AreEqual((welltype)((Warrior::BASEHP / 2.f) + maxHp), pc1.getMaxHP());
		}

		TEST_METHOD(EquipTest) {
			PlayerCharacter rogue(new Rogue());
			Assert::IsTrue(ItemManager::Equip(ItemManager::CreateWeapon("Dagger", CoreStats(), WEAPONSLOT::MELEE, 3, 7), &rogue));
			Assert::IsNotNull(rogue.getEquippedWeaponAt((unsigned long long)WEAPONSLOT::MELEE));
			Assert::IsFalse(ItemManager::Equip(ItemManager::CreatePotion("ArmorPot", 0, 1, new Buff("ArmorBuff", CoreStats(0, 0, 0, 10, 0), 4)), &rogue));

		}
	};
}
