#pragma once
#include <iostream>

class simple_node {
	public:
		int value;
		simple_node* next;
		simple_node* back;

		simple_node() {
			next = NULL;
			back = NULL;
			value = 0;
		}
};