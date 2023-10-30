#pragma once
#include "DiagramaSala.h"
#include <cstring>
#include <Windows.h>
#include "rlutil.h"
class ArchivoDiagrama
{
private:
	char _nombre[30];
public:

	ArchivoDiagrama(const char* nombre) {
		strcpy(_nombre, nombre);
	}
	/**
	* @brief Metodo que permite leer un registro de un archivo segun su posicion.
	* @param posicion Posicion del registro a leer.
	* @return Devuelve un objeto de tipo DiagramaSala.
	*/
	DiagramaSala leerRegistro(int posicion);
	/**
	* @brief Metodo que permite contar la cantidad de registros que tiene un archivo.
	* @param void
	* @return Devuelve la cantidad de registros que tiene un archivo.
	*/
	int contarRegistros();
	/**
	* @brief Metodo que permite grabar un registro en un archivo.
	* @param diagrama Objeto de tipo DiagramaSala a grabar.
	* @return Devuelve true si se pudo grabar el registro, false en caso contrario.
	*/
	bool grabarRegistro(DiagramaSala diagrama);
	/**
	* @brief Sobrecarga del metodo que permite grabar un registro en un archivo en una posicion especifica.
	* @param diagrama Objeto de tipo DiagramaSala a grabar.
	* @param posicion Posicion del registro a grabar.
	* @return Devuelve true si se pudo grabar el registro, false en caso contrario.
	*/
	bool grabarRegistro(DiagramaSala diagrama, int posicion);
	/**
	* @brief Metotodo para mostrar el registro indicado segun su id y que no tenga baja logica.
	* @param idFuncion Id de la funcion a mostrar.
	* @return void
	*/
	void mostrarRegistro(int idFuncion);
	/**
	* @brief metodo para reservar un asiento en el diagrama guardado en registro.
	* @param idFuncion Id de la funcion a reservar.
	* @param fila Fila del asiento a reservar.
	* @param columna Columna del asiento a reservar.
	* @return Devuelve true si se pudo reservar el asiento, false en caso contrario.
	*/
	bool reservarAsientoEnRegistro(int idFuncion, int fila, int columna);
	/**
	* @brief metodo para cancelar una reserva de un asiento en el diagrama guardado en registro.
	* @param idFuncion Id de la funcion a cancelar la reserva.
	* @param fila Fila del asiento a cancelar la reserva.
	* @param columna Columna del asiento a cancelar la reserva.
	* @return Devuelve true si se pudo cancelar la reserva del asiento, false en caso contrario.
	*/
	bool cancelarReservaEnRegistro(int idFuncion, int fila, int columna);
	/**
	* @brief metodo para buscar la posicion de un registro segun su id.
	* @param valorBuscado Id del registro a buscar.
	* @return Devuelve la posicion del registro buscado o -1 si no existe.
	*/
	int buscarPosDiagramaxID(int valorBuscado);
	/**
	* @brief metodo para generar un archivo de backup.
	* @param void
	* @return Devuelve true si se pudo generar el archivo de backup, false en caso contrario.
	 */
	bool generarBackUp();
	/**
	* @brief metodo para restaurar un archivo de backup.	
	* @param void
	* @return Devuelve true si se pudo restaurar el archivo de backup, false en caso contrario.
	*/
	bool restaurarBackUp();
};

