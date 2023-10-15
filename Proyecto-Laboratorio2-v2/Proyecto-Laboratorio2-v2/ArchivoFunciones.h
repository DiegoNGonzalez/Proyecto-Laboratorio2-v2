#pragma once
#include <Windows.h>
#include <cstring>
#include "Funcion.h"
#include "rlutil.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"
#include "ArchivoDiagrama.h"
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
	bool grabarRegistro(Funcion funcion, int posicion);
	bool generarBackUp();
	bool restaurarBackUp();
	int validarId();
	int buscarPosFuncionxID(int valorBuscado);
	Funcion buscarFuncionxID(int valorBuscado);
	
};

