#pragma once
//#include <Windows.h>
#include <cstring>
#include "Funcion.h"
//#include "rlutil.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"
#include "ArchivoDiagrama.h"
class ArchivoFunciones
{
private:
	char _nombre[30];
public:
	ArchivoFunciones(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	/**
	* @brief Metodo que permite leer un registro de un archivo
	* @param posicion posicion del registro a leer
	* @return retorna un objeto de tipo Funcion
	*/
	Funcion leerRegistro(int posicion);
	/**
	* @brief Metodo que permite contar los registros del archivo
	* @param void
	* @return retorna la cantidad de registros del archivo
	*/
	int contarRegistros();
	/**
	* @brief Metodo que permite grabar un registro en el archivo
	* @param funcion objeto de tipo Funcion
	* @return retorna true si se grabo correctamente, false en caso contrario
	*/
	bool grabarRegistro(Funcion funcion);
	/**
	* @brief sobrecarga del metodo grabarRegistro que permite grabar un registro en una posicion especifica del archivo
	* @param funcion objeto de tipo Funcion
	* @param posicion posicion del registro a grabar
	* @return retorna true si se grabo correctamente, false en caso contrario
	*/
	bool grabarRegistro(Funcion funcion, int posicion);
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
	* @brief metodo para hacer autoincremental el id de las funciones
	* @param void
	* @return retorna el id autoincremental
	*/
	int validarId();
	/**
	* @brief metodo para buscar la posicion de una funcion por su id
	* @param valorBuscado id de la funcion a buscar
	* @return retorna la posicion de la funcion
	*/
	int buscarPosFuncionxID(int valorBuscado);
	/**
	* @brief metodo para buscar una funcion por su id
	* @param valorBuscado id de la funcion a buscar
	* @return retorna la funcion buscada
	*/
	Funcion buscarFuncionxID(int valorBuscado);
	
};

