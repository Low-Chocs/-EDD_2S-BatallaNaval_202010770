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
	void insert(string nick, string password, int coins, int age);
	void show();
	void edit(string value);
	void erase(string value);
	bool login(string user, string pass);
	int get_quantity();
	int get_points(string user);
private:
};