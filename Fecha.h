#pragma once
#include <string>

class Fecha
{
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    bool esValida;
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    int getDia();
    int getMes();
    int getAnio();
    bool validar();
    std::string toString();
    friend std::istream& operator>>(std::istream& in, Fecha& fecha);
    bool operator>(Fecha f1);
    bool operator==(Fecha f1);

private:

    int _dia;
    int _mes;
    int _anio;
    int _meses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    ///METODOS PARA VALIDAR LA FECHA
    bool esValidoDia();
    bool esValidoMes();
    bool esValidoAnio();
    bool esFechaValida(int dia, int mes, int anio);
    bool esValidoDia(int dia, int mes);
    bool esValidoMes(int mes);
    void setFechaDefault();
    bool esBisiesto();
    bool esBisiesto(int anio);



};
