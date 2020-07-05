//MAIN
        // *************************************************************
// main function declaration to run the class funcitons
// DO NOT MODIFY THIS FILE
// **************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "P10.h" 
#include <fstream>

using namespace std;
bool Combat(Character, Character);
int main()
{
    srand(time(NULL));
    ifstream inFile;
    ofstream outFile;
    outFile.open("characters.txt");
    inFile.open("characters.txt");
    int geneboost = 1;
    float height = 70, weight = 200;
    string name, class1;
    string racee;
    char race;
    string bodytype = "what";
    string charactersave;

    cout << "Welcome to THE GAME" << endl;
    cout << "First of all, what is your name?" << endl;
    cin >> name;
    cout << "Input a height from 65 through 84: " << endl;
    cin >> height;
    cout << "Input a weight from 100 through 300: " << endl;
    cin >> weight;
    cout << "What difficulty do you want to play on? 1 for hard and 4 for easy, with 2 and 3 in between" << endl;
    cin >> geneboost;
    cout << "Now " << name << ", You have a choice of the following: " << endl;
    cout << "Classes: Warrior, Archer, Medic, Assassin, Wizard and Mage. What class do you choose?" << endl;
    cin >> class1;
    cout << "Races: Human, Kemononian, Izadon, Ninfa, Taida, Gigutsan. What race?" << endl;
    cin >> racee;
    race = racee.at(0);
    cout << endl;
   
    Character character1(name, race, height, weight, bodytype, class1, geneboost);
    character1.SetStats();
    character1.PrintStats();
    cout << "Do you want to save your character? ";
    cin >> charactersave;
    if (charactersave == "Yes") {
        string newcharactercheck;
        int charactercount = 1;
        getline(inFile, newcharactercheck, '\n');
        cout <<"The first line is "<< newcharactercheck << endl;
        while (newcharactercheck != "") {
            getline(inFile, newcharactercheck);
        }
        outFile << "Character " << charactercount << endl;
        charactercount += 1;
        outFile << character1.charactername << endl;
        outFile << "--------------------------" << endl;
        outFile << "Attack: " << character1.attack << endl;
        outFile << "Defense: " << character1.defense << endl;
        outFile << "Magic: " << character1.magic << endl;
        outFile << "Magic Defense: " << character1.magicdefense << endl;
        outFile << "Health: " << character1.health << endl;
        outFile << "Speed: " << character1.speed << endl;
        outFile << "Dexterity: " << character1.dexterity << endl;
        outFile << "Intelligence: " << character1.intelligence << endl;
        outFile << "Accuracy: " << character1.accuracy << endl;
        outFile << "Endurance: " << character1.endurance << endl;
    }

    Character character3(name, 'K', 80.0, 250, "Null", "Assassin", 4);
    Character character2(name, 'I', 90.0, 100, "Null", "Ninfa", 4);
    Character character5(name, 'N', 80.0, 300, "Null", "Mage", 4);
    Character character4(name, 'H', 80.0, 300, "Null", "Warrior", 4) ;
    cout << endl;
    character2.SetStats();
    character2.PrintStats();
    cout << endl;
    character3.SetStats();
    character3.PrintStats();
    cout << endl;
    character4.SetStats();
    character4.PrintStats();
    cout << endl;
    character5.SetStats();
    character5.PrintStats();
    cout << endl;
   
    Combat(character1, character2);
    Combat(character1, character3);
    Combat(character1, character4);
    Combat(character1, character5);

 
}

