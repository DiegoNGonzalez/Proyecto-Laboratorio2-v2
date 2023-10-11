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

void Funcion::setEstado(bool estado)
{
	_estado = estado;
}

bool Funcion::getEstado() const
{
	return _estado;
}
Funcion::Funcion()
{
}

Funcion::Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, float precioEntrada, int idFuncion)
{
	_pelicula = pelicula;
	_sala = sala;
	_fechaHoraFuncion = fechaHoraFuncion;
	_precioEntrada = precioEntrada;
	_estado = true;
	_idFuncion = idFuncion;
}

void Funcion::mostrarDetalles()
{
	cout << "Pelicula: " << endl;
	_pelicula.mostrarDetalles();
	cout << "Sala: " << endl;
	_sala.mostrarDetalles();
	cout << "Fecha y hora de la funcion: " << endl;
	_fechaHoraFuncion.mostrarFechaHora();
	cout << "Precio de la entrada: $" << _precioEntrada << endl;
	
	cout << "id funcion " << _idFuncion << endl;	

}





