#include <iostream>
#include "FuncionesEspecialidades.h"
#include "EspecialidadesArchivo.h"
#include "funcionesGlobales.h"

bool existeEspecialidad(char *nombreEspecialidad)
{
    EspecialidadesArchivo ea;
    int cantidad = ea.getCantidad();
    Especialidad *especialidades = new Especialidad[cantidad];
    ea.leerTodos(especialidades, cantidad);

    for(int i = 0; i < cantidad; i++)
    {
        if(sonStringsIguales((char *)especialidades[i].getNombreEspecialidad(), nombreEspecialidad))
        {
            delete [] especialidades;
            return true;
        }
    }

    delete [] especialidades;

    return false;
}
bool existeEspecialidad(char *nombreEspecialidad, int codigo)
{
    EspecialidadesArchivo ea;
    int cantidad = ea.getCantidad();
    Especialidad *especialidades = new Especialidad[cantidad];
    ea.leerTodos(especialidades, cantidad);

    for(int i = 0; i < cantidad; i++)
    {
        if(sonStringsIguales((char *)especialidades[i].getNombreEspecialidad(), nombreEspecialidad) && especialidades[i].getId() != codigo)
        {
            delete [] especialidades;
            return true;
        }
    }

    delete [] especialidades;

    return false;
}
Especialidad cargarEspecialidad()
{
    char nombreEspecialidad[LONGITUD_ESPECIALIDAD];
    int id;

    std::cout << "Carga especialidad" << std::endl;
    std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    std::cout<<"Ingrese el nombre de la especialidad : ";
    std::cin.ignore();
    std::cin.getline(nombreEspecialidad, LONGITUD_ESPECIALIDAD);

    while(!validateInputString(nombreEspecialidad, LONGITUD_ESPECIALIDAD))
    {
        std::cout<<"Ingrese el nombre de la especialidad : ";
        std::cin.getline(nombreEspecialidad, LONGITUD_ESPECIALIDAD);
    }

    if(existeEspecialidad(nombreEspecialidad))
    {
        std::cout<<"La especialidad ya existe " <<std::endl;
        return Especialidad();

    }

    if(validateCancelValueString(nombreEspecialidad))
    {
        return Especialidad();
    }

    id = EspecialidadesArchivo().getCantidad()+1;

    return Especialidad(nombreEspecialidad,id ,false);
}
void guardarEspecialidad()
{
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    especialidad = cargarEspecialidad();

    if(estaStringVacio((char *)especialidad.getNombreEspecialidad()))
    {
        std::cout<<"Carga de especialidad cancelada " <<std::endl;

        return;
    }

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
    char nombreEspecialidad[LONGITUD_ESPECIALIDAD];
    bool existeEsp = false;
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    mostrarTodasEspecialidadesActivas();
    std::cout<<std::endl<<"Digite 0 para cancelar" << std::endl;

    do{
        std::cout << "Ingrese el codigo de la especialidad que desea editar: ";
        std::cin>>id;
        existeEsp = existeEspecialidadActiva(id) || validateCancelValueInt(id); //si ingresa 0, dejamos que avance para que cancele
    }while(!validateInputInt());

    std::cin.ignore();



    if(validateCancelValueInt(id)){
        std::cout << "Edicion de especialidad cancelada" << std::endl;
        return;
    }

    std::cout<<std::endl;

    if(existeEsp){
        do{
            std::cout<<"Ingrese el nombre de la especialidad : ";
            std::cin.getline(nombreEspecialidad, LONGITUD_ESPECIALIDAD);
        }while(!validateInputString(nombreEspecialidad, LONGITUD_ESPECIALIDAD));

        if(validateCancelValueString(nombreEspecialidad)){
            return;
        }

        if(existeEspecialidad(nombreEspecialidad, id)){
            std::cout<<"La especialidad ya existe " <<std::endl;
            return;
        }

        int pos = ea.buscar(id);
        if(pos != -1)
        {
            especialidad = ea.Leer(pos);
            especialidad.setNombreEspecialidad(nombreEspecialidad);
            ea.guardar(pos,especialidad);
            std::cout<<"especialidad modificada " <<std::endl;
        }
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
    bool existeEsp = false;
    std::cout<<std::endl<<"Digite 0 para cancelar" << std::endl;
    do{
        std::cout << "Ingrese el codigo de la especialidad que desea eliminar: ";
        std::cin>>codigo;
        existeEsp = existeEspecialidadActiva(codigo) || validateCancelValueInt(codigo); //si ingresa 0, dejamos que avance para que cancele

    }while(!validateInputInt());

    if(validateCancelValueInt(codigo)){
        std::cout << "Eliminacion de especialidad cancelada" << std::endl;
        return;
    }

    if(existeEsp){
        int pos = ea.buscar(codigo);
        if(pos != -1)
        {
            especialidad = ea.Leer(pos);
            especialidad.setEliminado(true);
            ea.guardar(pos,especialidad);
            std::cout<<"especialidad eliminada " <<std::endl;
        }
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
    bool existeEsp = false;
    mostrarTodasEspeciaidadesEliminadas();
    std::cout<<std::endl<<"Digite 0 para cancelar" << std::endl;
     do{
        std::cout << "Ingrese el codigo de la especialidad ";
        std::cin >> codigo;
        existeEsp = existeEspecialidad(codigo) || validateCancelValueInt(codigo); //si ingresa 0, dejamos que avance para que cancele

    }while(!validateInputInt());


    if(validateCancelValueInt(codigo)){
        std::cout << "Restauracion de especialidad cancelada" << std::endl;
        return;
    }

    if(existeEsp){

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
    }
    else
    {
        std::cout<<"Especialidad no encontrada " <<std::endl;
    }

}
