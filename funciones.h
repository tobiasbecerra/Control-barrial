#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
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

bool esNombreValido(char* nombre) {

	for (int i = 0; nombre[i] != '\0'; ++i) {

		if (!isalpha(nombre[i]) && !isspace(nombre[i])) {
			
			return false;
		}
	}

	return true;
}

bool esDniValido(char* dni) {

	for (int i = 0; dni[i] != '\0'; ++i) {

		if (!isdigit(dni[i])) {

			return false;
		}
	}
	return true;
}

bool esNombreresidenteValido(char* nombreResidente) {

	for (int i = 0; nombreResidente[i] != '\0'; ++i) {
		if (!isalpha(nombreResidente[i]) && !isspace(nombreResidente[i])) {
			return false;
		}
	}
	return true;
}

bool esfechaEgresoValida(char* fechaEgreso) {

	for (int i = 0; fechaEgreso[i] != '\0'; ++i) {
		if (!isdigit(fechaEgreso[i]) && fechaEgreso[i] != '/') {
			return false;
		}
	}
	return true;

}


void añadirIngresoAuto() {

	ofstream añadir_ingreso("ingreso.dat", ios::binary | ios::app);
	if (añadir_ingreso.is_open()) {

		cout << "\nIngrese el nombre del visitante: ";
		cin.ignore();
		cin.getline(sm.nombre, sizeof(sm.nombre));
		while (true) {

			char* nombreLimpio = sm.nombre;
			while (*nombreLimpio && isspace(*nombreLimpio)) {
				nombreLimpio++;
			}

			if (strlen(nombreLimpio) == 0) {
				cout << "Error: El nombre no puede estar vacio." << endl;
				cout << "Por favor, ingresa el nombre nuevamente: ";
				cin.getline(sm.nombre, sizeof(sm.nombre));
			}

			else if (!esNombreValido(nombreLimpio)) {
				cout << "Error: Debes ingresar un nombre valido sin numeros ni simbolos." << endl;
				cout << "Por favor, ingresa el nombre nuevamente: ";
				cin.getline(sm.nombre, sizeof(sm.nombre));
			}

			else {
				break;
			}
		}

		cout << "\nIngrese el DNI del visitante: ";
		cin.getline(sm.dni, sizeof(sm.dni));

		while (true) {

			char* dniLimpio = sm.dni;

			while (*dniLimpio && isspace(*dniLimpio)) {
				dniLimpio++;
			}

			if (strlen(dniLimpio) == 0) {
				cout << "Error: El dni no puede estar vacio." << endl;
				cout << "Por favor, ingresa el dni nuevamente: ";
				cin.getline(sm.dni, sizeof(sm.dni));
			}

			else if (!esDniValido(sm.dni)) {
				cout << "ERROR: El DNI solo acepta numeros sin espacios." << endl;
				cout << "Por favor, ingresa el DNI nuevamente: ";
				cin.getline(sm.dni, sizeof(sm.dni));
			}

			else {
				break;
			}
		}

		cout << "\nIngrese la patente del vehiculo: ";
		cin.getline(sm.patente, sizeof(sm.patente));
		
		while (true) {
			
			char* patenteLimpia = sm.patente;
			while (*patenteLimpia && isspace(*patenteLimpia)) {
				patenteLimpia++;
			}

			if (strlen(patenteLimpia) == 0) {
				cout << "Error: La patente no puede estar vacia." << endl;
				cout << "Por favor, ingresa la patente nuevamente: ";
				cin.getline(sm.patente, sizeof(sm.patente));
			}

			else {
				break;
			}
		}

		cout << "\nIngrese nombre de residente: ";
		cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));
		while (true) {

			char* nombreresidenteLimpio = sm.nombreResidente;

			while (*nombreresidenteLimpio && isspace(*nombreresidenteLimpio)) {
				nombreresidenteLimpio++;
			}

			if (strlen(nombreresidenteLimpio) == 0) {
				cout << "Error: El nombre del residente no puede estar vacio." << endl;
				cout << "Por favor, ingresa el nombre nuevamente: ";
				cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));
			}

			else if (!esNombreresidenteValido(nombreresidenteLimpio)) {
				cout << "Error: Debes ingresar un nombre valido sin numeros ni simbolos." << endl;
				cout << "Por favor, ingresa el nombre nuevamente: ";
				cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));
			}

			else {
				break;
			}
		}

		cout << "\nIngrese lote: ";
		cin.getline(sm.lote, sizeof(sm.lote));
		while (true) {

			char* loteLimpio = sm.lote;

			while (*loteLimpio && isspace(*loteLimpio)) {
				loteLimpio++;
			}

			if (strlen(loteLimpio) == 0) {
				cout << "Error: El lote no puede estar vacio." << endl;
				cout << "Por favor, ingrese el lote nuevamente: ";
				cin.getline(sm.lote, sizeof(sm.lote));
			}

			else
			{
				break;
			}
		}

		cout << "\nIngrese fecha de ingreso (dd/mm/aaaa): ";
		cin.getline(sm.fechaEntrada, sizeof(sm.fechaEntrada));
		while (true) {

			char* fechaIgresoLimpia = sm.fechaEntrada;

			while (*fechaIgresoLimpia && isspace(*fechaIgresoLimpia)) {
				fechaIgresoLimpia++;
			}

			if (strlen(fechaIgresoLimpia) == 0) {
				cout << "Error: La fecha no puede estar vacia." << endl;
				cout << "Por favor, ingrese la fecha nuevamente: ";
				cin.getline(sm.fechaEntrada, sizeof(sm.fechaEntrada));
			}

			else if (!esfechaEgresoValida(sm.fechaEntrada)) {
				cout << "ERROR: La fecha en la que entro solo acepta el formato dd/mm/aaaa, con sus respectivos numeros: " << endl;
				cout << "Por favor, ingresa la fecha en la que entro nuevamente: ";
				cin.getline(sm.fechaEntrada, sizeof(sm.fechaEntrada));
			}

			else {
				break;
			}
		}


		cout << "\n----------INGRESO CARGADO CORRECTAMENTE----------" << endl;

		añadir_ingreso.seekp(0, ios::end);
		añadir_ingreso.write(reinterpret_cast<char*>(&sm), sizeof(sm));
		añadir_ingreso.close();
	}
}

