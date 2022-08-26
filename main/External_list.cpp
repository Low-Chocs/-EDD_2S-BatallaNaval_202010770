#include "External_list.h"
#include"Sorted_list.h"
Sorted_list sorted_list;


void External_list::insert(string category, string id, string nombre, int precio, string src) {

   
    if (head == NULL)
    {
        External_node* new_node = new External_node(category);
        new_node->internal_list.insert(id,nombre, precio, src);
        head = new_node;
        bottom = new_node;
        ++quantity;
    }
    else
    {
        if (check_category(head, category) == NULL) 
        {
            if (check_id(id)) 
            {
                External_node* new_node = new External_node(category);
                new_node->internal_list.insert(id, nombre, precio, src);
                bottom->next = new_node;
                bottom = new_node;
                ++quantity;
            }
            else 
            {
                cout << "1. The Id is in use\n";
            }
        }
        else 
        
            if (check_id(id))
            {
            check_category(head, category)->internal_list.insert(id, nombre, precio, src);
            }
            else 
            {
                cout << "2. The Id is in use\n";
            }
        
    }

}

//Checking the category of the node
External_node* External_list::check_category(External_node* external_node, string category) {
    int iterator = 0;
	if (external_node == NULL) {
		return external_node;
	}
	else 
    {
        External_node* aux = external_node;
        while (aux != NULL) {
            if (aux->category == category) {
                break;
            }
            aux = aux->next;
            ++iterator;
        }
        return aux;
	}
}

//Checking if the id is in use
bool External_list::check_id(string _id) {
    bool test = true;
    int iterator = 0;
    External_node* aux = head;
    if (head != NULL) 
    {
        while (iterator != quantity) 
        {
            if (!(aux->internal_list.check_id(_id))) {
                return false;
            }
            aux = aux->next;
            ++iterator;
        }
        return true;
    }
    else {
        return true;
    }
  
}

void External_list::show() {
    External_node* aux = head;
    int iterator = 0;
    if (quantity > 0) {
        while (iterator != quantity) {
            aux->internal_list.show(aux->category);
            ++iterator;
            aux = aux->next;
        }
    }
    else {
        cout << "The list of lists is empty";
    }

}

void External_list::show_category() {
    External_node* aux = head;
    int iterator = 0;
    if (quantity > 0) {
        while (iterator != quantity) {
            cout <<"\n" <<aux->category<<"\n";
            ++iterator;
            aux = aux->next;
        }
    }
    else {
        cout << "The list of lists is empty";
    }

}

void External_list::list_list_graph() {
    int iterator;

    string dot = "";
    dot = dot + "digraph G {\n";
    dot = dot + "label=\"Lista de listas\";\n";
    dot = dot + "nodesep=.05;\n";
    dot += "\trankdir=LR;\n";
    dot += "node[shape=record,width=.1,height=.1];\n";
    dot += "node0[label = \"";
    iterator = 0;
    External_node* aux = head;
    while (iterator != quantity-1) {
        dot += "<f" + to_string(iterator) +">"+aux->category + "|";
        aux = aux ->next;
        ++iterator;

    }
    dot += "<f" + to_string(iterator) + ">"+bottom->category;
    dot += "\",height = 2.5];\n";
    dot += "node [width = 1.5];\n";

    iterator = 0;
    int iterator2 = 0;
    aux = head;
    
    while (iterator2 != quantity) {
        dot += "node"+to_string(iterator2+1)+"[label = \"{";
        while (iterator != aux->internal_list.get_quantity()-1) {
            dot += "<f" + to_string(iterator) +">"+ aux->internal_list.get_name(iterator)+"| ";
            ++iterator;
        }
        iterator=0;
        dot += aux->internal_list.get_name(iterator)+"}\"];\n";
        dot += "node0:f"+to_string(iterator2)+"->node"+ to_string(iterator2+1) +":n; \n";
        ++iterator2;
        aux = aux->next;
    }
    dot += "}";
    //------->escribir archivo
 
    ofstream file;

    file.open("Pruebas2.dot");
    file << dot;
    file.close();

    //------->generar png
    system(("dot -Tpng Pruebas2.dot -o  Pruebas2.png"));

    //------>abrir archivo
    system(("Pruebas2.png"));

}