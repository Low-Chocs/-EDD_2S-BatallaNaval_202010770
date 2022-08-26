#pragma once
#include"stack_node.h"
#include"node.h"
#include"Header.h"
class Stack
{
public:
    stack_node* head;
    stack_node* bottom;
    int height = 0;
    int width = 0;
    int quantity = 0;

    Stack() {
        head = NULL;
        bottom = NULL;
    }
    void add_x_y(int _height, int _width);
    void push(int x, int y);
    void pop();
    void show();
    int get_quantity();
    int return_x(int x);
    int return_y(int y);

};