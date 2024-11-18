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



//TODOS 
bool validateCancelValueString(std::string str);
bool validateCancelValueChar(char c);
bool validateCancelValueInt(int num);
bool validateCancelValueFloat(float num);
bool estaStringVacio(const char *str);


//PARA CREAR FECHAS
int pedirDiaFechaCancelable();
int pedirMesFechaCancelable();
int pedirAnioFechaCancelable();
Fecha obtenerFechaActual();


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
bool existeEspecialidad(int Id);
