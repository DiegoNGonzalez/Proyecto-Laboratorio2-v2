#pragma once
#include "Pelicula.h"
class Sala
{
	private:
		int _numeroSala;
		int _capacidadMaximaAsientos;
		int _filas;
		int _columnas;
		
	public:

		void setNumeroSala(int numeroSala);
		int getNumeroSala();
		
		Sala();
		Sala(int numeroSala, int capacidadMaxima);
		void mostrarDetalles() const;
		void descontarAsientos();
		void descontarAsientos(int cantidad);
		bool hayAsientosDisponibles();
		float porcentajeOcupacion();
		int getFilas() const;
		int getColumnas() const;
		int getCapacidadMaximaAsientos();

};

