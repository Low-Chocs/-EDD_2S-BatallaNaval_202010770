#include "Internal_list.h"
#include"Internal_node.h"
using namespace std;

void internal_list::insert(string id, string nombre, int precio, string src) {
	//The new node is created but not added to the list
	internal_node* new_node = new internal_node(id, nombre, precio, src);

	//Adding in the header of the list
	if (head == NULL)
	{
		head = new_node;
		bottom = new_node;
		head->next = bottom;
		++quantity;
	}
	else if (quantity > 0) {
		bottom->next = new_node;
		bottom = new_node;
		++quantity;
	}
}

void internal_list::show(string category){
	internal_node* aux = head;
	int iterator = 0;
	while (quantity != iterator) {
		cout << aux->id<<"\t" << aux->nombre<< "\t" << category<< "\t" << aux->precio << "\t" << aux->src <<"\n";
		aux = aux->next;
		++iterator;
	}
}
//Checking the id
bool internal_list::check_id(string _id) {
	internal_node* aux = head;
	int iterator = 0;
	//Checking inside the list if the id is in use
	while (quantity != iterator) {
		if (aux->id == _id) {
			return false;
		}
		aux = aux->next;
		++iterator;
	}
	return true;
}

int internal_list::get_quantity() {
	return quantity;
}

string internal_list::get_name(int number) {
	int iterator = 0;
	internal_node* aux = head;
	while (iterator != number) {
		++iterator;
		aux = aux->next;
	}
	return aux->nombre;
}
