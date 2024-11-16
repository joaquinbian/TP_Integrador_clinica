#include "funcionesGlobales.h"
#include <iostream>


bool validateCancelValueString(std::string str){
    return strcmp(str.c_str(), "0") == 0;
}
bool validateCancelValueInt(int n){
    return n == 0;
}
bool validateCancelValueFloat(float num){
    return num == 0.0;
}
bool validateCancelValueFecha(Fecha fecha){
    return fecha.validar();
}

int pedirDiaFechaCancelable(){
    int dia;
    do {
        std::cout << "Ingrese el dia (1-31) (0 para cancelar): ";
        std::cin >> dia;
        if(dia < 0 || dia > 31){
            std::cout << "Dia invalido" << std::endl;
        }
    }while(dia < 0 || dia > 31);

    return dia;
}

int pedirMesFechaCancelable(){
    int mes;
    do {
        std::cout << "Ingrese el mes (1-12) (0 para cancelar): ";
        std::cin >> mes;
        if(mes < 0 || mes > 12){
            std::cout << "Mes invalido" << std::endl;
        }
    }while(mes < 0 || mes > 12);

    return mes;
}

int pedirAnioFechaCancelable(){
    int anio;
    do {
        std::cout << "Ingrese el anio (1-12) (0 para cancelar): ";
        std::cin >> anio;
        if(anio < 0){
            std::cout << "Anio invalido" << std::endl;
        }
    }while(anio < 0);

    return anio;
}

bool existePaciente(char* dni)
{

    PacientesArchivo pa;

    int pos = pa.buscar(dni);

    if(pos >= 0){
        return true;
    }
    return false;
}
bool existeEspecialidad(int Id)
{
    EspecialidadesArchivo ea;

    int pos = ea.buscar(Id);

    if(pos >= 0){
        return true;
    }
    return false;
}
void buscarProfesionalesPorEspecialidad(int idEspecialidad)
{
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
void mostrarEspecialidades(Especialidad especialidad)
{
    std::cout<<especialidad.getId()<< " - " <<especialidad.getNombreEspecialidad() <<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
}
void mostrarTodasEspecialidadesActivas()
{
    Especialidad *especialidades;
    EspecialidadesArchivo ea;
    int cantidad = ea.getCantidad();
    especialidades = new Especialidad[cantidad];
    ea.leerTodos(especialidades, cantidad);

    // Ordenar especialidades alfab∩┐╜ticamente por nombre, sin cambiar los IDs
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
Especialidad buscarEspecialidad(int id)
{
    EspecialidadesArchivo espFile;

    return espFile.buscarEspecalidad(id);
}
