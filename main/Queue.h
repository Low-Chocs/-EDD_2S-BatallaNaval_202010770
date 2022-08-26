#pragma once
#include "Queue_node.h"


class Queue

{
public:
    Queue_node* head;
    Queue_node* bottom;
    int height;
    int width;
    int quantity = 0;

    Queue() {
        head = NULL;
        bottom = NULL;
    }
    void push(int x, int y);
    void pop();
    void show();
    void add_x_y(int _height, int _width);
    void stack_graph();
};



