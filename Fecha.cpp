#include "Fecha.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

Fecha::Fecha(){}
void Fecha::setDia(int dia) {
    _dia = dia;
}
void Fecha::setMes(int mes) {
    _mes = mes;
}
void Fecha::setAnio(int anio) {
    _anio = anio;
}
int Fecha::getDia()
{
    return _dia;
}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}

string Fecha::toString(){
    return to_string(this->_dia) + "/" + to_string(this->_mes) + "/" + to_string(this->_anio);
}

///SOBRECARGA CIN
std::istream& operator>>(std::istream& in, Fecha& fecha) {
    int dia, mes, anio;
    std::cout << "Ingrese el dia: ";
    in >> dia;
    std::cout << "Ingrese el mes: ";
    in >> mes;
    std::cout << "Ingrese el anio: ";
    in >> anio;

    fecha.setDia(dia);
    fecha.setMes(mes);
    fecha.setAnio(anio);

    fecha.validar();
    return in;
}

///METODOS PRIVADOS
void Fecha::validar()
{
    if(!esValidoDia() || !esValidoMes() || !esValidoAnio())
    {
        fechaDefault();
    }
}
void Fecha::fechaDefault()
{
    _dia = 1;
    _mes = 1;
    _anio = 1111;
}
bool Fecha::esValidoDia()
{
    int diasMeses[12] {31,28,31,30,31,30,31,31,30,31,30,31};

    if(_mes == 2)
    {
        if(esBisiesto())
        {
            diasMeses[1]++;
        }
    }
    return _dia >= 1 && _dia <= diasMeses[_mes - 1];
}
bool Fecha::esValidoMes()
{
    return _mes >= 1 && _mes <= 12;
}

bool Fecha::esValidoAnio()
{
    return _anio > 0;
}
bool Fecha::esBisiesto()
{
    return (_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0);
}
