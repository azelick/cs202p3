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
        //TODO arg constructor
        Character(char *);
        //destructor
        ~Character();

        //block of overloaded operators
       //=, +=, +, ==, !=, <, <=, >, >=, <<, >> 
       Character operator + (const Weapon &) const;
       Character operator + (const Power &) const;
       Character operator + (const Location &) const;

       Character& operator += (const Character &);
       Character& operator += (const Weapon &);
       Character& operator += (const Power &);
       Character& operator += (const Location &);

       Character& operator = (const Character &);
       
       bool operator == (const Character &) const;
       bool operator != (const Character &) const;

       //Friend to allow this to output our data
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
