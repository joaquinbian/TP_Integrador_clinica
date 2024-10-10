#pragma once
#include <string>
#include "persona.h"
#include "Fecha.h"


class Paciente : public Persona
{
public:
    Paciente();
    Paciente(std::string nombre, std::string apellido, std::string telefono, std::string direccion, std::string ciudad, std::string email, Fecha fechaNacimiento, int edad, std::string obraSocial, std::string dni);
    void setFechaNacimiento(Fecha fechaNacimiento);
    //void setFechaTurno(Fecha fechaTurno);
    void setEdad(int edad);
    void setObraSocial(std::string obraSocial);
    void setDni(std::string Dni);
    Fecha getFechaNacimiento() const;
    int getEdad() const;
    const char* getDni() const;
    const char* getObraSocial() const;
    void cargar();
    void mostrar();


private:
    Fecha _fechaNacimiento;
    Fecha _fechaTurno;
    int _edad;
    char _dni[20];
    char _obraSocial[20];

};


