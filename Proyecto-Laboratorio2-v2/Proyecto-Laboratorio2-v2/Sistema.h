#pragma once
#include <vector>
#include "Funcion.h"
#include "Administrador.h"

class Sistema
{
	/*Clase Cine
		Esta clase representa el cine en s� y administra todas las funciones y salas.

		Propiedades:

	Lista de pel�culas disponibles(objeto de tipo vector de Pel�cula)
		Lista de salas(objeto de tipo vector de Sala)
		Lista de funciones(objeto de tipo vector de Funci�n)
		Funciones :

		M�todo para agregar una pel�cula a la lista de pel�culas disponibles.
		M�todo para agregar una sala a la lista de salas.
		M�todo para programar una funci�n(asociar una pel�cula y una sala en una fecha y hora espec�ficas).
		M�todo para mostrar todas las funciones disponibles.
		M�todo para vender entradas para una funci�n espec�fica.
		M�todo para mostrar las estad�sticas de ocupaci�n de las salas.
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
