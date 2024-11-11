#include "funcionesGlobales.h"
#include <iostream>
bool existePaciente(char* dni){
    PacientesArchivo pa;

    int pos = pa.buscar(dni);

    if(pos >= 0){
        return true;
    }
    return false;
}

void buscarProfesionalesPorEspecialidad(int idEspecialidad){
    Profesional *profesional;
    ProfesionalesArchivo pa;
    int cantidad = pa.getCantidad();
    profesional = new Profesional[cantidad];

    bool encontrado = false;

    if(profesional == NULL){
        std::cout << "No se pudo leer los profesionales" << std::endl;
    }

    pa.leerTodos(profesional, cantidad);

    for(int i = 0; i < cantidad; i++){
        if(profesional[i].getEspecialidad() == idEspecialidad){
            encontrado  = true;
            std::cout << std::endl;
            mostrarProfesional(profesional[i]);
        }
    }

    if(!encontrado){
        std::cout << "NO se encontro ningun profesional con esa especialidad" << std::endl;
    }

    delete [] profesional;
}

void mostrarProfesional(Profesional profesional)
{
    std::cout<<"Nombre : " <<profesional.getNombre() <<std::endl;
    std::cout<<"Apellido : " <<profesional.getApellido() <<std::endl;
    std::cout<<"Domicilio : " <<profesional.getDireccion() <<std::endl;
    std::cout<<"Ciudad : " <<profesional.getCiudad() <<std::endl;
    std::cout<<"Telefono : " <<profesional.getTelefono() <<std::endl;
    std::cout<<"Email : " <<profesional.getEmail() <<std::endl;
    std::cout<<"Matricula : " <<profesional.getMatricula() <<std::endl;
    std::cout<<"Especialidad : " << buscarEspecialidad(profesional.getEspecialidad()).getNombreEspecialidad() <<std::endl;
    std::cout<<"Valor de la consulta : $" <<profesional.getValorConsulta() <<std::endl;
    std::cout<<"Atiende obras sociales y prepagas : " <<profesional.getSoloParticular() <<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
}

void mostrarEspecialidades(Especialidad especialidad){
    std::cout<<especialidad.getId()<< " - " <<especialidad.getNombreEspecialidad() <<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
}

void mostrarTodasEspecialidadesActivas(){
    Especialidad *especialidades;
    EspecialidadesArchivo ea;
    int cantidad = ea.getCantidad();
    especialidades = new Especialidad[cantidad];
    ea.leerTodos(especialidades, cantidad);

    // Ordenar especialidades alfabΓê⌐ΓöÉΓò£ticamente por nombre, sin cambiar los IDs
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = i + 1; j < cantidad; j++)
        {
            int id1 = especialidades[i].getId();
            int id2 = especialidades[j].getId();

            if (id1 > id2)
            {

                Especialidad temp = especialidades[i];
                especialidades[i] = especialidades[j];
                especialidades[j] = temp;
            }
        }
    }


    for (int i = 0; i < cantidad; i++)
    {
        if (!especialidades[i].getEliminado())
        {
            mostrarEspecialidades(especialidades[i]);
        }
    }

    delete[] especialidades;
}
Especialidad buscarEspecialidad(int id){
    EspecialidadesArchivo espFile;
    
    return espFile.buscarEspecalidad(id);
}
