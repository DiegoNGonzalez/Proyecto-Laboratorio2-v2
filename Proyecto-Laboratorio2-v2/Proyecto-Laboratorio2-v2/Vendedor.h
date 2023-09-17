#pragma once
#include "Persona.h"
class Vendedor : public Persona
{
public:
	Vendedor();
	Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
	void venderEntrada(int cantidad);

};

