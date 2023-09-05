#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SantaMonica {
	char nombre[50];
	char patente[50];
	int dni;
	char lote[50];
	char nombreResidente[50];
	char fechaEntrada[50];
};

SantaMonica sm;

void añadirIngresoAuto() {

	ofstream añadir_ingreso("visitas.dat", ios::binary | ios::app);
	if (añadir_ingreso.is_open()) {

		cout << "\nIngrese el nombre del visitante: ";
		cin.ignore();
		cin.getline(sm.nombre, sizeof(sm.nombre));

		cout << "\nIngrese el DNI del visitante: ";
		cin >> sm.dni, sizeof(sm.dni);

		cout << "\nIngrese la patente del vehiculo: ";
		cin.ignore();
		cin.getline(sm.patente, sizeof(sm.patente));

		cout << "\nIngrese nombre de residente: ";
		cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));

		cout << "\nIngrese lote: ";
		cin.getline(sm.lote, sizeof(sm.lote));

		cout << "\nIngrese fecha de ingreso (dd/mm/aaaa): ";
		cin.getline(sm.fechaEntrada, sizeof(sm.fechaEntrada));

		añadir_ingreso.seekp(0, ios::end);
		añadir_ingreso.write(reinterpret_cast<char*>(&sm), sizeof(sm));
		añadir_ingreso.close();
	}
}

void añadirIngresoPie() {
	;
}

void añadirEgresoAuto() {
	;
}

void añadirEgresoPie() {
	;
}

void buscarHistorialNombre() {
	char nombreBuscar[50];
	cout << "\nIngrese el nombre del visitante a buscar: ";
	cin.ignore();
	cin.getline(nombreBuscar, sizeof(nombreBuscar));

	ifstream buscar_historial("visitas.dat", ios::binary);
	if (buscar_historial.is_open()) {
		cout << "\n---------- INGRESOS ----------" << endl;
		while (buscar_historial.read(reinterpret_cast<char*>(&sm), sizeof(sm))) {
			if (strcmp(sm.nombre, nombreBuscar) == 0) {
				cout << "\nNombre: " << sm.nombre << endl;
				cout << "DNI: " << sm.dni << endl;
				cout << "Patente: " << sm.patente << endl;
				cout << "Nombre de residente: " << sm.nombreResidente << endl;
				cout << "Lote de residente: " << sm.lote << endl;
				cout << "Fecha de ingreso: " << sm.fechaEntrada << endl;
			}
		}
		buscar_historial.close();
	}
}

void buscarHistorialDNI() {
	int dniBuscar;
	cout << "\nIngrese el DNI del visitante a buscar: ";
	cin >> dniBuscar;

	ifstream buscar_historialDNI("visitas.dat", ios::binary);
	if (buscar_historialDNI.is_open()) {
		cout << "\n---------- INGRESOS ----------" << endl;
		while (buscar_historialDNI.read(reinterpret_cast<char*>(&sm), sizeof(sm))) {
			if (sm.dni == dniBuscar) {
				cout << "\nNombre: " << sm.nombre << endl;
				cout << "DNI: " << sm.dni << endl;
				cout << "Patente: " << sm.patente << endl;
				cout << "Nombre de residente: " << sm.nombreResidente << endl;
				cout << "Lote de residente: " << sm.lote << endl;
				cout << "Fecha de ingreso: " << sm.fechaEntrada << endl;
			}
		}
		buscar_historialDNI.close();
	}
}