#include <iostream>
#include <cstring>
#include "PacientesArchivo.h"
#include "Paciente.h"
#include "Profesional.h"
#include "ProfesionalesArchivo.h"
#include "Especialidad.h"
#include "EspecialidadesArchivo.h"
#include "Turno.h"
#include "TurnosArchivo.h"

using namespace std;
void mostrarTodasEspecialidadesActivas();
Especialidad buscarEspecialidad(int id);
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

bool existePaciente(char* dni){
    PacientesArchivo pa;

    int pos = pa.buscar(dni);

    if(pos >= 0){
        return true;
    }
    return false;
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
    char nombre[50], apellido[50], direccion[50], telefono[50], ciudad[50], email[50], matricula[50], soloParticularChar;
    float valorConsulta;
    int especialidad;
    bool soloParticular = false;


    cout << "Ingrese el nombre: ";
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

    cout << "Especialidades: " << endl;
    mostrarTodasEspecialidadesActivas();
    cout << "Ingrese el codigo de la especialidad ";
    cin >> especialidad;

    cout << "Ingrese el numero de matricula: ";
    cin.ignore();
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
    cout<<"Especialidad : " << buscarEspecialidad(profesional.getEspecialidad()).getNombreEspecialidad() <<endl;
    cout<<"Valor de la consulta : $" <<profesional.getValorConsulta() <<endl;
    cout<<"Atiende obras sociales y prepagas : " <<profesional.getSoloParticular() <<endl;
    cout<<"-----------------------------------------------"<<endl;
}
void mostrarProfesionalResumido(Profesional profesional)
{
    cout<<"Nombre : " <<profesional.getNombre() <<endl;
    cout<<"Apellido : " <<profesional.getApellido() <<endl;
    cout<<"Matricula : " <<profesional.getMatricula() <<endl;
    cout<<"Especialidad : " << buscarEspecialidad(profesional.getEspecialidad()).getNombreEspecialidad() <<endl;
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
    char matricula[50];
    ProfesionalesArchivo pa;
    mostrarTodosProfesionalesActivos();
    cout <<endl<< "Ingrese la matricula del profesional que quiere editar: ";
    cin.ignore();
    cin.getline(matricula, 50);

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
        return;
    }
    else
    {
        cout <<endl<< "Ocurrio un error al editar el profesional"<<endl;
        return;
    }
}
void eliminarProfesional()
{
    Profesional profesional;
    ProfesionalesArchivo pa;

    mostrarTodosProfesionalesActivosResumido();

    char matricula[50];
    cout<<endl<<"Ingrese la matricula del profesional a eliminar : ";
    cin.ignore();
    cin.getline(matricula, 50);

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

    char matricula[50];
    cout<<endl<<"Ingrese la matricula del profesional a eliminar : ";
    cin.ignore();
    cin.getline(matricula, 50);

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
    char matricula[50];
    ProfesionalesArchivo pa;
    cout << "Ingrese la matricula del profesional que quiere buscar: ";
    cin.ignore();
    cin.getline(matricula, 50);

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
    system("cls");
    mostrarTodasEspecialidadesActivas();
    int especialidad;
    cout << "Ingrese la especialidad del profesional que quiere buscar: ";
    cin >> especialidad;

    for(int i = 0; i < cantidad; i++){
        if(profesional[i].getEspecialidad() == especialidad){
            encontrado  = true;
            cout << endl;
            mostrarProfesional(profesional[i]);
        }
    }

    if(!encontrado){
        cout << "NO se encontro ningun profesional con esa especialidad" << endl;
    }

    delete [] profesional;
}

