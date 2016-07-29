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

        void display() const;
        void display_powers(const Power *) const;
        void copy_powers(Power *&, const Power *);
        void delete_pwrs(Power *&);
        void add_at_end(Power *&, const Power *);

        //overloaded operators
        friend ostream & operator << (ostream &, const Power &);
        friend istream & operator >> (istream &, Power &);

        bool operator> (const Power &) const;
        bool operator>= (const Power &) const;
        bool operator< (const Power &) const;
        bool operator<= (const Power &) const;
        bool operator==(const Power &) const;
        bool operator!=(const Power &) const;

    protected:
        char * name;
        int attack_buff;
        int health_buff;

        Power *next;
};
