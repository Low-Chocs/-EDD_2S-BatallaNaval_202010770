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
	void insert(string id, string nombre, int precio, string src);
	void show(string category);
	void edit(string value);
	void erase(string value);
	bool login(string user, string pass);
	int get_quantity();
	string get_name(int number);
	int get_price();
	bool check_id(string _id);
private:
};