#include<iostream>
#include <cstring>
#include "Profesional.h"
#include "Persona.h"
using namespace std;
Profesional::Profesional(){}
Profesional::Profesional(string nombre, string apellido, string telefono, string direccion, string ciudad, string email, string matricula, string especialidad, float valorConsulta, bool soloParticular ):Persona(nombre, apellido, telefono, direccion, ciudad, email)
{
    setMatricula(matricula);
    setEspecialidad(especialidad);
    setValorConsulta(valorConsulta);
    setSoloParticular(soloParticular);
}
void Profesional::setMatricula(string matricula)
{
    strcpy(_matricula, matricula.c_str());
}
void Profesional::setEspecialidad(string especialidad)
{
    strcpy(_especialidad,especialidad.c_str());
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
void Profesional::setSoloParticular(bool soloParticular)
{
    _soloParticular = soloParticular;
}
const char* Profesional::getMatricula() const
{
    return _matricula;
}
const char* Profesional::getEspecialidad() const
{
    return _especialidad;
}
const float Profesional::getValorConsulta() const
{
    return _valorConsulta;
}
const bool Profesional::getSoloParticular() const
{
    return _soloParticular;
}

void Profesional::mostrar(){
    cout<<"Nombre : " <<this->getNombre() <<endl;
    cout<<"Apellido : " <<this->getApellido() <<endl;
    cout<<"Domicilio : " <<this->getDireccion() <<endl;
    cout<<"Ciudad : " <<this->getCiudad() <<endl;
    cout<<"Telefono : " <<this->getTelefono() <<endl;
    cout<<"Email : " <<this->getEmail() <<endl;
    cout<<"Matricula : " <<this->getMatricula() <<endl;
    cout<<"Especialidad : " <<this->getEspecialidad() <<endl;
    cout<<"Valor de la consulta : $" <<this->getValorConsulta() <<endl;
    cout<<"Atiende obras sociales y prepagas : " <<this->getSoloParticular() <<endl;
}