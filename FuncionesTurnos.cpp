#include <iostream>
#include "FuncionesTurnos.h"
#include "TurnosArchivo.h"
#include "funcionesGlobales.h"
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
        /// Inicio implementaciΓö£Γöé manejo fecha >= Actual

        do
        {

        std::cout << "Ingrese la fecha del turno: " << std::endl;
        std::cout << "Ingrese 0 en cualquier campo para cancelar" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
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
            if(fechaTurno > obtenerFechaActual() || fechaTurno == obtenerFechaActual()){
                std::cout << "Fecha vΓö£├¡lida" << std::endl;
                fechaFutura=true;

            } else{
                std::cout << "La fecha ingresada es anterior a la fecha actual. Por favor ingrese una fecha vΓö£├¡lida." << std::endl;
                fechaFutura=false;
            }

        }
        while(!fechaFutura);


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
            ///Aca, al ingresar dni incorrecto, la segunda vez elimina el primer caracter
            std::cin.ignore();
            std::cout << "1 Ingrese el DNI del paciente: ";
            std::cin.getline(dniPaciente, LONGITUD_DNI);
            ///PRUEBA
            std::cout << "PRUEBA --> DNI del paciente:" << dniPaciente << std::endl;
            inputValido  = validateInputString(dniPaciente, LONGITUD_DNI);

            while(!inputValido){
                std::cin.ignore();
                std::cout << "2 Ingrese el DNI del paciente: ";
                std::cin.getline(dniPaciente, LONGITUD_DNI);
                ///PRUEBA
                std::cout << "PRUEBA --> DNI del paciente:" << dniPaciente << std::endl;
                inputValido = validateInputString(dniPaciente, LONGITUD_DNI);
            }

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

        do{
            std::cin.ignore();
            std::cout << "Ingrese la matricula del profesional: ";
            std::cin.getline(matricula, LONGITUD_MATRICULA);
            inputValido = validateInputString(matricula, LONGITUD_MATRICULA);

            existeMatricula = existeProfesional(matricula);

        if(validateCancelValueString(matricula)){
        return Turno();
        }

        }while(!inputValido || !existeMatricula);


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
    int horaTurno;
    TurnosArchivo ta;
    std::cout << "Ingrese DNI del paciente para buscar turno: ";
    std::cin.ignore();
    std::cin.getline(DNI, 20);

    std::cout << "Ingrese fecha del turno a buscar: ";
    std::cin >> fechaTurno;

    std::cout << "Ingrese hora del turno a buscar: ";
    std::cin >> horaTurno;

    int pos = ta.buscar(DNI, fechaTurno, horaTurno);
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

    do{
        std::cout << std::endl << "Ingrese el nro. de turno a editar: ";
        std::cin >> indEditar;
        std::cout << std::endl;
        if(validateCancelValueInt(indEditar)){ return; }
    }while(turnos[indEditar-1].getEliminado() || indEditar<1 || indEditar>cantidad);

    if(turnos[indEditar-1].getEliminado()){
        std::cout << "Turno inexistente " << std::endl;
    }else{
        char DNI[20];
        strncpy(DNI, turnos[indEditar-1].getDniPaciente(), sizeof(DNI) - 1);
        DNI[sizeof(DNI) - 1] = '\0';
        int horaTurno = turnos[indEditar-1].getHoraTurno();
        Fecha fechaTurno = turnos[indEditar-1].getFecha();

        //std::cout << "PRUEBA --> " << "DNI: " << DNI << ", Fecha: " << fechaTurno.toString() << ", Hora: " << horaTurno << std::endl;


        int pos = ta.buscar(DNI, fechaTurno, horaTurno);

        Turno turno;
        turno = cargarTurno();
        bool res = false;
        ///Saber si el Turno esta vacio:
        if(turno.getHoraTurno()!=0){
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
    int cantidad = ta.getCantidad(), contNumeracion=0;
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
            contNumeracion++;
            std::cout<<"------------------------ "<< "TURNO " << contNumeracion << " -----------------------"<<std::endl;
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

    do{
        std::cout << "Ingrese el nro. de turno a eliminar: ";
        std::cin >> indEliminar;
        if(validateCancelValueInt(indEliminar)){ return; }
    }while(turnos[indEliminar-1].getEliminado() || indEliminar<1 || indEliminar>cantidad);

    char DNI[20];
    strncpy(DNI, turnos[indEliminar-1].getDniPaciente(), sizeof(DNI) - 1);
    DNI[sizeof(DNI) - 1] = '\0';
    int horaTurno = turnos[indEliminar-1].getHoraTurno();
    Fecha fechaTurno = turnos[indEliminar-1].getFecha();

    int pos = ta.buscar(DNI, fechaTurno, horaTurno);

    Turno turno = ta.Leer(pos);

    turno.setEliminado(true);

    bool res = ta.guardar(pos, turno);

    if(res){
        std::cout << std::endl << "Turno eliminado con ├⌐xito" << std::endl;
    }

    delete [] turnos;
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
    Turno turno;
    TurnosArchivo ta;

    ///
    mostrarTodosTurnosEliminados();
    char dni[20];
    Fecha fechaTurno;
    int horaTurno;
    std::cout<<std::endl<<"Ingrese el DNI/paciente del turno a restaurar : ";
    std::cin.ignore();
    std::cin.getline(dni, 20);

    int pos = ta.buscar(dni, fechaTurno, horaTurno);
    if(pos != -1)
    {
        turno = ta.Leer(pos);
        turno.setEliminado(false);
        ta.guardar(pos,turno);
        std::cout << std::endl;
        std::cout<<"Turno restaurado con ╬ô├¬ΓîÉ╬ô├╢├ë╬ô├▓┬úxito" <<std::endl<<std::endl;
    }
    else
    {
        std::cout<<std::endl<<"No se pudo restaurar el turno"<<std::endl<<std::endl;
    }
}

void informarProfesionalQueMasPacientesAtendio()
{
    ///Profesional que mΓò¼├┤Γö£┬¼╬ô├«├ëΓò¼├┤Γö£ΓòóΓö£├½Γò¼├┤Γö£ΓûôΓö¼├║s pacientes atendiΓò¼├┤Γö£┬¼╬ô├«├ëΓò¼├┤Γö£ΓòóΓö£├½Γò¼├┤Γö£ΓûôΓö¼├║:
    int ind=-1, maximo = 0;

    ///Profesionales activos e inactivos
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidadProfesionales = pa.getCantidad();
    profesionales = new Profesional[cantidadProfesionales];
    pa.leerTodos(profesionales, cantidadProfesionales);
    ///Vector acumulador de pacientes atendidos por profesional. Comparte el Γò¼├┤Γö£┬¼╬ô├«├ëΓò¼├┤Γö£ΓòóΓö£├½Γò¼├┤Γö£ΓûôΓö¼├║ndice con el de profesionales
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
    } else {

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
    ea.leerTodos(especialidades, cantidadEspecialidades);
    ///Vector acumulador de pacientes atendidos por especialidad. Comparte el ind con el de especialidades
    int* pacientesAtendidos = new int[cantidadEspecialidades] {};
    ///Vector Turnos
    Turno *turnos;
    TurnosArchivo ta;
    int cantidadTurnos = ta.getCantidad();
    turnos = new Turno [cantidadTurnos];
    ta.leerTodos(turnos, cantidadTurnos);

    ///Vector de profesionales para comparar la matrΓö£┬ícula con la del turno
    Profesional *profesionales;
    ProfesionalesArchivo pa;
    int cantidadProfesionales = pa.getCantidad();
    profesionales = new Profesional[cantidadProfesionales];
    pa.leerTodos(profesionales, cantidadProfesionales);



    for(int j = 0; j < cantidadTurnos; j++)
    {
        ///Inicio: Relacionamiento de matricula turno con matricula profesionales para conocer el nombre de la especialidad
        std::string matriculaTurno = turnos[j].getMatricula();
        int idEspecialidadTurno;
        std::string especialidadTurno;

        for(int m = 0; m < cantidadProfesionales; m++){
            if(matriculaTurno == profesionales[m].getMatricula()){
                idEspecialidadTurno=profesionales[m].getEspecialidad();
                break;
            }
        }
        for(int n = 0; n < cantidadEspecialidades; n++){
            if(idEspecialidadTurno==especialidades[n].getId() && existeEspecialidadActiva(idEspecialidadTurno)){
                //especialidadTurno=especialidades[n].getNombreEspecialidad();
                if(!turnos[j].getEliminado()){pacientesAtendidos[n]++; }
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
    if(maximo < 1 ){
        std::cout << "No hay turnos cargados" << std::endl;
        return;
    } else {

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

void informarProfesionalMayoresAtencionesParticulares(){
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
    ta.leerTodos(turnos, cantidadTurnos);

    ///RECORRIDO DE TURNOS PARA SABER SI NO FUE ELIMINADO Y OBTENER LA MATRICULA
    for(int a=0; a<cantidadTurnos; a++){
        std::string matriculaTurno;
        if(!turnos[a].getEliminado()){
            matriculaTurno = std::string(turnos[a].getMatricula());
            ///RECORRO EL VECTOR DE PROFESIONALES QUE ATIENDAN DE MANERA PARTICULAR
            ///BUSCANDO POR MatriculaTurno PARA INCREMENTAR ATENCIONES
            for(int b=0; b<cantidadProfesionales; b++){
                if(matriculaTurno == std::string(profesionales[b].getMatricula()) && profesionales[b].getSoloParticular() && estaProfesionalActivo((char *)profesionales[b].getMatricula())){
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
/*     std::cout << "PRUEBA: " << std::endl;

    for(int d = 0; d < cantidadProfesionales; d++)
    {
        std::cout << "Profesional: " << std::string(profesionales[d].getApellido()) << ", " << std::string(profesionales[d].getNombre()) <<
        " / Recaudacion: $" << atencionesParticulares[d] << std::endl;

    }  */

    if(maximo < 1){
        std::cout << "No se registraron atenciones particulares" << std::endl;
    } else {

        std::cout << std::endl << std::string(profesionales[ind].getApellido()) << ", " << std::string(profesionales[ind].getNombre()) <<
        " registra la mayor recaudacion por atenciones particulares ($" << atencionesParticulares[ind] << ")" << std::endl << std::endl;
    }

    delete[] profesionales;
    delete[] atencionesParticulares;
    delete[] turnos;
}
