#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/* Materials Structure */

typedef struct materials {
    int wood = 1, oak = 2, maple = 3, ash = 4, bronze = 2, iron = 3, steel = 4, mithril = 5, dragon = 6;
};

/* Weapon Structure */

typedef struct weapons {
    int dagger = 2, sword = 3, axe = 4, mace = 5, bow = 3, arrows = 2;
} weapons;

/* Spell Structure */

typedef struct spells {
    int fire = 4, frost = 6, dark = 8, chaos = 10;
} spells;


/* Character Structure */

typedef struct character {
    string name;
    int health = 100, mana = 100, strength, stamina, intellect, weaponAttack, spellAttack, souls = 0;
    spells spell;
    weapons weapon;
    materials material;
} character;

/* Function Declaration */

character characterCreation(string name);
void printInfo(character createChar);

/* Main Function */

int main() {
    string characterName;
    cout << "Please input character name: ";
    cin >> characterName;

    srand(time(NULL));
    character player = characterCreation(characterName);
    printInfo(player);

    system("pause");
    return 0;
}

/* Function Definition */

character characterCreation(string name) {
    character createChar;
    createChar.name = name;
    createChar.strength = rand() % 5 + 5;
    createChar.stamina = rand() % 5 + 5;
    createChar.intellect = rand() % 5 + 5;
    createChar.health += 2 * createChar.stamina;
    createChar.mana += 3 * createChar.intellect;
    createChar.weaponAttack = (createChar.weapon.dagger * createChar.material.bronze) + (2 * createChar.strength);
    createChar.spellAttack = (createChar.spell.fire + (createChar.intellect * 2));
    return createChar;
}

void printInfo(character createChar) {
    cout << createChar.name << endl;
    cout << createChar.health << endl;
    cout << createChar.mana << endl;
    cout << createChar.strength << endl;
    cout << createChar.stamina << endl;
    cout << createChar.intellect << endl;
    cout << createChar.weaponAttack << endl;
    cout << createChar.spellAttack << endl;
    cout << createChar.souls << endl;
}