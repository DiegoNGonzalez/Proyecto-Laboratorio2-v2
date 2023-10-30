#pragma once
#include <cstring>
#include "Sala.h"
#include <Windows.h>
#include "rlutil.h"

class ArchivoSalas
{
private:
	char _nombre[30];
public:
	ArchivoSalas(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	/**
	* @brief Metodo que permite leer un registro de un archivo segun su posicion.
	* @param posicion Posicion del registro a leer.
	* @return Devuelve un objeto de tipo Sala.
	*/
	Sala leerRegistro(int posicion);
	/**
	* @brief Metodo que permite contar la cantidad de registros que tiene un archivo.
	* @param void
	* @return Devuelve la cantidad de registros que tiene un archivo.
	*/
	int contarRegistros();
	/**
	* @brief Metodo que permite grabar un registro en un archivo.
	* @param sala Objeto de tipo Sala a grabar.
	* @return Devuelve true si se pudo grabar el registro, false en caso contrario.
	*/
	bool grabarRegistro(Sala sala);
	/**
	* @brief Sobrecarga del metodo que permite grabar un registro en un archivo en una posicion especifica.
	* @param sala Objeto de tipo Sala a grabar.
	* @param posicion Posicion del registro a grabar.
	* @return Devuelve true si se pudo grabar el registro, false en caso contrario.
	*/
	bool grabarRegistro(Sala sala, int posicionSala);
	/**
	* @brief metodo para generar un archivo de backup
	* @param void
	* @return retorna true si se genero correctamente, false en caso contrario
	*/
	bool generarBackUp();
	/**
	* @brief metodo para restaurar un archivo de backup
	* @param void
	* @return retorna true si se restauro correctamente, false en caso contrario
	*/
	bool restaurarBackUp();
	/**
	* @brief metodo para hacer autoincremental el id de las salas
	* @param void
	* @return retorna el id autoincremental
	*/
	int validarId();
	/**
	* @brief metodo para buscar la posicion de una sala por su id
	* @param valorBuscado id de la sala a buscar
	* @return retorna la posicion de la sala
	*/
	int buscarPosSalaxID(int valorBuscado);

};

