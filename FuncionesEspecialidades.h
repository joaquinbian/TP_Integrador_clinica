#pragma once
#include "Especialidad.h"


const int LONGITUD_ESPECIALIDAD = 50;
Especialidad cargarEspecialidad();
void guardarEspecialidad();
void mostrarTodasEspeciaidadesEliminadas();
void editarEspecialidad();
void eliminarEspecialidad();
void restaurarEspecialidad();
bool existeEspecialidad(char *nombreEspecialidad);
bool existeEspecialidad(char *nombreEspecialidad, int id);