#include "Header.h"
#include"simple_list.h"
#include"External_list.h"
#include"Queue.h"
#include"external_stack_list.h"
#include"json/json.h"
#include"json/value.h"
#include<fstream>
#include <sstream>
using namespace std;

simple_list user_list;
External_list store_list;
Queue cola;
Stack pila;
external_stack_list stack_list;
Sorted_list sort_by_age;
Sorted_list sort_by_expensive;

void menu() {
	int option;
	string nick;
	string password;
	int coins;
	int age;
	string user;
	string pass;
	string json_file_name;
	

	do {

		cout << "\nMenu\n1. Carga masiva \n2. Registrar Usuario \n3. Login\n4. Reportes \n5. Salir \n";
		cin >> option;
		switch (option) {

		case 1:
			cout << "Introduzca el nombre del archivo: \n";
			cin >> json_file_name;
			read_json(json_file_name);
			continue;
		case 2:
			cout << "Registrar Usuario\n";

			cout << "Ingrese el nombre del usuario: ";
			cin >> nick;
			cout << "\nIngrese la contrasena: ";
			cin >> password;
			cout << "\nIngrese su edad:  ";
			cin >> age;

			user_list.insert(nick, password, 0, age);
			user_list.show();

			continue;
		case 3:
			if (user_list.get_quantity() > 0) 
			{
				cout << "\nIngresa el usuario: ";
				cin >> user;
				cout << "\nIngresa la contrasena: ";
				cin >> pass;
				if (user_list.login(user, pass)) {
					log_menu(user);
				}
				else {
					cout << "Usuario o contrasena incorrectos";
				}
			}
			else {
				cout << "\nThe list is empty\n";
			}
			continue;

		case 4:
			report_menu();
			continue;
		case 5:
			cout << "Has salido :)\n";
			continue;
		default:
			cout << "Ingresa un numero dentro del rango determinado\n";
			continue;
		}
	} while (option != 5);
}

void report_menu() {
	int option;
	int quantity_aux;
	int option2;
	int move_x;
	int move_y;
	int _height;
	int _width;
	string match_name;

	do {
		cout << "\nMenu\n1. Lista doblemente enlazada circular  \n2. Lista de listas";
		cout << "\n3. Cola de movimientos \n4. Lista de pilas \n5. Orden de usuarios mayor a menor \n";
		cout << "6. Orden de usuarios menor a mayor\n7. Articulos mayor a menor\n8. Articulos menor a mayor\n9. Regresar al menu principal\n";
		cin >> option;
		switch (option) {
		case 1:
			cout << "opcion1";
			if (user_list.get_quantity() > 0) {
				user_list.simple_list_graph();
			}
			else {
				cout << "\nThe list is empty\n";
			}
			continue;
		case 2:
			cout << "opcion2";
			if (store_list.quantity > 0) {
				store_list.list_list_graph();
			}
			else {
				cout << "\nThe list is empty\n";
			}
			continue;
		case 3:
			if (stack_list.get_quantity() > 0) {
				stack_list.queue_graph();
			}
			else {
				cout << "The queue is empty";
			}
			continue;
		case 4:
			cola.stack_graph();
			continue;
		case 5:
			if (user_list.get_quantity() > 0) {
				show_in_order(1);
			}
			else {
				cout << "The list is empty";
			}
			continue;
		case 6:
			if (user_list.get_quantity() > 0) {
				show_in_order(0);
			}
			else {
				cout << "The list is empty";
			}
			continue;
		
		case 7:
			if (user_list.get_quantity() > 0) {
				show_in_order2(1);
			}
			else {
				cout << "The list is empty";
			}
			continue;
		case 8:
			if (user_list.get_quantity() > 0) {
				show_in_order2(0);
			}
			else {
				cout << "The list is empty";
			}
			continue;
		case 9:
			cout << "Regresando al menu principal\n";
			break;
	}

	} while (option != 9);
}


void log_menu(string user) {
	int option;
	int quantity_aux;
	int option2;
	int move_x;
	int move_y;
	int _height;
	int _width;
	string match_name;

	do {
		cout << "\nBienvenido: " << user;
		cout << "\nMenu\n1. Editar informacion \n2. Eliminar cuenta";
		cout << "\n3. Ver el tutorial\n4. Ver skins de la tienda \n";
		cout << "5. Realizar movimientos\n 6. Regresar al menu principal\n";
		cin >> option;
		switch (option) {

		case 1:
			user_list.edit(user);
			continue;
		case 2:
			cout << "Eliminar cuenta\n";
			quantity_aux = user_list.get_quantity();
			user_list.erase(user);
			if (quantity_aux > user_list.get_quantity()) {
				option = 6;
			}
			continue;
		case 3:
			cola.show();
			continue;
		case 4:
			cout << user << " Tienes un total de: " << user_list.get_points(user)<< " para gastar\n";
			store_list.show();
			cout << "\nPulse 1 para volver: ";
			cin >> option2;
			if (option == 1) {
				continue;
			}continue;
		case 5:
			cout << "\nIngresa el nombre de la partida: \n";
			cin >> match_name;
			stack_list.insert(match_name);
			cout << "Ingresa el ancho del tablero: ";
			cin>>_width;
			cout << "Ingresa la altura del tablero: ";
			cin >> _height;
			stack_list.insert_height_width(match_name, _height, _width);
			do {
				cout<<"\nPuntos totales: "<< user_list.get_points(user);
				cout << "\nRealiza un movimiento, pulsa 0,0 para salir (funcion no final)\n";
				cout << "\nx: ";
				cin >> move_x;
				cout << "\nx: "<<move_x<< " y: ";
				cin >> move_y;
				user_list.set_points(user);
				stack_list.insert_move(match_name, move_y, move_x);
			} while (move_x != 0 && move_y != 0);
			continue;
		case 6:
			cout << "Regresando al menu principal\n";
			break;
		}

	} while (option != 6);
}

