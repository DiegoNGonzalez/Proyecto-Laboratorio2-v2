#pragma once
#include "fecha.h"
#include "horario.h"

class FechaHorario {
public:
	Fecha getFecha();
	Horario getHorario();
	void setFecha(Fecha fecha);
	void setHorario(Horario horario);
	void setFecha(int dia, int mes, int anio);
	void setHorario(int minuto, int hora);
	FechaHorario();
	FechaHorario(Fecha fecha, Horario horario);
	FechaHorario(int dia, int mes, int anio, int minuto, int hora);
	/**
	* @brief Metodo para verificar si el anio es bisiesto.
	* @param anio Anio a evaluar.
	* @return true si el anio es bisiesto, false en caso contrario.
	*/
	bool esBisiesto(int anio);
	/**
	* @brief Metodo que devuelve la cantidad maxima de dias en un mes, segun el mes y anio.
	* @param mes Mes a evaluar.
	* @param anio Anio a evaluar.
	* @return devuelve la cantidad maxima de dias.
	*/
	int maximoDiasEnMes(int mes, int anio);
	void mostrarFechaHora();
	bool operator==(FechaHorario fechaHorario);
	bool operator<(FechaHorario fechaHorario);
private:
	Fecha _fecha;
	Horario _horario;
};

