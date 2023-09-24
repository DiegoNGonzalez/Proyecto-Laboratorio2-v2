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


int Sala::getCapacidadMaximaAsientos()
{
	return _capacidadMaximaAsientos;
}


Sala::Sala()
{
	_numeroSala = 0;
	_capacidadMaximaAsientos = 0;
}

Sala::Sala(int numeroSala, int capacidadMaxima)
{
	_numeroSala = numeroSala;
	/*_filas= filas;
	_columnas = columnas;*/
	_capacidadMaximaAsientos = capacidadMaxima;
}


void Sala::mostrarDetalles() const
{
	cout << "Numero de sala: " << _numeroSala << endl;
	cout << "Capacidad maxima de asientos: " << _capacidadMaximaAsientos << endl;
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


int Sala::getFilas() const
{
	return _filas;
}


int Sala::getColumnas() const
{
	return _columnas;
}