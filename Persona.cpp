#include "Persona.h"
#include <cstring>
#include<iostream>

using namespace std;
Persona::Persona(){}
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
void Persona::cargar()
{
    char nombre[50], apellido[50], direccion[50], telefono[50], ciudad[50], email[50];

    cout << "Ingrese el nombre: ";
    cin.ignore();
    cin.getline(nombre, 50);
    setNombre(nombre);

    cout << "Ingrese el apellido: ";
    cin.getline(apellido, 50);
    setApellido(apellido);

    cout << "Ingrese el domicilio: ";
    cin.getline(direccion, 50);
    setDireccion(direccion);

    cout << "Ingrese la ciudad: ";
    cin.getline(ciudad, 50);
    setCiudad(ciudad);

    cout << "Ingrese el telefono: ";
    cin.getline(telefono, 50);
    setTelefono(telefono);

    cout << "Ingrese el correo electronico: ";
    cin.getline(email, 50);
    setEmail(email);
}
void Persona::mostrar()
{
    cout<<"Nombre : " <<getNombre() <<endl;
    cout<<"Apellido : " <<getApellido() <<endl;
    cout<<"Domicilio : " <<getDireccion() <<endl;
    cout<<"Ciudad : " <<getCiudad() <<endl;
    cout<<"Telefono : " <<getTelefono() <<endl;
    cout<<"Email : " <<getEmail() <<endl;
}

