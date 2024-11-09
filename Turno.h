#pragma once
#include "Fecha.h"

class Turno
{
public:
    Turno();
    Turno(Fecha fechaTurno, int horaTurno, std::string especialidad, std::string dniPaciente, std::string matricula, bool eliminado = false);
    void cargar();
    void mostrar();

    void setFecha(Fecha fechaTurno);
    Fecha getFecha() const;
    void setHoraTurno(int horaTurno);
    void setEspecialidad(std::string especialidad);
    const char* getEspecialidad() const;
    void setDniPaciente(std::string dniPaciente);
    const char* getDniPaciente() const;
    void setMatricula(std::string matricula);
    const char* getMatricula() const;
    const int getHoraTurno() const;
    void setEliminado(bool estado);
    const bool getEliminado() const;

private:
    Fecha _fechaTurno;
    int _horaTurno; ///CADA UNA HORA
    char _especialidad[50];
    char _dniPaciente[50];
    char _matricula[50];
    bool _eliminado;
};
