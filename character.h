#include <iostream>
#include "weapon.h"
#include "power.h"
#include "location.h"

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
        
        
        //display functions
        void display();
        void display_weapons();
        void display_powers();

        //add at end of each LLL
        void add_weapon(Weapon * weapon);
        void add_power(Power * power);

        //use our active weapons and powers
        void fire_weapon();
        void use_power();

        //query's the user to select from available
        void set_active_power();
        void set_active_weapon();


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

        void copy_weapons(Weapon *&head);
        void copy_powers(Power *&head);

        void delete_weaps(Weapon *&);
        void delete_pwrs(Power *&);

        
};
