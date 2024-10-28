#include<iostream>
#include <cstring>
#include <string>
#include "Turno.h"
#include "Fecha.h"
using namespace std;


Turno::Turno(){}
Turno::Turno(Fecha fechaTurno, std::string dniPaciente, std::string dniProfesional)
{
    setFecha(fechaTurno);
    setDniPaciente(dniPaciente);
    setDniProfesional(dniProfesional);

}

void Turno::setFecha(Fecha fechaTurno)
{
    _fecha = fechaTurno;
}

void Turno::setDniPaciente(string dniPaciente)
{
    strncpy(_dniPaciente, dniPaciente.c_str(), sizeof(_dniPaciente) - 1);
    _dniPaciente[sizeof(_dniPaciente) - 1] = '\0';
}

void Turno::setDniProfesional(string dniProfesional)
{
    strncpy(_dniProfesional, dniProfesional.c_str(), sizeof(_dniProfesional) - 1);
    _dniProfesional[sizeof(_dniProfesional) - 1] = '\0';
}
