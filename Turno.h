#pragma once
#include "Fecha.h"

class Turno
{
public:
    Turno();
    Turno(Fecha fechaTurno, std::string horaTurno, std::string nombreProfesional, std::string apellidoProfesional, std::string especialidad);
    Fecha getFecha() const;
    void cargar();
    void mostrar();

    void setFecha(Fecha fechaTurno);
    void setHora(std::string horaTurno);
    void setNombre(std::string nombreProfesional);
    void setApellido(std::string apellidoProfesional);
    void setEspecialidad(std::string especialidad);

private:
    Fecha _fechaTurno;
    char _horaTurno [6];
    char _nombreProfesional[50];
    char _apellidoProfesional[50];
    char _especialidad[50];


};
