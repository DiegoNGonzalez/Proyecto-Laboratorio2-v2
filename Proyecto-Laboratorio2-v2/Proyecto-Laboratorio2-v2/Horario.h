#pragma once
#include <string>

class Horario {
public:
	int getSegundo();
	int getMinuto();
	int getHora();
	void setSegundo(int segundo);
	void setMinuto(int minuto);
	void setHora(int hora);
	Horario();
	Horario(int minuto, int hora);
	void mostrarHorario();

private:
	int _hora, _minuto, _segundo;

};