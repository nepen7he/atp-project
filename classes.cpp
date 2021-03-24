#include "classes.h"

void Archer::Heal() {
    healthPoints += 100;
}

void Knight::Heal() {
    healthPoints += 100;
}

void Knight::printHealth() {
    std::cout << healthPoints;
}

void Archer::printHealth() {
    std::cout << healthPoints;
}

void Hero::BattleCry() {
    bonusDamage = 20;
}

void Archer::setHealth(int &value) {
    healthPoints = value;
}

void Knight::setHealth(int &value) {
    healthPoints = value;
}

int Archer::getHealth() {
    return healthPoints;
}

int Knight::getHealth() {
    return healthPoints;
}

int Archer::attack() {
    int newDamage = damage;
    if (bonusDamage > 0) {
        newDamage += bonusDamage;
    }
    return newDamage;
}

int Knight::attack() {
    int newDamage = damage;
    if (bonusDamage > 0) {
        newDamage += bonusDamage;
    }
    return newDamage;
}