#pragma once
#include <vector>
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"

class Sistema
{
	/*Clase Sistema
		Esta clase representa el Sistema en sí y administra todas las funciones y salas.

		Propiedades:

	Lista de películas disponibles(objeto de tipo vector de Película)
		Lista de salas(objeto de tipo vector de Sala)
		Lista de funciones(objeto de tipo vector de Función)
		Funciones :

		Método para agregar una película a la lista de películas disponibles.
		Método para agregar una sala a la lista de salas.
		Método para programar una función(asociar una película y una sala en una fecha y hora específicas).
		Método para mostrar todas las funciones disponibles.
		Método para vender entradas para una función específica.
		Método para mostrar las estadísticas de ocupación de las salas.
		metodo para obtener la cantidad de entradas vendidas para una funcion especifica
		metodo para obtener ganancias por funcion
		*/
	private:
		std::vector<Pelicula> _peliculas;
		std::vector<Sala> _salas;
		std::vector<Funcion> _funciones;
		public:
			void agregarPelicula(Pelicula pelicula);
			void agregarSala(Sala sala);
			void programarFuncion(Funcion funcion);
			void mostrarFunciones();
			void venderEntradas(int idFuncion, int cantidadEntradas);
			void mostrarEstadisticasOcupacionSalas();
			int buscarFuncion(int idFuncion);
			int obtenerCantidadEntradasVendidas(int idFuncion);
			float obtenerGananciasPorFuncion(int idFuncion);

			Sistema();
			Sistema(std::vector<Pelicula> peliculas, std::vector<Sala> salas, std::vector<Funcion> funciones);

};

