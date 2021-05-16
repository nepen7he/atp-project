#ifndef DisCivilization_CLASSES_H
#define DisCivilization_CLASSES_H

#include <cstring>

class Hero {
public:
    int healthPoints = 10;
    int damage = 50;
    int bonusDamage = 0;
    int bonusHP = 0;
    void BattleCry();
    void Heal();
    int attack();
    void setHealth(int &value);
    int getHealth();
};

class Knight : public Hero {
private:
    int damage = 50;
    int healthPoints = 15;
public:
    const char* battleCry[3] = {"AVE MARIA, DEUS VULT!", "PRO FIDE!", "GOTT MIT UNS!"};
};

class Archer : public Hero {
private:
    int damage = 55;
    int healthPoints = 10;
};


#endif //DisCivilization_CLASSES_H