void buscarProfesionalesPorEspecialidad(int idEspecialidad){
    Profesional *profesional;
    ProfesionalesArchivo pa;
    int cantidad = pa.getCantidad();
    profesional = new Profesional[cantidad];

    bool encontrado = false;

    if(profesional == NULL){
        cout << "No se pudo leer los profesionales" << endl;
    }

    pa.leerTodos(profesional, cantidad);

    for(int i = 0; i < cantidad; i++){
        if(profesional[i].getEspecialidad() == idEspecialidad){
            encontrado  = true;
            cout << endl;
            mostrarProfesional(profesional[i]);
        }
    }

    if(!encontrado){
        cout << "NO se encontro ningun profesional con esa especialidad" << endl;
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
void mostrarEspecialidades(Especialidad especialidad){
    cout<<especialidad.getId()<< " - " <<especialidad.getNombreEspecialidad() <<endl;
    cout<<"-----------------------------------------------"<<endl;
}

void mostrarTodasEspecialidadesActivas(){
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

Especialidad buscarEspecialidad(int id){
    EspecialidadesArchivo espFile;

    return espFile.buscarEspecalidad(id);
}

///TURNOS
Turno cargarTurno(){

    Fecha fechaTurno;
    char dniPaciente[50], matricula[50];
    int horaTurno, especialidad;
    bool existeP;

    cout << "Ingrese la fecha del turno: " << endl;
    cin >> fechaTurno;

    do {
        cout << "Ingrese la hora del turno (8-20 hs): ";
        cin >> horaTurno;
    }while(horaTurno < 8 || horaTurno > 20);

    mostrarTodasEspecialidadesActivas();
    cout << "Ingrese el codigo de la especialidad ";
    cin >> especialidad;

    do {

        cout << "Ingrese el DNI del paciente: ";
        cin >> dniPaciente;
        existeP = existePaciente(dniPaciente);
        if(!existeP){
            cout << "No encontramos un paciente con ese DNI " << endl;
        }
    }while(!existeP);

    cout << "Profesionales de " << buscarEspecialidad(especialidad).getNombreEspecialidad() << endl;
    buscarProfesionalesPorEspecialidad(especialidad);
    cout << "Ingrese la matricula del profesional: ";
    cin >> matricula;

    return Turno(fechaTurno, horaTurno, especialidad, dniPaciente, matricula);
}

void buscarTurno(){
    char DNI[20];
    TurnosArchivo ta;
    cout << "Ingrese DNI del paciente para buscar turno: ";
    cin.ignore();
    cin.getline(DNI, 20);

    int pos = ta.buscar(DNI);
    if(pos == -1 ){
        cout << "El turno no ha sido encontrado." << endl;
        return;
    }
    Turno t = ta.Leer(pos);
    t.mostrar();
}

void guardarTurno()
{
    Turno turno;
    TurnosArchivo ta;
    turno = cargarTurno();

    if(ta.Guardar(turno))
    {
        cout<<"Turno guardado exitosamente" <<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"No se pudo guardar el turno " <<endl;
        system("pause");
        system("cls");
    }
}

void editarTurno(){
    char DNI[20];
    TurnosArchivo ta;
    cout << "DNI del paciente para editar turno: ";
    cin.ignore();
    cin.getline(DNI, 20);

    int pos = ta.buscar(DNI);
    if(pos == -1 ){
        cout << "El turno que quiere editar no ha sido encontrado." << endl;
        return;
    }

    Turno turno;
    turno = cargarTurno();
    bool res = ta.guardar(pos, turno);
    if(res){
        cout << "El turno ha sido editado correctamente";
    } else {
        cout << "Ocurrio un error al editar el turno";
    }
}

void mostrarTodosTurnosActivos()
{
    Turno *turnos;
    TurnosArchivo ta;
    int cantidad = ta.getCantidad();
    turnos = new Turno [cantidad];
    ta.leerTodos(turnos, cantidad);


    ///Inicio ordenamiento por fecha ascendente
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - 1; j++) {
            Fecha fecha1 = turnos[j].getFecha();
            Fecha fecha2 = turnos[j + 1].getFecha();
            if (fecha1.getAnio() > fecha2.getAnio() ||
                (fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() > fecha2.getMes()) ||
                (fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() == fecha2.getMes() && fecha1.getDia() > fecha2.getDia()))
            {
                Turno aux = turnos[j];
                turnos[j] = turnos[j + 1];
                turnos[j + 1] = aux;
            }
        }
    }
    ///Final ordenamiento por fecha ascendente

    for(int k = 0; k < cantidad; k++)
    {
        
        if(turnos[k].getEliminado() == false)
        
        {
            cout<<"------------------------ "<< "TURNO " << k + 1 << " -----------------------"<<endl;
            turnos[k].mostrar();


        }
    }
    delete [] turnos;
}

void eliminarTurno()
{
    Turno turno;
    TurnosArchivo ta;

    mostrarTodosTurnosActivos();
    char dni[20];
    cout<<endl<<"Ingrese DNI/paciente del turno a eliminar : ";
    cin.ignore();
    cin.getline(dni, 20);

    int pos = ta.buscar(dni);
    if(pos != -1)
    {
        turno = ta.Leer(pos);
        turno.setEliminado(true);
        ta.guardar(pos,turno);
        cout << endl <<"Turno eliminado con exito" <<endl << endl;
    }
    else
    {
        cout << endl << "No se pudo eliminar el turno" << endl << endl;
    }
}

