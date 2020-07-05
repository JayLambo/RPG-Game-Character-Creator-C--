

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "P10.h"


using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 


// ************** CONSTRUCTORS **************
Character::Character() {
	name = "Grunt";
	race = 'N';
	height = 68;
	weight = 135;
	bodytype = "None";
	class1 = "None";
	geneboost = 0;

};

Character::Character(string name0, char race1, float height2, float weight3, string bodytype4, string class5, int geneboost6) {
	name = name0;
	race = race1;
	height = height2;
	weight = weight3;
	bodytype = bodytype4;
	class1 = class5;
	geneboost = geneboost6;

};


// ************** TRANSFORMERS **************
void Character::SetCharacter(string name0, char race1, float height2, float weight3, string bodytype4, string class5, int geneboost6) {
	race = race1;
	name = name0;
	height = height2;
	weight = weight3;
	bodytype = bodytype4;
	class1 = class5;
	geneboost = geneboost6;
};

void Character::SetStats() {
	float BMI;
	
	charactername = name;
	nameidentif = race;
	classidentif = class1;
	BMI = (weight / (height * height)) * 703;
	if (class1 == "Warrior" || "Assassin") {
		if (BMI > 25)
			BMI = BMI - 4;
	}

	if (race == 'H') {
		attack = 90;
		defense = 90;
		magicdefense = 90;
		health = 95;
		speed = 90;
		magic = 90;
		dexterity = 80;
		intelligence = 80;
		accuracy = 80;
		endurance = 80;

	}

	else if (race == 'K') {
		attack = 110;
		defense = 90;
		magicdefense = 75;
		health = 120;
		speed = 87;
		magic = 64;
		dexterity = 72;
		intelligence = 70;
		accuracy = 80;
		endurance = 98;
	}

	else if (race == 'I') {
		attack = 40;
		defense = 70;
		magicdefense = 102;
		health = 93;
		speed = 101;
		magic = 129;
		dexterity = 90;
		intelligence = 100;
		accuracy = 90;
		endurance = 50;

	}

	else if (race == 'G') {
		attack = 80;
		defense = 122;
		magicdefense = 123;
		health = 90;
		speed = 50;
		magic = 80;
		dexterity = 55;
		intelligence = 120;
		accuracy = 100;
		endurance = 50;

	}

	else if (race == 'T') {
		attack = 63;
		defense = 60;
		magicdefense = 95;
		health = 150;
		speed = 87;
		magic = 75;
		dexterity = 80;
		intelligence = 80;
		accuracy = 80;
		endurance = 85;

	}

	else if (race == 'N') {
		attack = 75;
		defense = 82;
		magicdefense = 83;
		health = 102;
		speed = 97;
		magic = 107;
		dexterity = 95;
		intelligence = 78;
		accuracy = 80;
		endurance = 70;

	}

	if (class1 == "Warrior") {
		attack = attack + 12;
		defense = defense + 5;
		magicdefense = magicdefense - 10;
		health = health + 8;
		speed = speed - 5;
		magic = magic - 10;
		dexterity = dexterity + 5;
		intelligence = intelligence - 7;
		accuracy = accuracy - 2;
		endurance = endurance + 4;

	}

	else if (class1 == "Assassin") {
		attack = attack + 16;
		defense = defense - 7;
		magicdefense = magicdefense - 10;
		health = health + 0;
		speed = speed + 5;
		magic = magic - 4;
		dexterity = dexterity + 7;
		intelligence = intelligence + 0;
		accuracy = accuracy + 3;
		endurance = endurance - 10;
	}

	else if (class1 == "Wizard") {
		attack = attack - 10;
		defense = defense - 5;
		magicdefense = magicdefense + 5;
		health = health - 5;
		speed = speed + 5;
		magic = magic + 10;
		dexterity = dexterity + 2;
		intelligence = intelligence + 3;
		accuracy = accuracy +0;
		endurance = endurance - 5;

	}

	else if (class1 == "Mage") {
		attack = attack - 13;
		defense = defense + 0;
		magicdefense = magicdefense + 10;
		health = health + 5;
		speed = speed - 7;
		magic = magic + 5;
		dexterity = dexterity - 10;
		intelligence = intelligence + 5;
		accuracy = accuracy + 0;
		endurance = endurance + 5;
	}

	else if (class1 == "Archer") {
		attack = attack + 7;
		defense = defense - 3;
		magicdefense = magicdefense + 0;
		health = health + 0;
		speed = speed + 5;
		magic = magic - 10;
		dexterity = dexterity - 5;
		intelligence = intelligence + 0;
		accuracy = accuracy + 14;
		endurance = endurance - 5;
	}
	else if (class1 == "Medic") {
		attack = attack - 11;
		defense = defense + 3;
		magicdefense = magicdefense + 3;
		health = health + 15;
		speed = speed + 0;
		magic = magic - 10;
		dexterity = dexterity - 5;
		intelligence = intelligence + 5;
		accuracy = accuracy - 5;
		endurance = endurance + 5;
	}
	
	if (BMI > 30) {
		bodytype = "Obese";
		attack = attack + 5;
		defense = defense + 5;
		magicdefense = magicdefense + 5;
		health = health + 10;
		speed = speed - 15;
		magic = magic + 0;
		dexterity = dexterity - 10;
		intelligence = intelligence + 0;
		accuracy = accuracy + 5;
		endurance = endurance + 5;

	}

	else if (BMI > 25) {
		bodytype = "Heavy";
		attack = attack + 2;
		defense = defense + 2;
		magicdefense = magicdefense + 1;
		health = health + 10;
		speed = speed - 5;
		magic = magic + 0;
		dexterity = dexterity - 5;
		intelligence = intelligence + 0;
		accuracy = accuracy + 0;
		endurance = endurance + 5;
	}

	else if (BMI > 18) {
		bodytype = "Normal";
		attack = attack + 2;
		defense = defense + 2;
		magicdefense = magicdefense + 2;
		health = health + 2;
		speed = speed + 2;
		magic = magic + 0;
		dexterity = dexterity + 0;
		intelligence = intelligence + 0;
		accuracy = accuracy + 0;
		endurance = endurance + 0;
	}

	else {
		bodytype = "Underweight";
		attack = attack - 0;
		defense = defense - 5;
		magicdefense = magicdefense + 0;
		health = health - 5;
		speed = speed + 15;
		magic = magic + 0;
		dexterity = dexterity + 10;
		intelligence = intelligence + 0;
		accuracy = accuracy + 0;
		endurance = endurance - 5;
	}

	if (geneboost == 1) {
		attack = attack * 1.1;
		defense = defense * 1.1;
		magicdefense = magicdefense * 1.1;
		health = health * 1.1;
		speed = speed * 1.1;
		magic = magic * 1.1;
		dexterity = dexterity * 1.1;
		intelligence = intelligence * 1.1;
		accuracy = accuracy * 1.1;
		endurance = endurance * 1.1;
	}

	else if (geneboost == 2) {
		attack = attack * 1.2;
		defense = defense * 1.2;
		magicdefense = magicdefense * 1.2;
		health = health * 1.2;
		speed = speed * 1.2;
		magic = magic * 1.2;
		dexterity = dexterity * 1.2;
		intelligence = intelligence * 1.2;
		accuracy = accuracy * 1.2;
		endurance = endurance * 1.2;
	}

	else if (geneboost == 3) {
		attack = attack * 1.25;
		defense = defense * 1.25;
		magicdefense = magicdefense * 1.25;
		health = health * 1.25;
		speed = speed * 1.25;
		magic = magic * 1.25;
		dexterity = dexterity * 1.25;
		intelligence = intelligence * 1.25;
		accuracy = accuracy * 1.25;
		endurance = endurance * 1.25;
	}

	else if (geneboost == 4) {
		attack = attack * 1.4;
		defense = defense * 1.4;
		magicdefense = magicdefense * 1.4;
		health = health * 1.4;
		speed = speed * 1.4;
		magic = magic * 1.4;
		dexterity = dexterity * 1.4;
		intelligence = intelligence * 1.4;
		accuracy = accuracy * 1.4;
		endurance = endurance * 1.4;
	}
};
// ************** OBSERVERS *******************
void Character::PrintStats() const {
	float battlerating = 0, overallbattlerating = 0;
	float attackrating = 0;
	float defenserating = 0;
	float magicdefenserating = 0;
	float healthrating = 0;
	float speedrating = 0;
	float magicrating = 0;
	float dexterityrating = 0;
	float intelligencerating = 0;
	float accuracyrating = 0;
	float endurancerating = 0;

	if (class1 == "Warrior") {
		attackrating = 0.5 * attack;
		defenserating = 0.3 * defense;
		magicdefenserating = 0.2 * magicdefense;
		healthrating = 0.35 * health;
		speedrating = 0.2 * speed;
		magicrating = 0.1 * magic;
		dexterityrating = 0.1 * dexterity;
		intelligencerating = 0.05 * intelligence;
		accuracyrating = 0.1 * accuracy;
		endurancerating = 0.1 * endurance;

	}
	else if (class1 == "Assassin") {
		attackrating = 0.5 * attack;
		defenserating = 0.15 * defense;
		magicdefenserating = 0.1 * magicdefense;
		healthrating = 0.15 * health;
		speedrating = 0.55 * speed;
		magicrating = 0.1 * magic;
		dexterityrating = 0.15 * dexterity;
		intelligencerating = 0.1 * intelligence;
		accuracyrating = 0.15 * accuracy;
		endurancerating = 0.05 * endurance;

	}
	else if (class1 == "Wizard") {
		attackrating = 0.1 * attack;
		defenserating = 0.15 * defense;
		magicdefenserating = 0.3 * magicdefense;
		healthrating = 0.2 * health;
		speedrating = 0.35 * speed;
		magicrating = 0.5 * magic;
		dexterityrating = 0.1 * dexterity;
		intelligencerating = 0.15 * intelligence;
		accuracyrating = 0.1 * accuracy;
		endurancerating = 0.05 * endurance;
	}
	else if (class1 == "Mage") {
		attackrating = 0.1 * attack;
		defenserating = 0.25 * defense;
		magicdefenserating = 0.4 * magicdefense;
		healthrating = 0.4 * health;
		speedrating = 0.1 * speed;
		magicrating = 0.4 * magic;
		dexterityrating = 0.05 * dexterity;
		intelligencerating = 0.2 * intelligence;
		accuracyrating = 0.05 * accuracy;
		endurancerating = 0.05 * endurance;
	}

	else if (class1 == "Archer") {
		attackrating = 0.45 * attack;
		defenserating = 0.2 * defense;
		magicdefenserating = 0.2 * magicdefense;
		healthrating = 0.2 * health;
		speedrating = 0.35 * speed;
		magicrating = 0.15 * magic;
		dexterityrating = 0.15 * dexterity;
		intelligencerating = 0.05 * intelligence;
		accuracyrating = 0.2 * accuracy;
		endurancerating = 0.05 * endurance;
	}

	else if (class1 == "Medic") {
		attackrating = 0.1 * attack;
		defenserating = 0.4 * defense;
		magicdefenserating = 0.4 * magicdefense;
		healthrating = 0.55 * health;
		speedrating = 0.1 * speed;
		magicrating = 0.1 * magic;
		dexterityrating = 0.05 * dexterity;
		intelligencerating = 0.2 * intelligence;
		accuracyrating = 0.05 * accuracy;
		endurancerating = 0.05 * endurance;
	}
	battlerating = attackrating + defenserating + magicdefenserating + healthrating + speedrating + magicrating + dexterityrating + intelligencerating+endurancerating+accuracyrating;
	overallbattlerating = (0.2 * attack) + (0.2 * defense) + (0.2 * magicdefense) + (0.2 * health) + (0.2 * speed) +( 0.2 * magic) + (0.1 * dexterity) + (0.1 * intelligence)+(0.1*endurance)+(0.1*accuracy);
	cout << "Body type is "<< bodytype << endl;
	cout << "Race is " << race << endl;
	cout << "Class is " << class1 << endl;
	cout << "Attack is " << attack << endl;
	cout << "Defense is " << defense << endl;
	cout << "Magicdefense is " << magicdefense << endl;
	cout << "Health is " << health << endl;
	cout << "Speed is " << speed << endl;
	cout << "Magic is " << magic << endl;
	cout << "Dexterity is " << dexterity << endl;
	cout << "Intelligence is " << intelligence << endl;
	cout << "Accuracy is " << accuracy << endl;
	cout << "Endurance is " << endurance << endl;
	cout << "Positional battle rating is " << battlerating << endl;
	cout << "Overall battle rating is " << overallbattlerating << endl;
	
}

