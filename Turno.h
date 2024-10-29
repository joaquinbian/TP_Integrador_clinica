#pragma once
#include <cstring>
#include "Fecha.h"

class Turno
{
public:
    Turno();
    Turno(Fecha fechaTurno, std::string dniPaciente, std::string matricula, int horario);
    void setFecha(Fecha fechaTurno);
    void setDniPaciente(std::string dni);
    void setMatricula(std::string matricula);
    void setHorario(int horario);
    const char* getDniPaciente() const;
    const char* getMatricula() const;
    Fecha getFecha() const;
    const int getHorario() const;
    void cargar();
    void mostrar();

private:
    Fecha _fechaTurno;
    char _dniPaciente[50];
    char _matricula[50];
    int _horario; //cada 1 hora
};
