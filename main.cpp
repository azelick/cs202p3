// main program
//


#include <iostream>
#include "character.h"
using namespace std;

bool again();
bool another_weapon();
bool another_power();
void compare_weapons();
void compare_powers();
void move_character();
void create_characters_from_user_input();
void create_and_use_a_power();



ostream& operator << (ostream &ostream, const Character &character)
{
    character.display_all();
    return ostream;
};

ostream & operator << (ostream &cout, const Weapon &weap)
{
   weap.display();
   return cout;
}

istream & operator >> (istream &cin, Weapon &weap)
{
    weap.create_weapon();
    return cin;
}

ostream & operator << (ostream &cout, const Power &pow)
{
    pow.display();
    return cout;
}

istream & operator >> (istream &cin, Power &pow)
{
    pow.create_power();
    return cin;
}
int main() { 
    create_characters_from_user_input();
    
       //TODO Here we should use some of the powers
    compare_weapons(); 
    compare_powers();
    move_character();
    create_and_use_a_power();
}

void create_characters_from_user_input()
{
     char *input;
    input = new char[100];
    cout << "Please enter a name for the head character: ";
    cin >> input;
    cin.ignore(100, '\n');

    Character *char_list = new Character(input);
    cout << *char_list;
    
    Character *new_character = NULL;
    do
    {
        //make a new character
        char *input_name;
        input_name = new char[100];
        cout << "Please enter a name for the character: ";
        cin >> input_name;
        cin.ignore(50, '\n');
        new_character = new Character(input_name);
        //give new character weapons
        while(another_weapon())
        { 
            Weapon *weapon = new Weapon();
            cin >> *weapon;
           // weapon->create_weapon();
            *new_character += *weapon;
            delete weapon;
            weapon = NULL;
        }
        
        //give new character powers
        while(another_power())
        {
            Power *power = new Power();
            cin >> *power;
           // power->create_power();
            *new_character += *power;
            delete power;
            power = NULL;
        }
        
        //add character to list of characters
        //This should be done with the copy constructor.
        //Since we are copying, we can delete the memory allocated
        //with new_character before adding a new character
        *char_list += *new_character;
        cout << *char_list;
        delete []input_name;
        input_name = NULL;
        delete new_character;
        new_character = NULL;
    } while(again());

    //cleanup
    delete [] input;   

    char_list->delete_all(char_list);
}

void create_and_use_a_power()
{
    Power *pow = new Power();
    pow->create_power();

    cout << endl << "And here we use the power: " << endl;
    pow->use_power();
}

void select_weapon()
{
    Character *new_character;
    char *input_name;
    input_name = new char[100];
    cout << "Please enter a name for the character: ";
    cin >> input_name;
    cin.ignore(50, '\n');
    new_character = new Character(input_name);

    cout << "Please enter at lease two weapons" << endl;
     while(another_weapon())
    { 
        Weapon *weapon = new Weapon();
        cin >> *weapon;
       // weapon->create_weapon();
        *new_character += *weapon;
        delete weapon;
        weapon = NULL;
    }
     character->set_active_weapon();
     cout << *new_character;





}

void move_character_and_fire_weapon()
{
    //make a new character
        Character *new_character;
        char *input_name;
        input_name = new char[100];
        cout << "Please enter a name for the character: ";
        cin >> input_name;
        cin.ignore(50, '\n');
        new_character = new Character(input_name);
        cout << *new_character;

        cout << endl << "And now the character will move " << endl;
        Location loc_to_move(4, 6);
        //move the character to the new location
        *new_character += loc_to_move;
        cout << *new_character;

        if(new_character->can_fire())
            new_character->fire_weapon();
}

void compare_weapons()
{
    cout << "We are going to compare two Weapons with the relational operators... " << endl;
    //create two powers and use relational operator to compare them
    Weapon *weap1 = new Weapon();
    cin >> *weap1;
    Weapon *weap2 = new Weapon();
    cin >> *weap2;

    if(*weap1 > *weap2)
        cout << "Weap1 is bigger!" << endl;
    else
        cout << "Weap 2 is bigger!" << endl;

    delete weap1;
    delete weap2;
}

void compare_powers()
{
    //create two powers and use relational operator to compare them
    cout << "We are going to compare two Powers with the boolean operators... " << endl;
    Power *pow1= new Power();
    cin >> *pow1;
    Power *pow2= new Power();
    cin >> *pow2;

    if(*pow1 == *pow2)
        cout << "They are the same!" << endl;
    else if(*pow2 != *pow1)
        cout << "They aren't the same!" << endl;
    else
        cout << "We've broke the laws of logic!" << endl;

    delete pow1;
    delete pow2;
}

bool again()
{
    char input;
    cout << "Would you like to enter another Character?: ";
    cin >> input;
    cin.ignore(50, '\n');
    input = tolower(input);
    if(input == 'y')
        return true;
    return false;
}

bool another_weapon()
{
     char input;
    cout << "Would you like to add another weapon to this character?: ";
    cin >> input;
    cin.ignore(50, '\n');
    input = tolower(input);
    if(input == 'y')
        return true;
    return false;
}

bool another_power()
{
     char input;
    cout << "Would you like to add another power to this character?: ";
    cin >> input;
    cin.ignore(50, '\n');
    input = tolower(input);
    if(input == 'y')
        return true;
    return false;
}
