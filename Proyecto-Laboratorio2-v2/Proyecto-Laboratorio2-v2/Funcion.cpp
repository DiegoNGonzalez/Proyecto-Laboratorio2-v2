#include "Funcion.h"
#include <iostream>
#include <string>
using namespace std;


 void Funcion::setPelicula(const Pelicula pelicula )
{
	 	_pelicula = pelicula;
}

Pelicula Funcion::getPelicula()
{
	return _pelicula;
}

void Funcion::setSala(Sala sala)
{
	_sala = sala;
}

Sala Funcion::getSala()
{
	return _sala;
}

void Funcion::setFechaHoraFuncion(FechaHorario fechaHoraFuncion)
{
	_fechaHoraFuncion = fechaHoraFuncion;
}

FechaHorario Funcion::getFechaHoraFuncion()
{
	return _fechaHoraFuncion;
}

void Funcion::setIdFuncion(int idFuncion)
{
	_idFuncion = idFuncion;
}

int Funcion::getIdFuncion() const
{
	return _idFuncion;
}

void Funcion::setPrecioEntrada(float precioEntrada)
{
	_precioEntrada = precioEntrada;
}

float Funcion::getPrecioEntrada() const
{
	return _precioEntrada;
}

Funcion::Funcion()
{
}

Funcion::Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, float precioEntrada)
{
	_pelicula = pelicula;
	_sala = sala;
	_fechaHoraFuncion = fechaHoraFuncion;
	_precioEntrada = precioEntrada;

}

void Funcion::mostrarDetalles()
{
	cout << "Funcion: " << endl;
	cout << "Pelicula: " << endl;
	_pelicula.mostrarDetalles();
	cout << "Sala: " << endl;
	_sala.mostrarDetalles();
	cout << "Fecha y hora de la funcion: " << endl;
	cout << _fechaHoraFuncion.toString() << endl;
	cout << "Precio de la entrada: $" << _precioEntrada << endl;

}






