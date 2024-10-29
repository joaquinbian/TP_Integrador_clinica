#include<iostream>
#include "PacientesArchivo.h"
using namespace std;

PacientesArchivo::PacientesArchivo()
{
    _filename = "pacientes.dat";
}
bool PacientesArchivo::Guardar(const Paciente &registro)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "ab");
    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fwrite(&registro, sizeof(Paciente), 1, pFile);
    fclose(pFile);
    return resultado;
}
bool PacientesArchivo::leerTodos(Paciente registros[], int cantidad)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fread(registros, sizeof(Paciente), cantidad, pFile) == cantidad;
    fclose(pFile);
    return resultado;
}
int PacientesArchivo::getCantidad()
{
    int total;
    Paciente registro;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return 0;
    }
    fseek(pFile, 0, SEEK_END); ///Posiciono el cursor al final del archivo
    total = ftell(pFile); ///obtengo cantidad de bytes totales desde el inicio hasta la ubicacion del cursor
    fclose(pFile);
    return total / sizeof(Paciente); ///obtengo cantidad de registros

}
Paciente PacientesArchivo::Leer(int pos)
{
    Paciente registro;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return registro;
    }
    fseek(pFile, sizeof(Paciente) * pos, SEEK_SET);
    fread(&registro, sizeof(Paciente), 1, pFile);
    fclose(pFile);
    return registro;
}
bool PacientesArchivo::guardar(int pos, const Paciente &registro)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb+ ");
    if(pFile == NULL)
    {
        return false;
    }
    fseek(pFile, sizeof(Paciente) * pos, SEEK_SET);
    resultado = fwrite(&registro, sizeof(Paciente), 1, pFile);
    fclose(pFile);
    return resultado;
}
int PacientesArchivo::buscar(char* dni)
{
    Paciente registro;
    PacientesArchivo pa;
    int pos = 0;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return false;
    }
    while(fread(&registro, sizeof(Paciente), 1, pFile) == 1)
    {
        if(registro.getDni() == dni)
        {
            break;
        }
        pos++;
    }
    fclose(pFile);
    if(registro.getDni() == dni)
    {
        return pos;
    }
    return -1;
}
