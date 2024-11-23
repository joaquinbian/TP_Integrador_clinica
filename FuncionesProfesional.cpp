#include <iostream>
#include "FuncionesProfesional.h"
#include "funcionesGlobales.h"

Profesional cargarProfesional()
{
    char nombre[LONGITUD_NOMBRE], apellido[LONGITUD_APELLIDO], direccion[LONGITUD_DIRECCION], telefono[LONGITUD_TELEFONO], ciudad[LONGITUD_CIUDAD], email[LONGITUD_EMAIL], matricula[LONGITUD_MATRICULA], soloParticularChar;
    float valorConsulta;
    int especialidad;
    bool soloParticular = false, existeProf;
    std::cout << "Ingrese los datos del profesional " << std::endl;
    std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    do
    {
        std::cout << "Ingrese el numero de matricula: ";
        std::cin.ignore();
        std::cin.getline(matricula, LONGITUD_MATRICULA);

        while (estaStringVacio(matricula))
        {
            pedirStringBucle(matricula, "La matricula no puede estar vacia, ingrese nuevamente: ", LONGITUD_MATRICULA);
        }

        existeProf = existeProfesional(matricula);
        if (existeProf)
        {
            std::cout << "Ya existe un profesional con esta matricula, ingrese otra." << std::endl;
        }
    }
    while (existeProf);

    if(validateCancelValueString(matricula)){
        return Profesional();
    }

    std::cout << "Ingrese el apellido: ";
    std::cin.getline(apellido, LONGITUD_APELLIDO);

    while(estaStringVacio(apellido)){
        pedirStringBucle(apellido, "El apellido no puede estar vacio, ingrese nuevamente: ", LONGITUD_APELLIDO);
    }

    if(validateCancelValueString(apellido)){
        return Profesional();
    }

    std::cout << "Ingrese el nombre: ";
    //std::cin.ignore();
    std::cin.getline(nombre, LONGITUD_NOMBRE);

    while(estaStringVacio(nombre)){
        pedirStringBucle(nombre, "El nombre no puede estar vacio, ingrese nuevamente: ", LONGITUD_NOMBRE);
    }

    if(validateCancelValueString(nombre)){
        return Profesional();
    }

    std::cout << "Ingrese el domicilio: ";
    std::cin.getline(direccion, LONGITUD_DIRECCION);

    while(estaStringVacio(direccion)){
        pedirStringBucle(direccion, "El domicilio no puede estar vacio, ingrese nuevamente: ", LONGITUD_DIRECCION);
    }

    if(validateCancelValueString(direccion)){
        return Profesional();
    }

    std::cout << "Ingrese la ciudad: ";
    std::cin.getline(ciudad, LONGITUD_CIUDAD);

    while(estaStringVacio(ciudad)){
        pedirStringBucle(ciudad, "La ciudad no puede estar vacia, ingrese nuevamente: ", LONGITUD_CIUDAD);
    }

    if(validateCancelValueString(ciudad)){
        return Profesional();
    }


    std::cout << "Ingrese el telefono: ";
    std::cin.getline(telefono, LONGITUD_TELEFONO);

    while(estaStringVacio(telefono)){
        pedirStringBucle(telefono, "El telefono no puede estar vacio, ingrese nuevamente: ", LONGITUD_TELEFONO);
    }

    if(validateCancelValueString(telefono)){
        return Profesional();
    }

    std::cout << "Ingrese el correo electronico: ";
    std::cin.getline(email, LONGITUD_EMAIL);

    while(estaStringVacio(email)){
        pedirStringBucle(email, "El email no puede estar vacio, ingrese nuevamente: ", LONGITUD_EMAIL);
    }

    if(validateCancelValueString(email)){
        return Profesional();
    }

    std::cout << "Especialidades: " << std::endl;
    mostrarTodasEspecialidadesActivas();
    std::cout << "Ingrese el codigo de la especialidad ";
    std::cin >> especialidad;

    if(validateCancelValueInt(especialidad)){
        return Profesional();
    }

    std::cout << "Ingrese el valor de la consulta: $";
    std::cin >> valorConsulta;

    if(validateCancelValueFloat(valorConsulta)){
        return Profesional();
    }

    std::cout << "Atiende solo particulares? (s/n): ";

    std::cin >> soloParticularChar;

    while(soloParticularChar != 's' && soloParticularChar != 'S' && soloParticularChar != 'n' && soloParticularChar != 'N'){
        std::cout << "Ingrese una opcion valida (s/n): ";
        std::cin >> soloParticularChar;
    }

    if(validateCancelValueChar(soloParticularChar)){
        return Profesional();
    }

    // Actualiza `soloParticular` basado en la respuesta
    if (soloParticularChar == 's' || soloParticularChar == 'S')
    {
        soloParticular = true;
    }

    return Profesional(nombre, apellido, telefono, direccion, ciudad, email, matricula, especialidad, valorConsulta, soloParticular);
}


