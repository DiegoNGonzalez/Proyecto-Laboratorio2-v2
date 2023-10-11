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
    void mostrarSalaDeCine(int idFuncion);
    bool reservarAsiento(int idFuncion,int fila, int columna);
    bool cancelarReserva(int idFuncion,int fila, int columna);
    void setidFuncion(int idFuncion);
    int getidFuncion();
    int** getSalaDeCine()  ;
    


};

