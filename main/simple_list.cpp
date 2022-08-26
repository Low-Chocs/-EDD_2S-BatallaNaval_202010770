#include "simple_list.h"
#include<string>
#include<iostream>
#include<fstream>
#include <windows.h>
#include <sstream>
#include"Sorted_list.h"
using namespace std;
Sorted_list sorted_list2;

void simple_list::insert(string nick, string password, int coins, int age) {

	simple_node* new_node = new simple_node(nick, password, coins, age);
	int iterator = 0;
	bool state = true;

	//Add in the header
	if (head == NULL) 
{
		head = new_node;
		bottom = new_node;
		head->next = bottom;
		bottom->back = head;
		++quantity;
	}
	else if (quantity > 0) {
		simple_node* aux = head;
		//Verifies that the nick is not in usage
		while (iterator != quantity) {
			if (new_node->nick == aux->nick) {
				state = false;
				iterator = 0;
				break;
			}
			++iterator;
			aux = aux->next;
		}
		//If nick is not in usage it is added
		if (state) {
			simple_node* aux = bottom;
			aux->next = new_node;
			aux->next->back = aux;
			bottom = new_node;
			new_node->next = head;
			head->back = bottom;
			++quantity;
		}
		else {
			do {
				cout << "The nickname is already in use, please insert a new one: ";
				cin >> nick;
				simple_node* aux = head;
				while (iterator != quantity) {
					if (nick == aux->nick) {
						state = false;
						iterator = -2;
						break;
					}
					++iterator;
					aux = aux->next;
				}
				if (iterator != -2) {
					state = true;
					simple_node* aux = bottom;
					aux->next = new_node;
					aux->next->back = aux;
					bottom = new_node;
					bottom->nick = nick;
					new_node->next = head;
					++quantity;
					head->back = bottom;
				
				}
				iterator = 0;

			} while (state == false);
		}
	}
}
void simple_list::insert2(string nick, string password, int coins, int age) {

	simple_node* new_node = new simple_node(nick, password, coins, age);
	int iterator = 0;
	bool state = true;

	//Add in the header
	if (head == NULL)
	{
		head = new_node;
		bottom = new_node;
		head->next = bottom;
		bottom->back = head;
		++quantity;
	}
	else if (quantity > 0) {
		simple_node* aux = head;
		//Verifies that the nick is not in usage
		while (iterator != quantity) {
			if (new_node->nick == aux->nick) {
				state = false;
				iterator = 0;
				break;
			}
			++iterator;
			aux = aux->next;
		}
		//If nick is not in usage it is added
		if (state) {
			simple_node* aux = bottom;
			aux->next = new_node;
			aux->next->back = aux;
			bottom = new_node;
			new_node->next = head;
			++quantity;
			head->back = bottom;
		}	
	}
}

void simple_list::show() 
{
	simple_node* aux = head;
	int iterator = 0;

	if (quantity > 0) 
	{
		//Shows everything in the list
		while (iterator != quantity) 
		{
			cout <<"\nUser nick: " << aux->nick << "\n";
			cout << "User password: " << aux->password << "\n";
			cout << "User coins: " << aux->monedas << "\n";
			cout << "User age: " << aux->edad << "\n\n";
aux = aux->next;
++iterator;
		}
	}
	else
	{
	cout << "The list is empty\n";
	}
}

void simple_list::edit(string nickname)
{
	simple_node* aux = head;
	simple_node* aux2 = head;
	int iterator = 0;
	int new_value;
	int new_option = 0;
	int new_age;
	string new_nick;
	string new_pass;
	bool state = true;

	if (quantity > 0) {
		while (iterator != quantity)
		{
			if (aux->nick == nickname)
			{
				do
				{
					iterator = 0;
					aux2 = head;
					state = true;

					cout << "\n1. Nickname: " << aux->nick;
					cout << "\n2. Age: " << aux->edad;
					cout << "\n3. Password: " << aux->password;
					cout << "\n4. Regresar: ";
					cout << "Selecciona la informacion que deseas modificar: ";
					cin >> new_option;


					switch (new_option)
					{
					case 1:
						cout << "Ingresa el nuevo nick: ";
						cin >> new_nick;
						while (iterator != quantity)
						{
							if (new_nick == aux2->nick) {
								state = false;
								cout << "Ese nickname no esta disponible";
								break;
							}
							aux2 = aux2->next;
							++iterator;
						}
						if (state) {
							aux->nick = new_nick;
							cout << "\nSe modifico correctamente tu nickname";
						}
						continue;
					case 2:
						cout << "Ingresa tu edad: ";
						cin >> new_age;
						aux->edad = new_age;
						continue;
					case 3:
						cout << "Ingresa tu nueva contrasena: ";
						cin >> new_pass;
						aux->password = new_pass;
						continue;
					case 4:
						continue;
					default:
						cout << "Opcion no valida";
						continue;
					}

				} while (new_option != 4);
				break;
			}
			aux = aux->next;
			++iterator;
		}
	}
	else
	{
		cout << "The list is empty\n";
	}

}

