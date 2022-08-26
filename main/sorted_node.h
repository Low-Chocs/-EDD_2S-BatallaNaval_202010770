#pragma once
#include"Header.h"
using namespace std;

class  sorted_node {
public:
	sorted_node* next;
	sorted_node* back;
	int sorted_element;

	sorted_node(int _sorted_element) {
		next = NULL;
		back = NULL;
		sorted_element = _sorted_element;
	}

};