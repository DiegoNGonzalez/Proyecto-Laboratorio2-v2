#pragma once
#include <cstring>
#include "Pelicula.h"
#include <Windows.h>
#include "rlutil.h"
class ArchivoPeliculas
{
	private:
	char _nombre[30];
	public:
		ArchivoPeliculas(const char* nombre) {
		strcpy(_nombre, nombre);
	}
		Pelicula leerRegistro(int posicion);
		int contarRegistros();
		bool grabarRegistro(Pelicula pelicula);
		bool generarBackUp();
		bool restaurarBackUp();
		int validarId();

};

