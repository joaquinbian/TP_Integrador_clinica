#include<iostream>
#include "ProfesionalesArchivo.h"
using namespace std;

ProfesionalesArchivo::ProfesionalesArchivo()
{
    _filename = "profesionales.dat";
}
bool ProfesionalesArchivo::Guardar(const Profesional &registro)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "ab");
    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fwrite(&registro, sizeof(Profesional), 1, pFile) == 1;
    fclose(pFile);
    return resultado;
}
bool ProfesionalesArchivo::leerTodos(Profesional registros[], int cantidad)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fread(registros, sizeof(Profesional), cantidad, pFile) == cantidad;
    fclose(pFile);
    return resultado;
}
int ProfesionalesArchivo::getCantidad()
{
    int total;
    Profesional registro;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return 0;
    }
    fseek(pFile, 0, SEEK_END); ///Posiciono el cursor al final del archivo
    total = ftell(pFile); ///obtengo cantidad de bytes totales desde el inicio hasta la ubicacion del cursor
    fclose(pFile);
    return total / sizeof(Profesional); ///obtengo cantidad de registros

}
Profesional ProfesionalesArchivo::Leer(int pos)
{
    Profesional registro;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return registro;
    }
    fseek(pFile, sizeof(Profesional) * pos, SEEK_SET);
    fread(&registro, sizeof(Profesional), 1, pFile);
    fclose(pFile);
    return registro;
}
bool ProfesionalesArchivo::guardar(int pos, const Profesional &registro)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb+ ");
    if(pFile == NULL)
    {
        return false;
    }
    fseek(pFile, sizeof(Profesional) * pos, SEEK_SET);
    resultado = fwrite(&registro, sizeof(Profesional), 1, pFile) == 1;
    fclose(pFile);
    return resultado;
}
int ProfesionalesArchivo::buscar(char* matricula)
{
    Profesional registro;
    ProfesionalesArchivo pa;
    int pos = 0;
    bool encontrado = false;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return -1;
    }
    while(fread(&registro, sizeof(Profesional), 1, pFile) == 1)
    {
        if(strcmp(registro.getMatricula(), matricula) == 0){
            encontrado = true;
            break;
        }
        pos++;
    }
    fclose(pFile);
    if(encontrado){
        return pos;
    }
    return -1;
}
