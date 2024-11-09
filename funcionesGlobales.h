#include <iostream>
#include <cstring>
#include "PacientesArchivo.h"
#include "Paciente.h"
#include "Profesional.h"
#include "ProfesionalesArchivo.h"
#include "Especialidad.h"
#include "EspecialidadesArchivo.h"

using namespace std;
///PACIENTES
Paciente cargarPaciente()
{
    char nombre[50], apellido[50], direccion[50], telefono[50], ciudad[50], email[50];
    char obraSocial[20], dni[20];
    Fecha fechaNacimiento;

    cout << "Ingrese el nombre: ";
    cin.ignore();
    cin.getline(nombre, 50);

    cout << "Ingrese el apellido: ";
    cin.getline(apellido, 50);

    cout << "Ingrese el domicilio: ";
    cin.getline(direccion, 50);

    cout << "Ingrese la ciudad: ";
    cin.getline(ciudad, 50);

    cout << "Ingrese el telefono: ";
    cin.getline(telefono, 50);

    cout << "Ingrese el correo electronico: ";
    cin.getline(email, 50);

    cout<<"Fecha de nacimiento "<<endl;
    cin>>fechaNacimiento;

    cout << "Ingrese el DNI del paciente: ";
    cin.ignore();
    cin.getline(dni, 20);

    cout << "Ingrese la obra social: ";
    cin.getline(obraSocial, 20);

    return Paciente( nombre,  apellido, telefono,  direccion,  ciudad,  email, fechaNacimiento,  obraSocial,  dni);
}
void mostrarPaciente(Paciente paciente)
{
    cout<<"Apellido : " <<paciente.getApellido() <<endl;
    cout<<"Nombre : " <<paciente.getNombre() <<endl;
    cout<<"Domicilio : " <<paciente.getDireccion() <<endl;
    cout<<"Ciudad : " <<paciente.getCiudad() <<endl;
    cout<<"Telefono : " <<paciente.getTelefono() <<endl;
    cout<<"Email : " <<paciente.getEmail() <<endl;
    cout<<"Fecha de nacimiento : " << paciente.getFechaNacimiento().toString()<<endl;
    cout<<"DNI : " <<paciente.getDni() <<endl;
    cout<<"Obra Social : " <<paciente.getObraSocial() <<endl;
    cout<<"-----------------------------------------------"<<endl;
}
void mostrarPacienteResumido(Paciente paciente)
{
    cout<<"Nombre : " <<paciente.getNombre() <<endl;
    cout<<"Apellido : " <<paciente.getApellido() <<endl;
    cout<<"DNI : " <<paciente.getDni() <<endl;
    cout<<"-----------------------------------------------"<<endl;
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
    if(pa.Guardar(paciente))
    {
        cout<<endl<<"Paciente guardado exitosamente" <<endl<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<endl<<"No se pudo guardar el paciente " <<endl<<endl;
        system("pause");
        system("cls");
    }
}
void editarPaciente()
{
    char DNI[20];
    PacientesArchivo pa;
    cout << "Ingrese el DNI del paciente que quiere editar: ";
    cin.ignore();
    cin.getline(DNI, 20);

    int pos = pa.buscar(DNI);
    if(pos == -1 )
    {
        cout << endl <<"El paciente que quiere editar no ha sido encontrado." << endl<<endl;
        return;
    }

    Paciente paciente;
    cout << endl;
    paciente = cargarPaciente();
    bool res = pa.guardar(pos, paciente);
    if(res)
    {
        cout << endl;
        cout << "El paciente ha sido editado correctamente" << endl << endl;
    }
    else
    {
        cout << endl <<"Ocurrio un error al editar el paciente" <<endl << endl;
    }
}
void eliminarPaciente()
{
    Paciente paciente;
    PacientesArchivo pa;

    mostrarTodosPacientesActivosResumidos();
    char dni[20];
    cout<<endl<<"Ingrese el DNI del paciente a eliminar : ";
    cin.ignore();
    cin.getline(dni, 20);

    int pos = pa.buscar(dni);
    if(pos != -1)
    {
        paciente = pa.Leer(pos);
        paciente.setEliminado(true);
        pa.guardar(pos,paciente);
        cout << endl <<"Paciente eliminado con exito" <<endl << endl;
    }
    else
    {
        cout << endl << "No se logro eliminar el paciente con exito" << endl << endl;
    }
}
void restaurarPaciente()
{
    Paciente paciente;
    PacientesArchivo pa;

    mostrarTodosPacientesEliminados();
    char dni[20];
    cout<<endl<<"Ingrese el DNI del paciente a restaurar : ";
    cin.ignore();
    cin.getline(dni, 20);

    int pos = pa.buscar(dni);
    if(pos != -1)
    {
        paciente = pa.Leer(pos);
        paciente.setEliminado(false);
        pa.guardar(pos,paciente);
        cout << endl;
        cout<<"Paciente restaurado con exito" <<endl<<endl;
    }
    else
    {
        cout<<endl<<"No se logro restaurar el paciente con exito"<<endl<<endl;
    }
}

