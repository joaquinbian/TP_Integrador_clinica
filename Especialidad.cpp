#include <iostream>
#include <cstring>
#include "Especialidad.h"

using namespace std;

Especialidad::Especialidad() {
    //_id = _contadorId;
    _nombreEspecialidad[0] = '\0';
    _eliminado = false;
}

Especialidad::Especialidad(string nombreEspecialidad,int id, bool eliminado) {
    //_id = ++_contadorId;
    setId(id);
    setNombreEspecialidad(nombreEspecialidad);
    _eliminado = eliminado;
}

void Especialidad::setNombreEspecialidad(string nombreEspecialidad) {
    strncpy(_nombreEspecialidad, nombreEspecialidad.c_str(), sizeof(_nombreEspecialidad) - 1);
    _nombreEspecialidad[sizeof(_nombreEspecialidad) - 1] = '\0';
}

void Especialidad::setEliminado(bool estado) {
    _eliminado = estado;
}
void Especialidad::setId(int id){

    _id = id;
}
const char* Especialidad::getNombreEspecialidad() const {
    return _nombreEspecialidad;
}

const bool Especialidad::getEliminado() const {
    return _eliminado;
}
const int Especialidad::getId() const {

    return _id;
}

//int Especialidad::_contadorId = 0;
