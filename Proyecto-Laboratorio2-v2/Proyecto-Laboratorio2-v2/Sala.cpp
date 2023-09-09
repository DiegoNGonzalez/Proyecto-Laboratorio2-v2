#include "Sala.h"
#include <iostream>
#include <string>
using namespace std;

//private:
//	int _numeroSala;
//	int _capacidadMaximaAsientos;
//	float _precioEntrada;
//	Pelicula _pelicula;
//	public:
//
//		void setNumeroSala(int numeroSala);
//		int getNumeroSala();
//		void setCapacidadMaximaAsientos(int capacidadMaximaAsientos);
//		int getCapacidadMaximaAsientos();
//		void setPrecioEntrada(float precioEntrada);
//		float getPrecioEntrada();
//		void setPelicula(Pelicula pelicula);
//		Pelicula getPelicula();
//		Sala();
//		Sala(int numeroSala, int capacidadMaximaAsientos, float precioEntrada);
//		void asignarPelicula(Pelicula pelicula);
//		void mostrarDetalles();
//};

void Sala::setNumeroSala(int numeroSala)
{
	_numeroSala = numeroSala;
}

int Sala::getNumeroSala()
{
	return _numeroSala;
}

void Sala::setCapacidadMaximaAsientos(int capacidadMaximaAsientos)
{
	_capacidadMaximaAsientos = capacidadMaximaAsientos;
}

int Sala::getCapacidadMaximaAsientos()
{
	return _capacidadMaximaAsientos;
}

void Sala::setPrecioEntrada(float precioEntrada)
{
	_precioEntrada = precioEntrada;
}

float Sala::getPrecioEntrada()
{
	return _precioEntrada;
}

void Sala::setPelicula(Pelicula pelicula)
{
	_pelicula = pelicula;
}

Pelicula Sala::getPelicula()
{
	return _pelicula;
}

Sala::Sala()
{
	_numeroSala = 0;
	_capacidadMaximaAsientos = 0;
	_precioEntrada = 0;
}

Sala::Sala(int numeroSala, int capacidadMaximaAsientos, float precioEntrada, Pelicula pelicula)
{
	_numeroSala = numeroSala;
	_capacidadMaximaAsientos = capacidadMaximaAsientos;
	_precioEntrada = precioEntrada;
	_pelicula = pelicula;
}


void Sala::mostrarDetalles()
{
	cout << "Numero de sala: " << _numeroSala << endl;
	cout << "Capacidad maxima de asientos: " << _capacidadMaximaAsientos << endl;
	cout << "Precio de la entrada: " << _precioEntrada << endl;
	cout << "Pelicula: " << _pelicula.getTitulo() << endl;
}

void Sala::descontarAsientos()
{
	_capacidadMaximaAsientos--;
}

void Sala::descontarAsientos(int cantidad)
{
	_capacidadMaximaAsientos -= cantidad;
}
bool Sala::hayAsientosDisponibles()
{
	if (_capacidadMaximaAsientos > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Sala:: porcentajeOcupacion() {
	return _capacidadMaximaAsientos / 100.f;

}