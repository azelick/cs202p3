//Location class
//
//This just holds the coordinates of the character

#include <iostream>
using namespace std;

class Location
{
    public:
        Location();
        //Location(const Location &);
        Location(int x, int y);
        //~Location();
        

        //Block of overloaded operators

        //TODO try to not use these
        //get_x();
        //get_y();

        void display();
        void set_location(const Location &);
        void update_location(const Location &);

    protected:
        int x;
        int y;
};
