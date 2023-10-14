#pragma once
#include <string>
class Persona
{
protected:
	int _legajo;
	std::string _nombre;
	std::string _apellido;
	std::string _usuario;
	std::string _contrasenia;
	std::string _cargo;
public:
	void setLegajo(int legajo);
	int getLegajo() const;
	void setNombre(std::string nombre);
	std::string getNombre() const;
	void setApellido(std::string apellido);
	std::string getApellido() const;
	void setUsuario(std::string usuario);
	std::string getUsuario() const;
	void setContrasenia(std::string contrasenia);
	std::string getContrasenia() const;
	void setCargo(std::string cargo);
	std::string getCargo() const;
	std::string mostrarDatos();
	Persona();
	Persona(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
};

