#include "external_stack_list.h"
#include"Stack.h"

void external_stack_list::insert(string nombre) {
    string nombre2 = "";

    if (head == NULL)
    {
        external_stack_node* new_node = new external_stack_node(nombre);
        head = new_node;
        bottom = new_node;
        ++quantity;
    }
    else
    {
        if (check_name(head, nombre) == NULL)
        {
            
            external_stack_node* new_node = new external_stack_node(nombre);
            bottom->next = new_node;
            bottom = new_node;
            ++quantity;
        }
        else 
        {
            cout << "\nEl nombre de la partida ya esta en uso, ingresa otro: ";
            cin >> nombre2;
            insert(nombre2);
            cout << "\n";
        }


    }
}

int external_stack_list::get_quantity() {
    return quantity;
}
void external_stack_list::insert_height_width(string nombre, int _height, int _width) {
    external_stack_node* aux = head;
    int iterator = 0;
    if (quantity > 0) {
        while (iterator != quantity) {
            if (aux->nombre == nombre) {
                aux->internal_stack.add_x_y(_height, _width);
                break;
            }
            cout << "\n" << aux->nombre << "\n";
            ++iterator;
            aux = aux->next;
        }
    }
    else {
        cout << "The list of lists is empty";
    }
}
void external_stack_list::show_stack(string nombre) {
    external_stack_node* aux = head;
    int iterator = 0;
    if (quantity > 0) {
        while (iterator != quantity) {
            if (aux->nombre == nombre) {
                aux->internal_stack.show();
            }
            cout << "\n" << aux->nombre << "\n";
            ++iterator;
            aux = aux->next;
        }
    }
    else {
        cout << "The list of lists is empty";
    }
}

void external_stack_list::insert_move(string nombre, int _x, int _y) {
    external_stack_node* aux = head;
    int iterator = 0;
    if (quantity > 0) {
        while (iterator != quantity) {
            if (aux->nombre == nombre) {
                aux->internal_stack.push(_x, _y);
            }
            ++iterator;
            aux = aux->next;
        }
    }
    else {
        cout << "The list of lists is empty";
    }

}

//Checking the category of the node
external_stack_node* external_stack_list::check_name(external_stack_node* external_node, string nombre) {
    int iterator = 0;
    if (external_node == NULL) {
        return external_node;
    }
    else
    {
        external_stack_node* aux = external_node;
        while (aux != NULL) {
            if (aux->nombre == nombre) {
                break;
            }
            aux = aux->next;
            ++iterator;
        }
        return aux;
    }
}


void external_stack_list::show() {
    external_stack_node* aux = head;
    int iterator = 0;
    if (quantity > 0) {
        while (iterator != quantity) {
            aux->internal_stack.show();
            ++iterator;
            aux = aux->next;
        }
    }
    else {
        cout << "The list of lists is empty";
    }

}

void external_stack_list::show_name() {
    external_stack_node* aux = head;
    int iterator = 0;
    if (quantity > 0) {
        while (iterator != quantity) {
            cout << "\n" << aux->nombre << "\n";
            ++iterator;
            aux = aux->next;
        }
    }
    else {
        cout << "The list of lists is empty";
    }

}

void external_stack_list::queue_graph() {
    int iterator;

    string dot = "";
    dot = dot + "digraph G {\n";
    dot = dot + "label=\"Lista de listas\";\n";
    dot = dot + "nodesep=.05;\n";
    dot += "\trankdir=LR;\n";
    dot += "node[shape=record,width=.1,height=.1];\n";
    dot += "node0[label = \"";
    iterator = 0;
    external_stack_node* aux = head;
    while (iterator != quantity - 1) {
        dot += "<f" + to_string(iterator) + ">" + aux->nombre + "|";
        aux = aux->next;
        ++iterator;
        cout << "Me quede aqui";

    }
    dot += "<f" + to_string(iterator) + ">" + bottom->nombre;
    dot += "\",height = 2.5];\n";
    dot += "node [width = 1.5];\n";

    iterator = 0;
    int iterator2 = 0;
    aux = head;

    while (iterator2 != quantity) {
        dot += "node" + to_string(iterator2 + 1) + "[label = \"{";
        while (iterator != aux->internal_stack.get_quantity() - 1) {
            dot += "<f" + to_string(iterator) + ">" + to_string(aux->internal_stack.return_x(iterator)) + "," + to_string(aux->internal_stack.return_y(iterator)) + "| ";
            ++iterator;
        }
        iterator = 0;
        dot +=  to_string(aux->internal_stack.return_x(iterator)) + "," + to_string(aux->internal_stack.return_y(iterator)) + "}\"];\n";
        dot += "node0:f" + to_string(iterator2) + "->node" + to_string(iterator2 + 1) + ":n; \n";
        ++iterator2;
        aux = aux->next;
    }
    dot += "}";
    //------->escribir archivo

    ofstream file;

    file.open("Pruebas4.dot");
    file << dot;
    file.close();

    //------->generar png
    system(("dot -Tpng Pruebas4.dot -o  Pruebas4.png"));

    //------>abrir archivo
    system(("Pruebas4.png"));

}