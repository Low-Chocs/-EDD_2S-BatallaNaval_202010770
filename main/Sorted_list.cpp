#include"Sorted_list.h"

void Sorted_list::insert(int number) {
	if (head == NULL)
	{
		sorted_node* new_node = new sorted_node(number);
		head = new_node;
		bottom = new_node;
		++quantity;
	}
	else if (check_in_list(number)){
		sorted_node* new_node = new sorted_node(number);
		sorted_node* aux = head;
		int iterator = 0;

		if (number < head->sorted_element) {
			new_node->next = head;
			head->back = new_node;
			head = new_node;
			++quantity;
		}
		else if (number > bottom->sorted_element) {
			new_node->back = bottom;
			bottom->next = new_node;
			bottom = new_node;
			++quantity;
		}
		else {
			while (iterator != quantity) {
				if (number < aux->sorted_element) {
					aux->back->next = new_node;
					new_node->back = aux->back;
					new_node->next = aux;
					aux->back = new_node;
					++quantity;
					break;
				}
				aux = aux->next;
				++iterator;
			}
		}

		
	}
}
int Sorted_list::show_in_ascendent(int selected_age) {

	sorted_node* aux = head;
	int iterator = 0;
	while(iterator != selected_age) {
		aux = aux->next;
		++iterator;
	}
	return aux->sorted_element;
}

int Sorted_list::show_in_descendent(int selected_age) {
	sorted_node* aux = bottom;
	int iterator = 0;
	while (iterator != selected_age) {
		aux = aux->back;
		++iterator;
	}
	return aux->sorted_element;
}

bool Sorted_list::check_in_list(int number) {
	sorted_node* aux = head;
	int iterator = 0;
	//Checking inside the list if the id is in use
	while (iterator != quantity) {
		if (aux->sorted_element == number) {
			return false;
			break;
			cout << "1";
		}
		++iterator;
		aux = aux->next;
		
	}
	return true;
}

int Sorted_list::get_quantity() {
	return quantity;
}

void Sorted_list::only_show() {
	sorted_node* aux = head;
	int iterator = 0;

	while (iterator != quantity) {
		cout << "\n" << aux->sorted_element << "\n";
		aux = aux->next;
		++iterator;
	}
}