bool Combat(Character character1, Character character2) {

    float attack = character1.attack;
    float defense = character1.defense;
    float magicdefense = character1.magicdefense;
    float health = character1.health;
    float speed = character1.speed;
    float magic = character1.magic;
    float dexterity = character1.dexterity;
    float intelligence = character1.intelligence;
    float accuracy = character1.accuracy;
    float endurance = character1.endurance;
    float enemyattack = character2.attack;
    float enemydefense = character2.defense;
    float enemymagicdefense = character2.magicdefense;
    float enemyhealth = character2.health;
    float enemyspeed = character2.speed;
    float enemymagic = character2.magic;
    float enemydexterity = character2.dexterity;
    float enemyintelligence = character2.intelligence;
    float enemyaccuracy = character2.accuracy;
    float enemyendurance = character2.endurance;
    float damage = 0, enemydamage = 0;
    string enemystatus;
    float statuschance = 0, misschance = 0, enemymisschance = 0;
    float statuschancecheck = 0, misschancecheck = 0;
    float critchance = 0;
    float burndamage = 0;
    float originalenemyhealth = 0;

    bool battlestatus = true;
    cout << "A " << character2.nameidentif << " " << character2.classidentif << " attacked you!" << endl;
    int count = 1;
    int count2 = 1;
    enemystatus = "none";
    originalenemyhealth = enemyhealth;
    while (battlestatus == true) {
        cout << endl;
        cout << "Your health is " << health << endl;
        cout << "Enemy health is " << enemyhealth << endl;
        cout << endl;
        
       
        int attackchoice = 1;
        cout << "Press 1 to attack, press 2 for fire magic with a chance to burn, press 3 for water magic" << endl;
        cin >> attackchoice;
        if (speed >= enemyspeed) {


            if (attackchoice == 1) {
                misschance = accuracy / (1.15 * enemydexterity);
                misschancecheck = ((double)rand() / (RAND_MAX));
                cout << "Hit chance is " << misschance << endl;
                if (misschancecheck > misschance) {
                    cout << "Enemy dodged your attack!" << endl;
                    cout << endl;
                }
                else {
                    critchance = accuracy / (9 * enemydefense);
                    cout << "Your crit chance is " << critchance << "!" << endl;
                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    if (statuschancecheck < critchance) {
                        damage = (attack * 50) / enemydefense;
                        damage = 1.5 * damage;
                        cout << "You lunged at your enemy! Critical Hit! " << damage << " damage dealt!" << endl;
                        cout << endl;
                        enemyhealth = enemyhealth - damage;
                    }

                    else {
                        damage = (attack * 50) / enemydefense;
                        cout << "You lunged at your enemy! " << damage << " damage dealt!";
                        cout << endl;
                        enemyhealth = enemyhealth - damage;
                    }
                }


            }

            else if (attackchoice == 2) {
                misschance = accuracy / (1.15 * enemydexterity);
                misschancecheck = ((double)rand() / (RAND_MAX));
                cout << "Hit chance is " << misschance << endl;
                if (misschancecheck > misschance) {
                    cout << "Enemy dodged your attack!" << endl;
                    cout << endl;
                }
                else {
                    critchance = accuracy / (9 * enemymagicdefense);
                    cout << "Your crit chance is " << critchance << "!" << endl;
                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    if (statuschancecheck < critchance) {
                        damage = (magic * 30) / enemymagicdefense;
                        damage = 1.5 * damage;
                        cout << "You cast a fire spell! Critical Hit! " << damage << " damage dealt!" << endl;
                        cout << endl;

                    }

                    else {
                        damage = (magic * 30) / enemymagicdefense;
                        cout << "You cast a fire spell! " << damage << " damage dealt!";
                        cout << endl;
                    }
                    statuschance = (intelligence) / (intelligence + enemyintelligence);
                    cout << "Status chance is " << statuschance << endl;

                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    cout << "Random generated number is " << statuschancecheck << endl;
                    cout << endl;

                    if (statuschance >= statuschancecheck && enemystatus != "burn") {
                        enemystatus = "burn";
                        cout << "Opponent got burned!" << endl;
                        cout << endl;

                    }

                    enemyhealth = enemyhealth - damage;
                }
            }

            else if (attackchoice == 3) {
                misschance = accuracy / (1.15 * enemydexterity);
                misschancecheck = ((double)rand() / (RAND_MAX));
                cout << "Hit chance is " << misschance << endl;
                if (misschancecheck > misschance) {
                    cout << "Enemy dodged your attack!" << endl;
                    cout << endl;
                }

                else {
                    critchance = accuracy / (9 * enemymagicdefense);
                    cout << "Your crit chance is " << critchance << "!" << endl;
                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    if (statuschancecheck < critchance) {
                        damage = (magic * 50) / enemymagicdefense;
                        damage = 1.5 * damage;
                        cout << "You cast a water spell! Critical Hit! " << damage << " damage dealt!" << endl;
                        cout << endl;

                    }
                    else {
                        damage = (magic * 50) / enemymagicdefense;
                        cout << "You cast a water spell! " << damage << " damage dealt!" << endl;
                    }
                    enemyhealth = enemyhealth - damage;
                    cout << endl;
                }
            }
            if (enemyhealth < 0) {
                battlestatus = false;
                cout << endl;
                cout << "You won!" << endl;
                continue;
            }

            if (enemyattack > enemymagic) {
                enemymisschance = enemyaccuracy / (1.15 * dexterity);
                misschancecheck = ((double)rand() / (RAND_MAX));
                cout << "Enemy Hit chance is " << enemymisschance << endl;
                if (misschancecheck > enemymisschance) {
                    cout << "Enemy lunged at you!" << endl;
                    cout << "You dodged your enemy's attack!" << endl;
                    cout << endl;
                }
                else {
                    critchance = enemyaccuracy / (9 * defense);
                    cout << "Enemy crit chance is " << critchance << "!" << endl;
                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    if (statuschancecheck < critchance) {
                        enemydamage = (enemyattack * (50)) / defense;
                        enemydamage = 1.5 * enemydamage;
                        cout << "Enemy lunged at you! Critical Hit! " << damage << " damage dealt!" << endl;
                        cout << endl;
                        health = health - enemydamage;
                    }

                    else {
                        enemydamage = (enemyattack * (50)) / defense;
                        cout << "Enemy dealt " << enemydamage << " damage!" << endl;
                        cout << endl;
                        health = health - enemydamage;
                    }
                }
            }
            else {
                enemymisschance = enemyaccuracy / (1.15 * dexterity);
                misschancecheck = ((double)rand() / (RAND_MAX));
                cout << "Enemy Hit chance is " << enemymisschance << endl;
                if (misschancecheck > enemymisschance) {
                    cout << "Enemy cast a spell at you!" << endl;
                    cout << "You dodged your enemy's attack!" << endl;
                    cout << endl;
                }
                else {
                    critchance = enemyaccuracy / (9 * enemymagicdefense);
                    cout << "Enemy crit chance is " << critchance << "!" << endl;
                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    if (statuschancecheck < critchance) {
                        enemydamage = (enemymagic * (50)) / magicdefense;
                        enemydamage = 1.5 * enemydamage;
                        cout << "Enemy cast a spell! Critical Hit! " << enemydamage << " damage dealt!" << endl;
                        cout << endl;
                        health = health - enemydamage;
                    }

                    else {
                        enemydamage = (enemymagic * (50)) / magicdefense;
                        cout << "Enemy dealt " << enemydamage << " magic damage!" << endl;
                        cout << endl;
                        health = health - enemydamage;
                    }
                }
            }
            if (health < 0) {
                battlestatus = false;
                cout << endl;
                cout << "You died!" << endl;
                cout << endl;
                continue;
            }
            else {
                battlestatus = true;
            }
        }

        else if (enemyspeed > speed) {
        if (enemyattack > enemymagic) {
            enemymisschance = enemyaccuracy / (1.15 * dexterity);
            misschancecheck = ((double)rand() / (RAND_MAX));
            cout << "Enemy Hit chance is " << enemymisschance << endl;
            if (misschancecheck > enemymisschance) {
                cout << "Enemy lunged at you!" << endl;
                cout << "You dodged your enemy's attack!" << endl;
                cout << endl;
            }
            else {
                critchance = enemyaccuracy / (9 * defense);
                cout << "Enemy crit chance is " << critchance << "!" << endl;
                statuschancecheck = ((double)rand() / (RAND_MAX));
                if (statuschancecheck < critchance) {
                    enemydamage = (enemyattack * (50)) / defense;
                    enemydamage = 1.5 * enemydamage;
                    cout << "Enemy lunged at you! Critical Hit! " << damage << " damage dealt!" << endl;
                    cout << endl;
                    health = health - enemydamage;
                }

                else {
                    enemydamage = (enemyattack * (50)) / defense;
                    cout << "Enemy dealt " << enemydamage << " damage!" << endl;
                    cout << endl;
                    health = health - enemydamage;
                }
            }
        }
        else {
            enemymisschance = enemyaccuracy / (1.15 * dexterity);
            misschancecheck = ((double)rand() / (RAND_MAX));
            cout << "Enemy Hit chance is " << enemymisschance << endl;
            if (misschancecheck > enemymisschance) {
                cout << "Enemy cast a spell at you!" << endl;
                cout << "You dodged your enemy's attack!" << endl;
                cout << endl;
            }
            else {
                critchance = enemyaccuracy / (9 * enemymagicdefense);
                cout << "Enemy crit chance is " << critchance << "!" << endl;
                statuschancecheck = ((double)rand() / (RAND_MAX));
                if (statuschancecheck < critchance) {
                    enemydamage = (enemymagic * (50)) / magicdefense;
                    enemydamage = 1.5 * enemydamage;
                    cout << "Enemy cast a spell! Critical Hit! " << enemydamage << " damage dealt!" << endl;
                    cout << endl;
                    health = health - enemydamage;
                }

                else {
                    enemydamage = (enemymagic * (50)) / magicdefense;
                    cout << "Enemy dealt " << enemydamage << " magic damage!" << endl;
                    cout << endl;
                    health = health - enemydamage;
                }
            }
        }

            if (health < 0) {
                battlestatus = false;
                cout << endl;
                cout << "You died!" << endl;
                cout << endl;
                continue;
            }
            else {
                battlestatus = true;
            }

            if (attackchoice == 1) {
                misschance = accuracy / (1.15 * enemydexterity);
                misschancecheck = ((double)rand() / (RAND_MAX));
                cout << "Hit chance is " << misschance << endl;
                if (misschancecheck > misschance) {
                    cout << "Enemy dodged your attack!" << endl;
                    cout << endl;
                }
                else {
                    critchance = accuracy / (9 * enemydefense);
                    cout << "Your crit chance is " << critchance << "!" << endl;
                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    if (statuschancecheck < critchance) {
                        damage = (attack * 50) / enemydefense;
                        damage = 1.5 * damage;
                        cout << "You lunged at your enemy! Critical Hit! " << damage << " damage dealt!" << endl;
                        cout << endl;
                        enemyhealth = enemyhealth - damage;
                    }

                    else {
                        damage = (attack * 50) / enemydefense;
                        cout << "You lunged at your enemy! " << damage << " damage dealt!";
                        cout << endl;
                        enemyhealth = enemyhealth - damage;
                    }
                }


            }

            else if (attackchoice == 2) {
                misschance = accuracy / (1.15 * enemydexterity);
                misschancecheck = ((double)rand() / (RAND_MAX));
                cout << "Hit chance is " << misschance << endl;
                if (misschancecheck > misschance) {
                    cout << "Enemy dodged your attack!" << endl;
                    cout << endl;
                }
                else {
                    critchance = accuracy / (9 * enemymagicdefense);
                    cout << "Your crit chance is " << critchance << "!" << endl;
                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    if (statuschancecheck < critchance) {
                        damage = (magic * 30) / enemymagicdefense;
                        damage = 1.5 * damage;
                        cout << "You cast a fire spell! Critical Hit! " << damage << " damage dealt!" << endl;
                        cout << endl;

                    }

                    else {
                        damage = (magic * 30) / enemymagicdefense;
                        cout << "You cast a fire spell! " << damage << " damage dealt!";
                        cout << endl;
                    }
                    statuschance = (intelligence) / (intelligence + enemyintelligence);
                    cout << "Status chance is " << statuschance << endl;

                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    cout << "Random generated number is " << statuschancecheck << endl;
                    cout << endl;

                    if (statuschance >= statuschancecheck && enemystatus != "burn") {
                        enemystatus = "burn";
                        cout << "Opponent got burned!" << endl;
                        cout << endl;

                    }

                    enemyhealth = enemyhealth - damage;
                }
            }

            else if (attackchoice == 3) {
                misschance = accuracy / (1.15 * enemydexterity);
                misschancecheck = ((double)rand() / (RAND_MAX));
                cout << "Hit chance is " << misschance << endl;
                if (misschancecheck > misschance) {
                    cout << "Enemy dodged your attack!" << endl;
                    cout << endl;
                }

                else {
                    critchance = accuracy / (9 * enemymagicdefense);
                    cout << "Your crit chance is " << critchance << "!" << endl;
                    statuschancecheck = ((double)rand() / (RAND_MAX));
                    if (statuschancecheck < critchance) {
                        damage = (magic * 50) / enemymagicdefense;
                        damage = 1.5 * damage;
                        cout << "You cast a water spell! Critical Hit! " << damage << " damage dealt!" << endl;
                        cout << endl;

                    }
                    else {
                        damage = (magic * 50) / enemymagicdefense;
                        cout << "You cast a water spell! " << damage << " damage dealt!" << endl;
                    }
                    enemyhealth = enemyhealth - damage;
                    cout << endl;
                }

            }
            if (enemystatus == "burn") {
                
                burndamage = ((7 * originalenemyhealth)) / (enemyendurance);
                cout << "The opponent lost " << burndamage << " health from its burn, it's physical attributes remained weakened" << endl;
                enemyhealth = enemyhealth - burndamage;
                cout << "Enemy health is " << enemyhealth << endl;
                cout << endl;
                if (count2 == 1) {
                    enemyattack = 0.75 * enemyattack;
                    enemydefense = 0.75 * enemydefense;
                    count2 -= 1;
                }
            }
            if (enemyhealth < 0) {
                battlestatus = false;
                cout << endl;
                cout << "You won!" << endl;
                continue;
            }
        }
    }

    return 0;
}