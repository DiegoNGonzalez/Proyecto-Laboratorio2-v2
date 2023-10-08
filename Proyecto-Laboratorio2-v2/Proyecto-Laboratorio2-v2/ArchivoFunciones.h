#pragma once
#include <cstring>
#include "Funcion.h"
class ArchivoFunciones
{
private:
	char _nombre[30];
public:
	ArchivoFunciones(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	Funcion leerRegistro(int posicion);
	int contarRegistros();
	bool grabarRegistro(Funcion funcion);
};

