#include "horario.h"
#include <ctime>
#include <iostream>
int Horario::getSegundo() {
	return _segundo;
}
int Horario::getMinuto() {
	return _minuto;
}
int Horario::getHora() {
	return _hora;
}
void Horario::setSegundo(int segundo) {
	_segundo = segundo;
}
void Horario::setMinuto(int minuto) {
	_minuto = minuto;
}
void Horario::setHora(int hora) {
	_hora = hora;
}
Horario::Horario() {
	time_t t = time(NULL);
	struct tm* f = localtime(&t);
	_segundo = (*f).tm_sec; // Indirecciona f y accede a tm_mday
	_minuto = f->tm_min; // Indirecciona f y accede a tm_mon
	_hora = f->tm_hour;
}
Horario::Horario(int minuto, int hora) {

	setMinuto(minuto);
	setHora(hora);
}

void Horario::mostrarHorario() {
	std::cout << _hora << ":" << _minuto;
}