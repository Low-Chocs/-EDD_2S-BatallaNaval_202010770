#pragma once
#include"Internal_node.h"
#include"node.h"

class internal_list
{
public:
	internal_node* head;
	internal_node* bottom;
	int quantity;
	internal_list() {
		head = NULL;
		bottom = NULL;
		quantity = 0;
	}
	void insert(int id, string nombre, int precio, string src);
	void show(string category);
	void edit(string value);
	void erase(string value);
	bool login(string user, string pass);
	int get_quantity();
	bool check_id(int _id);
private:
};