#include "Persona.h"

void Persona::setLegajo(int legajo) {
	_legajo = legajo;
}
int Persona::getLegajo() const {
	return _legajo;
}
void Persona::setNombre(std::string nombre){
	_nombre = nombre;
}
std::string Persona::getNombre() const{
	return _nombre;
}
void Persona::setApellido(std::string apellido){
	_apellido = apellido;
}
std::string Persona::getApellido() const{
	return _apellido;
}
void Persona::setUsuario(std::string usuario){ 
	_usuario = usuario;
}
std::string Persona::getUsuario() const{
	return _usuario;
}
void Persona::setContrasenia(std::string contrasenia){
	_contrasenia = contrasenia;
}
std::string Persona::getContrasenia() const{
	return _contrasenia;
}
void Persona::setCargo(std::string cargo) {
	_cargo = cargo;
}
std::string Persona::getCargo() const
{
	return _cargo;
}


std::string Persona::mostrarDatos() {
	std::string valorADevolver;
	valorADevolver = "Legajo: " + std::to_string(_legajo) + ", Cargo:"+_cargo+", Nombre: " + _nombre + ", Apellido: " + _apellido + ", Usuario:" + _usuario;
	return valorADevolver;
}
Persona::Persona() {
	_legajo = 0;
	_cargo = "";
	_nombre = "";
	_apellido = "";
	_usuario = "";
	_contrasenia = "";
}
Persona::Persona(int legajo,std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) {
	_legajo = legajo;
	_cargo = cargo;
	_nombre = nombre;
	_apellido = apellido;
	_usuario = usuario;
	_contrasenia = contrasenia;

}