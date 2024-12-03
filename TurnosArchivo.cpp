#include<iostream>
#include "TurnosArchivo.h"
#include <cstring>
using namespace std;

TurnosArchivo::TurnosArchivo()
{
    _filename = "turnos.dat";
}
bool TurnosArchivo::Guardar(const Turno &registro)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "ab");
    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fwrite(&registro, sizeof(Turno), 1, pFile) == 1;
    fclose(pFile);
    return resultado;
}
bool TurnosArchivo::leerTodos(Turno registros[], int cantidad)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fread(registros, sizeof(Turno), cantidad, pFile) == cantidad;
    fclose(pFile);
    return resultado;
}
bool TurnosArchivo::guardar(int pos, const Turno &registro)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb+ ");
    if(pFile == NULL)
    {
        return false;
    }
    fseek(pFile, sizeof(Turno) * pos, SEEK_SET);
    resultado = fwrite(&registro, sizeof(Turno), 1, pFile) == 1;
    fclose(pFile);
    return resultado;
}
int TurnosArchivo::getCantidad()
{
    int total;
    Turno registro;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    total = ftell(pFile);
    fclose(pFile);
    return total / sizeof(Turno);

}
int TurnosArchivo::buscar(char* dni, Fecha fechaTurno, int horaTurno)
{
    Turno registro;
    TurnosArchivo ta;
    int pos = 0;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return false;
    }
    while(fread(&registro, sizeof(Turno), 1, pFile) == 1)
    {
        if(strcmp(registro.getDniPaciente(), dni) == 0 && registro.getFecha() == fechaTurno && registro.getHoraTurno() == horaTurno){
             return pos;
        }
        pos++;
    }
    fclose(pFile);

    return -1;
}
Turno TurnosArchivo::Leer(int pos)
{
    Turno registro;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return registro;
    }
    fseek(pFile, sizeof(Turno) * pos, SEEK_SET);
    fread(&registro, sizeof(Turno), 1, pFile);
    fclose(pFile);
    return registro;
}
