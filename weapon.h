#include <iostream>
using namespace std;

class Weapon 
{
    public:
        //default constructor
        Weapon();
        //copy constructor
        Weapon(const Weapon &);
        //arg constructor
        Weapon(char *, int, int);
        //destructor
        ~Weapon();

        void create_weapon();
        void fire_weapon();
        void display();
        void copy_weapons(Weapon *&, Weapon *);
        void display_weapons(Weapon *current);
        void delete_weaps(Weapon *&weapon);
        void add_at_end(Weapon *&to_add, Weapon *&current);

        //operator overloading section



    protected:
        char * name;
        int attack_value;
        int range;
        Weapon *next;
};

