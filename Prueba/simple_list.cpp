#include "simple_list.h"
using namespace std;

void simple_list::insert(int value) {

	simple_node* new_node = new simple_node();
	new_node->value = value;

	if (head == NULL) {
		head = new_node;
		bottom = new_node;
		head->next = bottom;
		bottom->back = head;
		++quantity;
	}
	else if(quantity > 0) {
		simple_node* aux = bottom;
		aux->next = new_node;
		aux->next->back = aux;
		bottom = new_node;
		new_node->next = head;
		++quantity;
	}
}

void simple_list::show() {
	simple_node* aux = head;
	int iterator = 0;

	if (quantity > 0) {
		while (iterator != quantity) {
			cout << aux->value<<"\n";
			aux = aux->next;
			++iterator;
		}
	}
	else {
		cout << "The list is empty\n";
	}
}

void simple_list::edit(int value) {
	simple_node* aux = head;
	int iterator = 0;
	int new_value;

	if (quantity > 0) {
		while (iterator != quantity) {
			if (aux->value == value) {
				cout << "El numero que se busco es: " << value;
				cout << "Ingrese el número a modificar: ";
				cin >> new_value;
				aux->value = new_value;
				break;
			}
			aux = aux->next;
			++iterator;	
		}
	}
	else {
		cout << "The list is empty\n";
	}
	
}

void simple_list::erase(int value){
	simple_node* aux = head;
	int iterator = 0;
	int new_value;

	//Checking the headers of the list
	if (value == head->value) {
		if (quantity == 1) {
			head = NULL;
			bottom = NULL;
			--quantity;
		}
		else {
			bottom->next = head->next;
			head = head->next;
			--quantity;
		}
	}
	//Checking the bottom of the list
	else if (value == bottom->value) {

		bottom->back->next = head;
		bottom = bottom->back;
		--quantity;
	}

	else if (quantity > 1) {
		while (iterator != quantity) {
			if (aux->value == value) {
				aux->back->next = aux->next;
				aux->next->back = aux->back;
				--quantity;
				break;
			}
			aux = aux->next;
			++iterator;
		}
	}
	else {
		cout << "No match\n";
	}
	
}