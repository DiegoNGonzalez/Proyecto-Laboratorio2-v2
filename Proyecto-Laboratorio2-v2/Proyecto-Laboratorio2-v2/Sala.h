#pragma once
#include "Pelicula.h"
class Sala
{
	/*Clase Sala
		Esta clase representa una sala de cine y sus detalles.

		Propiedades:

	N�mero de sala
		Capacidad m�xima de asientos
		Precio de la entrada
		pelicula a emitir
		Funciones :

	Constructor para inicializar los atributos.
		M�todos para obtener y establecer los atributos.
		M�todo para mostrar los detalles de la sala.
		metodo para descontar asientos de la sala  de a uno o con cantidad pasada por valores.
		metodo para comprobar si hay asientos disponibles en la sala.
		metodo para obtener porcentaje de ocupacion de la sala.

		*/
	private:
		int _numeroSala;
		int _capacidadMaximaAsientos;
		
	public:

		void setNumeroSala(int numeroSala);
		int getNumeroSala();
		void setCapacidadMaximaAsientos(int capacidadMaximaAsientos);
		int getCapacidadMaximaAsientos();
		Sala();
		Sala(int numeroSala, int capacidadMaximaAsientos);
		void mostrarDetalles() const;
		void descontarAsientos();
		void descontarAsientos(int cantidad);
		bool hayAsientosDisponibles();
		float porcentajeOcupacion();

};

