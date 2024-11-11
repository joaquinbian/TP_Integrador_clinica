#pragma once
#include <iostream>
#include <cstring>
#include "PacientesArchivo.h"
#include "Paciente.h"
#include "Profesional.h"
#include "ProfesionalesArchivo.h"
#include "Especialidad.h"
#include "EspecialidadesArchivo.h"
#include "Turno.h"
#include "TurnosArchivo.h"

bool validarExisteTurno(Turno t);
bool existeProfesional(char *matricula);


bool existePaciente(char* dni);

///PROFESIONALES
void mostrarProfesional(Profesional profesional);

//se queda aca
void buscarProfesionalesPorEspecialidad(int idEspecialidad);

//se queda aca
///ESPECIALIDADES
void mostrarTodasEspecialidadesActivas();
void mostrarEspecialidades(Especialidad especialidad);




//se queda aca
Especialidad buscarEspecialidad(int id);

///TURNOS
