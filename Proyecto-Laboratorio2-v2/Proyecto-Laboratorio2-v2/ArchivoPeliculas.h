#pragma once
#include <cstring>
#include "Pelicula.h"
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
		void generarBackUp();
		void restaurarBackUp();

};

