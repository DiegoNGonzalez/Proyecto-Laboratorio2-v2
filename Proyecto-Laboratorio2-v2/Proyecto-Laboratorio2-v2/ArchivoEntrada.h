#pragma once
#include "Entrada.h"
class ArchivoEntrada
{
private:
	char _nombre[30];
public:
	ArchivoEntrada(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	/**
	* @brief Metodo que permite leer un registro del archivo
	* @param posicion posicion del registro a leer
	* @return retorna un objeto de tipo Entrada
	*/
	Entrada leerRegistro(int posicion);
	/**
	* @brief Metodo que permite contar los registros del archivo
	* @param void
	* @return retorna la cantidad de registros del archivo
	*/
	int contarRegistros();
	/**
	* @brief Metodo que permite grabar un registro en el archivo
	* @param entrada objeto de tipo Entrada
	* @return retorna true si se grabo correctamente, false en caso contrario
	*/
	bool grabarRegistro(Entrada entrada);
	/**
	* @brief sobrecarga del metodo grabarRegistro que permite grabar un registro en una posicion especifica del archivo
	* @param entrada objeto de tipo Entrada
	* @param posicion posicion del registro a grabar
	* @return retorna true si se grabo correctamente, false en caso contrario
	*/
	bool grabarRegistro(Entrada entrada, int posicion);
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
	* @brief metodo para hacer autoincremental el id de las entradas
	* @param void
	* @return retorna el id autoincremental
	*/
	int validarId();
	/**
	* @brief metodo para buscar la posicion de una entrada por su id
	* @param valorBuscado id de la entrada a buscar
	* @return retorna la posicion de la entrada
	*/
	int buscarPosEntradaxID(int valorBuscado);
	/**
	* @brief metodo para buscar una entrada por su id
	* @param valorBuscado id de la entrada a buscar
	* @return retorna un objeto de tipo Entrada
	*/
	Entrada buscarEntradaxID(int valorBuscado);
	/**
	* @brief metodo para ver las ventas cargadas en el registro
	* @param void
	* @return void
	*/
	void verVentasCargadas();
};

