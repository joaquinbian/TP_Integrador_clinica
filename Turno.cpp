#include<iostream>
#include <cstring>
#include <string>
#include "Turno.h"
#include "Fecha.h"
using namespace std;

Turno::Turno()
{
    setDniPaciente("");
    setMatricula("");
    setFecha(Fecha());
    setHoraTurno(0);
    setEliminado(false);
}
Turno::Turno(Fecha fechaTurno, int horaTurno, std::string dniPaciente, std::string matricula, bool eliminado)
{
    setFecha(fechaTurno);
    setHoraTurno(horaTurno);
    setDniPaciente(dniPaciente);
    setMatricula(matricula);
    setEliminado(false);
}
void Turno::setFecha(Fecha fechaTurno)
{
    _fechaTurno = fechaTurno;
}
Fecha Turno::getFecha() const
{
    return _fechaTurno;
}
void Turno::setHoraTurno(int horaTurno)
{

    if(horaTurno > 8 || horaTurno < 17){

        _horaTurno = horaTurno;
    }
}
const int Turno::getHoraTurno() const
{

    return _horaTurno;
}
void Turno::setDniPaciente(string dniPaciente)
{
    strncpy(_dniPaciente, dniPaciente.c_str(), sizeof(_dniPaciente) - 1);
    _dniPaciente[sizeof(_dniPaciente) - 1] = '\0';
}
const char* Turno::getDniPaciente() const
{
    return _dniPaciente;
}
void Turno::setMatricula(string matriucla)
{
    strncpy(_matricula, matriucla.c_str(), sizeof(_matricula) - 1);
}
const char* Turno::getMatricula() const
{
    return _matricula;
}
void Turno::mostrar()
{
    cout<<"Fecha : " <<this->getFecha().toString() <<endl;
    cout<<"Hora : " <<this->getHoraTurno() <<endl;
    cout<<"DNI Paciente : " <<this->getDniPaciente() <<endl;
    cout<<"Matricula : " <<this->getMatricula() <<endl;
}
const bool Turno::getEliminado() const
{
    return _eliminado;
}
void Turno::setEliminado(bool estado)
{
    _eliminado = estado;
}
