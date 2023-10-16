#include "Funcion.h"
#include <iostream>
#include <string>
using namespace std;


void Funcion::setPelicula(const Pelicula pelicula)
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


void Funcion::setEstado(bool estado)
{
	_estado = estado;
}

bool Funcion::getEstado() const
{
	return _estado;
}
void Funcion::setContadorEntrada(int contadorEntrada)
{
	_contadorEntrada = contadorEntrada;
}
int Funcion::getContadorEntrada() const
{
	return _contadorEntrada;
}
Funcion::Funcion()
{
}

Funcion::Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, int idFuncion)
{
	_pelicula = pelicula;
	_sala = sala;
	_fechaHoraFuncion = fechaHoraFuncion;
	_estado = true;
	_idFuncion = idFuncion;
	_contadorEntrada = 0;
}

void Funcion::mostrarDetalles()
{
	cout << "|||||| FUNCION  #" << _idFuncion <<" ||||||" << endl;
	cout << endl;
	_pelicula.mostrarDetalles();
	cout << endl;
	_sala.mostrarDetalles();
	cout << "Fecha y hora de la funcion: " << endl;
	_fechaHoraFuncion.mostrarFechaHora();
	cout <<"||||||||||||||||||||||||||||||||||"<< endl;
}

void Funcion::mostrarDetallesEntradas()
{
	cout << "|||||| FUNCION  #" << _idFuncion << " ||||||" << endl;
	cout << endl;
	_pelicula.mostrarDetalles();
	cout << endl;
	_sala.mostrarDetalles();
	cout << "Fecha y hora de la funcion: " << endl;
	_fechaHoraFuncion.mostrarFechaHora();
	cout << " Entradas Reservadas: " << _contadorEntrada << endl;
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||" << endl;
}




