#include<iostream>
#include "EspecialidadesArchivo.h"
#include <cstring>

using namespace std;

EspecialidadesArchivo::EspecialidadesArchivo()
{
    _filename = "especialidades.dat";
}
bool EspecialidadesArchivo::Guardar(const Especialidad &registro)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "ab");
    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fwrite(&registro, sizeof(Especialidad), 1, pFile) == 1;
    fclose(pFile);
    return resultado;
}
bool EspecialidadesArchivo::guardar(int pos, const Especialidad &registro)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb+ ");
    if(pFile == NULL)
    {
        return false;
    }
    fseek(pFile, sizeof(Especialidad) * pos, SEEK_SET);
    resultado = fwrite(&registro, sizeof(Especialidad), 1, pFile) == 1;
    fclose(pFile);
    return resultado;
}
bool EspecialidadesArchivo::leerTodos(Especialidad registros[], int cantidad)
{
    bool resultado;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return false;
    }
    resultado = fread(registros, sizeof(Especialidad), cantidad, pFile) == cantidad;
    fclose(pFile);
    return resultado;
}
int EspecialidadesArchivo::getCantidad()
{
    int total;
    Especialidad registro;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return 0;
    }
    fseek(pFile, 0, SEEK_END); ///Posiciono el cursor al final del archivo
    total = ftell(pFile); ///obtengo cantidad de bytes totales desde el inicio hasta la ubicacion del cursor
    fclose(pFile);
    return total / sizeof(Especialidad); ///obtengo cantidad de registros

}
int EspecialidadesArchivo::buscar(int id)
{
    Especialidad registro;
    EspecialidadesArchivo ea;
    int pos = 0;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return -1;
    }
    while(fread(&registro, sizeof(Especialidad), 1, pFile) == 1)
    {
        if(registro.getId() == id){
             return pos;
        }
        pos++;
    }
    fclose(pFile);

    return -1;
}
Especialidad EspecialidadesArchivo::Leer(int pos)
{
    Especialidad registro;
    FILE *pFile;
    pFile = fopen(_filename.c_str(), "rb");
    if(pFile == nullptr)
    {
        return registro;
    }
    fseek(pFile, sizeof(Especialidad) * pos, SEEK_SET);
    fread(&registro, sizeof(Especialidad), 1, pFile);
    fclose(pFile);
    return registro;
}
Especialidad EspecialidadesArchivo::buscarEspecalidad(int id)
{
    Especialidad especialidad;
    int pos = buscar(id);

    if(pos == -1){

        return Especialidad();
    }
    especialidad = Leer(pos);
    return especialidad;
}