Profesional cargarProfesionalAEditar(char *matriculaAEditar)
{
    char nombre[LONGITUD_NOMBRE], apellido[LONGITUD_APELLIDO], direccion[LONGITUD_DIRECCION], telefono[LONGITUD_TELEFONO], ciudad[LONGITUD_CIUDAD], email[LONGITUD_EMAIL], matricula[LONGITUD_MATRICULA], soloParticularChar;
    float valorConsulta;
    int especialidad;
    bool soloParticular = false, existeProf;
    std::cout << "Ingrese los datos del profesional " << std::endl;
    std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    do
    {
        std::cout << "Ingrese el numero de matricula: ";
        //std::cin.ignore();
        std::cin.getline(matricula, LONGITUD_MATRICULA);

        while (estaStringVacio(matricula))
        {
            pedirStringBucle(matricula, "La matricula no puede estar vacia, ingrese nuevamente: ", LONGITUD_MATRICULA);
        }

        existeProf = existeProfesional(matricula) && strcmp(matricula, matriculaAEditar) != 0;
        if (existeProf)
        {
            std::cout << "Ya existe un profesional con esta matricula, ingrese otra." << std::endl;
        }
    }
    while (existeProf);

    if(validateCancelValueString(matricula)){
        return Profesional();
    }

    std::cout << "Ingrese el apellido: ";
    std::cin.getline(apellido, LONGITUD_APELLIDO);

    while(estaStringVacio(apellido)){
        pedirStringBucle(apellido, "El apellido no puede estar vacio, ingrese nuevamente: ", LONGITUD_APELLIDO);
    }

    if(validateCancelValueString(apellido)){
        return Profesional();
    }

    std::cout << "Ingrese el nombre: ";
    //std::cin.ignore();
    std::cin.getline(nombre, LONGITUD_NOMBRE);

    while(estaStringVacio(nombre)){
        pedirStringBucle(nombre, "El nombre no puede estar vacio, ingrese nuevamente: ", LONGITUD_NOMBRE);
    }
    

    if(validateCancelValueString(nombre)){
        return Profesional();
    }

    std::cout << "Ingrese el domicilio: ";
    std::cin.getline(direccion, LONGITUD_DIRECCION);

    while(estaStringVacio(direccion)){
        pedirStringBucle(direccion, "El domicilio no puede estar vacio, ingrese nuevamente: ", LONGITUD_DIRECCION);
    }

    if(validateCancelValueString(direccion)){
        return Profesional();
    }

    std::cout << "Ingrese la ciudad: ";
    std::cin.getline(ciudad, LONGITUD_CIUDAD);

    while(estaStringVacio(ciudad)){
        pedirStringBucle(ciudad, "La ciudad no puede estar vacia, ingrese nuevamente: ", LONGITUD_CIUDAD);
    }

    if(validateCancelValueString(ciudad)){
        return Profesional();
    }


    std::cout << "Ingrese el telefono: ";
    std::cin.getline(telefono, LONGITUD_TELEFONO);

    while(estaStringVacio(telefono)){
        pedirStringBucle(telefono, "El telefono no puede estar vacio, ingrese nuevamente: ", LONGITUD_TELEFONO);
    }

    if(validateCancelValueString(telefono)){
        return Profesional();
    }

    std::cout << "Ingrese el correo electronico: ";
    std::cin.getline(email, LONGITUD_EMAIL);

    while(estaStringVacio(email)){
        pedirStringBucle(email, "El email no puede estar vacio, ingrese nuevamente: ", LONGITUD_EMAIL);
    }

    if(validateCancelValueString(email)){
        return Profesional();
    }

    std::cout << "Especialidades: " << std::endl;
    mostrarTodasEspecialidadesActivas();
    std::cout << "Ingrese el codigo de la especialidad ";
    std::cin >> especialidad;

    if(validateCancelValueInt(especialidad)){
        return Profesional();
    }

    std::cout << "Ingrese el valor de la consulta: $";
    std::cin >> valorConsulta;

    if(validateCancelValueFloat(valorConsulta)){
        return Profesional();
    }

    std::cout << "Atiende solo particulares? (s/n): ";
    std::cin >> soloParticularChar;

    while(soloParticularChar != 's' && soloParticularChar != 'S' && soloParticularChar != 'n' && soloParticularChar != 'N'){
        std::cout << "Ingrese una opcion valida (s/n): ";
        std::cin >> soloParticularChar;
    }

    if(validateCancelValueChar(soloParticularChar)){
        return Profesional();
    }

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


    if(estaStringVacio(profesional.getMatricula())){
        std::cout << "Carga de profesional cancelada " << std::endl;
        return;

    }


    if(pa.Guardar(profesional))
    {
        std::cout<<std::endl<<"Profesional guardado exitosamente" <<std::endl<<std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        std::cout<<std::endl<<"No se pudo guardar el profesional " <<std::endl<<std::endl;
        system("pause");
        system("cls");
    }
}




