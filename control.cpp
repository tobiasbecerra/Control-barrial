#include <iostream>
#include <fstream>
#include <string>
#include "funciones.h"
using namespace std;

int main() {
	
	int opc = 0;

	while (opc != 11) {
		cout << "\n1. Añadir ingreso al barrio." << endl;
		cout << "2. Añadir egreso del barrio." << endl;
		cout << "3. Buscar historial de personas. " << endl;
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
				;
			}
			break;
		case 2:
			break;
		case 3:
			int opcion1;

			cout << "\n1. Buscar por DNI." << endl;
			cout << "2. Buscar por nombre." << endl;
			cout << "Ingrese opcion: ";
			cin >> opcion1;

			if (opcion1 == 1) {
				buscarHistorialDNI();
			}

			if (opcion1 == 2) {
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