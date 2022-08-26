#pragma once
#include"Header.h"
#include<string>
using namespace std;

class stack_node {
public:
	stack_node* next;
	int x;
	int y;
	stack_node(int _x, int _y) {
		next = NULL;
		x = _x;
		y = _y;
	};

};