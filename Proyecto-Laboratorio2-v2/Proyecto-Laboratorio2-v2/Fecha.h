#pragma once
#include <string>

class Fecha {
public:
	int getDia();
	int getMes();
	int getAnio();
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	Fecha();
	Fecha(int dia, int mes, int anio);
	void mostrarFecha();

private:
	int _dia, _mes, _anio;
	int _diaSemana;
};