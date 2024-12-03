#include "Persona.h"
#include <cstring>
#include<iostream>

using namespace std;
Persona::Persona()
{
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_direccion, "");
    strcpy(_ciudad, "");
    strcpy(_email, "");
}
Persona::Persona(std::string nombre, std::string apellido, std::string telefono, std::string direccion, std::string ciudad, std::string email)
{

    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setDireccion(direccion);
    setCiudad(ciudad);
    setEmail(email);


}
void Persona::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}
void Persona::setApellido(std::string apellido)
{
    strcpy(_apellido, apellido.c_str());
}
void Persona::setTelefono(std::string telefono)
{
    strcpy(_telefono, telefono.c_str());
}
void Persona::setDireccion(std::string direccion)
{
    strcpy(_direccion, direccion.c_str());
}
void Persona::setCiudad(std::string ciudad)
{
    strcpy(_ciudad, ciudad.c_str());
}
void Persona::setEmail(std::string email)
{
    strcpy(_email, email.c_str());
}
const char* Persona::getNombre() const
{
    return _nombre;
}
const char* Persona::getApellido() const
{
    return _apellido;
}
const char* Persona::getTelefono() const
{
    return _telefono;
}
const char* Persona::getDireccion() const
{
    return _direccion;
}
const char* Persona::getCiudad() const
{
    return _ciudad;
}
const char* Persona::getEmail() const
{
    return _email;
}

