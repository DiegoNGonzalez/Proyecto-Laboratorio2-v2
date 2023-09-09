#pragma once
#include <vector>
#include "Funcion.h"
#include "Administrador.h"

class Sistema
{
	/*Clase Cine
		Esta clase representa el cine en sí y administra todas las funciones y salas.

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
		std::vector<Pelicula> vecPeliculas;
		std::vector<Sala> vecSalas;
		std::vector<Funcion> vecFunciones;
		Administrador _admin1;

		
		public:
			void mostrarMenuIniciarPrograma();


			Sistema();
			

};

