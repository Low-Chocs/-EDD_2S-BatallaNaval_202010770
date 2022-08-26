#pragma once
#include"Header.h"
#include<string>
#include"Stack.h"
using namespace std;


class external_stack_node
{
public:
	external_stack_node* next;
	string nombre;
	Stack internal_stack;


	external_stack_node(string _name) {
		next = NULL;
		nombre = _name;
	}
	
};
