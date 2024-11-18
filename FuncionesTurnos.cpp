#include <iostream>
#include "FuncionesTurnos.h"
#include "TurnosArchivo.h"
#include "funcionesGlobales.h"
#include <ctime> ///Para menejar fechas

Turno cargarTurno()
{

    Turno turno;
    Fecha fechaTurno;
    char dniPaciente[50], matricula[50];
    int horaTurno, dia, mes, anio;
    bool existeP, existeT, fechaFutura;

    do
    {
        /// Inicio implementació manejo fecha >= Actual

        do
        {

        std::cout << "Ingrese la fecha del turno: " << std::endl;
        std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        //std::cin >> fechaTurno;
            do {
                dia = pedirDiaFechaCancelable();

                if(validateCancelValueInt(dia)){
                    return Turno();
                }

                mes = pedirMesFechaCancelable();

                if(validateCancelValueInt(mes)){
                    return Turno();
                }

                anio = pedirAnioFechaCancelable();

                if(validateCancelValueInt(anio)){
                    return Turno();
                }

                fechaTurno = Fecha(dia, mes, anio);
                if(!fechaTurno.esValida){
                    std::cout << "La fecha ingresada es invalida, ingrese otra por favor " << std::endl;
                }
            }while(!fechaTurno.esValida);

        // Obtener la fecha actual
        std::time_t tiempoActual = std::time(0);  ///Obtiene el tiempo actual
        std::tm* now = std::localtime(&tiempoActual); ///Convierte el tiempo actual a una estructura time

        ///Comprobar si la fecha ingresada es anterior a la fecha actual
        if (fechaTurno.getAnio() < (1900 + now->tm_year) ||  /// Compara el año
            (fechaTurno.getAnio() == (1900 + now->tm_year) && fechaTurno.getMes() < (now->tm_mon + 1)) ||  /// Compara el mes
            (fechaTurno.getAnio() == (1900 + now->tm_year) && fechaTurno.getMes() == (now->tm_mon + 1) && fechaTurno.getDia() < now->tm_mday))/// Compara el día
        {
            std::cout << "La fecha ingresada es anterior a la fecha actual. Por favor ingrese una fecha válida." << std::endl;
            fechaFutura=false;
        }else{
            fechaFutura=true;
        }

        }
        while(!fechaFutura);

        /// Final implementació manejo fecha >= Actual

        do
        {
            std::cout << "Ingrese la hora del turno (8-20 hs): ";
            std::cin >> horaTurno;

            if(validateCancelValueInt(horaTurno)){
            return Turno();
    }
        }
        while(horaTurno < 8 || horaTurno > 20);

        do
        {

            std::cout << "Ingrese el DNI del paciente: ";
            std::cin >> dniPaciente;

            if(validateCancelValueString(dniPaciente)){
            return Turno();
    }

            existeP = existePaciente(dniPaciente);
            if(!existeP)
            {
                std::cout << "No encontramos un paciente con ese DNI " << std::endl;
            }
        }
        while(!existeP);

//        std::cout << "Profesionales de " << buscarEspecialidad(especialidad).getNombreEspecialidad() << std::endl;
//        buscarProfesionalesPorEspecialidad(especialidad);
        std::cout << "Ingrese la matricula del profesional: ";
        std::cin >> matricula;

        if(validateCancelValueString(matricula)){
        return Turno();
    }

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
    TurnosArchivo ta;
    std::cout << "Ingrese DNI del paciente para buscar turno: ";
    std::cin.ignore();
    std::cin.getline(DNI, 20);

    int pos = ta.buscar(DNI);
    if(pos == -1 )
    {
        std::cout << "El turno no ha sido encontrado." << std::endl;
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

    if(strlen(turno.getDniPaciente()) == 0){
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
    char DNI[20];
    TurnosArchivo ta;
    std::cout << "Digite 0 para cancelar" << std::endl;
    std::cout << "DNI del paciente para editar turno: ";
    std::cin.ignore();
    std::cin.getline(DNI, 20);

    if(validateCancelValueString(DNI)){
        return;
    }

    int pos = ta.buscar(DNI);
    if(pos == -1 )
    {
        std::cout << "El turno que quiere editar no ha sido encontrado." << std::endl;
        return;
    }

    Turno turno;
    turno = cargarTurno();
    bool res = ta.guardar(pos, turno);
    if(res)
    {
        std::cout << "El turno ha sido editado correctamente";
    }
    else
    {
        std::cout << "Ocurrio un error al editar el turno";
    }
}

void mostrarTodosTurnosActivos()
{
    Turno *turnos;
    TurnosArchivo ta;
    int cantidad = ta.getCantidad();
    turnos = new Turno [cantidad];
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
            std::cout<<"------------------------ "<< "TURNO " << k + 1 << " -----------------------"<<std::endl;
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
    std::cout<<std::endl<<"Digite 0 para cancelar" << std::endl;
    std::cout<<"Ingrese DNI/paciente del turno a eliminar : ";
    std::cin.ignore();
    std::cin.getline(dni, 20);

    if(validateCancelValueString(dni)){
        return;
    }

    int pos = ta.buscar(dni);
    if(pos != -1)
    {
        turno = ta.Leer(pos);
        turno.setEliminado(true);
        ta.guardar(pos,turno);
        std::cout << std::endl <<"Turno eliminado con exito" <<std::endl << std::endl;
    }
    else
    {
        std::cout << std::endl << "No se pudo eliminar el turno" << std::endl << std::endl;
    }
}

bool validarFechaTurno(Turno t1, Turno t2)
{
    //if(t1.getFecha() == t2.getFecha() && t1.getHoraTurno() == t2.getHoraTurno()){
    Fecha f1 = t1.getFecha();
    Fecha f2 = t2.getFecha();
    if(f1.getDia() == f2.getDia() && f1.getMes() == f2.getMes() && f1.getAnio() == f2.getAnio())
    {
        if(t1.getHoraTurno() == t2.getHoraTurno())
        {
            return true;
        }
    }

    return false;
}

bool validarExisteTurno(Turno t)
{

    Turno *turnos;
    TurnosArchivo ta;

    int cantidad = ta.getCantidad();
    turnos = new Turno [cantidad];
    ta.leerTodos(turnos, cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        if(validarFechaTurno(t, turnos[i]))
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
    ta.leerTodos(turnos, cantidad);


    ///Inicio ordenamiento por fecha ascendente
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
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
    Turno turno;
    TurnosArchivo ta;

    ///
    mostrarTodosTurnosEliminados();
    char dni[20];
    std::cout<<std::endl<<"Ingrese el DNI/paciente del turno a restaurar : ";
    std::cin.ignore();
    std::cin.getline(dni, 20);

    int pos = ta.buscar(dni);
    if(pos != -1)
    {
        turno = ta.Leer(pos);
        turno.setEliminado(false);
        ta.guardar(pos,turno);
        std::cout << std::endl;
        std::cout<<"Turno restaurado con ∩┐╜xito" <<std::endl<<std::endl;
    }
    else
    {
        std::cout<<std::endl<<"No se pudo restaurar el turno"<<std::endl<<std::endl;
    }
}

void informarProfesionalQueMasPacientesAtendio()
{
    ///Profesional que m∩┐╜s pacientes atendi∩┐╜:
    int ind=0, maximo;

    ///Profesionales activos e inactivos
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidadProfesionales = pa.getCantidad();
    profesionales = new Profesional[cantidadProfesionales];
    pa.leerTodos(profesionales, cantidadProfesionales);
    ///Vector acumulador de pacientes atendidos por profesional. Comparte el ∩┐╜ndice con el de profesionales
    int* pacientesAtendidos = new int[cantidadProfesionales] {};
    ///Vector Turnos
    Turno *turnos;
    TurnosArchivo ta;
    int cantidadTurnos = ta.getCantidad();
    turnos = new Turno [cantidadTurnos];
    ta.leerTodos(turnos, cantidadTurnos);

    for(int i = 0; i < cantidadProfesionales; i++)
    {

        for(int j = 0; j < cantidadTurnos; j++)
        {

            if(std::string(profesionales[i].getMatricula()) == std::string(turnos[j].getMatricula()) && !turnos[j].getEliminado())
            {

                pacientesAtendidos[i]++;

            }

        }

    }

    for(int k = 0; k < cantidadProfesionales; k++)
    {
        if(ind == 0)
        {
            maximo=pacientesAtendidos[k];
        }
        else if(pacientesAtendidos[k]>maximo)
        {
            maximo=pacientesAtendidos[k];
            ind=k;
        }
    }

    std::cout << profesionales[ind].getApellido() << ", " << profesionales[ind].getNombre() <<
              " (Matr∩┐╜cula: " << profesionales[ind].getMatricula() << ") - " << pacientesAtendidos[ind] <<
              " pacientes atendidos" << std::endl << std::endl;

    delete[] profesionales;
    delete[] pacientesAtendidos;
    delete[] turnos;

}
