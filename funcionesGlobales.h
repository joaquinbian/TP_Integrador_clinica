#include <iostream>
#include "PacientesArchivo.h"
#include "Paciente.h"
#include "Profesional.h"
#include "ProfesionalesArchivo.h"

using namespace std;

Paciente cargarPaciente()
{
    char nombre[50], apellido[50], direccion[50], telefono[50], ciudad[50], email[50];
    int edad;
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

    cout<<"Ingrese la edad del paciente : ";
    cin>>edad;

    cout << "Ingrese el DNI del paciente: ";
    cin.ignore();
    cin.getline(dni, 20);

    cout << "Ingrese la obra social: ";
    cin.getline(obraSocial, 20);

    return Paciente( nombre,  apellido, telefono,  direccion,  ciudad,  email, fechaNacimiento,  edad,  obraSocial,  dni);
}
Profesional cargarProfesional()
{
    char nombre[50], apellido[50], direccion[50], telefono[50], ciudad[50], email[50], matricula[15], especialidad[50];
    float valorConsulta;
    bool soloParticular;

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
    //cin.ignore();
    cin.getline(especialidad, 50);

    cout << "Ingrese el numero de matricula: ";
    //cin.ignore();
    cin.getline(matricula, 50);

    cout << "Ingrese el valor de la consulta : $";
    cin>>valorConsulta;

    cout << "Atiende por Obras sociales y prepagas ? : ";
    cin>>soloParticular;

    return Profesional(nombre,  apellido, telefono,  direccion,  ciudad,  email, matricula, especialidad, valorConsulta, soloParticular);
}
void mostrarPaciente(Paciente paciente)
{
    cout<<"Nombre : " <<paciente.getNombre() <<endl;
    cout<<"Apellido : " <<paciente.getApellido() <<endl;
    cout<<"Domicilio : " <<paciente.getDireccion() <<endl;
    cout<<"Ciudad : " <<paciente.getCiudad() <<endl;
    cout<<"Telefono : " <<paciente.getTelefono() <<endl;
    cout<<"Email : " <<paciente.getEmail() <<endl;
    cout<<"Fecha de nacimiento : " << paciente.getFechaNacimiento().toString()<<endl;
    cout<<"Edad : " <<paciente.getEdad() <<endl;
    cout<<"DNI : " <<paciente.getDni() <<endl;
    cout<<"Obra Social : " <<paciente.getObraSocial() <<endl;
    cout<<"-----------------------------------------------"<<endl;
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
void guardarPaciente()
{
    Paciente paciente;
    PacientesArchivo pa;
    paciente = cargarPaciente();
    if(pa.Guardar(paciente))
    {
        cout<<"Paciente guardado exitosamente" <<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"No se pudo guardar el paciente " <<endl;
        system("pause");
        system("cls");
    }
}
void editarPaciente(){
    char DNI[20];
    PacientesArchivo pa;
    cout << "Ingrese el DNI del paciente que quiere editar: ";
    cin.ignore();
    cin.getline(DNI, 20);

    int pos = pa.buscar(DNI);
    if(pos == -1 ){
        cout << "El paciente que quiere editar no ha sido encontrado." << endl;
        return;
    }

    Paciente paciente;
    paciente = cargarPaciente();
    bool res = pa.guardar(pos, paciente);
    if(res){
        cout << "El paciente ha sido editado correctamente";
    } else {
        cout << "Ocurrio un error al editar el pacietne";
    }
}

void guardarProfesional()
{
    Profesional profesional;
    ProfesionalesArchivo pa;
    profesional = cargarProfesional();
    if(pa.Guardar(profesional))
    {
        cout<<"Profesional guardado exitosamente" <<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"No se pudo guardar el profesional " <<endl;
        system("pause");
        system("cls");
    }
}
void mostrarTodosPacientes()
{
    Paciente *pacientes;
    PacientesArchivo pa;
    int cantidad = pa.getCantidad();
    pacientes = new Paciente [cantidad];
    pa.leerTodos(pacientes, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        mostrarPaciente(pacientes[i]);
    }
    delete [] pacientes;
}
void mostrarTodosProfesionales()
{
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidad = pa.getCantidad();
    profesionales = new Profesional [cantidad];
    pa.leerTodos(profesionales, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        mostrarProfesional(profesionales[i]);
    }
    delete [] profesionales;
}
