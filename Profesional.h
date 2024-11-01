#pragma once
#include <cstring>
#include "Persona.h"


class Profesional : public Persona
{
    public:
        Profesional();
        Profesional(std::string nombre, std::string apellido, std::string telefono, std::string direccion, std::string ciudad, std::string email, std::string matricula, std::string especialidad, float valorConsulta, bool soloParticular);
        void setMatricula(std::string matricula);
        void setEspecialidad(std::string especialidad);
        void setValorConsulta(float valorConsulta);
        void setSoloParticular(bool soloParticular);


        void mostrar();
        const char* getMatricula() const;
        const char* getEspecialidad() const;
        const float getValorConsulta() const;
        const bool getSoloParticular() const;

    private:
        char _matricula[15];
        char _especialidad[50];
        float _valorConsulta;
        bool _soloParticular = true;
};


