#include "Stack.h"

void Stack::add_x_y(int _width, int _height) {
    height = _height;
    width = _width;
}
void Stack::push(int _x, int _y) {
    

    if (((_x <= width) && (_y <= height)) && ((_x > 0) && (_y > 0))) {
        stack_node* new_node = new stack_node(_x, _y);
        if (head == NULL) {
            head = new_node;
            cout << "\nSe realizo el movimiento:" << _x<<","<< _y;;
            cout << "\n";
            ++quantity;
        }
        else {
            new_node->next = head;
            head = new_node;
            ++quantity;
        }

    }
    else {
        cout << "\nNo admitido: " << _x << "," << _y << "\n";
    }
}

void Stack::pop() {
    stack_node* aux = head;
    head = aux->next;
}

int Stack::get_quantity() {
    return quantity;
}

void Stack::show() {
    stack_node* aux = head;
    cout << "\nTablero:\n \tAncho: " << width << "\n\tAltura: " << height << "\n";
    while (aux != NULL) {
        cout << "[" << aux->x << "," << aux->y << "] -> ";
        aux = aux->next;
    }
}

int Stack::return_x(int number) {
    int iterator = 0;
    stack_node* aux = head;
    if (number != iterator) {
        ++iterator;
        aux = aux->next;
    }
    return aux->x; 
}

int Stack::return_y(int number) {
    int iterator=0;
    stack_node* aux = head;
    if (number != iterator) {
        ++iterator;
        aux = aux->next;
    }
    return aux->y;
}
