#include "Queue.h"

void Queue::add_x_y(int _width, int _height) {
    height = _height;
    width = _width;
}
void Queue::push(int x, int y) {
    Queue_node* new_node = new Queue_node(x, y);
    
    if (((x <= width) && (y <= height)) && ((x >= 0) && (y >= 0))) {
        if (head == NULL) {
            head = new_node;
            bottom = new_node;
            ++quantity;
        }
        else {
            bottom->next = new_node;
            bottom = new_node;
            ++quantity;
        }

    }
    else {
        cout<<"\nNo admitido: "<<x<<","<<y<<"\n";
    }
}

void Queue::pop() {
    Queue_node* aux = head;
    head = aux->next;
    --quantity;
}

void Queue::show() {
    int iterator = 0;
    Queue_node* aux = head;
    cout << "\nTablero:\n \tAncho: " << width << "\n\tAltura: " << height<<"\n";
    if (quantity != 0) {
        while (quantity != iterator) {
            cout << "[" << aux->x << "," << aux->y << "] -> ";
            aux = aux->next;
            ++iterator;
        }
    }
    else {
        cout << "No movements founded";
    }
}

void Queue::stack_graph() {
    int iterator = 0;

    string dot = "";
    dot = dot + "digraph G {\n";
    dot = dot + "label=\"Pila\";\n";
    dot = dot + "nodesep=.05;\n";
    dot += "node[shape=record,width=.1,height=.1];\n";
    dot += "node0[label = \"";

    Queue_node* aux2 = head;


    while (iterator != quantity-1) {
        dot += "<f" + to_string(iterator) + ">" + to_string(aux2->x) +","+ to_string(aux2->y) + "|";
        aux2 = aux2->next;
        ++iterator;
        cout << iterator<<endl;
    }

    dot += "< f" + to_string(iterator) + ">"+to_string(aux2->x) + ", " + to_string(aux2->y) + "\",height = 2.5];\n";
    dot += "node [width = 1.5];\n";

    dot += "Entrada->node0:f0\n";
    dot += "node0:f47->Salida";

    dot = dot + "}\n";


    cout << dot;

    //------->escribir archivo
    ofstream file;

    file.open("Pruebas3.dot");
    file << dot;
    file.close();

    //------->generar png
    system(("dot -Tpng Pruebas3.dot -o  Pruebas3.png"));

    //------>abrir archivo
    system(("Pruebas3.png"));

}


