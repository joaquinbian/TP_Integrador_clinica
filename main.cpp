#include <iostream>
#include <cstdlib>
#include "Persona.h"
#include "Paciente.h"
#include "funcionesGlobales.h"
#include "Turno.h"

using namespace std;

int main()
{
    int opcion, opcionPaciente, opcionProfesional, opcionListado, opcionTurno;
    char salir;
    Paciente p1;
    Profesional pr1;

    while(true)
    {
        cout << "\033[4m";  // Comienza subrayado
        cout<<"SISTEMA DE GESTION DE TURNOS " <<endl<<endl;
        cout << "\033[0m";  // Detiene subrayado

        cout<<"1 - PACIENTES" <<endl;
        cout<<"2 - PROFESIONALES " <<endl;
        cout<<"3 - LISTADOS " <<endl;
        cout<<"4 - TURNOS " <<endl;
        cout<<"0 - SALIR " <<endl<<endl;

        cout<<"Ingrese una opcion : ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            while (true)
            {
                system("cls");
                cout << "\033[4m";  // Comienza subrayado
                cout<<"PACIENTES " <<endl<<endl;
                cout << "\033[0m";  // Detiene subrayado

                cout << "1 - CARGAR PACIENTE" << endl;
                cout << "2 - ASIGNAR TURNO" << endl;
                cout << "3 - MODIFICAR TURNO" << endl;
                cout << "4 - ELIMINAR TURNO" << endl;
                cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;

                cout << "Ingrese una opcion: ";
                cin >> opcionPaciente;

                switch (opcionPaciente)
                {
                case 1:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout << "DATOS DEL PACIENTE" << endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    guardarPaciente();
                    break;
                case 0:
                    system("cls");
                    break;
                default:
                    cout << "Opcion no valida." << endl;
                }

                if (opcionPaciente == 0)
                {
                    break;
                }
            }
            break;
        case 2:
            while (true)
            {
                system("cls");
                cout << "\033[4m";  // Comienza subrayado
                cout<<"PROFESIONALES " <<endl<<endl;
                cout << "\033[0m";  // Detiene subrayado

                cout << "1 - CARGAR PROFESIONAL" << endl;
                cout << "2 - MODIFICAR PROFESIONAL" << endl;
                cout << "3 - ELIMINAR PROFESIONAL" << endl;
                cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;

                cout << "Ingrese una opcion: ";
                cin >> opcionProfesional;

                switch(opcionProfesional)
                {
                case 1:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"DATOS DEL PROFESIONAL " <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    guardarProfesional();
                    break;
                case 0:
                    system("cls");
                    break;
                default:
                    cout << "Opcion no valida." << endl;
                }

                if (opcionProfesional == 0)
                {
                    break;
                }
            }
            break;
        case 3:
            while (true)
            {
                system("cls");
                cout << "\033[4m";  // Comienza subrayado
                cout<<"LISTADOS " <<endl<<endl;
                cout << "\033[0m";  // Detiene subrayado

                cout << "1 - LISTAR PACIENTES" << endl;
                cout << "2 - LISTAR PROFESIONALES" << endl;
                cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;

                cout << "Ingrese una opcion: ";
                cin >> opcionListado;

                switch(opcionListado)
                {
                case 1:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"LISTADO DE PACIENTES" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    mostrarTodosPacientes();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"LISTADO DE PROFESIONALES" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    mostrarTodosProfesionales();
                    system("pause");
                    break;
                case 0:
                    system("cls");
                    break;
                default:
                    cout << "Opcion no valida." << endl;
                }

                if (opcionListado == 0)
                {
                    break;
                }
            }
            break;
                case 4:
            while (true)
            {
                system("cls");
                cout << "\033[4m";  // Comienza subrayado
                cout<<"TURNOS " <<endl<<endl;
                cout << "\033[0m";  // Detiene subrayado

                cout << "1 - EDITAR OPCION 1" << endl;
                cout << "2 - EDITAR OPCION 2" << endl;
                cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;

                cout << "Ingrese una opciÓn: ";
                cin >> opcionTurno;

                switch(opcionTurno)
                {
                case 1:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"SECCION OPCION 1" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"SECCION OPCION 2" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    system("pause");
                    break;
                case 0:
                    system("cls");
                    break;
                default:
                    cout << "Opción no válida." << endl;
                }

                if (opcionTurno == 0)
                {
                    break;
                }
            }
                    break;
        case 0:
            do
            {
                system("cls");
                cout<<"Desea salir ? S/N : " <<endl;
                cin>>salir;
                system("cls");


                if(salir == 's' || salir == 'S')
                {
                    exit(0);

                }
                else if(salir == 'n' || salir == 'N')
                {
                    break;
                }
            }
            while(salir != 's' && salir != 'S' && salir != 'n' && salir != 'N');
            break;









        }

    }




    return 0;
}


