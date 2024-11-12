#include<iostream>
#include <cstring>
#include <string>

#include "Paciente.h"
#include "Fecha.h"

using namespace std;
Paciente::Paciente(){}
Paciente::Paciente(string nombre, string apellido, string telefono, string direccion, string ciudad, string email, Fecha fechaNacimiento, std::string obraSocial, std::string dni, bool eliminado):Persona(nombre, apellido, telefono, direccion, ciudad, email)
{
    setFechaNacimiento(fechaNacimiento);
    setDni(dni);
    setObraSocial(obraSocial);
}
void Paciente::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}
void Paciente::setObraSocial(string obraSocial)
{
    strncpy(_obraSocial, obraSocial.c_str(), sizeof(_obraSocial) - 1);
    _obraSocial[sizeof(_obraSocial) - 1] = '\0';
}
void Paciente::setDni(string Dni)
{
    strncpy(_dni, Dni.c_str(), sizeof(_dni) - 1);
    _dni[sizeof(_dni) - 1] = '\0';
}
void Paciente::setEliminado(bool estado){

    _eliminado = estado;
}
Fecha Paciente::getFechaNacimiento() const
{
    return _fechaNacimiento;
}
const char* Paciente::getDni() const
{
    return _dni;
}
const char* Paciente::getObraSocial()const
{
    return _obraSocial;
}
const bool Paciente::getEliminado() const{
    return _eliminado;

}


