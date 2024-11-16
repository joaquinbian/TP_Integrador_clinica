#pragma once
#include <string>


class Especialidad
{
    public:
        Especialidad();
        Especialidad(std::string nombreEspecialidad,int id, bool eliminado = false);
        void setNombreEspecialidad(std::string nombreEspecialidad);
        void setEliminado(bool estado);
        void setId(int id);
        const char* getNombreEspecialidad() const;
        const bool getEliminado() const;
        const int getId() const;

    private:
        char _nombreEspecialidad[50];
        bool _eliminado;
        int _id;
        //static int _contadorId;
};



