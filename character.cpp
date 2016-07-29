#include "character.h"

Character::Character(): health(20), name(NULL), weaps(NULL), pwrs(NULL), location(NULL), active_weapon(NULL), left(NULL), right(NULL)
{
    location = new Location();
}

Character::Character(const Character & character)
{
    if(!character.name)
        name = NULL; 
    else
    {
        name = new char[strlen(character.name) + 1];
        strcpy(name, character.name);
    }
    //health
    health = character.health;
    //weaps
    copy_weapons(character.weaps);
    //powers
    copy_powers(character.pwrs);
    //location
    if(!location)
        location = new Location();
    copy_location(character.location);

}

Character::Character(char * src_name): health(20), weaps(NULL), pwrs(NULL), location(NULL), active_weapon(NULL), left(NULL), right(NULL)
{

    if(!src_name)
        src_name = NULL; 
    else
    {
        name = new char[strlen(src_name) + 1];
        strcpy(name, src_name);
        location = new Location();
    }
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
    display();
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
   
    if(location)
    {
        cout << "The character is at: " << endl;
        location->display();
        cout << endl;
    }
    if(weaps)
    {
        cout << "The weapons this character has: " << endl;
        weaps->display_weapons(weaps);
    }
    if(pwrs)
    {
        cout << "The powers this character has: " << endl;
        pwrs->display_powers(pwrs);
    }
}

void Character::display_weapons() const
{
    weaps->display_weapons(weaps);
}

void Character::display_powers() const 
{
    pwrs->display_powers(pwrs);
}

void Character::add_character(const Character *to_insert)
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

void Character::add_weapon(const Weapon *weapon)
{
    weaps->add_at_end(weaps, weapon);    
}

void Character::add_power(const Power *power)
{
    pwrs->add_at_end(pwrs, power);
}

void Character::move(const Location *src_location)
{
    location->update_location(src_location);
}

void Character::set_to_location(const Location *src_location)
{
    location->set_location(src_location);
}

void Character::fire_weapon()
{
    if(active_weapon)
        active_weapon->fire_weapon();
    else if(weaps)
        weaps->fire_weapon();
    else
        cout << "No weapon" << endl;
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

void Character::set_active_weapon()
{
    //Whatever active_weapon is pointing at is the active weapon
   weaps->display_weapons(weaps); 
    char * input;
    input = new char[100];
    cout << "What is the name of the weapon you wish to use as active? ";
    cin >> input;
    cin.ignore(100, '\n');
    
    //if string matches weapon in list
    //set ptr to it
    //if it doesn't match, cout error

//TODO
}

void Character::copy_weapons(const Weapon *src_head)
{
    weaps->copy_weapons(weaps, src_head);
}

void Character::copy_powers(const Power *src_head)
{
   pwrs->copy_powers(pwrs, src_head); 
}

void Character::copy_location(const Location *loc)
{
    location->copy(loc);
}

void Character::delete_weaps()
{
    weaps->delete_weaps(weaps);
}

void Character::delete_pwrs()
{
    pwrs->delete_pwrs(pwrs);
}

void Character::insert(Character *&root, const Character *to_insert)
{
    //insertion
    if(!root)
    {
        root = new Character(*to_insert);
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

bool Character::compare_names(const Character *to_compare) const
{
    //we want to return true if to_compare.name is less than 
    // this object's name
    if(strcmp(to_compare->name, name) <= 0)
        return true;
    return false;
}

Character Character::operator + (const Weapon &weapon) const
{
    Character temp(*this);
    temp.add_weapon(&weapon);
    return temp;
}

Character Character::operator + (const Power &power) const
{
    Character temp(*this);
    temp.add_power(&power);
    return temp;
}

Character Character::operator + (const Location &location) const
{
    Character temp(*this);
    temp.move(&location);
    return temp;
}

       
Character& Character::operator += (const Character &character)
{
    //Character *temp = &character;
    add_character(&character);
    return *this;
}

Character& Character::operator += (const Weapon &weapon)
{
    add_weapon(&weapon);
    return *this;
}

Character& Character::operator += (const Power &power)
{
    add_power(&power);
    return *this;
}

Character& Character::operator += (const Location &location)
{
    move(&location);
    return *this;
}

Character& Character::operator = (const Character &character)
{
    if(!(&character == this))
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
    }
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

