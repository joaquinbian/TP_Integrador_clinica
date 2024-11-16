#pragma once
#include <string>
#include "Persona.h"
#include "Fecha.h"

class Paciente : public Persona
{
public:
    Paciente();
    Paciente(std::string nombre, std::string apellido, std::string telefono, std::string direccion, std::string ciudad, std::string email, Fecha fechaNacimiento, std::string obraSocial, std::string dni, bool eliminado = false);
    void setFechaNacimiento(Fecha fechaNacimiento);
    void setObraSocial(std::string obraSocial);
    void setDni(std::string Dni);
    void setEliminado(bool estado);
    Fecha getFechaNacimiento() const;
    const char* getDni() const;
    const char* getObraSocial() const;
    const bool getEliminado() const;
    int getEdad();

private:
    Fecha _fechaNacimiento;
    char _dni[20];
    char _obraSocial[20];
    bool _eliminado;
};
