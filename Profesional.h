#pragma once
#include <cstring>
#include "Persona.h"


class Profesional : public Persona
{
    public:
        Profesional();
        Profesional(std::string nombre, std::string apellido, std::string telefono, std::string direccion, std::string ciudad, std::string email, std::string matricula, int especialidad, float valorConsulta, bool soloParticular, bool eliminado = false);
        void setMatricula(std::string matricula);
        void setEspecialidad(int especialidad);
        void setValorConsulta(float valorConsulta);
        void setSoloParticular(bool soloParticular);
        void setEliminado(bool eliminado);
        const char* getMatricula() const;
        const int getEspecialidad() const;
        const float getValorConsulta() const;
        const bool getSoloParticular() const;
        const bool getEliminado() const;

    private:
        char _matricula[50];
        int idEspecialidad;
        float _valorConsulta;
        bool _soloParticular = true;
         bool _eliminado;
};


