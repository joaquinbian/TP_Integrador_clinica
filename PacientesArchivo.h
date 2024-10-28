#pragma once
#include "Paciente.h"

class PacientesArchivo
{
    public:
        PacientesArchivo();
        bool Guardar(const Paciente &registro);
        bool leerTodos(Paciente registros[], int cantidad);
        bool guardar(int pos, const Paciente &registro);
        int getCantidad();
        int buscar(char* dni);
        bool editar(char* dni);
        Paciente Leer(int pos);


    private:
        std::string _filename;

};


