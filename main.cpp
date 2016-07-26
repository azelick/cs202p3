// main program
//
//
//


#include <iostream>
#include "character.h"
using namespace std;

bool again();
bool another_weapon();
bool another_power();

int main() {

    char input[100];
    cout << "Please enter a name for the character: ";
    cin >> input;

    Character *char_list = new Character(input);
    cout << char_list;

 
    do
    {
        //make a new character
        char input[100];
        cout << "Please enter a name for the character: ";
        cin >> input;
        cin.ignore(50, '\n');
        Character *character = new Character(input);
        //give new character weapons
        while(another_weapon())
        { 
            Weapon *weapon = new Weapon();
            weapon->create_weapon();
            *character += *weapon;
        }
        
        //give new character powers
        while(another_power())
        {
            Power *power = new Power();
            power->create_power();
            *character += *power;
        }
        
        //add character to list of characters
        *char_list += *character;
        cout << char_list;
        
    } while(again());

   

    //TODO Implement the delete block. Need to deallocate all the news that are being created.
    char_list->delete_all(char_list);
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
