#pragma once
#include "character.h"

class Thief : public Character
{
protected:
    int throwing_knife_count;
    bool is_invulnerable;

public:
    Thief(const string &name, const string &race, int health, const Weapon &current_weapon);
    void stab(Character &target);
    void throw_knife(Character &target);
    void mirage_step();
    void disable_mirage_step();
    bool get_is_invulnerable();
};