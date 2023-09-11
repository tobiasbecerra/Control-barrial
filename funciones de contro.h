#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "funciones.h"
using namespace std;

SantaMonica ms;

bool esNombreValido(char* nombre) {

	for (int i = 0; nombre[i] != '\0'; ++i) {
		if (!isalpha(nombre[i]) && !isspace(nombre[i])) {
			return false;
		}
	}
	return true;
}

void controlarNombreEgreso() {



	while (true) {

		char* nombreLimpio = ms.nombre;
		while (*nombreLimpio && isspace(*nombreLimpio)) {
			nombreLimpio++;
		}
		if (strlen(nombreLimpio) == 0) {
			cout << "Error: El nombre no puede estar vacio." << endl;
			cout << "Por favor, ingresa el nombre nuevamente: ";
			cin.getline(ms.nombre, sizeof(ms.nombre));
		}
		else if (!esNombreValido(nombreLimpio)) {
			cout << "Error: Debes ingresar un nombre valido sin numeros ni simbolos." << endl;
			cout << "Por favor, ingresa el nombre nuevamente: ";
			cin.getline(ms.nombre, sizeof(ms.nombre));
		}
		else {
			break;
		}
	}
}