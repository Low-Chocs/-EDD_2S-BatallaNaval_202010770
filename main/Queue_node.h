#pragma once
#include"Header.h"
#include<string>
using namespace std;

class Queue_node {
public:
	Queue_node* next;
	int x;
	int y;
	Queue_node(int _x, int _y) {
		next = NULL;
		x = _x;
		y = _y;
	};

};