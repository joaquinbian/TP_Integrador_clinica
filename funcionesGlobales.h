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


//PACIENTES
bool existePaciente(char* dni);

///PROFESIONALES
void mostrarProfesional(Profesional profesional);
void buscarProfesionalesPorEspecialidad(int idEspecialidad);
bool existeProfesional(char *matricula);

//TURNOS
bool validarExisteTurno(Turno t);

///ESPECIALIDADES
void mostrarTodasEspecialidadesActivas();
void mostrarEspecialidades(Especialidad especialidad);
Especialidad buscarEspecialidad(int id);





