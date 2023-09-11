#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "funciones de contro.h"
using namespace std;

struct SantaMonica {
	char nombre[50];
	char patente[50];
	char dni[50];
	char lote[50];
	char nombreResidente[50];
	char fechaEntrada[50];
	char fechaEgreso[50];
};

SantaMonica sm;

void añadirIngresoAuto() {

	ofstream añadir_ingreso("ingreso.dat", ios::binary | ios::app);
	if (añadir_ingreso.is_open()) {

		cout << "\nIngrese el nombre del visitante: ";
		cin.ignore();
		cin.getline(sm.nombre, sizeof(sm.nombre));

		cout << "\nIngrese el DNI del visitante: ";
		cin.getline(sm.dni, sizeof(sm.dni));

		cout << "\nIngrese la patente del vehiculo: ";
		cin.getline(sm.patente, sizeof(sm.patente));

		cout << "\nIngrese nombre de residente: ";
		cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));

		cout << "\nIngrese lote: ";
		cin.getline(sm.lote, sizeof(sm.lote));

		cout << "\nIngrese fecha de ingreso (dd/mm/aaaa): ";
		cin.getline(sm.fechaEntrada, sizeof(sm.fechaEntrada));

		cout << "\n----------INGRESO CARGADO CORRECTAMENTE----------" << endl;

		añadir_ingreso.seekp(0, ios::end);
		añadir_ingreso.write(reinterpret_cast<char*>(&sm), sizeof(sm));
		añadir_ingreso.close();
	}
}

void añadirEgresoAuto() {

	ofstream añadir_egreso("egreso.dat", ios::binary);
	if (añadir_egreso.is_open()) {

		cout << "\nIngrese el nombre del visitante: ";
		cin.ignore();
		cin.getline(sm.nombre, sizeof(sm.nombre));
		controlarNombreEgreso();

		cout << "\nIngrese el DNI del visitante: ";
		cin.getline(sm.dni, sizeof(sm.dni));

		cout << "\nIngrese la patente del vehiculo: ";
		cin.getline(sm.patente, sizeof(sm.patente));

		cout << "\nIngrese nombre de residente: ";
		cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));

		cout << "\nIngrese lote: ";
		cin.getline(sm.lote, sizeof(sm.lote));

		cout << "\nIngrese fecha de egreso: ";
		cin.getline(sm.fechaEgreso, sizeof(sm.fechaEgreso));

		cout << "\n----------INGRESO CARGADO CORRECTAMENTE----------" << endl;

		añadir_egreso.seekp(0, ios::end);
		añadir_egreso.write(reinterpret_cast<char*>(&sm), sizeof(sm));
		añadir_egreso.close();
	}
}

void añadirIngresoPie() {
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

	ifstream buscar_historial("ingreso.dat", ios::binary);
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
		cout << "\n------------------------------" << endl;
		buscar_historial.close();
	}
}

void buscarHistorialDNI() {
	char dniBuscar[50];
	cout << "\nIngrese el DNI del visitante a buscar: ";
	cin >> dniBuscar;

	ifstream buscar_historialDNI("ingreso.dat", ios::binary);
	if (buscar_historialDNI.is_open()) {
		cout << "\n---------- INGRESOS ----------" << endl;
		while (buscar_historialDNI.read(reinterpret_cast<char*>(&sm), sizeof(sm))) {
			if (strcmp(sm.dni, dniBuscar) == 0) {
				cout << "\nNombre: " << sm.nombre << endl;
				cout << "DNI: " << sm.dni << endl;
				cout << "Patente: " << sm.patente << endl;
				cout << "Nombre de residente: " << sm.nombreResidente << endl;
				cout << "Lote de residente: " << sm.lote << endl;
				cout << "Fecha de ingreso: " << sm.fechaEntrada << endl;
			}
		}
		cout << "\n------------------------------" << endl;
		buscar_historialDNI.close();
	}
}