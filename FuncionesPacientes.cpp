#include <iostream>
#include <cstring>
#include "FuncionesPacientes.h"
#include "PacientesArchivo.h"
#include "funcionesGlobales.h"


Paciente cargarPaciente()
{
    char nombre[50], apellido[50], direccion[50], telefono[50], ciudad[50], email[50];
    char obraSocial[20], dni[20];
    Fecha fechaNacimiento;
    bool existeP;
    int dia, mes, anio;

    std::cout << "Ingrese los datos del paciente " << std::endl;
    std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
    std::cout << "------------------------------------" << std::endl;   
    
    do
    {
        std::cout << "Ingrese el DNI del paciente: ";
        std::cin.ignore();
        std::cin.getline(dni, 20);
        existeP = existePaciente(dni);
        if(existeP)
        {
            std::cout << "El paciente ya ha sido ingresado en el sistema " << std::endl;
        }
    }
    while(existeP);

    if(validateCancelValueString(dni)){
        return Paciente();
    }

    std::cout << "Ingrese el nombre: ";
    //std::cin.ignore();
    std::cin.getline(nombre, 50);

    if(validateCancelValueString(nombre)){
        return Paciente();
    }

    std::cout << "Ingrese el apellido: ";
    std::cin.getline(apellido, 50);
    
    if(validateCancelValueString(apellido)){
        return Paciente();
    }

    std::cout << "Ingrese el domicilio: ";
    std::cin.getline(direccion, 50);

    if(validateCancelValueString(direccion)){
        return Paciente();
    }

    std::cout << "Ingrese la ciudad: ";
    std::cin.getline(ciudad, 50);

    if(validateCancelValueString(ciudad)){
        return Paciente();
    }

    std::cout << "Ingrese el telefono: ";
    std::cin.getline(telefono, 50);

    if(validateCancelValueString(telefono)){
        return Paciente();
    }


    std::cout << "Ingrese el correo electronico: ";
    std::cin.getline(email, 50);

    if(validateCancelValueString(email)){
        return Paciente();
    }
    
    std::cout<<"Fecha de nacimiento "<<std::endl;
    
    do {
        dia = pedirDiaFechaCancelable();

        if(validateCancelValueInt(dia)){
            return Paciente();
        }

        mes = pedirMesFechaCancelable();
    
        if(validateCancelValueInt(mes)){
            return Paciente();
        }

        anio = pedirAnioFechaCancelable();

        if(validateCancelValueInt(anio)){
            return Paciente();
        }

        fechaNacimiento = Fecha(dia, mes, anio);    //std::cin>>fechaNacimiento;
        if(!fechaNacimiento.esValida){
            std::cout << "La fecha ingresada es invalida, ingrese otra por favor " << std::endl;
        }
    } while(!fechaNacimiento.esValida);
   
    

    std::cout << "Ingrese la obra social: ";
    std::cin.ignore();
    std::cin.getline(obraSocial, 20);
    if(validateCancelValueString(obraSocial)){
        return Paciente();
    }

    return Paciente( nombre,  apellido, telefono,  direccion,  ciudad,  email, fechaNacimiento,  obraSocial,  dni);
}

