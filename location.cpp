#include "location.h"

Location::Location(): x(0), y(0)
{

}

Location::Location(int src_x, int src_y)
{
    x = src_x;
    y = src_y;
}

void Location::display()
{
    cout << "The location is x: " << x
        << ", y: " << y << endl;
}

