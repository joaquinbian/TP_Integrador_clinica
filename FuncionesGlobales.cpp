#include "funcionesGlobales.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <limits>

//FUNCIONES GENERALES USADAS EN TODA LA APP

bool sonStringsIguales(char* str1, char* str2){
    return strcmp(str1, str2) == 0;
}
char* trim(char* s)
{
    int len = strlen(s);
    char* d = new char[len + 1];
    if(d == NULL){
        std::cout << "No se pudo reservar memoria para validar el string" << std::endl;
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < len; i++) {
        if (!(isspace(s[i]))) {
            d[count] = s[i];
            count++;
        }
    }

    d[count] = '\0';

    return d;
}
bool estaStringVacio(char *str)
{
   char *sinEspacios = trim(str);
    bool isEmpty = strlen(sinEspacios) == 0;

    delete[] sinEspacios;

    return isEmpty;
}
void pedirStringBucle(char* variable, std::string mensaje, int longitud)
{
    do {
        std::cout << mensaje;
        std::cin.getline(variable, longitud);

    }while(estaStringVacio(variable) || !validateInputString(variable, longitud));

}
bool validarInput()
{
    bool valid = true;
    if(std::cin.fail()){
        valid = false;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return valid;
}
bool validateInputInt()
{
    bool valid = true;

    valid = validarInput();

    if(!valid){
        std::cout << "Ocurrio un error. Ingrese un numero valido" << std::endl;
        return valid;
    }


    return valid;
}
bool validateInputString(char* str, int longitud)
{
    bool valid = true;
    valid = validarInput();

    if(!valid){
        std::cout << "Ocurrio un error. El campo no puede tener mas de " << longitud - 1 << " caracteres. Intente nuevamente" << std::endl;
        return valid;
    }

    if(estaStringVacio(str)){
        std::cout << "El campo no puede estar vacio" << std::endl;
        valid = false;
        return valid;
    }

    return valid;
}
bool validateCancelValueString(std::string str)
{
    return strcmp(str.c_str(), "0") == 0;
}
bool validateCancelValueChar(char c)
{
    return c == '0';
}
bool validateCancelValueInt(int n)
{
    return n == 0;
}
bool validateCancelValueFloat(float num)
{
    return num == 0.0;
}
bool validateCancelValueFecha(Fecha fecha)
{
    return fecha.validar();
}
int pedirIntValido(std::string msj)
{
    int num;
    do {
        std::cout << msj;
        std::cin >> num;
    }while(!validateInputInt());

    return num;
}
int pedirDiaFechaCancelable()
{
    int dia;
    do {
        do {
            std::cout << "Ingrese el dia (1-31) (0 para cancelar): ";
            std::cin >> dia;
        }while(!validateInputInt());
        if(dia < 0 || dia > 31){
            std::cout << "Dia invalido" << std::endl;
        }
    }while(dia < 0 || dia > 31);

    return dia;
}
int pedirMesFechaCancelable()
{
    int mes;
    do {
        do{
            std::cout << "Ingrese el mes (1-12) (0 para cancelar): ";
            std::cin >> mes;
        }while(!validateInputInt());
        if(mes < 0 || mes > 12){
            std::cout << "Mes invalido" << std::endl;
        }
    }while(mes < 0 || mes > 12);

    return mes;
}
int pedirAnioFechaCancelable()
{
    int anio;
    do {
        do{
            std::cout << "Ingrese el anio (0 para cancelar): ";
            std::cin >> anio;
        }while(!validateInputInt());

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
bool estaPacienteActivo(char *dni)
{
    PacientesArchivo pa;

    int pos = pa.buscar(dni);

    if(pos >= 0){
        Paciente paciente = pa.Leer(pos);
        return !paciente.getEliminado();
    }
    return false;
}
bool estaProfesionalActivo(char *matricula)
{
    ProfesionalesArchivo pa;

    int pos = pa.buscar(matricula);

    if(pos >= 0){
        Profesional profesional = pa.Leer(pos);
        return !profesional.getEliminado();
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
bool existeEspecialidadActiva(int Id)
{
    Especialidad *especialidades = nullptr;
    EspecialidadesArchivo ea;
    int cantidad = ea.getCantidad();
    especialidades = new Especialidad[cantidad];
    ea.leerTodos(especialidades, cantidad);

    if(especialidades == NULL){
        std::cout << "No se pudo leer las especialidades" << std::endl;
        return false;
    }
    for(int i = 0; i < cantidad; i++){
        if(especialidades[i].getId() == Id && especialidades[i].getEliminado() == false){
            delete [] especialidades;
            return true;
        }
    }

    delete [] especialidades;

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
    std::cout<<"Atiende obras sociales y prepagas : " <<profesional.getSoloParticular() << " (1 - Si / 0 - No) " <<std::endl;
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
Fecha obtenerFechaActual()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int dia = ltm->tm_mday;
    int mes = 1 + ltm->tm_mon; //meses del 1 al 11
    int anio = 1900 + ltm->tm_year; // +1900 porque empieza a contar desde 1900

    return Fecha(dia, mes, anio);
}
