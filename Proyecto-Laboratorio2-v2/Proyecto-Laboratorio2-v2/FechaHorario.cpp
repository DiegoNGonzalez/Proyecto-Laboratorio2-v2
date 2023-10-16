#include "fechahorario.h"
#include "fecha.h"
#include "horario.h"
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
	_fecha.setDia(dia);
	_fecha.setMes(mes);
	_fecha.setAnio(anio);
	_horario.setMinuto(minuto);
	_horario.setHora(hora);

}
void FechaHorario::mostrarFechaHora() {
	_fecha.mostrarFecha();
	std::cout << " ";
	_horario.mostrarHorario();
	std::cout << std::endl;

}