#include <ctime>
#include <iostream>
#include "fecha.h"


int Fecha::getDia() {
    return _dia;
}
int Fecha::getMes() {
    return _mes;
}
int Fecha::getAnio() {
    return _anio;
}
void Fecha::setDia(int dia) {
    _dia = dia;
}
void Fecha::setMes(int mes) {
    _mes = mes;
}
void Fecha::setAnio(int anio) {
    _anio = anio;
}
Fecha::Fecha() {
    time_t t = time(NULL);
    struct tm* f = localtime(&t);
    _dia = (*f).tm_mday; // Indirecciona f y accede a tm_mday
    _mes = f->tm_mon + 1; // Indirecciona f y accede a tm_mon
    _anio = f->tm_year + 1900;
    _diaSemana = f->tm_wday;
}
Fecha::Fecha(int dia, int mes, int anio) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    _diaSemana = -1;
}

void Fecha::mostrarFecha() {
    std::cout << _dia << "/" << _mes << "/" << _anio;
}