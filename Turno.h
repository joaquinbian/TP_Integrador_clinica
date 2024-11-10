#pragma once
#include "Fecha.h"

class Turno
{
public:
    Turno();
    Turno(Fecha fechaTurno, int horaTurno, int especialidad, std::string dniPaciente, std::string matricula);
    void cargar();
    void mostrar();

    void setFecha(Fecha fechaTurno);
    Fecha getFecha() const;
    void setHoraTurno(int horaTurno);
    void setEspecialidad(int especialidad);
    const int getEspecialidad() const;
    void setDniPaciente(std::string dniPaciente);
    const char* getDniPaciente() const;
    void setMatricula(std::string matricula);
    const char* getMatricula() const;
    const int getHoraTurno() const;

private:
    Fecha _fechaTurno;
    int _horaTurno; ///CADA UNA HORA
    int _idEspecialidad;
    char _dniPaciente[50];
    char _matricula[50];
};
