#include<iostream>
#include <cstring>
#include "Profesional.h"
#include "Persona.h"

using namespace std;
Profesional::Profesional():Persona()
{
    strcpy(_matricula, "");
    idEspecialidad = 0;
    _valorConsulta = 0.0;
    _soloParticular = false;
}
Profesional::Profesional(string nombre, string apellido, string telefono, string direccion, string ciudad, string email, string matricula, int especialidad, float valorConsulta, bool soloParticular, bool eliminado ):Persona(nombre, apellido, telefono, direccion, ciudad, email)
{
    setMatricula(matricula);
    setEspecialidad(especialidad);
    setValorConsulta(valorConsulta);
    setSoloParticular(soloParticular);
    setEliminado(false);
}
void Profesional::setMatricula(string matricula)
{
    strcpy(_matricula, matricula.c_str());
}
void Profesional::setEspecialidad(int especialidad)
{
    idEspecialidad = especialidad;
}
void Profesional::setValorConsulta(float valorConsulta)
{
    if(valorConsulta > 0)
    {
        _valorConsulta = valorConsulta;
    }
    else
    {
        _valorConsulta = 0;
    }
}
void Profesional::setEliminado(bool estado)
{

    _eliminado = estado;
}
void Profesional::setSoloParticular(bool soloParticular)
{
    _soloParticular = soloParticular;
}
const char* Profesional::getMatricula() const
{
    return _matricula;
}
const int Profesional::getEspecialidad() const
{
    return idEspecialidad;
}
const float Profesional::getValorConsulta() const
{
    return _valorConsulta;
}
const bool Profesional::getSoloParticular() const
{
    return _soloParticular;
}
const bool Profesional::getEliminado() const
{

    return _eliminado;
}
