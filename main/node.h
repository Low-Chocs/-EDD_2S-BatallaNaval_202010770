#pragma once
#include"Player.h"
#include"Header.h"
#include<string>
using namespace std;

class simple_node {
public:
	simple_node* next;
	simple_node* back;
	string nick;
	string password;
	int monedas;
	int edad;

	simple_node(string _nick, string _password, int _monedas, int _age) {
		next = NULL;
		back = NULL;
		nick = _nick;
		password = _password;
		monedas = _monedas;
		edad = _age;
	}
};