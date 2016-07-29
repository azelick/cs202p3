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
    cout << "x: " << x
        << ", y: " << y << endl;
}

void Location::set_location(const Location *src_location)
{
    x = src_location->x;
    y = src_location->y;
}


void Location::update_location(const Location *src_location)
{
    x += src_location->x;
    y += src_location->y;
} 

void Location::copy(const Location *loc)
{
    x = loc->x;
    y = loc->y;
}

