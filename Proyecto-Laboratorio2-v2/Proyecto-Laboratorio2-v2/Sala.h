#pragma once
#include "Pelicula.h"
class Sala
{
	/*Clase Sala
		Esta clase representa una sala de cine y sus detalles.

		Propiedades:

	Número de sala
		Capacidad máxima de asientos
		Precio de la entrada
		pelicula a emitir
		Funciones :

	Constructor para inicializar los atributos.
		Métodos para obtener y establecer los atributos.
		Método para mostrar los detalles de la sala.
		metodo para descontar asientos de la sala  de a uno o con cantidad pasada por valores.
		metodo para comprobar si hay asientos disponibles en la sala.
		metodo para obtener porcentaje de ocupacion de la sala.

		*/
	private:
		int _numeroSala;
		int _capacidadMaximaAsientos;
		float _precioEntrada;
		Pelicula _pelicula;
	public:

		void setNumeroSala(int numeroSala);
		int getNumeroSala();
		void setCapacidadMaximaAsientos(int capacidadMaximaAsientos);
		int getCapacidadMaximaAsientos();
		void setPrecioEntrada(float precioEntrada);
		float getPrecioEntrada();
		void setPelicula(Pelicula pelicula);
		Pelicula getPelicula();
		Sala();
		Sala(int numeroSala, int capacidadMaximaAsientos, float precioEntrada, Pelicula pelicula);
		void mostrarDetalles();
		void descontarAsientos();
		void descontarAsientos(int cantidad);
		bool hayAsientosDisponibles();
		float porcentajeOcupacion();

};

