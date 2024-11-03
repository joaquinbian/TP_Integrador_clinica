#include<iostream>
#include <cstring>
#include <string>
#include "Paciente.h"
#include "Fecha.h"
using namespace std;

Paciente::Paciente(){}
Paciente::Paciente(string nombre, string apellido, string telefono, string direccion, string ciudad, string email, Fecha fechaNacimiento, int edad, std::string obraSocial, std::string dni):Persona(nombre, apellido, telefono, direccion, ciudad, email)
{
    setFechaNacimiento(fechaNacimiento);
    setEdad(edad);
    setDni(dni);
    setObraSocial(obraSocial);
}
void Paciente::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}
void Paciente::setEdad(int edad)
{
    if(edad > 0)
    {
        _edad = edad;
    }
    else
    {
        _edad = 0;
    }
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
Fecha Paciente::getFechaNacimiento() const
{
    return _fechaNacimiento;
}
int Paciente::getEdad() const
{
    return _edad;
}
const char* Paciente::getDni() const
{
    return _dni;
}
const char* Paciente::getObraSocial()const
{
    return _obraSocial;
}

void Paciente::setTurno(Turno turno){
    _turno = turno;
}
Turno Paciente::getTurno(){
    return _turno;
}

void Paciente::mostrar(){
     cout<<"Nombre : " <<this->getNombre() <<endl;
    cout<<"Apellido : " <<this->getApellido() <<endl;
    cout<<"Domicilio : " <<this->getDireccion() <<endl;
    cout<<"Ciudad : " <<this->getCiudad() <<endl;
    cout<<"Telefono : " <<this->getTelefono() <<endl;
    cout<<"Email : " <<this->getEmail() <<endl;
    cout<<"Fecha de nacimiento : " << this->getFechaNacimiento().toString()<<endl;
    cout<<"Edad : " <<this->getEdad() <<endl;
    cout<<"DNI : " <<this->getDni() <<endl;
    cout<<"Obra Social : " <<this->getObraSocial() <<endl;
}
