#pragma once
#include"external_stack_node.h"
class external_stack_list
{
public:
	external_stack_node* head;
	external_stack_node* bottom;
	int quantity;

	external_stack_list() {
		head = NULL;
		bottom = NULL;
		quantity = 0;
	}
	void insert(string nombre);
	void show();
	void show_name();
	bool login(string user, string pass);
	int get_quantity();
	void insert_height_width(string nombre, int _height, int _width);
	void insert_move(string nombre, int _x, int _y);
	void show_stack(string nombre);
	external_stack_node* check_name(external_stack_node* external_node, string nombre);
	void queue_graph();

private:
};