void buscarPaciente(){
    char DNI[20];
    PacientesArchivo pa;
    cout << "Ingrese el DNI del paciente que quiere buscar: ";
    cin.ignore();
    cin.getline(DNI, 20);

    int pos = pa.buscar(DNI);
    if(pos == -1 ){
        cout << endl << "El paciente no ha sido encontrado." << endl <<endl;
        return;
    }
    Paciente p = pa.Leer(pos);
    cout << endl;
    mostrarPaciente(p);
}

void buscarPacientesPorObraSocial(){
    Paciente *pacientes;
    PacientesArchivo pa;
    int cantidad = pa.getCantidad();
    pacientes = new Paciente[cantidad];

    bool encontrado = false;

    if(pacientes == NULL){
        cout << endl <<"No se pudo leer los pacientes" << endl <<endl;
    }

    pa.leerTodos(pacientes, cantidad);
    char obraSocial[20];
    cout << "Ingrese la obra social del paciente que quiere buscar: ";
    cin.ignore();
    cin.getline(obraSocial, 20);

    for(int i = 0; i < cantidad; i++){
        if(strcmp(pacientes[i].getObraSocial(), obraSocial) == 0){
            encontrado  = true;
            cout << endl;
            mostrarPaciente(pacientes[i]);
        }
    }

    if(!encontrado){
        cout << "NO se encontro ningun paciente con esa obra social" << endl;
    }

    delete [] pacientes;
}


