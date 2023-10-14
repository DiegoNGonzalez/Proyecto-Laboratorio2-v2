#pragma once
#include "Persona.h"
#include "Funcion.h"
class Vendedor : public Persona
{
private:
public:
	Vendedor();
	Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia);
	void venderEntradas(int contadorEntradas, int idFuncion, int contadorGeneralEntradas);
	

};

