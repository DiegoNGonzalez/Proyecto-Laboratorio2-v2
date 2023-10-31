#pragma once
#include "Sala.h"
class DiagramaSala
{
private:
	int salaDeCine[10][10] = { 0 };
	int _idFuncion;
	bool _estado;
public:
	DiagramaSala();
	DiagramaSala(int idFuncion);
	/**
	* @brief Metodo que permite reservar un asiento.
	* @param fila Fila del asiento a reservar.
	* @param columna Columna del asiento a reservar.
	* @return Devuelve true si se pudo reservar el asiento, false en caso contrario.
	*/
	bool reservarAsiento(int fila, int columna);
	/**
	* @brief Metodo que permite cancelar la reserva de un asiento.
	* @param fila Fila del asiento a cancelar la reserva.
	* @param columna Columna del asiento a cancelar la reserva.
	* @return Devuelve true si se pudo cancelar la reserva del asiento, false en caso contrario.
	*/
	bool cancelarReserva(int fila, int columna);
	/**
	* @brief Metodo que setear el estado de un diagrama.
	* @param est Estado a setear.
	* @return void
	*/
	void setEstado(bool est);
	/**
	* @brief Metodo que devuelve el estado de un diagrama.
	* @param void
	* @return Devuelve true si el diagrama esta activo, false en caso contrario.
	*/
	bool getEstado();
	/**
	* @brief Metodo que setea el id de la funcion.
	* @param idFuncion Id de la funcion a setear.
	* @return void
	*/
	void setIdFuncion(int idFuncion);
	/**
	* @brief Metodo que devuelve el id de la funcion.
	* @param void
	* @return Devuelve el id de la funcion.
	*/
	int getIdFuncion();
	/**
	* @brief Metodo que permite mostrar el diagrama de la sala.
	* @param void
	* @return void
	*/
	void mostrarSala();
	/**
	* @brief Metodo que permite mostrar los asientos disponibles de una fila.
	* @param fila Fila a mostrar los asientos disponibles.
	* @return void
	*/
	void mostrarAsientosPorFilaDisponible(int fila);
	/**
	* @brief Metodo que permite mostrar los asientos reservados de una fila.
	* @param fila Fila a mostrar los asientos reservados.
	* @return void
	*/
	void setSalaDeCine(int fila, int columna, int estado);

};

