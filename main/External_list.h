#pragma once
#include"External_node.h"
#include"Internal_node.h"
#include"node.h"

class External_list
{
public:
	External_node* head;
	External_node* bottom;
	int quantity;

	External_list() {
		head = NULL;
		bottom = NULL;
		quantity = 0;
	}
	void insert(string category, int id, string nombre, int precio, string src);
	void show();
	void show_category();
	void edit(string value);
	void erase(string value);
	bool login(string user, string pass);
	int get_quantity();
	bool check_id(int id);
	External_node * check_category(External_node*external_node, string category);
private:
};


