#pragma once
#include "Especialidad.h"


class EspecialidadesArchivo
{
    public:
        EspecialidadesArchivo();
        bool Guardar(const Especialidad &registro);
        bool leerTodos(Especialidad registros[], int cantidad);
        bool guardar(int pos, const Especialidad &registro);
        int getCantidad();
        int buscar(int id);
        bool editar(char* dni);
        Especialidad buscarEspecalidad(int id);
        Especialidad Leer(int pos);


    private:
        std::string _filename;

};
