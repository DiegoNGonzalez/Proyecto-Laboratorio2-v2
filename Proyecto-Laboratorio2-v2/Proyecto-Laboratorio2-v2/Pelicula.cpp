#include "Pelicula.h"
#include <iostream>
#include <string>


void Pelicula::setId(int id)
{
	_id = id;
}

int Pelicula::getId()
{
	return _id;
}
void Pelicula::setTitulo(std::string titulo)
{
	strcpy(_titulo, titulo.c_str());
}

char* Pelicula::getTitulo()
{
	return _titulo;
}

void Pelicula::setDirector(std::string director)
{
	strcpy(_director, director.c_str());
}

char* Pelicula::getDirector()
{
	return _director;
}

void Pelicula::setClasificacionEdad(std::string clasificacionEdad)
{
	strcpy(_clasificacionEdad, clasificacionEdad.c_str());
}

char* Pelicula::getClasificacionEdad()
{
	return _clasificacionEdad;
}

void Pelicula::setGenero(std::string genero)
{
	strcpy(_genero, genero.c_str());
}

char* Pelicula::getGenero()
{
	return _genero;
}


void Pelicula::setDuracion(int duracion)
{
	_duracion = duracion;
}

int Pelicula::getDuracion() const
{
	return _duracion;
}

void Pelicula::setEstado(bool estado)
{
	_estado = estado;
}

bool Pelicula::getEstado() const
{
	return _estado;
}
Pelicula::Pelicula()
{
	strcpy(_titulo, "Transformers");
	strcpy(_director, "Julian Alvarez");
	strcpy(_clasificacionEdad, "+18");
	strcpy(_genero, "Accion");
	_duracion = 0;
	_estado = true;
}

Pelicula::Pelicula(int id, const char *titulo, const char* director, const char* clasificacionEdad, const char* genero, int duracion)
{
	strcpy(_titulo, titulo);
	strcpy(_director, director);
	strcpy(_clasificacionEdad, clasificacionEdad);
	strcpy(_genero, genero);
	_duracion = duracion;
	_id = id;
	_estado = true;
}

void Pelicula::mostrarDetalles() const
{
	std::cout << "--------- PELICULA #" << _id << " ---------" << std::endl;
	std::cout << "TITULO: " << _titulo << std::endl;
	std::cout << "DIRECTOR: " << _director << std::endl;
	std::cout << "CLASIFICACION DE EDAD: " << _clasificacionEdad << std::endl;
	std::cout << "GENERO: " << _genero << std::endl;
	std::cout << "DURACION: " << _duracion << " MINUTOS." << std::endl;
}


