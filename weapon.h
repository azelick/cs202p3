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
        void display() const;
        void copy_weapons(Weapon *&, const Weapon *);
        void display_weapons(Weapon *current) const;
        void delete_weaps(Weapon *&weapon);
        void add_at_end(Weapon *&current, const Weapon *src_head);

        //operator overloading section

        //overloaded operators
        friend ostream & operator << (ostream &, const Weapon &);
        friend istream & operator >> (istream &, Weapon &);

        bool operator> (const Weapon &) const;
        bool operator>= (const Weapon &) const;
        bool operator< (const Weapon &) const;
        bool operator<= (const Weapon &) const;
        bool operator==(const Weapon&) const;
        bool operator!=(const Weapon&) const;


    protected:
        char * name;
        int attack_value;
        int range;
        Weapon *next;
};

