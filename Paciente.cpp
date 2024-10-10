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
void Paciente::cargar(){
    Persona::cargar();

    int edad;
    char obraSocial[20], dni[20];
    Fecha fechaNacimiento;

    cout<<"Fecha de nacimiento "<<endl;
    cin>>fechaNacimiento;
    setFechaNacimiento(fechaNacimiento);

    cout<<"Ingrese la edad del paciente : ";
    cin>>edad;
    setEdad(edad);

    cout << "Ingrese el DNI del paciente: ";
    cin.ignore();
    cin.getline(dni, 20);
    setDni(dni);

    cout << "Ingrese la obra social: ";
    cin.getline(obraSocial, 20);
    setObraSocial(obraSocial);
}

void Paciente::mostrar(){
    Persona::mostrar();

    cout<<"Fecha de nacimiento : " << getFechaNacimiento().toString()<<endl;
    cout<<"Edad : " <<getEdad() <<endl;
    cout<<"DNI : " <<getDni() <<endl;
    cout<<"Obra Social : " <<getObraSocial() <<endl;
}
