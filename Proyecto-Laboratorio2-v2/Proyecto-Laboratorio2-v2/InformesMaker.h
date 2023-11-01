#pragma once
//#include  "ArchivoPeliculas.h"	
#include "ArchivoEntrada.h"
#include "Administrador.h"
#include <iomanip>

class InformesMaker {
private:
	int _cantidadInformesXPelicula;
public:
	InformesMaker();
	/**
	* @brief Muestra el informe de recaudacion por pelicula.
	* @param void
	* @return void
	*/
	void mostrarInfomeRecaXPelicula();
	/**
	* @brief Muestra el informe de recaudacion por dia.
	* @param void
	* @return void
	*/
	void mostrarInformeRecaXDia();
	/**
	* @brief Muestra el informe de recaudacion por mes.
	* @param void
	* @return void
	*/
	void mostrarInformeRecaXMes();
	/**
	* @brief Muestra el informe de recaudacion por anio.
	* @param void
	* @return void
	*/
	void mostrarInformeRecaXAnio();
	/**
	* @brief Muestra el informe de recaudacion por franja horaria.
	* @param void
	* @return void
	*/
	void mostrarInformeFranjasHorarias();

};

