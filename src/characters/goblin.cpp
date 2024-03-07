#include "../../header/goblin.h"


Goblin::Goblin(const string &name, const string &race, int health, const Weapon &current_weapon):Character(name, race, health, current_weapon)
{
}
void Goblin::attack(Character &target)
{
    int dmg_amount = current_weapon.damage;
    int target_new_health = target.get_health() - dmg_amount;
    target.set_health(target_new_health);
}