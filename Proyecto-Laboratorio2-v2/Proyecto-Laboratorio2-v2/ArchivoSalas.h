#pragma once
#include <cstring>
#include "Sala.h"
#include <Windows.h>
#include "rlutil.h"
class ArchivoSalas
{
private:
	char _nombre[30];
public:
	ArchivoSalas(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	Sala leerRegistro(int posicion);
	int contarRegistros();
	bool grabarRegistro(Sala sala);
	bool generarBackUp();
	bool restaurarBackUp();
	int validarId();
	int buscarPosSalaxID(int valorBuscado);

};

