#pragma once
#include "Turno.h"

class TurnosArchivo{
public:
    TurnosArchivo();

    bool Guardar(const Turno &registro);
    bool leerTodos(Turno registros[], int cantidad);
    bool guardar(int pos, const Turno &registro);
    int getCantidad();
    int buscar(char* dni, Fecha fechaTurno, int horaTurno);
    Turno Leer(int pos);

private:
    std::string _filename;
};
