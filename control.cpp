#include <iostream>
#include <fstream>
#include <string>
#include "funciones.h"
#include "colors.h"
#include <locale.h>
using namespace std;

int main() {

	setlocale(LC_ALL, "");
	
	int opc = 0;

	while (opc != 11) {
		cout << LGREEN << "\n----- BIENVENIDO AL BARRIO SANTAMONICA -----" << endl;
		cout << "\n1. Añadir ingreso al barrio." << endl;
		cout << "2. Añadir egreso del barrio." << endl;
		cout << "3. Buscar registro de personas. " << endl;
		cout << "4. Salir del programa." << endl;
		cout << "Ingrese opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			int opcion;

			cout << "\n1. Con auto." << endl;
			cout << "2. A pie." << endl;
			cout << "Ingrese opcion: ";
			cin >> opcion;

			if (opcion == 1) {
				añadirIngresoAuto();
			}

			if (opcion == 2) {
				añadirIngresoPie();
			}
			break;
		
		case 2:
			int opcion2;

			cout << "\n1. Con auto." << endl;
			cout << "2. A pie." << endl;
			cout << "Ingrese opcion: ";
			cin >> opcion2;

			if (opcion2 == 1) {
				añadirEgresoAuto();
			}

			if (opcion2 == 2) {
				añadirEgresoPie();
			}
			break;
	
		case 3:
			int opcion3;

			cout << "\n1. Buscar por DNI." << endl;
			cout << "2. Buscar por nombre." << endl;
			cout << "Ingrese opcion: ";
			cin >> opcion3;

			if (opcion3 == 1) {
				buscarHistorialDNI();
			}

			if (opcion3 == 2) {
				buscarHistorialNombre();
			}
			break;
		
		case 4:
			return 0;
			break;
		}
	}
	return 0;
}