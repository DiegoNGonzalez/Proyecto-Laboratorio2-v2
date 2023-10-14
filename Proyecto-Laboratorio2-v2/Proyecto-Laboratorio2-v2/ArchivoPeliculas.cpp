#include "ArchivoPeliculas.h"
#include <iostream>
Pelicula ArchivoPeliculas::leerRegistro(int posicion) {
	Pelicula pelicula;
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) {
		std::cout << "Error al tratar de leer" << std::endl;
		return pelicula;
	}
	fseek(p, posicion * sizeof(Pelicula), SEEK_SET);
	fread(&pelicula, sizeof(Pelicula), 1, p);
	fclose(p);
	return pelicula;
}
int ArchivoPeliculas::contarRegistros() {
	FILE* p;
	p = fopen(_nombre, "rb");
	if (p == NULL) { 
		std::cout << "Error al contar" << std::endl;
		return -1; };
	fseek(p, 0, 2);
	int tam = ftell(p);
	fclose(p);
	return tam / sizeof(Pelicula);
};
bool ArchivoPeliculas::grabarRegistro(Pelicula pelicula) {
	FILE* p;
	p = fopen(_nombre, "ab");
	if (p == NULL) { 
		std::cout << "Error al grabar registro" << std::endl;
		return false; };
	int escribio = fwrite(&pelicula, sizeof pelicula, 1, p);
	fclose(p);
	return escribio;
};