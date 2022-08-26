#pragma once
#include"Header.h"
#include<string>
using namespace std;

class internal_node {
public:
	internal_node* next;
	string id;
	int precio;
	string nombre;
	string src;


	internal_node(string _id, string _nombre, int _precio, string _src) {
		next = NULL;
		id = _id;
		nombre = _nombre;
		precio = _precio;
		src = _src;
	};

};