///PROFESIONALES
Profesional cargarProfesional()
{
    char nombre[50], apellido[50], direccion[50], telefono[50], ciudad[50], email[50], matricula[15], especialidad[50], soloParticularChar;
    float valorConsulta;
    bool soloParticular = false;

    cout << "Ingrese el nombre: ";
    cin.ignore();
    cin.getline(nombre, 50);

    cout << "Ingrese el apellido: ";
    cin.getline(apellido, 50);

    cout << "Ingrese el domicilio: ";
    cin.getline(direccion, 50);

    cout << "Ingrese la ciudad: ";
    cin.getline(ciudad, 50);

    cout << "Ingrese el telefono: ";
    cin.getline(telefono, 50);

    cout << "Ingrese el correo electronico: ";
    cin.getline(email, 50);

    cout << "Ingrese la especialidad: ";
    cin.getline(especialidad, 50);

    cout << "Ingrese el numero de matricula: ";
    cin.getline(matricula, 50);

    cout << "Ingrese el valor de la consulta: $";
    cin >> valorConsulta;

    cout << "Atiende solo particulares? (s/n): ";
    cin >> soloParticularChar;

    // Actualiza `soloParticular` basado en la respuesta
    if (soloParticularChar == 's' || soloParticularChar == 'S')
    {
        soloParticular = true;
    }

    return Profesional(nombre, apellido, telefono, direccion, ciudad, email, matricula, especialidad, valorConsulta, soloParticular);
}
void guardarProfesional()
{
    Profesional profesional;
    ProfesionalesArchivo pa;
    profesional = cargarProfesional();
    if(pa.Guardar(profesional))
    {
        cout<<endl<<"Profesional guardado exitosamente" <<endl<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<endl<<"No se pudo guardar el profesional " <<endl<<endl;
        system("pause");
        system("cls");
    }
}
void mostrarProfesional(Profesional profesional)
{
    cout<<"Nombre : " <<profesional.getNombre() <<endl;
    cout<<"Apellido : " <<profesional.getApellido() <<endl;
    cout<<"Domicilio : " <<profesional.getDireccion() <<endl;
    cout<<"Ciudad : " <<profesional.getCiudad() <<endl;
    cout<<"Telefono : " <<profesional.getTelefono() <<endl;
    cout<<"Email : " <<profesional.getEmail() <<endl;
    cout<<"Matricula : " <<profesional.getMatricula() <<endl;
    cout<<"Especialidad : " <<profesional.getEspecialidad() <<endl;
    cout<<"Valor de la consulta : $" <<profesional.getValorConsulta() <<endl;
    cout<<"Atiende obras sociales y prepagas : " <<profesional.getSoloParticular() <<endl;
    cout<<"-----------------------------------------------"<<endl;
}
void mostrarProfesionalResumido(Profesional profesional)
{
    cout<<"Nombre : " <<profesional.getNombre() <<endl;
    cout<<"Apellido : " <<profesional.getApellido() <<endl;
    cout<<"Matricula : " <<profesional.getMatricula() <<endl;
    cout<<"Especialidad : " <<profesional.getEspecialidad() <<endl;
    cout<<"-----------------------------------------------"<<endl;
}
void mostrarTodosProfesionalesActivos()
{
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidad = pa.getCantidad();
    profesionales = new Profesional[cantidad];
    pa.leerTodos(profesionales, cantidad);

    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = i + 1; j < cantidad; j++)
        {

            if (strcmp(profesionales[i].getApellido(), profesionales[j].getApellido()) > 0)
            {
                Profesional temp = profesionales[i];
                profesionales[i] = profesionales[j];
                profesionales[j] = temp;
            }
        }
    }

    // Mostrar pacientes activos
    for (int i = 0; i < cantidad; i++)
    {
        if (!profesionales[i].getEliminado())
        {
            mostrarProfesional(profesionales[i]);
        }
    }

    delete[] profesionales;
}
void mostrarTodosProfesionalesActivosResumido()
{
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidad = pa.getCantidad();
    profesionales = new Profesional [cantidad];
    pa.leerTodos(profesionales, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        if(profesionales[i].getEliminado() == false)
        {

            mostrarProfesionalResumido(profesionales[i]);
        }
    }
    delete [] profesionales;
}
void mostrarTodosProfesionalesEliminados()
{
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidad = pa.getCantidad();
    profesionales = new Profesional [cantidad];
    pa.leerTodos(profesionales, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        if(profesionales[i].getEliminado() == true)
        {

            mostrarProfesionalResumido(profesionales[i]);
        }
    }
    delete [] profesionales;
}
void editarProfesional()
{
    char matricula[20];
    ProfesionalesArchivo pa;
    mostrarTodosProfesionalesActivos();
    cout <<endl<< "Ingrese la matricula del profesional que quiere editar: ";
    cin.ignore();
    cin.getline(matricula, 20);

    int pos = pa.buscar(matricula);
    if(pos == -1 )
    {
        cout << endl <<"El profesional que quiere editar no ha sido encontrado." <<endl<< endl;
        return;
    }

    Profesional profesional;
    cout<<endl;
    profesional = cargarProfesional();
    bool res = pa.guardar(pos, profesional);
    if(res)
    {
        cout <<endl<< "El profesional ha sido editado correctamente"<<endl;
    }
    else
    {
        cout <<endl<< "Ocurrio un error al editar el profesional"<<endl;
    }
}
void eliminarProfesional()
{
    Profesional profesional;
    ProfesionalesArchivo pa;

    mostrarTodosProfesionalesActivosResumido();

    char matricula[20];
    cout<<endl<<"Ingrese la matricula del profesional a eliminar : ";
    cin.ignore();
    cin.getline(matricula, 20);

    int pos = pa.buscar(matricula);
    if(pos != -1)
    {
        profesional = pa.Leer(pos);
        profesional.setEliminado(true);
        pa.guardar(pos,profesional);
        cout<<endl<<"profesional eliminado " <<endl<<endl;
    }
    else
    {
        cout<<endl<<"No se encontro el profesional "<<endl<<endl;
    }
}
void restaurarProfesional()
{
    Profesional profesional;
    ProfesionalesArchivo pa;

    mostrarTodosProfesionalesEliminados();

    char matricula[20];
    cout<<endl<<"Ingrese la matricula del profesional a eliminar : ";
    cin.ignore();
    cin.getline(matricula, 20);

    int pos = pa.buscar(matricula);
    if(pos != -1)
    {
        profesional = pa.Leer(pos);
        profesional.setEliminado(false);
        pa.guardar(pos,profesional);
        cout<<endl<<"Profesional restaurado con exito" <<endl<<endl;
    }
    else
    {
        cout<<endl<<"No se encontro el profesional "<<endl<<endl;
    }
}
void buscarProfesional(){
    char matricula[15];
    ProfesionalesArchivo pa;
    cout << "Ingrese la matricula del profesional que quiere buscar: ";
    cin.ignore();
    cin.getline(matricula, 15);

    int pos = pa.buscar(matricula);
    if(pos == -1 ){
        cout << "El profesional no ha sido encontrado." << endl;
        return;
    }
    Profesional p = pa.Leer(pos);
    cout << endl;
    mostrarProfesional(p);
}
void buscarProfesionalPorEspecialidad(){
    Profesional *profesional;
    ProfesionalesArchivo pa;
    int cantidad = pa.getCantidad();
    profesional = new Profesional[cantidad];

    bool encontrado = false;

    if(profesional == NULL){
        cout << "No se pudo leer los profesionales" << endl;
    }

    pa.leerTodos(profesional, cantidad);
    char especialidad[50];
    cout << "Ingrese la especialidad del profesional que quiere buscar: ";
    cin.ignore();
    cin.getline(especialidad, 50);

    for(int i = 0; i < cantidad; i++){
        if(strcmp(profesional[i].getEspecialidad(), especialidad) == 0){
            encontrado  = true;
            cout << endl;
            mostrarProfesional(profesional[i]);
        }
    }

    if(!encontrado){
        cout << "NO se encontro ningun profesional con esa obra social" << endl;
    }

    delete [] profesional;
}
///ESPECIALIDADES
Especialidad cargarEspecialidad()
{
    char nombreEspecialidad[50];

    cout<<"Ingrese el nombre de la especialidad : ";
    cin.ignore();
    cin.getline(nombreEspecialidad, 50);

    return Especialidad(nombreEspecialidad);
}
void guardarEspecialidad()
{
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    especialidad = cargarEspecialidad();
    if(ea.Guardar(especialidad))
    {
        cout<<"Especialidad guardada exitosamente" <<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"No se pudo guardar la especialidad " <<endl;
        system("pause");
        system("cls");
    }
}
void mostrarEspecialidades(Especialidad especialidad)
{
    cout<<especialidad.getId()<< " - " <<especialidad.getNombreEspecialidad() <<endl;
    cout<<"-----------------------------------------------"<<endl;
}
#include <cstring> // Para usar strcmp

