#include<iostream>
#include <cstring>
#include <string>
#include "Paciente.h"
#include "Fecha.h"
#include <ctime> ///Para menejar fechas

using namespace std;

Paciente::Paciente():Persona()
{
    strcpy(_dni,"");
    strcpy(_obraSocial,"");
    _fechaNacimiento = Fecha();
}
Paciente::Paciente(string nombre, string apellido, string telefono, string direccion, string ciudad, string email, Fecha fechaNacimiento, std::string obraSocial, std::string dni, bool eliminado):Persona(nombre, apellido, telefono, direccion, ciudad, email)
{
    setFechaNacimiento(fechaNacimiento);
    setDni(dni);
    setObraSocial(obraSocial);
    setEliminado(false);
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
void Paciente::setEliminado(bool estado)
{

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
const bool Paciente::getEliminado() const
{
    return _eliminado;
}
int Paciente::getEdad()
{
    /// Obtener la fecha actual
    std::time_t tiempoActual = std::time(0);  ///Obtiene el tiempo actual
    std::tm* now = std::localtime(&tiempoActual); ///Convierte el tiempo actual a una estructura time

    int edad = (1900 + now->tm_year) - getFechaNacimiento().getAnio();  /// Calcula la diferencia de años

    if (now->tm_mon + 1 < getFechaNacimiento().getMes() ||  /// Si el mes actual es menor que el de nacimiento
        (now->tm_mon + 1 == getFechaNacimiento().getMes() && now->tm_mday < getFechaNacimiento().getDia())) {  /// ..o si el mes es igual pero el día aún no pasó
         edad--;  /// Resta un año por que aún no cumplió
    }

    return edad;
}
