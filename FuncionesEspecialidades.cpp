#include <iostream>
#include "FuncionesEspecialidades.h"
#include "EspecialidadesArchivo.h"
#include "funcionesGlobales.h"

Especialidad cargarEspecialidad()
{
    char nombreEspecialidad[50];

    std::cout<<"Ingrese el nombre de la especialidad : ";
    std::cin.ignore();
    std::cin.getline(nombreEspecialidad, 50);

    return Especialidad(nombreEspecialidad);
}
void guardarEspecialidad()
{
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    especialidad = cargarEspecialidad();
    if(ea.Guardar(especialidad))
    {
        std::cout<<"Especialidad guardada exitosamente" <<std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        std::cout<<"No se pudo guardar la especialidad " <<std::endl;
        system("pause");
        system("cls");
    }
}




void mostrarTodasEspeciaidadesEliminadas()
{
    Especialidad *especialidades;
    EspecialidadesArchivo ea;
    int cantidad = ea.getCantidad();
    especialidades = new Especialidad [cantidad];
    ea.leerTodos(especialidades, cantidad);
    for(int i = 0; i < cantidad; i++)
    {

        if(especialidades[i].getEliminado() == true)
        {

            mostrarEspecialidades(especialidades[i]);
        }
    }
    delete [] especialidades;
}
void editarEspecialidad()
{
    int id;
    char nombreEspecialidad[50];
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    mostrarTodasEspecialidadesActivas();
    std::cout << "Ingrese el ID de la especialidad que desea editar: ";
    std::cin>>id;
    std::cin.ignore();

    std::cout<<"Ingrese el nombre de la especialidad : ";
    std::cin.getline(nombreEspecialidad, 50);

    int pos = ea.buscar(id);
    if(pos != -1)
    {
        especialidad = ea.Leer(pos);
        especialidad.setNombreEspecialidad(nombreEspecialidad);
        ea.guardar(pos,especialidad);
        std::cout<<"especialidad modificada " <<std::endl;
    }
    else
    {
        std::cout<<"No se encontro la especialidad "<<std::endl;
    }
}
void eliminarEspecialidad()
{
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    mostrarTodasEspecialidadesActivas();
    int codigo;
    std::cout<<"Ingrese el codigo a eliminar : ";
    std::cin>>codigo;
    int pos = ea.buscar(codigo);
    if(pos != -1)
    {
        especialidad = ea.Leer(pos);
        especialidad.setEliminado(true);
        ea.guardar(pos,especialidad);
        std::cout<<"especialidad eliminada " <<std::endl;
    }
    else
    {
        std::cout<<"No se encontro la especialidad "<<std::endl;
    }
}
void restaurarEspecialidad()
{
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    int codigo;
    mostrarTodasEspeciaidadesEliminadas();
    std::cout<<"Ingrese el codigo de la especialidad a restaurar : ";
    std::cin>>codigo;
    int pos = ea.buscar(codigo);
    if(pos != -1)
    {
        especialidad = ea.Leer(pos);

        if(especialidad.getEliminado())
        {
            especialidad.setEliminado(false);
            ea.guardar(pos, especialidad);
            std::cout<<"Especialidad restaurada " <<std::endl;
        }
        else
        {
            std::cout<<"La especialidad ya se encuentra en el listado" <<std::endl;
        }

    }
    else
    {
        std::cout<<"Especialidad no encontrada " <<std::endl;
    }

}