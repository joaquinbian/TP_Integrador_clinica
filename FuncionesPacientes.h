#pragma once
#include "Paciente.h"

const int LONGITUD_NOMBRE = 50;
const int LONGITUD_APELLIDO = 50;
const int LONGITUD_DIRECCION = 50;
const int LONGITUD_TELEFONO = 50;
const int LONGITUD_CIUDAD = 50;
const int LONGITUD_EMAIL = 50;
const int LONGITUD_OBRASOCIAL = 20;
const int LONGITUD_DNI = 20;




bool existePaciente(char *dni);
Paciente cargarPaciente();
Paciente cargarPacienteAEditar(char *dni);
void mostrarPaciente(Paciente paciente);
void mostrarPacienteResumido(Paciente paciente);
void mostrarTodosPacientesActivos();
void mostrarTodosPacientesActivosResumidos();
void mostrarTodosPacientesEliminados();
void guardarPaciente();
void editarPaciente();
void eliminarPaciente();
void restaurarPaciente();
void buscarPaciente();
void buscarPacientesPorObraSocial();








