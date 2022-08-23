#include"simple_list.h"
#include<stddef.h>
#include <iostream>
#include<cstdlib>
using namespace std;
//getters
string get_nick();
string get_password();
int get_coins();
int get_age();
//setters
void set_nick(string nick);
void set_password(string password);
void set_coins(int coins);
void set_age(int age);

int main()
{
    simple_list test;
    test.insert(33);
    test.erase(33);
    test.insert(34);
    test.insert(35);
    test.insert(36);
    test.insert(37);
    test.insert(38);
    test.erase(33);
    test.erase(38);
    test.erase(36);
    test.erase(35);
    test.erase(35);
    test.erase(34);
    test.erase(37);
    test.show();
    cout << "listo\n";
    test.insert(34);
    test.insert(35);
    test.insert(36);
    test.insert(37);
    test.insert(38);
    test.show();
    return 0;
}

