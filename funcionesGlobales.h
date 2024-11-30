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


const int LONGITUD_NOMBRE = 50;
const int LONGITUD_APELLIDO = 50;
const int LONGITUD_DIRECCION = 50;
const int LONGITUD_TELEFONO = 50;
const int LONGITUD_CIUDAD = 50;
const int LONGITUD_EMAIL = 50;
const int LONGITUD_DNI = 20;
const int LONGITUD_MATRICULA = 50;



//TODOS
bool validateCancelValueString(std::string str);
bool validateCancelValueChar(char c);
bool validateCancelValueInt(int num);
bool validateCancelValueFloat(float num);
bool estaStringVacio(char *str);
void pedirStringBucle(char* variable, std::string mensaje, int longitud);
bool validarInput();
bool validateInputString(char* str, int longitud);
bool validateInputInt();
char *trim(char *s);
int pedirIntValido(std::string msj);
bool sonStringsIguales(char* str1, char* str2);


//PARA CREAR FECHAS
int pedirDiaFechaCancelable();
int pedirMesFechaCancelable();
int pedirAnioFechaCancelable();
Fecha obtenerFechaActual();


//PACIENTES
bool existePaciente(char* dni);
bool estaPacienteActivo(char* dni);

///PROFESIONALES
void mostrarProfesional(Profesional profesional);
void buscarProfesionalesPorEspecialidad(int idEspecialidad);
bool existeProfesional(char *matricula);
bool estaProfesionalActivo(char *matricula);
//TURNOS
bool validarExisteTurno(Turno t);

///ESPECIALIDADES
void mostrarTodasEspecialidadesActivas();
void mostrarEspecialidades(Especialidad especialidad);
Especialidad buscarEspecialidad(int id);
bool existeEspecialidad(int Id);
bool existeEspecialidadActiva(int id);
