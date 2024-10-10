#include <iostream>
#include <cstdlib>
#include "Persona.h"
#include "Paciente.h"
#include "funcionesGlobales.h"

using namespace std;

int main()
{
    int opcion;
    Paciente p1;
    Profesional pr1;

    while(true)
    {
        cout<<"SISTEMA DE GESTION DE TURNOS " <<endl<<endl;
        cout<<"1 - SOLICITAR TURNO " <<endl;
        cout<<"2 - MODIFICAR TURNO " <<endl;
        cout<<"3 - ELIMINAR TURNO " <<endl;
        cout<<"4 - LISTAR TURNOS " <<endl;
        cout<<"5 - LISTAR PACIENTES " <<endl;
        cout<<"6 - LISTAR PROFESIONALES " <<endl;
        cout<<"7 - CARGAR PROFESIONAL " <<endl<<endl;

        cout<<"Ingrese una opcion : ";
        cin>>opcion;

        switch(opcion)
        {
        case 1 :
            system("cls");
            guardarPaciente();
            system("pause");
            mostrarTodosPacientes();
            cout<<"Paciente cargado exitosamente " <<endl;
            system("pause");
            system("cls");
            break;
        case 7 :
            system("cls");
            pr1 = cargarProfesional();
            cout<<"Profesional cargado exitosamente " <<endl;
            system("pause");
            mostrarProfesional(pr1);
            system("pause");
            system("cls");
            break;










        }

    }




    return 0;
}
