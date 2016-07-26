#include "character.h"

Character::Character(): health(20), name(NULL), weaps(NULL), pwrs(NULL), location(NULL), left(NULL), right(NULL)
{

}

Character::Character(const Character & character)
{
    

}

Character::Character(char * name): health(20), weaps(NULL), pwrs(NULL), location(NULL), left(NULL), right(NULL)
{




}

Character::~Character()
{
    if(weaps)
        weaps->delete_weaps(weaps);
    if(pwrs)
        pwrs->delete_pwrs(pwrs);
    if(location)
        delete location;
    left = NULL;
    right = NULL;

}

void Character::display_all() const 
{
    display(left);
    display(right);
}

void Character::display(const Character *root) const 
{
    if(!root)
        return;
    display(root->left);
    root->display();
    display(root->right);
}

void Character::display() const
{
    cout << "The character is: " << name << endl;
    cout << "They is at: " << health << " health" << endl;
    
    cout << "The character is at: " << endl;
    location->display();
    cout << endl;
    cout << "The weapons this character has: " << endl;
    weaps->display_weapons(weaps);
    cout << "The powers this character has: " << endl;
    pwrs->display_powers(pwrs);

}

void Character::display_weapons() const
{
    weaps->display_weapons(weaps);
}

void Character::display_powers() const 
{
    pwrs->display_powers(pwrs);
}

void Character::add_character(const Character &to_insert)
{
    if(compare_names(to_insert))
    {
        insert(left, to_insert);
    }
    else 
    {
        insert(right, to_insert);
    }
}

void Character::add_weapon(const Weapon &weapon)
{
    weaps->add_at_end(weaps, weapon);    
}

void Character::add_power(const Power &power)
{
    pwrs->add_at_end(pwrs, power);
}

void Character::move(const Location &src_location)
{
    location->update_location(src_location);
}

void Character::set_to_location(const Location &src_location)
{
    //TODO
    location->set_location(src_location);
}

void Character::fire_weapon()
{
    weaps->fire_weapon();
}

void Character::use_power()
{
    pwrs->use_power();
}

void Character::delete_all(Character *&character)
{
    if(!character)
        return;
    delete_all(character->left);
    delete_all(character->right);

    delete character;
}

void Character::set_active_power()
{
    //TODO this isn't required and is more complicated to code

}

void Character::set_active_weapon()
{
    //TODO this isn't required and is more complicated to code
}

void Character::copy_weapons(Weapon *src_head)
{
    weaps->copy_weapons(weaps, src_head);
}

void Character::copy_powers(Power *src_head)
{
   pwrs->copy_powers(pwrs, src_head); 
}

void Character::delete_weaps()
{
    weaps->delete_weaps(weaps);
}

void Character::delete_pwrs()
{
    pwrs->delete_pwrs(pwrs);
}

void Character::insert(Character *&root, const Character &to_insert)
{
    //insertion
    if(!root)
    {
        //TODO marking this that it could be a problem
        //Are we copying the value of the ptr? So should 
        //point to same place...
        *root = to_insert;
        return;
    }
    if(root->compare_names(to_insert))
    {
        insert(root->left, to_insert);
    }
    else 
    {
        insert(root->right, to_insert);
    }
}

bool Character::compare_names(const Character &to_compare) const
{
    //we want to return true if to_compare.name is less than 
    // this object's name
    if(strcmp(to_compare.name, name) <= 0)
        return true;
    return false;
}

Character Character::operator + (const Weapon &weapon) const
{
    Character temp(*this);
    temp.add_weapon(weapon);
    return temp;
    
}

Character Character::operator + (const Power &power) const
{
    Character temp(*this);
    temp.add_power(power);
    return temp;
}

Character Character::operator + (const Location &location) const
{
    Character temp(*this);
    temp.move(location);
    return temp;
}

       
Character& Character::operator += (const Character &character)
{
    add_character(character);
    return *this;
}

Character& Character::operator += (const Weapon &weapon)
{
    add_weapon(weapon);
    return *this;
}

Character& Character::operator += (const Power &power)
{
    add_power(power);
    return *this;
}

Character& Character::operator += (const Location &location)
{
    move(location);
    return *this;

}

Character& Character::operator = (const Character &character)
{
    health = character.health;
    if(name)
        delete [] name;
    name = new char[strlen(character.name) + 1];
    strcpy(name, character.name);
    weaps->delete_weaps(weaps);
    weaps->copy_weapons(weaps, character.weaps);
    pwrs->delete_pwrs(pwrs);
    pwrs->copy_powers(pwrs, character.pwrs);
    delete location;
    location = new Location(*(character.location));
    return *this;    
}

bool Character::operator == (const Character &character) const
{
    if(0 == strcmp(name, character.name))
        return true;
    return false;
}

bool Character::operator != (const Character &character) const
{
    if(0 != strcmp(name, character.name))
        return true;
    return false;
}

//not a member function
ostream& operator << (ostream &ostream, const Character &character)
{
    character.display_all();
    return ostream;
}
