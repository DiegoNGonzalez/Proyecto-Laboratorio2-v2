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
	 strcpy(_genero,"Accion");
	_duracion = 0;
	_estado = true;
}

Pelicula::Pelicula(int id, std::string titulo, std::string director, std::string clasificacionEdad, std::string genero, int duracion)
{
	strcpy(_titulo, titulo.c_str());
	strcpy(_director, director.c_str());
	strcpy(_clasificacionEdad, clasificacionEdad.c_str());
	strcpy(_genero, genero.c_str());
	_duracion=duracion;
	_id = id;
	_estado = true;
}

void Pelicula::mostrarDetalles() const
{
	cout << "Titulo: " << _titulo << endl;
	cout << "Director: " << _director << endl;
	cout << "Clasificacion de edad: " << _clasificacionEdad << endl;
	cout << "Genero: " << _genero << endl;
	cout << "Duracion: " <<_duracion <<" min."<< endl;
	cout << "Id: " << _id << endl;
}