void mostrarProfesionalResumido(Profesional profesional)
{
    std::cout<<"Nombre : " <<profesional.getNombre() <<std::endl;
    std::cout<<"Apellido : " <<profesional.getApellido() <<std::endl;
    std::cout<<"Matricula : " <<profesional.getMatricula() <<std::endl;
    std::cout<<"Especialidad : " << buscarEspecialidad(profesional.getEspecialidad()).getNombreEspecialidad() <<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
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
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout <<"Ingrese la matricula del profesional que quiere editar: ";
    std::cin.ignore();
    std::cin.getline(matricula, LONGITUD_MATRICULA);

    while(estaStringVacio(matricula)){
        pedirStringBucle(matricula, "La matricula no puede estar vacia, ingrese nuevamente: ", LONGITUD_MATRICULA);
    }
    

    if(validateCancelValueString(matricula)){
        return;
    }

    int pos = pa.buscar(matricula);
    if(pos == -1 )
    {
        std::cout << std::endl <<"El profesional que quiere editar no ha sido encontrado." <<std::endl<< std::endl;
        return;
    }

    Profesional profesional;
    profesional = cargarProfesionalAEditar(matricula);

    if(strlen(profesional.getMatricula()) == 0){
        std::cout << "Edicion de profesional cancelada " << std::endl;
        return; 
    }
    bool res = pa.guardar(pos, profesional);
    if(res)
    {
        std::cout <<std::endl<< "El profesional ha sido editado correctamente"<<std::endl;
        return;
    }
    else
    {
        std::cout <<std::endl<< "Ocurrio un error al editar el profesional"<<std::endl;
        return;
    }
}

void eliminarProfesional()
{
    Profesional profesional;
    ProfesionalesArchivo pa;

    mostrarTodosProfesionalesActivosResumido();

    char matricula[50];
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout<<"Ingrese la matricula del profesional a eliminar : ";
    std::cin.ignore();
    std::cin.getline(matricula, 50);

    if(validateCancelValueString(matricula)){
        return;
    }

    int pos = pa.buscar(matricula);
    if(pos != -1)
    {
        profesional = pa.Leer(pos);
        profesional.setEliminado(true);
        pa.guardar(pos,profesional);
        std::cout<<std::endl<<"profesional eliminado " <<std::endl<<std::endl;
    }
    else
    {
        std::cout<<std::endl<<"No se encontro el profesional "<<std::endl<<std::endl;
    }
}


void restaurarProfesional()
{
    Profesional profesional;
    ProfesionalesArchivo pa;

    mostrarTodosProfesionalesEliminados();

    char matricula[50];
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout<<"Ingrese la matricula del profesional a restaurar : ";
    std::cin.ignore();
    std::cin.getline(matricula, 50);

    if(validateCancelValueString(matricula)){
        return;
    }

    int pos = pa.buscar(matricula);
    if(pos != -1)
    {
        profesional = pa.Leer(pos);
        profesional.setEliminado(false);
        pa.guardar(pos,profesional);
        std::cout<<std::endl<<"Profesional restaurado con exito" <<std::endl<<std::endl;
    }
    else
    {
        std::cout<<std::endl<<"No se encontro el profesional "<<std::endl<<std::endl;
    }
}

void buscarProfesional()
{
    char matricula[50];
    ProfesionalesArchivo pa;
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout << "Ingrese la matricula del profesional que quiere buscar: ";
    std::cin.ignore();
    std::cin.getline(matricula, 50);

    if(validateCancelValueString(matricula)){
        return;
    }

    int pos = pa.buscar(matricula);
    if(pos == -1 )
    {
        std::cout << "El profesional no ha sido encontrado." << std::endl;
        return;
    }
    Profesional p = pa.Leer(pos);
    std::cout << std::endl;
    mostrarProfesional(p);
}

bool existeProfesional(char *matricula)
{
    ProfesionalesArchivo pa;
    int pos = pa.buscar(matricula);
    if(pos == -1 )
    {
        return false;
    }
    return true;
}
void buscarProfesionalPorEspecialidad()
{
    Profesional *profesional;
    ProfesionalesArchivo pa;
    int cantidad = pa.getCantidad();
    profesional = new Profesional[cantidad];

    bool encontrado = false;

    if(profesional == NULL)
    {
        std::cout << "No se pudo leer los profesionales" << std::endl;
    }

    pa.leerTodos(profesional, cantidad);
    system("cls");
    mostrarTodasEspecialidadesActivas();
    int especialidad;
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout << "Ingrese la especialidad del profesional que quiere buscar: ";
    std::cin >> especialidad;

    if(validateCancelValueInt(especialidad)){
        return;
    }

    for(int i = 0; i < cantidad; i++)
    {
        if(profesional[i].getEspecialidad() == especialidad)
        {
            encontrado  = true;
            std::cout << std::endl;
            mostrarProfesional(profesional[i]);
        }
    }

    if(!encontrado)
    {
        std::cout << "NO se encontro ningun profesional con esa especialidad" << std::endl;
    }

    delete [] profesional;
}
