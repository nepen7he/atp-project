#include <iostream>
#include "classes.cpp"

void Greeting();

int main() {

    char mainMenu[6];
    char nickname[100];
    char command[25];

    Archer archers[5] = {Archer(), Archer(), Archer(), Archer(), Archer()};
    Knight knights[5] = {Knight(), Knight(), Knight(), Knight(), Knight()};
    Archer archersEnemy[5] = {Archer(), Archer(), Archer(), Archer(), Archer()};
    Knight knightsEnemy[5] = {Knight(), Knight(), Knight(), Knight(), Knight()};

    std::cout << '\n' << '\n';
    Greeting();
    std::cin >> mainMenu;

    while (true) {
        if (!(strcmp(mainMenu, "QUIT"))) {
            std::cout << "Goodbye, my commaner!";
            return 0;
        } else if (!(strcmp(mainMenu, "START"))) {
            std::cout << "Great. Please. enter your nickname" << '\n';
            std::cin >> nickname;
            break;
        } else {
            std::cout << "Wrong input. Please, try again." << "\n";
        }
    }

    std::cout << nickname << ", you have two armies: knights and archers." << "\n";
    std::cout << "You need to defeat French army" << "\n";

    std::cout << "Options: 'battlecry'(bonusdamage, once), AA(archer to archer), AK(archer to knight)," << " ";
    std::cout << "KA(knight to archer), KK(knight to knight), printhealth(shows healpoints)," << " ";
    std::cout << "heal(to heal army), resign(to resign)" << '\n';

    int archSize = 5;
    int knSize = 5;
    int archEnemySize = 5;
    int knEnemySize = 5;
    int i = 0;

    while ((archSize > 0 || knSize > 0) && (archSize > 0 || knSize > 0)) {
        i = (i + 1) % 3;
        std::cout << "Your orders?" << '\n';

        if (archEnemySize == 0) {
            std::cout << "ALARM! No enemy archers alive, you can't attack them." << '\n';
        } else if (knEnemySize == 0) {
                std::cout << "ALARM! No enemy knights alive, you can't attack them." << '\n';
        }
        if (archSize == 0) {
            std::cout << "ALARM! You have no archers, so, you can't use them." << '\n';
        } else if (knSize == 0) {
            std::cout << "ALARM! You have no knights, so, you can't use them." << '\n';
        }


        std::cin >> command;

        if (!(strcmp(command, "battlecry"))) {
            archers[archSize - 1].BattleCry();
            knights[knSize - 1].BattleCry();
            std::cout << "Army: " << knights[knSize - 1].battleCry[i] << '\n';
        } else if (!(strcmp(command, "AA"))) {
            int damageGiven = archers[archSize - 1].attack();
            int deltaHP = archersEnemy[archEnemySize - 1].getHealth() - damageGiven;
            archersEnemy[archEnemySize - 1].setHealth(deltaHP);
        } else if (!(strcmp(command, "AK"))) {
            int damageGiven = archers[archSize - 1].attack();
            int deltaHP = knightsEnemy[knEnemySize - 1].getHealth() - damageGiven;
            knightsEnemy[knEnemySize - 1].setHealth(deltaHP);
        } else if (!(strcmp(command, "KA"))) {
            int damageGiven = knights[knSize - 1].attack();
            int deltaHP = archersEnemy[archEnemySize - 1].getHealth() - damageGiven;
            archersEnemy[archEnemySize - 1].setHealth(deltaHP);
        } else if (!(strcmp(command, "KK"))) {
            int damageGiven = knights[knSize - 1].attack();
            int deltaHP = knightsEnemy[knEnemySize - 1].getHealth() - damageGiven;
            knightsEnemy[knEnemySize - 1].setHealth(deltaHP);
        } else if (!(strcmp(command, "printhealth"))) {
            std::cout << knights[knSize - 1].getHealth() << " Front knight's health" << '\n';
            std::cout << archers[archSize - 1].getHealth() << " Front archer's health" << '\n';
        } else if (!(strcmp(command, "heal"))) {
            knights[knSize - 1].Heal();
            archers[archSize - 1].Heal();
        } else if (!(strcmp(command, "resign"))) {
            knSize = 0;
            archSize = 0;
        }

        if (archSize > 0) {
            int damageGiven = knights[knSize - 1].attack();
            int deltaHP = archers[archSize - 1].getHealth() - damageGiven;
            archers[archSize - 1].setHealth(deltaHP);
        } else if (knSize > 0) {
            int damageGiven = knights[knSize - 1].attack();
            int deltaHP = knights[knSize - 1].getHealth() - damageGiven;
            knights[knSize - 1].setHealth(deltaHP);
        }

        if (archers[archSize - 1].getHealth() <= 0) {
            archSize -= 1;
        }
        if (knights[knSize - 1].getHealth() <= 0) {
            knSize -= 1;
        }
        if (knightsEnemy[knEnemySize - 1].getHealth() <= 0) {
            knEnemySize -= 1;
        }
        if (archersEnemy[archEnemySize - 1].getHealth() <= 0) {
            archEnemySize -= 1;
        }

    }
    if (archSize = 0 && knSize == 0) {
        std::cout << "Unfortunately, you lost." << '\n';
    } else {
        std::cout << "Congratulations! You won!" << '\n';
    }
    std::cout << "Thanks for playing! Please, support us: 5469-4000-1718-8926, and next update we will add new Hero!" << '\n';
    return 0;
}

void Greeting() {
    std::cout << "Weclome to the DisCivilization v.0.05" << "\n";
    std::cout << "Please, enter 'QUIT' to quit the game or 'START' to start the battle." << "\n";
}