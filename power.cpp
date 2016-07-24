#include "power.h"

Power::Power(): name(NULL), attack_buff(0), health_buff(0), next(NULL)
{
}

Power::Power(const Power &pwr)
{
    name = new char[strlen(pwr.name) + 1];
    strcpy(name, pwr.name);
    attack_buff = pwr.attack_buff;
    health_buff = pwr.health_buff;
    next = NULL;
}

Power::Power(char * src_name, int atk_buf, int hth_buf)
{

    name = new char[strlen(src_name) + 1];
    strcpy(name, src_name);
    
    attack_buff = atk_buf;
    health_buff = hth_buf;
    next = NULL;
}

Power::~Power()
{
    if(name)
        delete [] name;
}

void Power::create_power()
{
    char input[100];
    cout << "What is the name of this power? ";
    cin >> input;
    cin.ignore(100, '\n');
    name = new char[strlen(input) + 1];
    strcpy(name, input);
    cout << endl;

    cout << "What is the attack buff value of this power? ";
    cin >> attack_buff;
    cin.ignore(20, '\n');
    cout << endl;

    cout << "What is the health buff value of this power? ";
    cin >> health_buff;
    cin.ignore(20, '\n');
    cout << endl;

}

void Power::use_power()
{
    cout << "Imma chargin this player's health " << health_buff << " and " << endl
        << "Imma chargin this player's attack " << attack_buff << endl;
}

void Power::display()
{
    //TODO 
}

void Power::copy_powers(Power *&current, Power *src_head)
{
    if(!src_head)
    {
        current = NULL;
        return;
    }
    current = new Power(*src_head);
    copy_powers(current->next, src_head->next);
}

void Power::display_powers(Power *current)
{
    if(!current)
        return;
    current->display();
    display_powers(current->next);
}

void Power::delete_pwrs(Power *&power)
{
    if(!power)
        return;
    delete_pwrs(power->next);
    delete power;
    return;
}

void Power::add_at_end(Power *&current, const Power &src_power)
{
    if(!current)
        return;
    if(!current->next)
    {
        current->next = new Power(src_power);
        current->next->next = NULL;
        return;
    }
    else
    {
        add_at_end(current->next, src_power);
    }
}