void añadirEgresoAuto() {

	ofstream añadir_egreso("egreso.dat", ios::binary | ios::app);
	if (añadir_egreso.is_open()) {

		cout << "\nIngrese el nombre del visitante: ";
		cin.ignore();
		cin.getline(sm.nombre, sizeof(sm.nombre));
		while (true) {

			char* nombreLimpio = sm.nombre;
			while (*nombreLimpio && isspace(*nombreLimpio)) {
				nombreLimpio++;
			}

			if (strlen(nombreLimpio) == 0) {
				cout << "Error: El nombre no puede estar vacio." << endl;
				cout << "Por favor, ingresa el nombre nuevamente: ";
				cin.getline(sm.nombre, sizeof(sm.nombre));
			}

			else if (!esNombreValido(nombreLimpio)) {
				cout << "Error: Debes ingresar un nombre valido sin numeros ni simbolos." << endl;
				cout << "Por favor, ingresa el nombre nuevamente: ";
				cin.getline(sm.nombre, sizeof(sm.nombre));
			}

			else {
				break;
			}
		}

		cout << "\nIngrese el DNI del visitante: ";
		cin.getline(sm.dni, sizeof(sm.dni));
		while (true) {

			char* dniLimpio = sm.dni;

			while (*dniLimpio && isspace(*dniLimpio)) {
				dniLimpio++;
			}

			if (strlen(dniLimpio) == 0) {
				cout << "Error: El dni no puede estar vacio." << endl;
				cout << "Por favor, ingresa el dni nuevamente: ";
				cin.getline(sm.dni, sizeof(sm.dni));
			}

			else if (!esDniValido(sm.dni)) {
				cout << "ERROR: El DNI solo acepta numeros sin espacios." << endl;
				cout << "Por favor, ingresa el DNI nuevamente: ";
				cin.getline(sm.dni, sizeof(sm.dni));
			}

			else {
				break;
			}
		}

		cout << "\nIngrese la patente del vehiculo: ";
		cin.getline(sm.patente, sizeof(sm.patente));
		while (true) {

			char* patenteLimpia = sm.patente;
			while (*patenteLimpia && isspace(*patenteLimpia)) {
				patenteLimpia++;
			}

			if (strlen(patenteLimpia) == 0) {
				cout << "Error: La patente no puede estar vacia." << endl;
				cout << "Por favor, ingresa la patente nuevamente: ";
				cin.getline(sm.patente, sizeof(sm.patente));
			}

			else {
				break;
			}
		}

		cout << "\nIngrese nombre de residente: ";
		cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));
		while (true) {

			char* nombreresidenteLimpio = sm.nombreResidente;

			while (*nombreresidenteLimpio && isspace(*nombreresidenteLimpio)) {
				nombreresidenteLimpio++;
			}

			if (strlen(nombreresidenteLimpio) == 0) {
				cout << "Error: El nombre del residente no puede estar vacio." << endl;
				cout << "Por favor, ingresa el nombre nuevamente: ";
				cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));
			}

			else if (!esNombreresidenteValido(nombreresidenteLimpio)) {
				cout << "Error: Debes ingresar un nombre valido sin numeros ni simbolos." << endl;
				cout << "Por favor, ingresa el nombre nuevamente: ";
				cin.getline(sm.nombreResidente, sizeof(sm.nombreResidente));
			}

			else {
				break;
			}
		}

		cout << "\nIngrese lote: ";
		cin.getline(sm.lote, sizeof(sm.lote));
		while (true) {

			char* loteLimpio = sm.lote;

			while (*loteLimpio && isspace(*loteLimpio)) {
				loteLimpio++;
			}

			if (strlen(loteLimpio) == 0) {
				cout << "Error: El lote no puede estar vacio." << endl;
				cout << "Por favor, ingrese el lote nuevamente: ";
				cin.getline(sm.lote, sizeof(sm.lote));
			}

			else
			{
				break;
			}
		}

		cout << "\nIngrese fecha de egreso: ";
		cin.getline(sm.fechaEgreso, sizeof(sm.fechaEgreso));
		while (true) {

			char* fechaEgresoLimpia = sm.fechaEgreso;

			while (*fechaEgresoLimpia && isspace(*fechaEgresoLimpia)) {
				fechaEgresoLimpia++;
			}

			if (strlen(fechaEgresoLimpia) == 0) {
				cout << "Error: La fecha no puede estar vacia." << endl;
				cout << "Por favor, ingrese la fecha nuevamente: ";
				cin.getline(sm.fechaEntrada, sizeof(sm.fechaEntrada));
			}

			else if (!esfechaEgresoValida(sm.fechaEntrada)) {
				cout << "ERROR: La fecha en la que salio solo acepta el formato dd/mm/aaaa, con sus respectivos numeros: " << endl;
				cout << "Por favor, ingresa la fecha en la que salio nuevamente: ";
				cin.getline(sm.fechaEgreso, sizeof(sm.fechaEgreso));
			}

			else {
				break;
			}
		}

		cout << "\n----------EGRESO CARGADO CORRECTAMENTE----------" << endl;

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
		buscar_historial.close();
	}

	ifstream buscar_historial_nombre_egreso("egreso.dat", ios::binary);
	if (buscar_historial_nombre_egreso.is_open()) {
		cout << "\n---------- EGRESOS ----------" << endl;
		while (buscar_historial_nombre_egreso.read(reinterpret_cast<char*>(&sm), sizeof(sm))) {
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
		buscar_historial_nombre_egreso.close();
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
		buscar_historialDNI.close();
	}

	ifstream buscar_historial_dni_egreso("egreso.dat", ios::binary);
	if (buscar_historial_dni_egreso.is_open()) {
		cout << "\n---------- EGRESOS ----------" << endl;
		while (buscar_historial_dni_egreso.read(reinterpret_cast<char*>(&sm), sizeof(sm))) {
			if (strcmp(sm.dni, dniBuscar) == 0) {
				cout << "\nNombre: " << sm.nombre << endl;
				cout << "DNI: " << sm.dni << endl;
				cout << "Patente: " << sm.patente << endl;
				cout << "Nombre de residente: " << sm.nombreResidente << endl;
				cout << "Lote de residente: " << sm.lote << endl;
				cout << "Fecha de ingreso: " << sm.fechaEgreso << endl;
			}
		}
		cout << "\n------------------------------" << endl;
		buscar_historial_dni_egreso.close();
	}
}