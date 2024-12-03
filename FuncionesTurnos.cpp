#include <iostream>
#include "FuncionesTurnos.h"
#include "TurnosArchivo.h"
#include "funcionesGlobales.h"
#include "funcionesProfesional.h"
#include <ctime> ///Para menejar fechas

Turno cargarTurno()
{

    Turno turno;
    Fecha fechaTurno;
    char dniPaciente[LONGITUD_DNI], matricula[LONGITUD_MATRICULA];
    int horaTurno, dia, mes, anio;
    bool inputValido = false, existeP, existeT, fechaFutura, existeMatricula;

    do
    {
        /// Inicio implementacion manejo fecha >= Actual

        std::cin.ignore();
        do
        {
            ///Aca, al ingresar dni incorrecto, la segunda vez elimina el primer caracter
            std::cout << "Ingrese el DNI del paciente: ";
            std::cin.getline(dniPaciente, LONGITUD_DNI);
            inputValido  = validateInputString(dniPaciente, LONGITUD_DNI);

            while(!inputValido)
            {
                std::cout << "Ingrese el DNI del paciente: ";
                std::cin.getline(dniPaciente, LONGITUD_DNI);
                inputValido = validateInputString(dniPaciente, LONGITUD_DNI);
            }

            if(validateCancelValueString(dniPaciente))
            {
                return Turno();
            }

            existeP = estaPacienteActivo(dniPaciente);
            if(!existeP)
            {
                std::cout << "No encontramos un paciente con ese DNI " << std::endl;
            }
        }
        while(!existeP);

        std::cout << "\n";
        std::cout << "PROFESIONALES";
        std::cout << "\n";
        std::cout << "\n";
        mostrarTodosProfesionalesActivosResumido();
        std::cout << "\n";


        do
        {
            std::cout << "Ingrese la matricula del profesional: ";
            std::cin.getline(matricula, LONGITUD_MATRICULA);
            inputValido = validateInputString(matricula, LONGITUD_MATRICULA);

            if(validateCancelValueString(matricula))
            {
                return Turno();
            }

            existeMatricula = existeProfesional(matricula) && estaProfesionalActivo(matricula);

            if(!existeMatricula)
            {

                std::cout<<"La matricula ingresada son se encuentra registrada";
                std::cout<<"\n";
            }

        }
        while(!inputValido || !existeMatricula);

        do
        {

            std::cout << "Ingrese la fecha del turno: " << std::endl;
            std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
            std::cout << "------------------------------------------" << std::endl;
            //std::cin >> fechaTurno;
            do
            {
                dia = pedirDiaFechaCancelable();

                if(validateCancelValueInt(dia))
                {
                    return Turno();
                }

                mes = pedirMesFechaCancelable();

                if(validateCancelValueInt(mes))
                {
                    return Turno();
                }

                anio = pedirAnioFechaCancelable();

                if(validateCancelValueInt(anio))
                {
                    return Turno();
                }

                fechaTurno = Fecha(dia, mes, anio);
                if(!fechaTurno.esValida)
                {
                    std::cout << "La fecha ingresada es invalida, ingrese otra por favor " << std::endl;
                }
            }
            while(!fechaTurno.esValida);

            // Obtener la fecha actual
            if(fechaTurno > obtenerFechaActual() || fechaTurno == obtenerFechaActual())
            {
                fechaFutura=true;

            }
            else
            {
                std::cout << "La fecha ingresada es anterior a la fecha actual. Por favor ingrese una fecha valida." << std::endl;
                fechaFutura=false;
            }

        }
        while(!fechaFutura);


        do
        {
            std::cout << "Ingrese la hora del turno (8-20 hs): ";
            std::cin >> horaTurno;

            if(validateCancelValueInt(horaTurno))
            {
                return Turno();
            }
        }
        while(horaTurno < 8 || horaTurno > 20);


//        std::cout << "Profesionales de " << buscarEspecialidad(especialidad).getNombreEspecialidad() << std::endl;
//        buscarProfesionalesPorEspecialidad(especialidad);



        turno = Turno(fechaTurno, horaTurno, dniPaciente, matricula);

        existeT = validarExisteTurno(turno);

        if(existeT)
        {
            std::cout << "El profesional ya tiene un turno el dia " << fechaTurno.toString() << " a las " << horaTurno << ", seleccione otro horario"<< std::endl;
        }

    }
    while(existeT);

    return turno;
}
void buscarTurno()
{
    char DNI[20];
    Fecha fechaTurno;
    int horaTurno, dia, mes, anio;
    TurnosArchivo ta;
    std::cout << "Ingrese DNI del paciente para buscar turno: ";
    std::cin.ignore();
    std::cin.getline(DNI, 20);

    std::cout << "Ingrese fecha del turno a buscar: ";
    do
    {
        dia = pedirDiaFechaCancelable();

        if(validateCancelValueInt(dia))
        {
            std::cout << "Busqueda de turno cancelada" << std::endl;
            return;
        }

        mes = pedirMesFechaCancelable();

        if(validateCancelValueInt(mes))
        {
            std::cout << "Busqueda de turno cancelada" << std::endl;

            return ;
        }

        anio = pedirAnioFechaCancelable();

        if(validateCancelValueInt(anio))
        {
            std::cout << "Busqueda de turno cancelada" << std::endl;

            return ;
        }

        fechaTurno = Fecha(dia, mes, anio);
        if(!fechaTurno.esValida)
        {
            std::cout << "La fecha ingresada es invalida, ingrese otra por favor " << std::endl;
        }
    }
    while(!fechaTurno.esValida);

    do
    {

        std::cout << "Ingrese hora del turno a buscar (8hs - 20hs): ";
        std::cin >> horaTurno;
    }
    while(horaTurno < 8 || horaTurno > 20);

    int pos = ta.buscar(DNI, fechaTurno, horaTurno);
    if(pos == -1 )
    {
        std::cout << "El turno no ha sido encontrado." << std::endl;
        return;
    }
    Turno t = ta.Leer(pos);

    if(t.getEliminado())
    {
        std::cout << "El turno no ha sido encontrado." << std::endl;
        return;
    }

    t.mostrar();
}
void guardarTurno()
{
    Turno turno;
    TurnosArchivo ta;
    turno = cargarTurno();

    if(strlen(turno.getDniPaciente()) == 0)
    {
        std::cout << "Carga de turno cancelada " << std::endl;
        return;
    }

    if(ta.Guardar(turno))
    {
        std::cout<<"Turno guardado exitosamente" <<std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        std::cout<<"No se pudo guardar el turno " <<std::endl;
        system("pause");
        system("cls");
    }
}
void editarTurno()
{
    Turno *turnos;
    TurnosArchivo ta;
    int cantidad = ta.getCantidad();
    turnos = new Turno [cantidad];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ta.leerTodos(turnos, cantidad);

    if(cantidad == 0)
    {
        std::cout << "No hay turnos asignados por el momento " << std::endl;
        delete [] turnos;
        return;
    }
    ///Inicio ordenamiento por fecha ascendente
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            Fecha fecha1 = turnos[j].getFecha();
            Fecha fecha2 = turnos[j + 1].getFecha();
            if (fecha1 > fecha2)
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
            std::cout<<"------------------------ "<< "TURNO " << k + 1 << " -----------------------"<<std::endl;
            turnos[k].mostrar();


        }
    }

    int indEditar;

    std::cout << "\n";
    do
    {
        indEditar = pedirIntValido("Ingrese el nro. de turno a editar: ");
        std::cout << std::endl;
        if(validateCancelValueInt(indEditar))
        {
            return;
        }
    }
    while(turnos[indEditar-1].getEliminado() || indEditar<1 || indEditar>cantidad);

    if(turnos[indEditar-1].getEliminado())
    {
        std::cout << "Turno inexistente " << std::endl;
    }
    else
    {
        char DNI[20];
        strncpy(DNI, turnos[indEditar-1].getDniPaciente(), sizeof(DNI) - 1);
        DNI[sizeof(DNI) - 1] = '\0';
        int horaTurno = turnos[indEditar-1].getHoraTurno();
        Fecha fechaTurno = turnos[indEditar-1].getFecha();

        int pos = ta.buscar(DNI, fechaTurno, horaTurno);

        Turno turno;
        turno = cargarTurno();
        bool res = false;
        ///Saber si el Turno esta vacio:
        if(turno.getHoraTurno()!=0)
        {
            res = ta.guardar(pos, turno);
        }
        if(res)
        {
            std::cout << std::endl << "El turno ha sido editado correctamente" << std::endl;
        }
        else
        {
            std::cout << std::endl << "Ocurrio un error al editar el turno" << std::endl;
        }

    }
    delete [] turnos;

}
void mostrarTodosTurnosActivos()
{
    Turno *turnos;
    TurnosArchivo ta;
    int cantidad = ta.getCantidad();
    turnos = new Turno [cantidad];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ta.leerTodos(turnos, cantidad);

    if(cantidad == 0)
    {
        std::cout << "No hay turnos asignados por el momento " << std::endl;
        delete [] turnos;
        return;
    }
    ///Inicio ordenamiento por fecha ascendente
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            Fecha fecha1 = turnos[j].getFecha();
            Fecha fecha2 = turnos[j + 1].getFecha();
            if (fecha1 > fecha2)
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
            std::cout<<"------------------------ "<< "TURNO " << k + 1 << " -----------------------"<<std::endl;
            turnos[k].mostrar();


        }
    }
    delete [] turnos;
}
void eliminarTurno()
{
    Turno *turnos;
    TurnosArchivo ta;
    int cantidad = ta.getCantidad();
    turnos = new Turno [cantidad];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ta.leerTodos(turnos, cantidad);

    if(cantidad == 0)
    {
        std::cout << "No hay turnos asignados por el momento " << std::endl;
        delete [] turnos;
        return;
    }
    ///Inicio ordenamiento por fecha ascendente
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            Fecha fecha1 = turnos[j].getFecha();
            Fecha fecha2 = turnos[j + 1].getFecha();
            if (fecha1 > fecha2)
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
            std::cout<<"------------------------ "<< "TURNO " << k + 1 << " -----------------------"<<std::endl;
            turnos[k].mostrar();


        }
    }

    int indEliminar;

    do
    {
        indEliminar = pedirIntValido("Ingrese el nro. de turno a eliminar: ");
        if(validateCancelValueInt(indEliminar))
        {
            std::cout << "Eliminacion de turno cancelada" << std::endl;
            return;
        }
    }
    while(turnos[indEliminar-1].getEliminado() || indEliminar<1 || indEliminar>cantidad);

    char DNI[20];
    strncpy(DNI, turnos[indEliminar-1].getDniPaciente(), sizeof(DNI) - 1);
    DNI[sizeof(DNI) - 1] = '\0';
    int horaTurno = turnos[indEliminar-1].getHoraTurno();
    Fecha fechaTurno = turnos[indEliminar-1].getFecha();

    int pos = ta.buscar(DNI, fechaTurno, horaTurno);

    Turno turno = ta.Leer(pos);

    turno.setEliminado(true);

    bool res = ta.guardar(pos, turno);

    if(res)
    {
        std::cout << std::endl << "Turno eliminado con exito" << std::endl;
    }

    delete [] turnos;
}
bool validarFechaTurno(Turno t1, Turno t2)
{
    Fecha f1 = t1.getFecha();
    Fecha f2 = t2.getFecha();
    if(f1 == f2)
    {
        return true;
    }

    return false;
}
bool validarExisteTurno(Turno t)
{

    Turno *turnos;
    TurnosArchivo ta;

    int cantidad = ta.getCantidad();
    turnos = new Turno [cantidad];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ta.leerTodos(turnos, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        if(validarFechaTurno(t, turnos[i]) && t.getHoraTurno() == turnos[i].getHoraTurno())
        {
            if(strcmp(t.getMatricula(), turnos[i].getMatricula()) == 0)
            {
                delete [] turnos;
                return true;
            }
        }
    }

    delete [] turnos;
    return false;
}
void mostrarTodosTurnosEliminados()
{
    Turno *turnos;
    TurnosArchivo ta;
    int cantidad = ta.getCantidad();
    turnos = new Turno [cantidad];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ta.leerTodos(turnos, cantidad);


    ///Inicio ordenamiento por fecha ascendente
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            Fecha fecha1 = turnos[j].getFecha();
            Fecha fecha2 = turnos[j + 1].getFecha();
            if (fecha1 > fecha2)
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

        if(turnos[k].getEliminado() == true)

        {
            std::cout<<"------------------------ "<< "TURNO " << k + 1 << " -----------------------"<<std::endl;
            turnos[k].mostrar();


        }
    }
    delete [] turnos;
}
void restaurarTurno()
{
    Turno *turnos;
    TurnosArchivo ta;
    int cantidad = ta.getCantidad();
    bool hayTurnoEliminado = false;
    turnos = new Turno [cantidad];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ta.leerTodos(turnos, cantidad);

    if(cantidad == 0)
    {
        std::cout << "No hay turnos asignados por el momento " << std::endl;
        delete [] turnos;
        return;
    }
    ///Inicio ordenamiento por fecha ascendente
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            Fecha fecha1 = turnos[j].getFecha();
            Fecha fecha2 = turnos[j + 1].getFecha();
            if (fecha1 > fecha2)
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

        if(turnos[k].getEliminado())
        {
            hayTurnoEliminado = true;
            std::cout<<"------------------------ "<< "TURNO " << k + 1 << " -----------------------"<<std::endl;
            turnos[k].mostrar();


        }
    }

    if(!hayTurnoEliminado)
    {
        std::cout << "No hay turnos eliminados" << std::endl;
        delete [] turnos;
        return;
    }


    int indRestauar;

    do
    {
        indRestauar = pedirIntValido("Ingrese el nro. de turno a restaurar: ");
        if(validateCancelValueInt(indRestauar))
        {
            std::cout << "Restauracion de turno cancelada" << std::endl;
            return;
        }
    }
    while(turnos[indRestauar-1].getEliminado() == false || indRestauar<1 || indRestauar>cantidad );

    char DNI[20];
    strncpy(DNI, turnos[indRestauar-1].getDniPaciente(), sizeof(DNI) - 1);
    DNI[sizeof(DNI) - 1] = '\0';
    int horaTurno = turnos[indRestauar-1].getHoraTurno();
    Fecha fechaTurno = turnos[indRestauar-1].getFecha();

    int pos = ta.buscar(DNI, fechaTurno, horaTurno);

    Turno turno = ta.Leer(pos);

    turno.setEliminado(false);

    bool res = ta.guardar(pos, turno);

    if(res)
    {
        std::cout << std::endl << "Turno restaurado con exito" << std::endl;
    }

    delete [] turnos;
}
void informarProfesionalQueMasPacientesAtendio()
{
    ///Profesional que mas pacientes atendiio:
    int ind=-1, maximo = 0;

    ///Profesionales activos e inactivos
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidadProfesionales = pa.getCantidad();
    profesionales = new Profesional[cantidadProfesionales];

    if(profesionales == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    pa.leerTodos(profesionales, cantidadProfesionales);
    ///Vector acumulador de pacientes atendidos por profesional. Comparte el indice con el de profesionales
    int* pacientesAtendidos = new int[cantidadProfesionales] {};
    if(pacientesAtendidos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ///Vector Turnos
    Turno *turnos;
    TurnosArchivo ta;
    int cantidadTurnos = ta.getCantidad();
    turnos = new Turno [cantidadTurnos];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ta.leerTodos(turnos, cantidadTurnos);

    for(int i = 0; i < cantidadProfesionales; i++)
    {

        for(int j = 0; j < cantidadTurnos; j++)
        {

            if(std::string(profesionales[i].getMatricula()) == std::string(turnos[j].getMatricula()) && !turnos[j].getEliminado() && estaProfesionalActivo((char *)profesionales[i].getMatricula()))
            {

                pacientesAtendidos[i]++;

            }

        }

    }

    for(int k = 0; k < cantidadProfesionales; k++)
    {
        if(ind == -1)
        {
            maximo=pacientesAtendidos[k];
            ind=k;
        }
        else if(pacientesAtendidos[k]>maximo)
        {
            maximo=pacientesAtendidos[k];
            ind=k;
        }
    }

    if(maximo < 1)
    {
        std::cout << "No hay turnos cargados" << std::endl;
        return;
    }
    else
    {

        std::cout << profesionales[ind].getApellido() << ", " << profesionales[ind].getNombre() <<
                  " (Matricula: " << profesionales[ind].getMatricula() << ") - " << pacientesAtendidos[ind] <<
                  " pacientes atendidos" << std::endl << std::endl;
    }

    delete[] profesionales;
    delete[] pacientesAtendidos;
    delete[] turnos;
}
void informarEspecialidadMasSolicitada()
{
    ///Especialidad mas solicitada:
    int ind=-1, maximo = 0 ;

    ///Especialidades activas e inactivas
    Especialidad *especialidades;
    EspecialidadesArchivo ea;
    int cantidadEspecialidades = ea.getCantidad();
    especialidades = new Especialidad[cantidadEspecialidades];

    if(especialidades == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ea.leerTodos(especialidades, cantidadEspecialidades);
    ///Vector acumulador de pacientes atendidos por especialidad. Comparte el ind con el de especialidades
    int* pacientesAtendidos = new int[cantidadEspecialidades] {};

    if(pacientesAtendidos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ///Vector Turnos
    Turno *turnos;
    TurnosArchivo ta;
    int cantidadTurnos = ta.getCantidad();
    turnos = new Turno [cantidadTurnos];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";


    }

    ta.leerTodos(turnos, cantidadTurnos);

    ///Vector de profesionales para comparar la matrΓö£┬ícula con la del turno
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidadProfesionales = pa.getCantidad();
    profesionales = new Profesional[cantidadProfesionales];

    if(profesionales == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    pa.leerTodos(profesionales, cantidadProfesionales);



    for(int j = 0; j < cantidadTurnos; j++)
    {
        ///Inicio: Relacionamiento de matricula turno con matricula profesionales para conocer el nombre de la especialidad
        std::string matriculaTurno = turnos[j].getMatricula();
        int idEspecialidadTurno;
        std::string especialidadTurno;

        for(int m = 0; m < cantidadProfesionales; m++)
        {
            if(matriculaTurno == profesionales[m].getMatricula())
            {
                idEspecialidadTurno=profesionales[m].getEspecialidad();
                break;
            }
        }
        for(int n = 0; n < cantidadEspecialidades; n++)
        {
            if(idEspecialidadTurno==especialidades[n].getId() && existeEspecialidadActiva(idEspecialidadTurno))
            {
                //especialidadTurno=especialidades[n].getNombreEspecialidad();
                if(!turnos[j].getEliminado())
                {
                    pacientesAtendidos[n]++;
                }
                break;
            }
        }

    }
    ///Final

    for(int p = 0; p < cantidadEspecialidades; p++)
    {
        if(ind == -1)
        {
            maximo=pacientesAtendidos[p];
            ind=p;
        }
        else if(pacientesAtendidos[p]>maximo)
        {
            maximo=pacientesAtendidos[p];
            ind=p;
        }
    }
    if(maximo < 1 )
    {
        std::cout << "No hay turnos cargados" << std::endl;
        return;
    }
    else
    {

        std::cout << especialidades[ind].getNombreEspecialidad() << ", con " << pacientesAtendidos[ind] <<
                  " pacientes atendidos, fue la especialidad mas solicitada " << std::endl << std::endl;
    }

    /*   ///PRUEBA
      std::cout << "PRUEBA: " << std::endl;

      for(int p = 0; p < cantidadEspecialidades; p++)
      {
          std::cout << "Especialidad: " << especialidades[p].getNombreEspecialidad() << " / Atenciones: " << pacientesAtendidos[p] << std::endl;

      } */

    delete[] especialidades;
    delete[] pacientesAtendidos;
    delete[] turnos;
    delete[] profesionales;
}
void informarProfesionalMayoresAtencionesParticulares()
{
    ///MAYOR RECAUDACION PARTICULAR
    int ind=-1, maximo = 0;
    ///VECTOR CON TODOS LOS PROFESIONALES
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidadProfesionales = pa.getCantidad();
    profesionales = new Profesional[cantidadProfesionales];
    pa.leerTodos(profesionales, cantidadProfesionales);

    ///VECTOR ACUMULADOR PARALELO A PROFESIONALES
    float *atencionesParticulares = new float[cantidadProfesionales] {};

    ///VECTOR CON TODOS LOS TURNOS
    Turno *turnos;
    TurnosArchivo ta;
    int cantidadTurnos = ta.getCantidad();
    turnos = new Turno [cantidadTurnos];

    if(turnos == nullptr)
    {
        std::cout<<"No se pudo asignar memoria ";

    }

    ta.leerTodos(turnos, cantidadTurnos);

    ///RECORRIDO DE TURNOS PARA SABER SI NO FUE ELIMINADO Y OBTENER LA MATRICULA
    for(int a=0; a<cantidadTurnos; a++)
    {
        std::string matriculaTurno;
        if(!turnos[a].getEliminado())
        {
            matriculaTurno = std::string(turnos[a].getMatricula());
            ///RECORRO EL VECTOR DE PROFESIONALES QUE ATIENDAN DE MANERA PARTICULAR
            ///BUSCANDO POR MatriculaTurno PARA INCREMENTAR ATENCIONES
            for(int b=0; b<cantidadProfesionales; b++)
            {
                if(matriculaTurno == std::string(profesionales[b].getMatricula()) && profesionales[b].getSoloParticular() && estaProfesionalActivo((char *)profesionales[b].getMatricula()))
                {
                    atencionesParticulares[b]+=profesionales[b].getValorConsulta();
                }
            }
        }
    }

    ///CON EL ACUMULADOR CARGADO, SE ESTABLECE POR INDICE, LA MAYOR RECAUDACION Y SE IDENTIFICA AL PROFESIONAL
    for(int c = 0; c < cantidadProfesionales; c++)
    {
        if(ind == -1)
        {
            maximo=atencionesParticulares[c];
            ind=c;
        }
        else if(atencionesParticulares[c]>maximo)
        {
            maximo=atencionesParticulares[c];
            ind=c;
        }
    }

    ///PRUEBA

    if(maximo < 1)
    {
        std::cout << "No se registraron atenciones particulares" << std::endl;
    }
    else
    {

        std::cout << std::endl << std::string(profesionales[ind].getApellido()) << ", " << std::string(profesionales[ind].getNombre()) <<
                  " registra la mayor recaudacion por atenciones particulares ($" << atencionesParticulares[ind] << ")" << std::endl << std::endl;
    }

    delete[] profesionales;
    delete[] atencionesParticulares;
    delete[] turnos;
}
