#pragma once
#include"node.h"

class simple_list
{
public:
	simple_node* head;
	simple_node* bottom;
	int quantity;
	simple_list() {
		head = NULL;
		bottom = NULL;
		quantity = 0;
	}
	void insert(int value);
	void show();
	void edit(int value);
	void erase(int value);
private:
};

