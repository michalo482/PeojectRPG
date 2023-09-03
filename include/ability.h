#pragma once
#include <cstdint>
#include <string>
#include "buff.h"

enum class ABILITYTARGET { SELF, ALLY, ENEMY };
enum class ABILITYSCALER { NONE, STR, AGI, INT };

struct Ability {
    Ability(std::string name = "Unnamed",
        uint32_t hpe = 1u,
        Buff* b = nullptr,
        uint32_t cost = 0u,
        uint32_t cd = 1u,
        ABILITYTARGET t = ABILITYTARGET::SELF,
        ABILITYSCALER s = ABILITYSCALER::NONE);

    ~Ability();

    std::string Name;
    uint32_t HpEffect;
    Buff* GivenBuff;
    uint32_t Cost;      
    uint32_t Cooldown;  
    ABILITYTARGET Target;
    ABILITYSCALER Scaler;
};