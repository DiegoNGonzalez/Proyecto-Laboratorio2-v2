#include "Vendedor.h"
#include <iostream>
Vendedor::Vendedor() : Persona() {
	
}

Vendedor::Vendedor(int legajo, std::string cargo, std::string nombre, std::string apellido, std::string usuario, std::string contrasenia) : Persona(legajo, cargo, nombre, apellido, usuario, contrasenia) {

}