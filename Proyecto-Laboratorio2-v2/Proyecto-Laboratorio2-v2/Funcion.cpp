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
Funcion::Funcion()
{
	_estado = false;
	_idFuncion = 0;
}
Funcion::Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, int idFuncion)
{
	_pelicula = pelicula;
	_sala = sala;
	_fechaHoraFuncion = fechaHoraFuncion;
	_estado = true;
	_idFuncion = idFuncion;
}
void Funcion::mostrarDetalles()
{
	cout << "--------- FUNCION  #" << _idFuncion <<" ---------" << endl;
	cout << endl;
	_pelicula.mostrarDetalles();
	cout << endl;
	_sala.mostrarDetalles();
	cout << "Fecha y hora de la funcion: ";
	_fechaHoraFuncion.mostrarFechaHora();
	cout << std::endl << "------------------------------------"<< endl;
}