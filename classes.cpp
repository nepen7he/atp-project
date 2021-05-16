#include "classes.h"

int Hero::attack() {
    int newDamage = damage;
    if (bonusDamage > 0) {
        newDamage += bonusDamage;
    }
    return newDamage;
}

void Hero::Heal() {
    healthPoints += 100;
}

void Hero::BattleCry() {
    bonusDamage = 20;
}

void Hero::setHealth(int &value) {
    healthPoints = value;
}

int Hero::getHealth() {
    return healthPoints;
}