void read_json(string value) {
	cout << "";
	ifstream file(value);

	Json::Value actualJson;
	Json::Reader reader;
	int age;
	int coins;
	string name;
	string password;


	reader.parse(file, actualJson);

	
	for (int i = 0; i < actualJson["usuarios"].size(); i++) {
		age =  stoi(actualJson["usuarios"][i]["edad"].asString());
		coins = stoi(actualJson["usuarios"][i]["monedas"].asString());
		name = actualJson["usuarios"][i]["nick"].asString();
		password = actualJson["usuarios"][i]["password"].asString();
		user_list.insert2(name, password, coins, age);
		sort_by_age.insert(age);
	}

	string id;
	string category;
	int price;
	string ob_name;
	string src;
	cout<< actualJson["articulos"].size();
	for (int i = 0; i < actualJson["articulos"].size(); i++) {
		id = actualJson["articulos"][i]["id"].asString();
		price = stoi(actualJson["articulos"][i]["precio"].asString());
		category = actualJson["articulos"][i]["categoria"].asString();
		ob_name = actualJson["articulos"][i]["nombre"].asString();
		src = actualJson["articulos"][i]["src"].asString();
		store_list.insert(category, id, ob_name, price, src);
		sort_by_expensive.insert(price);
	}
	

	int width;
	int height;
	int _x;
	int _y;

	width = stoi(actualJson["tutorial"]["ancho"].asString());
	height = stoi(actualJson["tutorial"]["alto"].asString());
	cout << width;
	cout << height;
	cola.add_x_y(height, width);
	for (int i = 0; i < actualJson["tutorial"]["movimientos"].size(); i++) {
		_x = stoi(actualJson["tutorial"]["movimientos"][i]["x"].asString());
		_y = stoi(actualJson["tutorial"]["movimientos"][i]["y"].asString());
		cola.push(_x, _y);
	}

}

void show_in_order(int decision) {
	int iterator = 0;
	simple_node* aux = user_list.head;
	if (decision == 0) {
		for (int i = 0; i < sort_by_age.get_quantity(); i++) {
			iterator = 0;
			aux = user_list.head;
			while (iterator != user_list.quantity) {
				if (aux->edad == sort_by_age.show_in_ascendent(i)) {
					cout << "\nUser nick: " << aux->nick << "\n";
					cout << "User password: " << aux->password << "\n";
					cout << "User coins: " << aux->monedas << "\n";
					cout << "User age: " << aux->edad << "\n\n";
				}
				aux = aux->next;
				++iterator;
			}
		}
	}else {
		for (int i = 0; i < sort_by_age.get_quantity(); i++) {
			iterator = 0;
			aux = user_list.head;
			while (iterator != user_list.get_quantity()) {
				if (aux->edad == sort_by_age.show_in_descendent(i)) {
					cout << "\nUser nick: " << aux->nick << "\n";
					cout << "User password: " << aux->password << "\n";
					cout << "User coins: " << aux->monedas << "\n";
					cout << "User age: " << aux->edad << "\n\n";
				}
				aux = aux->next;
				++iterator;
			}
		}
	}
}

void show_in_order2(int decision) {
	int iterator = 0;
	int iterator2 = 0;
	External_node* aux = store_list.head;
	internal_node* aux2 = aux->internal_list.head;
	
	if (decision == 0) {
		for (int i = 0; i < sort_by_expensive.get_quantity(); i++) {
			iterator = 0;
			aux = store_list.head;
			while (iterator != store_list.quantity) {
				aux2 = aux->internal_list.head;
				iterator2 = 0;
				while (iterator2 != aux->internal_list.get_quantity()){
					if (aux2->precio == sort_by_expensive.show_in_ascendent(i)) {
						cout << aux2->id << "\t" << aux2->nombre << "\t" << aux->category << "\t" << aux2->precio << "\t" << aux2->src << "\n";
					}
					aux2 = aux2->next;
					++iterator2;
				}
				aux = aux->next;
				++iterator;
			}
		}
	}
	else {
		for (int i = 0; i < sort_by_expensive.get_quantity(); i++) {
			iterator = 0;
			aux = store_list.head;
			while (iterator != store_list.quantity) {
				aux2 = aux->internal_list.head;
				iterator2 = 0;
				while (iterator2 != aux->internal_list.get_quantity()) {
					if (aux2->precio == sort_by_expensive.show_in_descendent(i)) {
						cout << aux2->id << "\t" << aux2->nombre << "\t" << aux->category << "\t" << aux2->precio << "\t" << aux2->src << "\n";
					}
					aux2 = aux2->next;
					++iterator2;
				}
				aux = aux->next;
				++iterator;
			}
		}
		}
}

void stack_graphic() {
	int iterator = 0;

	string dot = "";
	dot = dot + "digraph G {\n";
	dot = dot + "label=\"Cola\";\n";
	dot = dot + "nodesep=.05;\n";
	dot += "node[shape=record,width=.1,height=.1];\n";
	dot += "node0[label = \"";



	stack_node* aux = pila.head;
	while (aux != NULL) {

		dot += "<f" + to_string(iterator) + ">" + to_string((iterator)) + "|";
		aux = aux->next;
		++iterator;

	}

	dot += "\",height = 2.5];\n";
	dot += "node [width = 1.5];\n";


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
