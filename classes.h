#ifndef DisCivilization_CLASSES_H
#define DisCivilization_CLASSES_H

#include <cstring>

class Hero {
public:
    int bonusDamage = 0;
    int bonusHP = 0;
    void BattleCry();
};

class Knight : public Hero {
private:
    int damage = 50;
    int healthPoints = 10;
public:
    const char* battleCry[3] = {"AVE MARIA, DEUS VULT!", "PRO FIDE!", "GOTT MIT UNS!"};
    void printHealth();
    int attack();
    void Heal();
    void setHealth(int &value);
    int getHealth();
};

class Archer : public Hero {
private:
    int damage = 55;
    int healthPoints = 10;
public:
    void printHealth();
    void Heal();
    void setHealth(int &value);
    int attack();
    int getHealth();
};


#endif //DisCivilization_CLASSES_H