Paciente cargarPaciente(char* Dni)
{
    char nombre[50], apellido[50], direccion[50], telefono[50], ciudad[50], email[50];
    char obraSocial[20], dni[20];
    Fecha fechaNacimiento;

    do
    {
        std::cout << "Ingrese el DNI del paciente: ";
        //8std::cin.ignore();
        std::cin.getline(dni, 20);

        if(strlen(dni) == 0)
        {
            std::cout << "Debe completar el campo " << std::endl;
        }

    }
    while(strlen(dni) == 0);

    std::cout << "Ingrese el nombre: ";
    //std::cin.ignore();
    std::cin.getline(nombre, 50);

    std::cout << "Ingrese el apellido: ";
    std::cin.getline(apellido, 50);

    std::cout << "Ingrese el domicilio: ";
    std::cin.getline(direccion, 50);

    std::cout << "Ingrese la ciudad: ";
    std::cin.getline(ciudad, 50);

    std::cout << "Ingrese el telefono: ";
    std::cin.getline(telefono, 50);

    std::cout << "Ingrese el correo electronico: ";
    std::cin.getline(email, 50);

    std::cout<<"Fecha de nacimiento "<<std::endl;
    std::cin>>fechaNacimiento;

    std::cout << "Ingrese la obra social: ";
    std::cin.ignore();
    std::cin.getline(obraSocial, 20);
    return Paciente( nombre,  apellido, telefono,  direccion,  ciudad,  email, fechaNacimiento,  obraSocial,  dni);

}
void mostrarPaciente(Paciente paciente)
{
    std::cout<<"Apellido : " <<paciente.getApellido() <<std::endl;
    std::cout<<"Nombre : " <<paciente.getNombre() <<std::endl;
    std::cout<<"Domicilio : " <<paciente.getDireccion() <<std::endl;
    std::cout<<"Ciudad : " <<paciente.getCiudad() <<std::endl;
    std::cout<<"Telefono : " <<paciente.getTelefono() <<std::endl;
    std::cout<<"Email : " <<paciente.getEmail() <<std::endl;
    std::cout<<"Fecha de nacimiento : " << paciente.getFechaNacimiento().toString()<<std::endl;
    std::cout<<"DNI : " <<paciente.getDni() <<std::endl;
    std::cout<<"Obra Social : " <<paciente.getObraSocial() <<std::endl;
    ///Prueba edad
    std::cout<<"Prueba getEdad: " <<paciente.getEdad()<< " años" <<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
}
void mostrarPacienteResumido(Paciente paciente)
{
    std::cout<<"Nombre : " <<paciente.getNombre() <<std::endl;
    std::cout<<"Apellido : " <<paciente.getApellido() <<std::endl;
    std::cout<<"DNI : " <<paciente.getDni() <<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
}
void mostrarTodosPacientesActivos()
{
    Paciente *pacientes;
    PacientesArchivo pa;
    int cantidad = pa.getCantidad();
    pacientes = new Paciente[cantidad];
    pa.leerTodos(pacientes, cantidad);

    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = i + 1; j < cantidad; j++)
        {
            if (strcmp(pacientes[i].getApellido(), pacientes[j].getApellido()) > 0)
            {
                // Intercambiar pacientes
                Paciente temp = pacientes[i];
                pacientes[i] = pacientes[j];
                pacientes[j] = temp;
            }
        }
    }

    for (int i = 0; i < cantidad; i++)
    {
        if (!pacientes[i].getEliminado())
        {
            mostrarPaciente(pacientes[i]);
        }
    }

    delete[] pacientes;
}
void mostrarTodosPacientesActivosResumidos()
{
    Paciente *pacientes;
    PacientesArchivo pa;
    int cantidad = pa.getCantidad();
    pacientes = new Paciente [cantidad];
    pa.leerTodos(pacientes, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        if(pacientes[i].getEliminado() == false)
        {

            mostrarPacienteResumido(pacientes[i]);
        }
    }
    delete [] pacientes;
}
void mostrarTodosPacientesEliminados()
{
    Paciente *pacientes;
    PacientesArchivo pa;
    int cantidad = pa.getCantidad();
    pacientes = new Paciente [cantidad];
    pa.leerTodos(pacientes, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        if(pacientes[i].getEliminado() == true)
        {

            mostrarPacienteResumido(pacientes[i]);
        }
    }
    delete [] pacientes;
}
void guardarPaciente()
{
    Paciente paciente;
    PacientesArchivo pa;
    paciente = cargarPaciente();

    if(strlen(paciente.getDni()) == 0){
        std::cout << "Carga de paciente cancelada " << std::endl;
        return;
    }
    
    if(pa.Guardar(paciente))
    {
        std::cout<<std::endl<<"Paciente guardado exitosamente" <<std::endl<<std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        std::cout<<std::endl<<"No se pudo guardar el paciente " <<std::endl<<std::endl;
        system("pause");
        system("cls");
    }
}
void editarPaciente()
{
    char DNI[20];
    PacientesArchivo pa;
    std::cout << "Ingrese el DNI del paciente que quiere editar: ";
    std::cin.ignore();
    std::cin.getline(DNI, 20);

    int pos = pa.buscar(DNI);
    if(pos == -1 )
    {
        std::cout << std::endl <<"El paciente que quiere editar no ha sido encontrado." << std::endl<<std::endl;
        return;
    }

    Paciente paciente;
    std::cout << std::endl;
    paciente = cargarPaciente(DNI);
    bool res = pa.guardar(pos, paciente);
    if(res)
    {
        std::cout << std::endl;
        std::cout << "El paciente ha sido editado correctamente" << std::endl << std::endl;
    }
    else
    {
        std::cout << std::endl <<"Ocurrio un error al editar el paciente" <<std::endl << std::endl;
    }
}
void eliminarPaciente()
{
    Paciente paciente;
    PacientesArchivo pa;

    mostrarTodosPacientesActivosResumidos();
    char dni[20];
    std::cout<<std::endl<<"Ingrese el DNI del paciente a eliminar : ";
    std::cin.ignore();
    std::cin.getline(dni, 20);

    int pos = pa.buscar(dni);
    if(pos != -1)
    {
        paciente = pa.Leer(pos);
        paciente.setEliminado(true);
        pa.guardar(pos,paciente);
        std::cout << std::endl <<"Paciente eliminado con exito" <<std::endl << std::endl;
    }
    else
    {
        std::cout << std::endl << "No se logro eliminar el paciente con exito" << std::endl << std::endl;
    }
}
void restaurarPaciente()
{
    Paciente paciente;
    PacientesArchivo pa;

    mostrarTodosPacientesEliminados();
    char dni[20];
    std::cout<<std::endl<<"Ingrese el DNI del paciente a restaurar : ";
    std::cin.ignore();
    std::cin.getline(dni, 20);

    int pos = pa.buscar(dni);
    if(pos != -1)
    {
        paciente = pa.Leer(pos);
        paciente.setEliminado(false);
        pa.guardar(pos,paciente);
        std::cout << std::endl;
        std::cout<<"Paciente restaurado con exito" <<std::endl<<std::endl;
    }
    else
    {
        std::cout<<std::endl<<"No se logro restaurar el paciente con exito"<<std::endl<<std::endl;
    }
}
void buscarPaciente()
{
    char DNI[20];
    PacientesArchivo pa;
    std::cout << "Ingrese el DNI del paciente que quiere buscar: ";
    std::cin.ignore();
    std::cin.getline(DNI, 20);

    int pos = pa.buscar(DNI);
    if(pos == -1 )
    {
        std::cout << std::endl << "El paciente no ha sido encontrado." << std::endl <<std::endl;
        return;
    }
    Paciente p = pa.Leer(pos);
    std::cout << std::endl;
    mostrarPaciente(p);
}
void buscarPacientesPorObraSocial()
{
    Paciente *pacientes;
    PacientesArchivo pa;
    int cantidad = pa.getCantidad();
    pacientes = new Paciente[cantidad];

    bool encontrado = false;

    if(pacientes == NULL)
    {
        std::cout << std::endl <<"No se pudo leer los pacientes" << std::endl <<std::endl;
    }

    pa.leerTodos(pacientes, cantidad);
    char obraSocial[20];
    std::cout << "Ingrese la obra social del paciente que quiere buscar: ";
    std::cin.ignore();
    std::cin.getline(obraSocial, 20);

    for(int i = 0; i < cantidad; i++)
    {
        if(strcmp(pacientes[i].getObraSocial(), obraSocial) == 0)
        {
            encontrado  = true;
            std::cout << std::endl;
            mostrarPaciente(pacientes[i]);
        }
    }

    if(!encontrado)
    {
        std::cout << "NO se encontro ningun paciente con esa obra social" << std::endl;
    }

    delete [] pacientes;
}
