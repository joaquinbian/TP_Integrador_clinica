#pragma once
#include "Profesional.h"

class ProfesionalesArchivo
{
    public:
        ProfesionalesArchivo();
        bool Guardar(const Profesional &registro);
        bool leerTodos(Profesional registros[], int cantidad);
        bool guardar(int pos, const Profesional &registro);
        int getCantidad();
        int buscar(char* matricula);
        Profesional Leer(int pos);

    private:
        std::string _filename;

};


