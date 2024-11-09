#include <iostream>
#include <cstdlib>
#include "Persona.h"
#include "Paciente.h"
#include "funcionesGlobales.h"
#include "Turno.h"

using namespace std;

int main()
{
    int opcion, opcionPaciente, opcionProfesional, opcionTurno, opcionEspecialidad;
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
        cout<<"3 - TURNOS " <<endl;
        cout<<"4 - ESPECIALIDADES " <<endl;
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
                cout << "2 - BUSCAR PACIENTE" << endl;
                cout << "3 - MODIFICAR PACIENTE" << endl;
                cout << "4 - ELIMINAR PACIENTE" <<endl;
                cout << "5 - LISTAR PACIENTES" << endl;
                cout << "6 - RESTAURAR PACIENTES" << endl;
                cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;

                cout << "Ingrese una opcion: ";
                cin >> opcionPaciente;

                switch (opcionPaciente)
                {
                case 1:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout << "CARGAR PACIENTE" << endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    guardarPaciente();
                    //system("pause");
                    break;

                case 2:
                    system("cls");
                    cout << "BUSCAR PACIENTE" << endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado

                    cout << "1 - POR DNI" << endl;
                    cout << "2 - POR OBRA SOCIAL" << endl;
                    cout << "0 - VOLVER AL MENU PRINCIPAL" << endl;
                    int opcionBuscarPaciente;
                    cout << "Ingrese una opcion: ";
                    cin >> opcionBuscarPaciente;
                    switch (opcionBuscarPaciente){
                    case 1:
                        buscarPaciente();
                        system("pause");
                        break;
                    case 2:
                        buscarPacientesPorObraSocial();
                        system("pause");
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
                        break;
                case 3:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout << "MODIFICAR PACIENTE" << endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    editarPaciente();
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout << "ELIMINAR PACIENTE" << endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    eliminarPaciente();
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout << "LISTAR PACIENTES" << endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    mostrarTodosPacientesActivos();
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout << "RESTAURAR PACIENTE" << endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    restaurarPaciente();
                    system("pause");
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
                cout << "4 - LISTAR PROFESIONALES" << endl;
                cout << "5 - RESTAURAR PROFESIONALES" << endl;
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
                case 2:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"MODIFICAR PROFESIONAL " <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    editarProfesional();
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"ELIMINAR PROFESIONAL " <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    eliminarProfesional();
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"LISTAR PROFESIONAL " <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    mostrarTodosProfesionalesActivos();
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout << "RESTAURAR PROFESIONALES" << endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    restaurarProfesional();
                    system("pause");
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
                cout<<"TURNOS " <<endl<<endl;
                cout << "\033[0m";  // Detiene subrayado

                cout << "1 - ASIGNAR TURNO" << endl;
                cout << "2 - MODIFICAR TURNO" << endl;
                cout << "3 - ELIMINAR TURNO" << endl;
                cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;

                cout << "Ingrese una opcion: ";
                cin >> opcionTurno;

                switch(opcionTurno)
                {
                case 1:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"ASIGNAR TURNO" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    guardarTurno();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"MODIFICAR TURNO" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    editarTurno();
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"ELIMINAR TURNO" <<endl<<endl;
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
        case 4:
            while (true)
            {
                system("cls");
                cout << "\033[4m";  // Comienza subrayado
                cout<<"ESPECIALIDADES " <<endl<<endl;
                cout << "\033[0m";  // Detiene subrayado

                cout << "1 - CARGAR ESPECIALIDAD" << endl;
                cout << "2 - MODIFICAR ESPECIALIDAD" << endl;
                cout << "3 - ELIMINAR ESPECIALIDAD" << endl;
                cout << "4 - LISTAR ESPECIALIDADES" << endl;
                cout << "5 - RESTAURAR ESPECIALIDADES" << endl;
                cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;

                cout << "Ingrese una opcion: ";
                cin >> opcionEspecialidad;

                switch(opcionEspecialidad)
                {
                case 1:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"CARGAR ESPECIALIDAD" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    guardarEspecialidad();
                    break;
                case 2:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"MODIFICAR ESPECILIALIDAD" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    editarEspecialidad();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"ELIMINAR ESPECILIALIDAD" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    eliminarEspecialidad();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"LISTAR ESPECILIALIDADES" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    mostrarTodasEspecialidadesActivas();
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    cout << "\033[4m";  // Comienza subrayado
                    cout<<"RESTAURAR ESPECILIALIDAD" <<endl<<endl;
                    cout << "\033[0m";  // Detiene subrayado
                    restaurarEspecialidad();
                    system("pause");
                    system("cls");
                    break;
                case 0:
                    system("cls");
                    break;
                default:
                    cout << "Opción no válida." << endl;
                }

                if (opcionEspecialidad == 0)
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


