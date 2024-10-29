#include<iostream>
#include <cstring>
#include <string>
#include "Turno.h"
#include "Fecha.h"
using namespace std;


Turno::Turno(){}
Turno::Turno(Fecha fechaTurno, std::string dniPaciente, std::string matricula, int horario)
{
    setFecha(fechaTurno);
    setDniPaciente(dniPaciente);
    setMatricula(matricula);
    setHorario(horario);

}

void Turno::setFecha(Fecha fechaTurno)
{
    _fechaTurno = fechaTurno;
}

void Turno::setDniPaciente(string dniPaciente)
{
    strncpy(_dniPaciente, dniPaciente.c_str(), sizeof(_dniPaciente) - 1);
    _dniPaciente[sizeof(_dniPaciente) - 1] = '\0';
}

void Turno::setMatricula(string matriucla)
{
    strncpy(_matricula, matriucla.c_str(), sizeof(_matricula) - 1);
    _matricula[sizeof(_matricula) - 1] = '\0';
}

void Turno::setHorario(int horario){

    if(horario > 8 || horario < 17){

        _horario = horario;
    }
}

const char* Turno::getDniPaciente() const{

    return _dniPaciente;
}

const char* Turno::getMatricula() const{

    return _matricula;
}

Fecha Turno::getFecha() const{

    return _fechaTurno;
}

const int Turno::getHorario() const{

    return _horario;
}
