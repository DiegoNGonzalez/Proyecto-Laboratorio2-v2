#include "Empleado.h"

void Empleado::setLegajo(int legajo) {
	_legajo = legajo;
}
int Empleado::getLegajo() const {
	return _legajo;
}
void Empleado::setNombre(std::string nombre) {
	_nombre = nombre;
}
std::string Empleado::getNombre() const {
	return _nombre;
}
void Empleado::setApellido(std::string apellido) {
	_apellido = apellido;
}
std::string Empleado::getApellido() const {
	return _apellido;
}
void Empleado::setUsuario(std::string usuario) {
	_usuario = usuario;
}
std::string Empleado::getUsuario() const {
	return _usuario;
}
void Empleado::setContrasenia(std::string contrasenia) {
	_contrasenia = contrasenia;
}
std::string Empleado::getContrasenia() const {
	return _contrasenia;
}
void Empleado::setCargo(std::string cargo) {
	_cargo = cargo;
}
std::string Empleado::getCargo() const
{
	return _cargo;
}


std::string Empleado::mostrarDatos() {
	std::string valorADevolver;
	valorADevolver = "Legajo: " + std::to_string(_legajo) + ", Cargo:" + _cargo + ", Nombre: " + _nombre + ", Apellido: " + _apellido + ", Usuario:" + _usuario;
	return valorADevolver;
}
Empleado::Empleado() {
	_legajo = 0;
	_cargo = "";
	_nombre = "";
	_apellido = "";
	_usuario = "";
	_contrasenia = "";
}
Empleado::Empleado(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) {
	_legajo = legajo;
	_cargo = cargo;
	_nombre = nombre;
	_apellido = apellido;
	_usuario = usuario;
	_contrasenia = contrasenia;

}