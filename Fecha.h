#pragma once
#include <string>

class Fecha
{
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    int getDia();
    int getMes();
    int getAnio();
    std::string toString();
    friend std::istream& operator>>(std::istream& in, Fecha& fecha);

private:

    int _dia;
    int _mes;
    int _anio;

    ///METODOS PARA VALIDAR LA FECHA
    bool validar();
    bool esValidoDia();
    bool esValidoMes();
    bool esValidoAnio();
    bool esBisiesto();




};
