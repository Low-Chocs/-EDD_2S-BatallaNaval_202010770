#pragma once
#include"sorted_node.h"

class Sorted_list
{
public:
    sorted_node* head;
    sorted_node* bottom;
    int quantity = 0;


    Sorted_list() {
        head = NULL;
        bottom = NULL;
    }
    void insert(int number);
    int show_in_ascendent(int selected_age);
    int show_in_descendent(int selected_age);
    int get_quantity();
    bool check_in_list(int number);
    void only_show();
};