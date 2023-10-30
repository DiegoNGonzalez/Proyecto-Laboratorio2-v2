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
	bool esBisiesto(int anio);
	int maximoDiasEnMes(int mes, int anio);
	void mostrarFechaHora();
	bool operator==(FechaHorario fechaHorario);
	bool operator<(FechaHorario fechaHorario);
private:
	Fecha _fecha;
	Horario _horario;
};

