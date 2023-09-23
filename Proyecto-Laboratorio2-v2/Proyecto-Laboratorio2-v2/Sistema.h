#pragma once
#include <vector>
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Administrador.h"
#include "Vendedor.h"

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
		Pelicula vecPeliculas[5];
		Sala vecSalas[5];
		Funcion vecFunciones[25];
		Administrador _admin1;
		Vendedor _vendedor1;
		int matrizSalasxFuncion[25][10][10] = {0};
		
		public:
			Administrador getAdmin() const ;
			Vendedor getVendedor() const;
			void login(Administrador admin1, Vendedor vendedor1);
			void mostrarMenuAdmin();
			void mostrarMenuVendedor();


			Sistema();
			

};

