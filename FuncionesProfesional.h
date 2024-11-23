#pragma once
#include "Profesional.h"




Profesional cargarProfesional();
Profesional cargarProfesionalAEditar(char *matricula);
void guardarProfesional();
void mostrarProfesionalResumido(Profesional profesional);
void mostrarTodosProfesionalesActivos();
void mostrarTodosProfesionalesActivosResumido();
void mostrarTodosProfesionalesEliminados();
void editarProfesional();
void eliminarProfesional();
void restaurarProfesional();
void buscarProfesional();
bool existeProfesional(char *matricula);
void buscarProfesionalPorEspecialidad();