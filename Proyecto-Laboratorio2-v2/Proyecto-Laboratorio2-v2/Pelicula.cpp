#include "Pelicula.h"
#include <iostream>
#include <string>
using namespace std;

//private:
//	std::string _titulo;
//	std::string _director;
//	std::string _clasificacionEdad;
//	std::string _genero;
//	Horario _duracion;
//	public:
//		void setTitulo(std::string titulo);
//		std::string getTitulo();
//		void setDirector(std::string director);
//		std::string getDirector();
//		void setClasificacionEdad(std::string clasificacionEdad);
//		std::string getClasificacionEdad();
//		void setGenero(std::string genero);
//		std::string getGenero();
//		void setDuracion(Horario duracion);
//		Horario getDuracion();
//		Pelicula();
//		Pelicula(std::string titulo, std::string director, std::string clasificacionEdad, std::string genero, Horario duracion);
//		void mostrarDetalles();

void Pelicula::setId(int id)
{
	_id = id;
}

int Pelicula::getId() const
{
	return _id;
}
void Pelicula::setTitulo(std::string titulo)
{
	_titulo = titulo;
}

std::string Pelicula::getTitulo()
{
	return _titulo;
}

void Pelicula::setDirector(std::string director)
{
	_director = director;
}

std::string Pelicula::getDirector()
{
	return _director;
}

void Pelicula::setClasificacionEdad(std::string clasificacionEdad)
{
	_clasificacionEdad = clasificacionEdad;
}

std::string Pelicula::getClasificacionEdad()
{
	return _clasificacionEdad;
}

void Pelicula::setGenero(std::string genero)
{
	_genero = genero;
}

std::string Pelicula::getGenero()
{
	return _genero;
}

void Pelicula::setHora(int hora)
{
	_hora=hora;
}

int Pelicula::getHora() const
{
	return _hora;
}

void Pelicula::setMinuto(int minuto)
{
	_minuto = minuto;
}

int Pelicula::getMinuto() const
{
	return _minuto;
}

Pelicula::Pelicula()
{
	_titulo = "";
	_director = "";
	_clasificacionEdad = "";
	_genero = "";
	_hora = 0;
	_minuto = 0;
}

Pelicula::Pelicula(int id,std::string titulo, std::string director, std::string clasificacionEdad, std::string genero, int hora, int minuto)
{
	_titulo = titulo;
	_director = director;
	_clasificacionEdad = clasificacionEdad;
	_genero = genero;
	_hora=hora;
	_minuto=minuto;
}

void Pelicula::mostrarDetalles() const
{
	cout << "Titulo: " << _titulo << endl;
	cout << "Director: " << _director << endl;
	cout << "Clasificacion de edad: " << _clasificacionEdad << endl;
	cout << "Genero: " << _genero << endl;
	cout << "Duracion: " << _hora <<":"<<_minuto << endl;
}


