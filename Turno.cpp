#include<iostream>
#include <cstring>
#include <string>
#include "Turno.h"
#include "Fecha.h"
using namespace std;

Turno::Turno(){}
Turno::Turno(Fecha fechaTurno, std::string horaTurno, std::string nombreProfesional, std::string apellidoProfesional, std::string especialidad)
{
    setFecha(fechaTurno);
    setHora(horaTurno);
    setNombre(nombreProfesional);
    setApellido(apellidoProfesional);

}

void Turno::setFecha(Fecha fechaTurno)
{
    _fechaTurno = fechaTurno;
}

void Turno::setHora(std::string horaTurno)
{
    strcpy(_horaTurno, horaTurno.c_str());
}

void Turno::setNombre(std::string nombreProfesional)
{
    strcpy(_nombreProfesional, nombreProfesional.c_str());
}

void Turno::setApellido(std::string apellidoProfesional)
{
    strcpy(_apellidoProfesional, apellidoProfesional.c_str());
}

void Turno::setEspecialidad(std::string especialidad)
{
    strcpy(_especialidad, especialidad.c_str());
}
