#include "weapon.h"

Weapon::Weapon(): name(NULL), attack_value(0), range(0), next(NULL)
{

}

Weapon::Weapon(const Weapon & weap)
{
    name = new char[strlen(weap.name) + 1];
    strcpy(name, weap.name);
    attack_value = weap.attack_value;
    range = weap.range;
    next = NULL;
}

Weapon::Weapon(char * src_name, int atk_pwr, int rng)
{
    name = new char[strlen(src_name) + 1];
    strcpy(name, src_name);

    attack_value = atk_pwr;
    range = rng;
    next = NULL;
}

Weapon::~Weapon()
{
    if(name)
        delete [] name;
}

void Weapon::create_weapon()
{
    char * input;
    input = new char[100];
    cout << "What is the name of this weapon? ";
    cin >> input;
    cin.ignore(100, '\n');
    name = new char[strlen(input) + 1];
    strcpy(name, input);
    cout << endl;

    cout << "What is the attack value of this weapon? ";
    cin >> attack_value;
    cin.ignore(20, '\n');
    cout << endl;

    cout << "What is the range of this weapon? ";
    cin >> range;
    cin.ignore(20, '\n');
    cout << endl;
    
}


void Weapon::fire_weapon()
{
    cout << "pew pew, this gun fires " << range
        << " for " << attack_value << " damage."
        << endl;
}

void Weapon::display() const 
{
    cout << "The name of this weapon is: " << name << endl;
    cout << "Its attack value is: " << attack_value << endl;
    cout << "Its range is: " << range << endl;
}

void Weapon::copy_weapons(Weapon *&current, const Weapon *src_head)
{
    if(!src_head)
    {
        current = NULL;
        return;
    }
    current = new Weapon(*src_head);
    copy_weapons(current->next, src_head->next);
}


void Weapon::display_weapons(Weapon *current) const
{
    if(!current)
        return;
    current->display();
    display_weapons(current->next);
}

void Weapon::delete_weaps(Weapon *&weapon)
{
    if(!weapon)
        return;
    delete_weaps(weapon->next);
    delete weapon;
    return;
}

void Weapon::add_at_end(Weapon *&current, const Weapon *src_power)
{
    if(!current)
    {
        current = new Weapon(*src_power);
        current->next = NULL;
        return;
    }
    add_at_end(current->next, src_power);
}

bool Weapon::operator> (const Weapon &weap) const
{
    if (attack_value > weap.attack_value)
        return true;
    return false;
}

bool Weapon::operator>= (const Weapon &weap) const
{
    if (attack_value >= weap.attack_value)
        return true;
    return false;
}

bool Weapon::operator< (const Weapon &weap) const
{
    if (attack_value < weap.attack_value)
        return true;
    return false;
}

bool Weapon::operator<= (const Weapon &weap) const
{
    if (attack_value <= weap.attack_value)
        return true;
    return false;
}

bool Weapon::operator==(const Weapon &weap) const
{
    if(attack_value == weap.attack_value)
        return true;
    return false;

}

bool Weapon::operator!=(const Weapon &weap) const
{
    if(attack_value != weap.attack_value)
        return true;
    return false;
}


