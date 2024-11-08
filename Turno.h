#pragma once
#include "Fecha.h"

class Turno
{
public:
    Turno();
    Turno(Fecha fechaTurno, std::string dniPaciente, std::string dniProfesional);
    void setFecha(Fecha fechaTurno);
    void setDniPaciente(std::string dni);
    void setDniProfesional(std::string dni);
    const char* getDniPaciente() const;
    const char* getDniProfesional() const;
    Fecha getFecha() const;
    void cargar();
    void mostrar();

private:
    Fecha _fecha;
    char _dniPaciente[50];
    char _dniProfesional[50];

};
