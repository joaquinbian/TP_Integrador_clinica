#include <iostream>
#include "FuncionesProfesional.h"
#include "funcionesGlobales.h"

Profesional cargarProfesional()
{
    char nombre[LONGITUD_NOMBRE], apellido[LONGITUD_APELLIDO], direccion[LONGITUD_DIRECCION], telefono[LONGITUD_TELEFONO], ciudad[LONGITUD_CIUDAD], email[LONGITUD_EMAIL], matricula[LONGITUD_MATRICULA], soloParticularChar;
    float valorConsulta;
    int especialidad;
    bool inputValid, soloParticular, existeProf, existeEsp = false;
    std::cout << "Ingrese los datos del profesional " << std::endl;
    std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    do
    {
        std::cout << "Ingrese el numero de matricula: ";
        std::cin.ignore();
        std::cin.getline(matricula, LONGITUD_MATRICULA);
        inputValid = validateInputString(matricula, LONGITUD_MATRICULA);
        while(!inputValid)
        {
            std::cout << "Ingrese el numero de matricula: ";
            std::cin.getline(matricula, LONGITUD_MATRICULA);
            inputValid = validateInputString(matricula, LONGITUD_MATRICULA);
        }

        existeProf = existeProfesional(matricula);
        if (existeProf)
        {
            std::cout << "Ya existe un profesional con esta matricula, ingrese otra." << std::endl;
        }
    }
    while (existeProf);

    if(validateCancelValueString(matricula))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese el apellido: ";
        std::cin.getline(apellido, LONGITUD_APELLIDO);
        inputValid = validateInputString(apellido, LONGITUD_APELLIDO);
    }
    while(!inputValid);

    if(validateCancelValueString(apellido))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese el nombre: ";
        //std::cin.ignore();
        std::cin.getline(nombre, LONGITUD_NOMBRE);
        inputValid = validateInputString(nombre, LONGITUD_NOMBRE);
    }
    while(!inputValid);

    if(validateCancelValueString(nombre))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese el domicilio: ";
        std::cin.getline(direccion, LONGITUD_DIRECCION);
        inputValid = validateInputString(direccion, LONGITUD_DIRECCION);
    }
    while(!inputValid);

    if(validateCancelValueString(direccion))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese la ciudad: ";
        std::cin.getline(ciudad, LONGITUD_CIUDAD);
        inputValid = validateInputString(ciudad, LONGITUD_CIUDAD);
    }
    while(!inputValid);

    if(validateCancelValueString(ciudad))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese el telefono: ";
        std::cin.getline(telefono, LONGITUD_TELEFONO);
        inputValid = validateInputString(telefono, LONGITUD_TELEFONO);
    }
    while(!inputValid);

    if(validateCancelValueString(telefono))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese el correo electronico: ";
        std::cin.getline(email, LONGITUD_EMAIL);
        inputValid = validateInputString(email, LONGITUD_EMAIL);
    }
    while(!inputValid);

    if(validateCancelValueString(email))
    {
        return Profesional();
    }

    std::cout << "\n";
    std::cout << "Especialidades: " << std::endl;
    std::cout << "\n";

    mostrarTodasEspecialidadesActivas();
    do
    {
        std::cout << "Ingrese el codigo de la especialidad ";
        std::cin >> especialidad;
        existeEsp = existeEspecialidadActiva(especialidad) || validateCancelValueInt(especialidad); //si ingresa 0, dejamos que avance para que cancele
        if(!existeEsp)
        {
            std::cout << "No se encontro la especialidad" << std::endl;
        }

    }
    while(!validateInputInt() || !existeEsp);

    if(validateCancelValueInt(especialidad))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese el valor de la consulta: $";
        std::cin >> valorConsulta;
        if(valorConsulta < 0 )
        {
            std::cout<<"El valor de la consulta no puede ser 0 " ;
            std::cout<<"\n";
        }
    }
    while(!validateInputInt()|| valorConsulta <= 0);

    if(validateCancelValueFloat(valorConsulta))
    {
        return Profesional();
    }

    std::cout << "Atiende solo particulares? (s/n): ";

    std::cin >> soloParticularChar;

    while(soloParticularChar != 's' && soloParticularChar != 'S' && soloParticularChar != 'n' && soloParticularChar != 'N')
    {
        std::cout << "Ingrese una opcion valida (s/n): ";
        std::cin >> soloParticularChar;
    }

    if(validateCancelValueChar(soloParticularChar))
    {
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
    bool inputValid, soloParticular, existeProf, existeEsp = false;
    std::cout << "Ingrese los datos del profesional " << std::endl;
    std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    do
    {
        do
        {
            std::cout << "Ingrese el numero de matricula: ";
            //std::cin.ignore();
            std::cin.getline(matricula, LONGITUD_MATRICULA);
            inputValid = validateInputString(matricula, LONGITUD_MATRICULA);
        }
        while(!inputValid);


        existeProf = existeProfesional(matricula) && strcmp(matricula, matriculaAEditar) != 0;
        if (existeProf)
        {
            std::cout << "Ya existe un profesional con esta matricula, ingrese otra." << std::endl;
        }
    }
    while (existeProf);

    if(validateCancelValueString(matricula))
    {
        return Profesional();
    }



    do
    {
        std::cout << "Ingrese el apellido: ";
        std::cin.getline(apellido, LONGITUD_APELLIDO);
        inputValid = validateInputString(apellido, LONGITUD_APELLIDO);
    }
    while(!inputValid);


    if(validateCancelValueString(apellido))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese el nombre: ";
        //std::cin.ignore();
        std::cin.getline(nombre, LONGITUD_NOMBRE);
        inputValid = validateInputString(nombre, LONGITUD_NOMBRE);
    }
    while(!inputValid);

    if(validateCancelValueString(nombre))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese el domicilio: ";
        std::cin.getline(direccion, LONGITUD_DIRECCION);
        inputValid = validateInputString(direccion, LONGITUD_DIRECCION);
    }
    while(!inputValid);

    if(validateCancelValueString(direccion))
    {
        return Profesional();
    }

    do
    {
        std::cout << "Ingrese la ciudad: ";
        std::cin.getline(ciudad, LONGITUD_CIUDAD);
        inputValid = validateInputString(ciudad, LONGITUD_CIUDAD);
    }
    while(!inputValid);

    if(validateCancelValueString(ciudad))
    {
        return Profesional();
    }


    do
    {
        std::cout << "Ingrese el telefono: ";
        std::cin.getline(telefono, LONGITUD_TELEFONO);
        inputValid = validateInputString(telefono, LONGITUD_TELEFONO);
    }
    while(!inputValid);

    if(validateCancelValueString(telefono))
    {
        return Profesional();
    }
    do
    {
        std::cout << "Ingrese el correo electronico: ";
        std::cin.getline(email, LONGITUD_EMAIL);
        inputValid = validateInputString(email, LONGITUD_EMAIL);
    }
    while(!inputValid);

    if(validateCancelValueString(email))
    {
        std::cout << "Carga de profesional cancelada " << std::endl;
        return Profesional();
    }
    std::cout << "\n";
    std::cout << "Especialidades: " << std::endl;
    std::cout << "\n";
    mostrarTodasEspecialidadesActivas();
    do
    {
        std::cout << "Ingrese el codigo de la especialidad ";
        std::cin >> especialidad;
        existeEsp = existeEspecialidadActiva(especialidad) || validateCancelValueInt(especialidad); //si ingresa 0, dejamos que avance para que cancele
        if(!existeEsp)
        {
            std::cout << "No se encontro la especialidad" << std::endl;
        }

    }
    while(!validateInputInt() || !existeEsp);


    if(validateCancelValueInt(especialidad))
    {
        return Profesional();
    }

    do
    {

        std::cout << "Ingrese el valor de la consulta: $";
        std::cin >> valorConsulta;
    }
    while(!validateInputInt());

    if(validateCancelValueFloat(valorConsulta))
    {
        return Profesional();
    }

    std::cout << "Atiende solo particulares? (s/n): ";
    std::cin >> soloParticularChar;

    while(soloParticularChar != 's' && soloParticularChar != 'S' && soloParticularChar != 'n' && soloParticularChar != 'N')
    {
        std::cout << "Ingrese una opcion valida (s/n): ";
        std::cin >> soloParticularChar;
    }

    if(validateCancelValueChar(soloParticularChar))
    {
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


    if(estaStringVacio((char *)profesional.getMatricula()))
    {
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
        if (estaProfesionalActivo((char*)profesionales[i].getMatricula()))
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
        if(estaProfesionalActivo((char*)profesionales[i].getMatricula()))
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
        if(estaProfesionalActivo((char*)profesionales[i].getMatricula()) == false)
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

    while(!validateInputString(matricula, LONGITUD_MATRICULA))
    {
        std::cout << "Ingrese la matricula del profesional que quiere editar: ";
        std::cin.getline(matricula, LONGITUD_MATRICULA);
        validateInputString(matricula, LONGITUD_MATRICULA);
    }

    if(validateCancelValueString(matricula))
    {
        std::cout << "Edicion de profesional cancelada" << std::endl;
        return;
    }


    if(existeProfesional(matricula) && estaProfesionalActivo(matricula))
    {
        Profesional profesional;
        profesional = cargarProfesionalAEditar(matricula);

        if(strlen(profesional.getMatricula()) == 0)
        {
            std::cout << "Edicion de profesional cancelada " << std::endl;
            return;
        }

        int pos = pa.buscar(matricula);
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
    else
    {
        std::cout << std::endl <<"El profesional que quiere editar no ha sido encontrado." <<std::endl<< std::endl;
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

    while(!validateInputString(matricula, LONGITUD_MATRICULA))
    {
        std::cout<<"Ingrese la matricula del profesional a eliminar : ";
        std::cin.getline(matricula, LONGITUD_MATRICULA);
    }


    if(validateCancelValueString(matricula))
    {
        std::cout << "Eliminacion de profesional cancelada" << std::endl;
        return;
    }

    if(existeProfesional(matricula) && estaProfesionalActivo(matricula))
    {
        int pos = pa.buscar(matricula);
        if(pos != -1)
        {
            profesional = pa.Leer(pos);
            profesional.setEliminado(true);
            pa.guardar(pos,profesional);
            std::cout<<std::endl<<"profesional eliminado " <<std::endl<<std::endl;
        }
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

    while(!validateInputString(matricula, LONGITUD_MATRICULA))
    {
        std::cout<<"Ingrese la matricula del profesional a restaurar : ";
        std::cin.getline(matricula, LONGITUD_MATRICULA);
    }

    if(validateCancelValueString(matricula))
    {
        std::cout << "Restauracion de profesional cancelada" << std::endl;
        return;
    }

    if(existeProfesional(matricula) && estaProfesionalActivo(matricula) == false)
    {

        int pos = pa.buscar(matricula);
        if(pos != -1)
        {
            profesional = pa.Leer(pos);
            profesional.setEliminado(false);
            pa.guardar(pos,profesional);
            std::cout<<std::endl<<"Profesional restaurado con exito" <<std::endl<<std::endl;
        }
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

    while(!validateInputString(matricula, LONGITUD_MATRICULA))
    {
        std::cout << "Ingrese la matricula del profesional que quiere buscar: ";
        std::cin.getline(matricula, 50);
    }

    if(validateCancelValueString(matricula))
    {
        std::cout << "Busqueda de profesional cancelada" << std::endl;
        return;
    }


    if(existeProfesional(matricula) && estaProfesionalActivo(matricula))
    {
        int pos = pa.buscar(matricula);
        Profesional p = pa.Leer(pos);
        std::cout << std::endl;
        mostrarProfesional(p);
    }
    else
    {
        std::cout << "El profesional no ha sido encontrado." << std::endl;
    }
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
    int especialidad;

    if(profesional == NULL)
    {
        std::cout << "No se pudo leer los profesionales" << std::endl;
    }

    pa.leerTodos(profesional, cantidad);
    system("cls");
    mostrarTodasEspecialidadesActivas();
    std::cout << "Digite 0 para cancelar" << std::endl;
    do
    {
        std::cout << "Ingrese la especialidad del profesional que quiere buscar: ";
        std::cin >> especialidad;
    }
    while(!validateInputInt());

    if(validateCancelValueInt(especialidad))
    {
        return;
    }

    for(int i = 0; i < cantidad; i++)
    {
        if(profesional[i].getEspecialidad() == especialidad && estaProfesionalActivo((char*)profesional[i].getMatricula()) && existeEspecialidadActiva(especialidad))
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
