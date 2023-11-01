#pragma once
#include "Empleado.h"
#include "Funcion.h"
#include "ArchivoFunciones.h"
#include "ArchivoEntrada.h"
class Vendedor : public Empleado
{
private:
public:
	Vendedor();
	Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
	/**
	* @brief Vende entradas para una funcion
	* @param idFuncion id de la funcion a la que se le venderan las entradas
	* @return void
	*/
	void venderEntradas(int idFuncion);
	/**
	* @brief Cancela la venta de una entrada
	* @param idEntrada id de la entrada a cancelar
	* @return void
	*/
	void cancelarVenta( int idEntrada);


};

