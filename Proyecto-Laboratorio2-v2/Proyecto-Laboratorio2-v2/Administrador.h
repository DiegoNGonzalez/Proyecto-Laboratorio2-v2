#pragma once
#include <Windows.h>
//#include "rlutil.h"
#include "Empleado.h"
//#include "Funcion.h"
//#include "Pelicula.h"
//#include "Sala.h"
#include "ArchivoFunciones.h"
//#include "ArchivoPeliculas.h"
//#include "ArchivoSalas.h"
//#include "ArchivoDiagrama.h"
//#include "DiagramaSala.h"
#include "funcionesGlobales.h"


class Administrador : public Empleado
{
private:

public:
	/**
	* @brief Carga completa de los parametros de la clase Pelicula con id autoincremental y graba en registro.
	* @param void
	* @return void
	* 	*/
	void cargarPeliculas();
	/**
	* @brief Recorre el archivo de peliculas y muestra los registros que no tengan baja logica.
	* @param void
	* @return void
	*/
	void verPeliculasCargadas();
	/**
	* @brief Carga completa de los parametros de la clase Sala y graba en registro.
	* @param void
	* @return void
	*/
	void cargarSalas();
	/**
	* @brief Recorre el archivo de salas con id autoincremental y muestra los registros que no tengan baja logica.
	* @param void
	* @return void
	*/
	void verSalasCargadas();
	/**
	* @brief Recorre el archivo de peliculas, muestra los registros que no tengan baja logica, pide el ingreso de un ID y devuelve el registro que coincida con el ID ingresado.
	* @param void
	* @return Objeto Pelicula selecionada
	*/
	Pelicula seleccionarPelicula();
	/**
	* @brief Recibe un id de pelicula, con ese id busca la posicion en el archivo de peliculas y devuelve el registro que coincida con el id ingresado.
	* @param int valorBuscado
	* @return Objeto Pelicula buscado xID
	*/
	Pelicula buscarPeliculaxID(int valorBuscado);
	/**
	* @brief Recorre el archivo de peliculas, muestra los registros que no tengan baja logica, pide el ingreso de un ID, busca la posicion en el archivo de peliculas, da baja logica al registro y lo graba en el archivo con validacion y muestra por pantalla si pudo o no realizar la accion.
	* @param void
	* @return true o false segun si pudo o no realizar la accion
	*/
	bool darDeBajaPelicula();
	/**
	* @brief Recorre el archivo de salas, muestra los registros que no tengan baja logica, pide el ingreso de un ID y devuelve el registro que coincida con el ID ingresado.
	* @param void
	* @return Sala
	*/
	Sala seleccionarSala();
	/**
	* @brief Recibe un id de sala, con ese id busca la posicion en el archivo de salas y devuelve el registro que coincida con el id ingresado.
	* @param int valorBuscado
	* @return Objeto Sala buscado xID
 	*/
	Sala buscarSalaxID(int valorBuscado);
	/**
	* @brief Recibe un id de sala, con ese id busca la posicion en el archivo de salas, solicita por pantalla el nuevo valor de la entrada a la sala, modifica el registro , lo graba en el archivo con validacion y muestra por pantalla si pudo o no realizar la accion.
	* @param int nroSala
	* @return true o false segun si pudo o no realizar la accion
 	*/
	bool modificarSalaEnRegistro(int nroSala);
	/**
	* @brief Recorre el archivo de salas, muestra los registros que no tengan baja logica, pide el ingreso de un ID, busca la posicion en el archivo de salas, da baja logica al registro, lo graba en el archivo con validacion y muestra por pantalla si pudo o no realizar la accion.
	* @param void
	* @return true o false segun si pudo o no realizar la accion
	*/
	bool darDeBajaSala();
	/**
	* @brief Carga de un objeto funcion con id autoincremental, crea objeto Diagrama con mismo id de funcion, elige pelicula con seleccionarPelicula(), elige sala con seleccionarSala(), pide por pantalla el dia y hora de la funcion, graba en registro.
	* @param void
	* @return void
	*/
	void cargarFunciones();
	/**
	* @brief Recorre el archivo de funciones y muestra los registros que no tengan baja logica.
	* @param void
	* @return void
	*/
	void verFuncionesCargadas();
	/**
	* @brief Recibe un id de funcion, con ese id busca la posicion en el archivo de funciones, captura el registro que coincida con el id y abre un menu para modificar la funcion.
	* @param int idFuncion
	* @return true o false segun si pudo o no realizar la accion
	*/
	bool modificarFuncionEnRegistro(int idFuncion);


	void darDeBajaFuncionxSalaOxPelicula();
	bool darDeBajaFuncion();
	Administrador();
	Administrador(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);

	void ingresarDatosFuncion(int &dia, int &mes, int &anio, int &hora, int &minuto, FechaHorario &fechaHoraFuncion);


	


};