#pragma once
#include"Header.h"
#include<string>
#include"Internal_list.h"
#include"Internal_node.h"
using namespace std;


class External_node
{
public:
	External_node* next;
	string category;
	internal_list internal_list;
	

	External_node(string _category) {
		next = NULL;
		category = _category;
	};
};

