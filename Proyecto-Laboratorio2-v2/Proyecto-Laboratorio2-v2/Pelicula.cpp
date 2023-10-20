#include "Pelicula.h"
#include <iostream>
#include <string>
using namespace std;


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

Pelicula::Pelicula(int id, std::string titulo, std::string director, std::string clasificacionEdad, std::string genero, int duracion)
{
	strcpy(_titulo, titulo.c_str());
	strcpy(_director, director.c_str());
	strcpy(_clasificacionEdad, clasificacionEdad.c_str());
	strcpy(_genero, genero.c_str());
	_duracion = duracion;
	_id = id;
	_estado = true;
}

void Pelicula::mostrarDetalles() const
{
	cout << "--------- PELICULA #" << _id << " ---------" << endl;
	cout << "TITULO: " << _titulo << endl;
	cout << "DIRECTOR: " << _director << endl;
	cout << "CLASIFICACION DE EDAD: " << _clasificacionEdad << endl;
	cout << "GENERO: " << _genero << endl;
	cout << "DURACION: " << _duracion << " MINUTOS." << endl;
}


