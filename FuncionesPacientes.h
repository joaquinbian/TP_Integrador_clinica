#pragma once
#include "Paciente.h"

bool existePaciente(char *dni);
Paciente cargarPaciente();
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








