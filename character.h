#include <iostream>
#include "weapon.h"
#include "power.h"
#include "location.h"
#include <cstring>

using namespace std;


class Character
{
    public:
        //default constructor
        Character();
        //copy constructor
        Character(const Character &);
        //arg constructor
        Character(char *);
        //destructor
        ~Character();

        //block of overloaded operators
        //These are the operators required for the class
        //the relational operators live within the weapon
        //and power classes
       //=, +=, +, ==, !=, <, <=, >, >=, <<, >> 
       Character operator + (const Weapon &) const;
       Character operator + (const Power &) const;
       Character operator + (const Location &) const;

       //add a character to the list
       Character& operator += (const Character &);
       //add a weapon to the list of weapons for this character
       Character& operator += (const Weapon &);
       //add a power to the list of power for this character
       Character& operator += (const Power &);
       //add to the location of the character
       Character& operator += (const Location &);

       //assignment to the character
       Character& operator = (const Character &);
       
       //check to see if the name of the character is 
       //the same or not
       bool operator == (const Character &) const;
       bool operator != (const Character &) const;

       //Friend to allow this non-member function to output our data
       friend ostream& operator << (ostream &, const Character &);
        
        //display functions
        //recursive
        void display_all() const;
        void display(const Character *root) const;
        void display() const;
        void display_weapons() const;
        void display_powers() const;

        //add character to the BST
        void add_character(const Character *character);

        //add at end of each LLL
        void add_weapon(const Weapon *weapon);
        void add_power(const Power *power);
        void move(const Location *);
        void set_to_location(const Location *);

        //The compare used for BST
        bool compare_names(const Character *) const;

        //use our active weapons and powers
        bool can_fire();
        void fire_weapon();
        void use_power();

        //query's the user to select from available
        void set_active_power();
        void set_active_weapon();

        //remove list
        void delete_all(Character *&character);

    protected:
        int health;
        char *name;
        //These two are LLL
        Weapon * weaps;
        Power * pwrs;
        //This is just one location.
        Location * location;
        Weapon *active_weapon;

        Character * left;
        Character * right;

        void copy_weapons(const Weapon *head);
        void copy_powers(const Power *head);
        void copy_location(const Location *location);

        void delete_weaps();
        void delete_pwrs();

        //insert a new Character into the list
        //of characters
        void insert(Character *&root, const Character *to_insert);
        
};
