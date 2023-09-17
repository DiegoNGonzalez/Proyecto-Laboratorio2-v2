#include "Funcion.h"
#include <iostream>
#include <string>
using namespace std;

//private:
//	Pelicula _pelicula;
//	Sala _sala;
//	FechaHorario _fechaHoraFuncion;
//	int _asientosDisponibles;
//	int _asientosReservados;
//	public:
//
//		void setPelicula(Pelicula pelicula);
//		Pelicula getPelicula();
//		void setSala(Sala sala);
//		Sala getSala();
//		void setFechaHoraFuncion(FechaHorario fechaHoraFuncion);
//		FechaHorario getFechaHoraFuncion();
//		void setAsientosDisponibles(int asientosDisponibles);
//		int getAsientosDisponibles();
//		void setAsientosReservados(int asientosReservados);
//		int getAsientosReservados();
//		Funcion();
//		Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, int asientosDisponibles, int asientosReservados);
//		void mostrarDetalles();
//		void reservarAsiento();
//		bool hayAsientosDisponibles();


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

void Funcion::setAsientosDisponibles(int asientosDisponibles)
{
	_asientosDisponibles = asientosDisponibles;
}

int Funcion::getAsientosDisponibles()
{
	return _asientosDisponibles;
}

void Funcion::setAsientosReservados(int asientosReservados)
{
	_asientosReservados = asientosReservados;
}

int Funcion::getAsientosReservados()
{
	return _asientosReservados;
}

void Funcion::setIdFuncion(int idFuncion)
{
	_idFuncion = idFuncion;
}

int Funcion::getIdFuncion()
{
	return _idFuncion;
}

Funcion::Funcion()
{
}

Funcion::Funcion(Pelicula pelicula, Sala sala, FechaHorario fechaHoraFuncion, int asientosDisponibles, int asientosReservados)
{
	_pelicula = pelicula;
	_sala = sala;
	_fechaHoraFuncion = fechaHoraFuncion;
	_asientosDisponibles = asientosDisponibles;
	_asientosReservados = asientosReservados;
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
	cout << "Asientos disponibles: " << _asientosDisponibles << endl;
	cout << "Asientos reservados: " << _asientosReservados << endl;
}

void Funcion::reservarAsiento()
{
	if (hayAsientosDisponibles())
	{
		_asientosDisponibles--;
		_asientosReservados++;
	}
	else
	{
		cout << "No hay asientos disponibles" << endl;
	}
}

void Funcion::reservarAsiento(int cantidad)
{
	if (hayAsientosDisponibles())
	{
		_asientosDisponibles -= cantidad;
		_asientosReservados += cantidad;
	}
	else
	{
		cout << "No hay asientos disponibles" << endl;
	}
}

bool Funcion::hayAsientosDisponibles()
{
	return _asientosDisponibles > 0;
}


