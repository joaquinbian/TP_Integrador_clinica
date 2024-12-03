#include <iostream>
#include <cstring>
#include "FuncionesPacientes.h"
#include "PacientesArchivo.h"
#include "funcionesGlobales.h"

Paciente cargarPaciente()
{
    char nombre[LONGITUD_NOMBRE], apellido[LONGITUD_APELLIDO], direccion[LONGITUD_DIRECCION], telefono[LONGITUD_TELEFONO], ciudad[LONGITUD_CIUDAD], email[LONGITUD_EMAIL];
    char obraSocial[LONGITUD_OBRASOCIAL], dni[LONGITUD_DNI];
    Fecha fechaNacimiento;
    bool inputValid = false, existeP;
    int dia, mes, anio;

    std::cout << "Ingrese los datos del paciente " << std::endl;
    std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
    std::cout << "------------------------------------" << std::endl;


    std::cin.ignore();
    do
    {
        std::cout << "Ingrese el DNI del paciente: ";
        std::cin.getline(dni, LONGITUD_DNI);
        inputValid = validateInputString(dni, LONGITUD_DNI);

        while(!inputValid){
            std::cout << "Ingrese el DNI del paciente: ";
            std::cin.getline(dni, LONGITUD_DNI);
            inputValid = validateInputString(dni, LONGITUD_DNI);
        }

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

    do{
        std::cout << "Ingrese el nombre: ";
        //std::cin.ignore();
        std::cin.getline(nombre, LONGITUD_NOMBRE);
        inputValid = validateInputString(nombre, LONGITUD_NOMBRE);

    }while(!inputValid);


    if(validateCancelValueString(nombre)){
        return Paciente();
    }
    do {
        std::cout << "Ingrese el apellido: ";
        std::cin.getline(apellido, LONGITUD_APELLIDO);
        inputValid = validateInputString(apellido, LONGITUD_APELLIDO);
    }while(!inputValid);



    if(validateCancelValueString(apellido)){
        return Paciente();
    }
    do{
        std::cout << "Ingrese el domicilio: ";
        std::cin.getline(direccion, LONGITUD_DIRECCION);
        inputValid = validateInputString(direccion, LONGITUD_DIRECCION);
    }while(!inputValid);


    if(validateCancelValueString(direccion)){
        return Paciente();
    }


    do{
        std::cout << "Ingrese la ciudad: ";
        std::cin.getline(ciudad, LONGITUD_CIUDAD);
        inputValid = validateInputString(ciudad, LONGITUD_CIUDAD);
    }while(!inputValid);


    if(validateCancelValueString(ciudad)){
        return Paciente();
    }


    do{
        std::cout << "Ingrese el telefono: ";
        std::cin.getline(telefono, LONGITUD_TELEFONO);
        inputValid = validateInputString(telefono, LONGITUD_TELEFONO);
    }while(!inputValid);

    if(validateCancelValueString(telefono)){
        return Paciente();
    }

    do{
        std::cout << "Ingrese el correo electronico: ";
        std::cin.getline(email, LONGITUD_EMAIL);
        inputValid = validateInputString(email, LONGITUD_EMAIL);
    }while(!inputValid);

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

        if(fechaNacimiento > obtenerFechaActual()){
            std::cout << std::endl;
            std::cout << "La fecha ingresada es posterior a la fecha actual, ingrese otra por favor " << std::endl;
            std::cout << std::endl;
        }

    } while(!fechaNacimiento.esValida || fechaNacimiento > obtenerFechaActual());



    std::cout << "Ingrese la obra social: ";
    std::cin.ignore();
    std::cin.getline(obraSocial, LONGITUD_OBRASOCIAL);
    inputValid = validateInputString(obraSocial, LONGITUD_OBRASOCIAL);
    while(!inputValid){
        std::cout << "Ingrese la obra social: ";
        std::cin.getline(obraSocial, LONGITUD_OBRASOCIAL);
        inputValid = validateInputString(obraSocial, LONGITUD_OBRASOCIAL);
    }

    if(validateCancelValueString(obraSocial)){
        return Paciente();
    }

    return Paciente( nombre,  apellido, telefono,  direccion,  ciudad,  email, fechaNacimiento,  obraSocial,  dni);
}
Paciente cargarPacienteAEditar(char* Dni)
{
    char nombre[LONGITUD_NOMBRE], apellido[LONGITUD_APELLIDO], direccion[LONGITUD_DIRECCION], telefono[LONGITUD_TELEFONO], ciudad[LONGITUD_CIUDAD], email[LONGITUD_EMAIL];
    char obraSocial[LONGITUD_OBRASOCIAL], dni[LONGITUD_DNI];
    Fecha fechaNacimiento;
    bool inputValid = false, existeP;
    int dia, mes, anio;

    std::cout << "Ingrese los datos del paciente " << std::endl;
    std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    do
    {

        do{
            std::cout << "Ingrese el DNI del paciente: ";
            //std::cin.ignore();
            std::cin.getline(dni, LONGITUD_DNI);
            inputValid = validateInputString(dni, LONGITUD_DNI);
        }while(!inputValid);

        existeP = existePaciente(dni) && strcmp(dni, Dni) != 0; //chequea si el paciente existe y si el dni es distinto al que se quiere editar
        if(existeP)
        {
            std::cout << "El paciente ya ha sido ingresado en el sistema " << std::endl;
        }
    }
    while(existeP);

    if(validateCancelValueString(dni)){
        return Paciente();
    }

    do{
        std::cout << "Ingrese el nombre: ";
        //std::cin.ignore();
        std::cin.getline(nombre, LONGITUD_NOMBRE);
        inputValid = validateInputString(nombre, LONGITUD_NOMBRE);
    }while(!inputValid);


    if(validateCancelValueString(nombre)){
        return Paciente();
    }

    do{
        std::cout << "Ingrese el apellido: ";
        std::cin.getline(apellido, LONGITUD_APELLIDO);
        inputValid = validateInputString(apellido, LONGITUD_APELLIDO);
    }while(!inputValid);

    if(validateCancelValueString(apellido)){
        return Paciente();
    }


    do{
        std::cout << "Ingrese el domicilio: ";
        std::cin.getline(direccion, LONGITUD_DIRECCION);
        inputValid = validateInputString(direccion, LONGITUD_DIRECCION);
    }while(!inputValid);

    if(validateCancelValueString(direccion)){
        return Paciente();
    }


    do{
        std::cout << "Ingrese la ciudad: ";
        std::cin.getline(ciudad, LONGITUD_CIUDAD);
        inputValid = validateInputString(ciudad, LONGITUD_CIUDAD);
    }while(!inputValid);

    if(validateCancelValueString(ciudad)){
        return Paciente();
    }

    do{
        std::cout << "Ingrese el telefono: ";
        std::cin.getline(telefono, LONGITUD_TELEFONO);
        inputValid = validateInputString(telefono, LONGITUD_TELEFONO);
    }while(!inputValid);

    if(validateCancelValueString(telefono)){
        return Paciente();
    }

    do{
        std::cout << "Ingrese el correo electronico: ";
        std::cin.getline(email, LONGITUD_EMAIL);
        inputValid = validateInputString(email, LONGITUD_EMAIL);
    }while(!inputValid);


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

         if(fechaNacimiento > obtenerFechaActual()){
            std::cout << std::endl;
            std::cout << "La fecha ingresada es posterior a la fecha actual, ingrese otra por favor " << std::endl;
            std::cout << std::endl;
        }

    } while(!fechaNacimiento.esValida || fechaNacimiento > obtenerFechaActual());



    std::cout << "Ingrese la obra social: ";
    std::cin.ignore();
    std::cin.getline(obraSocial, LONGITUD_OBRASOCIAL);
    inputValid = validateInputString(obraSocial, LONGITUD_OBRASOCIAL);
    while(!inputValid){
        std::cout << "Ingrese la obra social: ";
        std::cin.getline(obraSocial, LONGITUD_OBRASOCIAL);
        inputValid = validateInputString(obraSocial, LONGITUD_OBRASOCIAL);
    }

    if(validateCancelValueString(obraSocial)){
        return Paciente();
    }

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
    //std::cout<<"Prueba getEdad: " <<paciente.getEdad()<< " años" <<std::endl;
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
        if (estaPacienteActivo((char *)pacientes[i].getDni()))
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
        if(estaPacienteActivo((char *)pacientes[i].getDni()))
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
        if(!estaPacienteActivo((char *)pacientes[i].getDni()))
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
    char DNI[LONGITUD_DNI];
    PacientesArchivo pa;
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout << "Ingrese el DNI del paciente que quiere editar: ";
    std::cin.ignore();
    std::cin.getline(DNI, LONGITUD_DNI);

    while(!validateInputString(DNI, LONGITUD_DNI)){
        std::cout << "Ingrese el DNI del paciente que quiere editar: ";
        std::cin.getline(DNI, LONGITUD_DNI);
    }

    if(validateCancelValueString(DNI)){
        std::cout << "Edicion de paciente cancelada " << std::endl;
        return;
    }




    if(existePaciente(DNI) && estaPacienteActivo(DNI)){

        Paciente paciente;
        std::cout << std::endl;
        paciente = cargarPacienteAEditar(DNI);

        if(strlen(paciente.getDni()) == 0){
            std::cout << "Edicion de paciente cancelada " << std::endl;
            return;
        }

        int pos = pa.buscar(DNI);
        bool res = pa.guardar(pos, paciente);
        if(res)
        {
            std::cout << std::endl;
            std::cout << "El paciente ha sido editado correctamente" << std::endl << std::endl;
            return;
        }
        else
        {
            std::cout << std::endl <<"Ocurrio un error al editar el paciente" <<std::endl << std::endl;
            return;
        }
    }
    else
    {
        std::cout << std::endl <<"El paciente que quiere editar no ha sido encontrado." << std::endl<<std::endl;
        return;
    }
}
void eliminarPaciente()
{
    Paciente paciente;
    PacientesArchivo pa;

    mostrarTodosPacientesActivosResumidos();

    char dni[LONGITUD_DNI];
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout<<"Ingrese el DNI del paciente a eliminar : ";
    std::cin.ignore();
    std::cin.getline(dni, LONGITUD_DNI);
    while(!validateInputString(dni, LONGITUD_DNI)){
        std::cout << "Ingrese el DNI del paciente que quiere editar: ";
        std::cin.getline(dni, LONGITUD_DNI);
    }


    if(validateCancelValueString(dni)){
        std::cout << "Eliminacion de paciente cancelada" << std::endl;
        return;
    }



    if(existePaciente(dni) && estaPacienteActivo(dni)){
        int pos = pa.buscar(dni);
        if(pos != -1)
        {
            paciente = pa.Leer(pos);
            paciente.setEliminado(true);
            pa.guardar(pos,paciente);
            std::cout << std::endl <<"Paciente eliminado con exito" <<std::endl << std::endl;
        }
    }
    else
    {
        std::cout << std::endl << "El paciente que quiere eliminar no ha sido encotrado" << std::endl << std::endl;
    }
}
void restaurarPaciente()
{
    Paciente paciente;
    PacientesArchivo pa;

    mostrarTodosPacientesEliminados();
    char dni[LONGITUD_DNI];
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout<<"Ingrese el DNI del paciente a restaurar : ";
    std::cin.ignore();
    std::cin.getline(dni, LONGITUD_DNI);

    while(!validateInputString(dni, LONGITUD_DNI)){
        std::cout << "Ingrese el DNI del paciente que quiere editar: ";
        std::cin.getline(dni, LONGITUD_DNI);
    }


    if(validateCancelValueString(dni)){
        std::cout << "Restauracion de paciente cancelada" << std::endl;
        return;
    }

    if(existePaciente(dni) && !estaPacienteActivo(dni)){
        int pos = pa.buscar(dni);
        if(pos != -1)
        {
            paciente = pa.Leer(pos);
            paciente.setEliminado(false);
            pa.guardar(pos,paciente);
            std::cout << std::endl;
            std::cout<<"Paciente restaurado con exito" <<std::endl<<std::endl;
        }
    }
    else
    {
        std::cout<<std::endl<<"El paciente que quiere restaurar no fue encontrado"<<std::endl<<std::endl;
    }
}
void buscarPaciente()
{
    char DNI[LONGITUD_DNI];
    PacientesArchivo pa;
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout << "Ingrese el DNI del paciente que quiere buscar: ";
    std::cin.ignore();
    std::cin.getline(DNI, LONGITUD_DNI);

    while(!validateInputString(DNI, LONGITUD_DNI)){
        std::cout << "Ingrese el DNI del paciente que quiere editar: ";
        std::cin.getline(DNI, LONGITUD_DNI);
    }

    if(validateCancelValueString(DNI)){
        std::cout << "Busqueda de paciente cancelada" << std::endl;
        return;
    }

    if(existePaciente(DNI) && estaPacienteActivo(DNI)){

        int pos = pa.buscar(DNI);
        Paciente p = pa.Leer(pos);
        std::cout << std::endl;
        mostrarPaciente(p);

    } else {
        std::cout << std::endl << "El paciente no ha sido encontrado." << std::endl <<std::endl;
        return;
    }
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
        delete [] pacientes;
        return;
    }

    pa.leerTodos(pacientes, cantidad);
    char obraSocial[LONGITUD_OBRASOCIAL];
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout << "Ingrese la obra social del paciente que quiere buscar: ";
    std::cin.ignore();
    std::cin.getline(obraSocial, LONGITUD_OBRASOCIAL);

    while(!validateInputString(obraSocial, LONGITUD_OBRASOCIAL)){
        std::cout << "Ingrese la obra social del paciente que quiere buscar: ";
        std::cin.getline(obraSocial, LONGITUD_OBRASOCIAL);
    }

    if(validateCancelValueString(obraSocial)){
        delete [] pacientes;
        std::cout << "Busqueda de pacientes por obra social cancelada" << std::endl;
        return;
    }

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
