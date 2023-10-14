#include "ArchivoFunciones.h"
#include <iostream>

Funcion ArchivoFunciones::leerRegistro(int posicion) {
	Funcion funcion;
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al tratar de leer" << std::endl;
		return funcion;
	}
	fseek(p, posicion * sizeof(Funcion), SEEK_SET);
	fread(&funcion, sizeof(Funcion), 1, p);
	fclose(p);
	return funcion;
}
int ArchivoFunciones::contarRegistros() {
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) { 
		std::cout << "Error al contar" << std::endl;
		return -1; 
	};
	fseek(p, 0, 2);
	int tam = ftell(p);
	fclose(p);
	return tam / sizeof(Funcion);
};
bool ArchivoFunciones::grabarRegistro(Funcion funcion) {
	FILE* p;
	p = fopen(_nombre, "ab");
	if (p == NULL) {
		std::cout << "Error al grabar registro" << std::endl;
		return false;
	};
	int escribio = fwrite(&funcion, sizeof funcion, 1, p);
	fclose(p);
	return escribio;
};