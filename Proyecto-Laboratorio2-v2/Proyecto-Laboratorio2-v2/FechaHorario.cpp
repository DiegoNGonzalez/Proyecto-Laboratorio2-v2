#include "fechahorario.h"
#include <iostream>


Fecha FechaHorario::getFecha() {
	return _fecha;
}
Horario FechaHorario::getHorario() {
	return _horario;
}
void FechaHorario::setFecha(Fecha fecha) {
	_fecha = fecha;
}
void FechaHorario::setHorario(Horario horario) {
	_horario = horario;
}
void FechaHorario::setFecha(int dia, int mes, int anio) {
	_fecha.setDia(dia);
	_fecha.setMes(mes);
	_fecha.setAnio(anio);
}
void FechaHorario::setHorario(int minuto, int hora) {
	_horario = Horario(minuto, hora);
}

FechaHorario::FechaHorario(Fecha fecha, Horario horario) {
	_fecha = fecha;
	_horario = horario;
}

FechaHorario::FechaHorario() {

}

FechaHorario::FechaHorario(int dia, int mes, int anio, int minuto, int hora) {
	if (dia > 0 && dia <= maximoDiasEnMes(mes, anio) && mes > 0 && mes <= 12 && anio > 0 && anio < 2030) {
		_fecha.setDia(dia);
		_fecha.setMes(mes);
		_fecha.setAnio(anio);

	}
	else {
		dia = 1;
		mes = 1;
		anio = 2023;
	}
	_horario.setMinuto(minuto);
	_horario.setHora(hora);

}
void FechaHorario::mostrarFechaHora() {
	_fecha.mostrarFecha();
	std::cout << " ";
	_horario.mostrarHorario();
	std::cout << std::endl;

}

bool FechaHorario::operator==(FechaHorario fechaHorario)
{
	if (_fecha == fechaHorario.getFecha() && _horario == fechaHorario.getHorario()) {
		return true;
	}
	else {
		return false;
	}
}

bool FechaHorario::operator<(FechaHorario fechaHorario)
{
	if (_fecha < fechaHorario.getFecha()) {
		return true;
	}
	else if (_fecha == fechaHorario.getFecha()) {
		if (_horario < fechaHorario.getHorario()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool FechaHorario::esBisiesto(int anio) {
	bool bisiesto = false;
	if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0) {
		bisiesto = true;
	}
	return bisiesto;
}

int FechaHorario::maximoDiasEnMes(int mes, int anio) {
	int diaMax = 31;// ENERO MARZO MAYO JULIO AGOSTO OCTUBRE DICIEMBRE
	if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		diaMax = 30;
	}
	else if (mes == 2) {
		if (esBisiesto(anio)) {
			diaMax = 29;
		}
		else {
			diaMax = 28;
		}
	}
	return diaMax;
}