void mostrarTodasEspecialidadesActivas()
{
    Especialidad *especialidades;
    EspecialidadesArchivo ea;
    int cantidad = ea.getCantidad();
    especialidades = new Especialidad[cantidad];
    ea.leerTodos(especialidades, cantidad);

    // Ordenar especialidades alfab�ticamente por nombre, sin cambiar los IDs
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = i + 1; j < cantidad; j++)
        {
            const char *nombre1 = especialidades[i].getNombreEspecialidad();
            const char *nombre2 = especialidades[j].getNombreEspecialidad();

            if (nombre1 && nombre2 && strcmp(nombre1, nombre2) > 0)
            {
                // Intercambiar especialidades, los IDs permanecen iguales
                Especialidad temp = especialidades[i];
                especialidades[i] = especialidades[j];
                especialidades[j] = temp;
            }
        }
    }

    // Mostrar especialidades activas
    for (int i = 0; i < cantidad; i++)
    {
        if (!especialidades[i].getEliminado())
        {
            mostrarEspecialidades(especialidades[i]);
        }
    }

    delete[] especialidades;
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
    cout << "Ingrese el ID de la especialidad que desea editar: ";
    cin>>id;
    cin.ignore();

    cout<<"Ingrese el nombre de la especialidad : ";
    cin.getline(nombreEspecialidad, 50);

    int pos = ea.buscar(id);
    if(pos != -1)
    {
        especialidad = ea.Leer(pos);
        especialidad.setNombreEspecialidad(nombreEspecialidad);
        ea.guardar(pos,especialidad);
        cout<<"especialidad modificada " <<endl;
    }
    else
    {
        cout<<"No se encontro la especialidad "<<endl;
    }
}
void eliminarEspecialidad()
{
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    mostrarTodasEspecialidadesActivas();
    int codigo;
    cout<<"Ingrese el codigo a eliminar : ";
    cin>>codigo;
    int pos = ea.buscar(codigo);
    if(pos != -1)
    {
        especialidad = ea.Leer(pos);
        especialidad.setEliminado(true);
        ea.guardar(pos,especialidad);
        cout<<"especialidad eliminada " <<endl;
    }
    else
    {
        cout<<"No se encontro la especialidad "<<endl;
    }
}
void restaurarEspecialidad()
{
    Especialidad especialidad;
    EspecialidadesArchivo ea;
    int codigo;
    mostrarTodasEspeciaidadesEliminadas();
    cout<<"Ingrese el codigo de la especialidad a restaurar : ";
    cin>>codigo;
    int pos = ea.buscar(codigo);
    if(pos != -1)
    {
        especialidad = ea.Leer(pos);

        if(especialidad.getEliminado())
        {
            especialidad.setEliminado(false);
            ea.guardar(pos, especialidad);
            cout<<"Especialidad restaurada " <<endl;
        }
        else
        {
            cout<<"La especialidad ya se encuentra en el listado" <<endl;
        }

    }
    else
    {
        cout<<"Especialidad no encontrada " <<endl;
    }

}




