//Power class
//using any power will give you a bonus to your
//attack and your health

#include <iostream>
using namespace std;

class Power
{
    public:
        //default constructor
        Power();
        //copy constructor
        Power(const Power &);
        //arg constructor
        Power(char *, int, int);
        //destructor
        ~Power();

        void create_power();
        void use_power();

        void display();
        void display_powers(Power *);
        void copy_powers(Power *&, Power *);
        void delete_pwrs(Power *&);
        void add_at_end(Power *&, const Power &);

        //operator overloading section

    protected:
        char * name;
        int attack_buff;
        int health_buff;

        Power *next;
};
