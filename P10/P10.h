// **************************************************************
//HEADER
// Header file for classes
//
#ifndef P10_HEADER
#define P10_HEADER

#include <string>
#include <cstdlib>

using namespace std;




class Character
{
private:
    string name;
    char race;
    float height;
    float weight;
    string bodytype;
    string class1;
    int geneboost;



protected:  // protected members here - none required

public:     // public members here - helper functions
    // ************** constructors
    string charactername;
    float attack, defense, magicdefense, health, speed, magic, dexterity, intelligence, accuracy, endurance;
    char nameidentif;
    string classidentif;
    Character();

    // parameterized constructor - use user provided values
    Character(string name0, char race1, float height2, float weight3, string bodytype4, string class5, int geneboost6);

    //**************  Transformers
    void SetCharacter(string name0, char race1, float height2, float weight3, string bodytype4, string class5, int geneboost6);
    void SetStats();
    //**************  observers

   
    void PrintStats() const;

    
};  
#endif