// Weekcha1 deadline 9 november
#include <iostream>
#include <cstdlib>
#include <ctime>

class Character {
private:
    std::string name;
    int health;
public:
    Character(const std::string& name, int health) : name(name), health(health) {}

    void attack(Character& enemy, int damage) {
        enemy.health -= damage;
        std::cout << name << " attacks " << enemy.name << " for " << damage << " damage." << std::endl;
    }

    bool isAlive() const {
        return health > 0;
    }

    void displayStatus() const {
        if (health < 0) {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Health: 0" << std::endl;
        }
        else {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Health: " << health << std::endl;
        }
    }

    const std::string& getName() const {
        return name;
    }
};


int rollDice(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::cout << "Enter your character's name(no spaces): ";
    std::string playerName;
    std::cin >> playerName;

    Character player(playerName, 100);
    Character goblin("Goblin", 100);

    bool gameOver = false;
    while (!gameOver) {
        std::cout << "Your turn:" << std::endl;
        std::cout << "1. Fight Back" << std::endl;
        std::cout << "2. Do Nothing" << std::endl;
        std::cout << "3. Give Up" << std::endl;
        std::cout << "Choose an action: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            player.attack(goblin, 10);
            break;
        case 2:
            std::cout << player.getName() << " prepares for the Goblin's attack." << std::endl;
            break;
        case 3:
            std::cout << player.getName() << " admits defeat. Game over." << std::endl;
            gameOver = true;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            continue;
        }

        if (goblin.isAlive()) {
            int goblinDamage = rollDice(5, 50);
            goblin.attack(player, goblinDamage);
        }

        std::cout << std::endl;
        player.displayStatus();
        goblin.displayStatus();

        if (!player.isAlive()) {
            std::cout << player.getName() << " has been defeated. Game over." << std::endl;
            gameOver = true;
        }
        else if (!goblin.isAlive()) {
            std::cout << "Congratulations! You have defeated the Goblin!" << std::endl;
            gameOver = true;
        }
    }

    return 0;
}
