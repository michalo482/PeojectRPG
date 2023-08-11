#pragma once
#include <cstdint>
typedef std::uint16_t leveltype;
typedef std::uint64_t exptype;
class LevelSystem {
public:
	static const exptype EXPTOLEVEL2 = 100u;

	LevelSystem() :
		CurrentLevel(1u), CurrentEXP(0u), EXPToNextLevel(EXPTOLEVEL2) {}

	void gainEXP(exptype gainedExp) {
		CurrentEXP += gainedExp;
		while (checkIfLevelUp()) {}
	}

	leveltype GetLevel() {
		return CurrentLevel;
	}

	exptype GetCurrentEXP() {
		return CurrentEXP;
	}

	exptype GetEXPToNextLevel() {
		return EXPToNextLevel;
	}

	virtual void LevelUp() = 0;

protected:
	leveltype CurrentLevel;
	exptype CurrentEXP;
	exptype EXPToNextLevel;

	bool checkIfLevelUp() {		
		static const leveltype levelmultipler = 2u;

		if (CurrentEXP >= EXPToNextLevel) {
			CurrentLevel++;
			LevelUp();
			EXPToNextLevel *= levelmultipler;
			return true;
		}
		return false;
		
	}
};
