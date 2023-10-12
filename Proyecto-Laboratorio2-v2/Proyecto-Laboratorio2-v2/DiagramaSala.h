#pragma once
#include "Sala.h"
class DiagramaSala
{
private:
    int salaDeCine[10][10] = {0};
    int _idFuncion;
    
public:
    DiagramaSala();
    DiagramaSala(int idFuncion);
    bool reservarAsiento(int fila, int columna);
    bool cancelarReserva( int fila, int columna);
    void setidFuncion(int idFuncion);
    int getidFuncion();
    void mostrarSala();
    void setSalaDeCine(int fila, int columna, int estado);
    


};

