#include "Header.h"
#include"simple_list.h"

simple_list user_list;

void menu() {
	int option;
	string nick;
	string password;
	int coins;
	int age;
	string user;
	string pass;

	do {
		cout << "\nMenu\n1. Carga masiva \n2. Registrar Usuario \n3. Login\n4. Reportes \n5. Salir \n";
		cin >> option;
		switch (option) {

		case 1:
			cout << "Carga masiva\n";
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

		case 4:
			cout << "Reportes\n";
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

void log_menu(string user) {
	int option;
	int quantity_aux;

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
			else {
				continue;
			}
		case 3:
			cout << "Ver el tutorial\n";
			continue;
		case 4:
			cout << "Ver las skins de la tienda\n";
			continue;
		case 5:
			cout << "Realizar movimientos, finalizar partida\n";
			continue;
		case 6:
			cout << "Regresando al menu principal\n";
			break;
		}

	} while (option != 6);
}