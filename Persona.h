#pragma once
#include <string>

class Persona
{
public:
    Persona();
    Persona(std::string nombre, std::string apellido, std::string telefono, std::string direccion, std::string ciudad, std::string email);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setTelefono(std::string telefono);
    void setDireccion(std::string direccion);
    void setCiudad(std::string ciudad);
    void setEmail(std::string email);
    const char* getNombre() const;
    const char*getApellido() const;
    const char* getTelefono() const;
    const char* getDireccion() const;
    const char* getCiudad() const;
    const char* getEmail() const;
    void cargar();
    void mostrar();



private:
    char _nombre [50];
    char _apellido[50];
    char _telefono[50];
    char _direccion[50];
    char _ciudad[50];
    char _email[50];
};
