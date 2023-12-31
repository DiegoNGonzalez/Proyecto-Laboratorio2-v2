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
	if (_minuto == 0) {
		std::cout << _hora << ":" << _minuto<<"0";
	}
	else if (_minuto < 10) {
		std::cout << _hora << ":" << "0"<<_minuto;
	}
	else if(_minuto>10 && _hora<10){
	std::cout << "0" << _hora << ":" << _minuto;
	}
	else {
		std::cout << _hora << ":" << _minuto;
	}
}

bool Horario::operator==(Horario horario)
{
	if (_hora == horario.getHora() && _minuto == horario.getMinuto()) {
		return true;
	}
	else {
		return false;
	}
}

bool Horario::operator<(Horario horario)
{
	if (_hora < horario.getHora()) {
		return true;
	}
	else if (_hora == horario.getHora() && _minuto < horario.getMinuto()) {
		return true;
	}else {
		return false;
	}
	
}