void simple_list::erase(string value) {
	int decision;

	
	cout << "\n1. Si, deseo eliminar mi cuenta\n";
	cout << "2. No quiero borrar mi cuenta\n";
	cout << "\nUna vez elimines tu cuenta, no hay vuelta atras: ";
	cin >> decision;

	if (decision == 1)
	{
		simple_node* aux = head;
		int iterator = 0;
		int new_value;

		//Checking the headers of the list
		if (value == head->nick) {
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
		else if (value == bottom->nick) {

			bottom->back->next = head;
			bottom = bottom->back;
			--quantity;
		}

		else if (quantity > 1) {
			while (iterator != quantity) {
				if (aux->nick == value) {
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
		cout << "La cuenta fue eliminada correctamente \n";

	}


}

bool simple_list::login(string user, string pass) {

	simple_node* aux = head;
	int iterator = 0;
	int new_value;


	while (iterator != quantity) 
	{
		if (aux->nick == user) 
		{
			if (aux->password == pass) 
			{
				return true;
			}
		}
		aux = aux->next;
		++iterator;
	}
	return false;

}

int simple_list::get_quantity() {
	return quantity;
}

int simple_list::get_points(string user) {
	simple_node* aux = head;
	int iterator = 0;


	while (iterator != quantity)
	{
		if (aux->nick == user)
		{
			return aux->monedas;
		}
		aux = aux->next;
		++iterator;
	}
}

void simple_list::set_points(string user) {
	simple_node* aux = head;
	int iterator = 0;


	while (iterator != quantity)
	{
		if (aux->nick == user)
		{
			++aux->monedas;
		}
		aux = aux->next;
		++iterator;
	}
}
void simple_list::simple_list_graph() {

		string dot = "";
		dot = dot + "digraph G {\n";
		dot = dot + "label=\"Lista doblemente enlazada circular\";\n";
		dot = dot + "node [shape=box];\n";
		cout << "Llegue hasta aqui 1\n";


		simple_node* aux = head;
		int iterator = 0;
		dot = dot + "//agregar nodos\n";
		while (iterator != quantity) {
			
			dot = dot + "N" + aux->nick + "[fontsize=\"10pt\" label=\"" + "nick: "+ aux->nick + "\npassword: " + aux->password + "\ncoins: " + to_string(aux->monedas) + "\nage: " + to_string(aux->edad) + "\"];\n";
			aux = aux->next;
			++iterator;
		}
		cout << "Llegue hasta aqui 2\n";
		dot = dot + "//Enlazar imagenes\n";
		dot = dot + "{rank=same;\n";
		aux = head;
		iterator = 0;
		while (iterator != quantity) {

			dot = dot + "N" + aux->nick;
			if (aux != bottom) {
				dot = dot + "->";
			}
			
			aux = aux->next;
			++iterator;
		}
		dot += "\n";
		aux = bottom;
		iterator = 0;
		while (iterator != quantity) {

			dot = dot + "N" + aux->nick;
			if (aux != head) {
				dot = dot + "->";
			}

			aux = aux->back;
			++iterator;
		}
		dot = dot + " N" + bottom->nick +"->" +"N"+ head->nick;
		dot = dot + " N" + head->nick + "->" + "N" + bottom->nick;
		dot = dot + "}\n";
		dot = dot + "}\n";

		cout << dot;

		//------->escribir archivo
		cout << "Llegue hasta aqui";
		ofstream file;
		
		file.open("Pruebas.dot");
		file << dot;
		file.close();

		//------->generar png
		system(("dot -Tpng Pruebas.dot -o  Pruebas.png"));

		//------>abrir archivo
		system(("Pruebas.png"));

	}




