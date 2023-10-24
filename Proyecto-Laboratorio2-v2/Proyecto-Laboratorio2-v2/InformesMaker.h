#pragma once
//#include  "ArchivoPeliculas.h"	
#include "ArchivoEntrada.h"
#include "Administrador.h"
#include <iomanip>

class InformesMaker {
private:
	int _cantidadInformesXPelicula;
public:
	InformesMaker();
	void mostrarInfomeRecaXPelicula();
	void mostrarInformeRecaXDia();
	void mostrarInformeRecaXMes();
	void mostrarInformeRecaXAnio();
	void mostrarInformeFranjasHorarias();

};

