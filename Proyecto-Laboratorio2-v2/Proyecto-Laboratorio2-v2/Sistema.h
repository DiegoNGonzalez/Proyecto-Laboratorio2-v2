#pragma once
#include "Pelicula.h"
#include "Sala.h"
#include "Funcion.h"
#include "Administrador.h"
#include "Vendedor.h"

class Sistema
{
private:
	Administrador _admin1;
	Vendedor _vendedor1;
	FechaHorario _fechaHorario;

public:
	Sistema();
	Administrador getAdmin() const;
	Vendedor getVendedor() const;
	/**
	* @brief Metodo para ingresar al sistema que verifica las credenciales y muestra el menu correspondiente para cada tipo de usuario.
	* @param admin1: objeto de tipo Administrador.
	* @param vendedor1: objeto de tipo Vendedor.
	* @return void.
	*/
	void login(Administrador admin1, Vendedor vendedor1);
	/**
	* @brief Metodo que muestra la bienvenida al sistema y llama al metodo para verificar si existe el directorio de back up.
	* @return void.
	*/
	void bienvenida();
	/**
	* @brief Metodo para mostrar el menu Administrador.
	* @return void.
	*/
	void mostrarMenuAdmin();
	/**
	* @brief Metodo para mostrar el menu Vendedor.
	* @return void.
	*/
	void mostrarMenuVendedor();
	/**
	* @brief Metodo para mostrar el menu de Informes.
	* @return void.
	*/
	void mostrarMenuInformes();
	/**
	* @brief Metodo para mostrar el menu de Listados.
	* @return void.
	*/
	void mostrarMenuListados();
	/**
	* @brief Metodo para mostrar el menu de Peliculas.
	* @return void.
	*/
	void menuPeliculas();
	/**
	* @brief Metodo para mostrar el menu de Salas.
	* @return void.
	*/
	void menuSalas();
	/**
	* @brief Metodo para mostrar el menu de Funciones.
	* @return void.
	*/
	void menuFunciones();
	/**
	* @brief Metodo para mostrar el menu de BackUp.
	* @return void.
	*/
	void menuBackUp();
	/**
	* @brief Metodo que verifica si existe el Directorio de Backup, si no, lo crea.
	* @return true si crea el directorio, false si ya existe el directorio.
	*/
	bool crearDirectorioBackUP();
	/**
	* @brief Metodo que verifica la fecha y hora de funcion, si la funcion tiene una fecha u hora anterior a la actual, le hace baja logica.
	* @return void.
	*/
	void verificarFechaYHoraFunciones();
	/**
	* @brief Metodo que muestra los creditos.
	* @return void.
	*/
	void creditos();
	/**
	* @brief Metodo que muestra el listado de Empleados.
	* @return void.
	*/
	void mostrarListadoEmpleados();
};

