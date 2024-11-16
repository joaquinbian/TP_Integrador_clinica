#include "Fecha.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

Fecha::Fecha(){
    this->setFechaDefault();
}

Fecha::Fecha(int dia, int mes, int anio){
    
    if(esBisiesto(anio)){
        _meses[1] = 29;
    }

    if(this->esFechaValida(dia, mes, anio)){
        this->_dia = dia;
        this->_mes = mes;
        this->_anio = anio;
    } else {
        this->setFechaDefault();
    }
}


//GETTERS
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


//SETTERS
void Fecha::setDia(int dia){

    if(this->esValidoDia(dia, this->_mes)){
        this->_dia = dia;
    } else {
        this->_dia = 1;
        std::cout << "El dia no es valido" << std::endl;
    }
}

void Fecha::setMes(int mes){
    if(this->esValidoMes(mes)){
        this->_mes = mes;
    } else {
        this->_mes = 1;
        std::cout << "El mes no es valido" << std::endl;
    }
}

void Fecha::setAnio(int anio){

    if(anio > 0){
        this->_anio = anio;
        if(esBisiesto(anio)){
            _meses[1] = 29;
        }
    } else {
        this->_anio = anio;
        std::cout << "El anio no es valido" << std::endl;
    }
}
void Fecha::setFechaDefault(){
    this->_dia = 1;
    this->_mes = 1;
    this->_anio = 2024;
}


//metodos


string Fecha::toString(){
    return to_string(this->_dia) + "/" + to_string(this->_mes) + "/" + to_string(this->_anio);
}

///SOBRECARGA CIN
std::istream& operator>>(std::istream& in, Fecha& fecha) {

    bool fechaValida=true;

    do{

    if(!fechaValida){
        std::cout << std::endl << "Fecha inválida, intente nuevamente" << std::endl << std::endl;
    }

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

    fechaValida=fecha.validar();

    }while(!fechaValida);

    return in;
}

bool operator==(Fecha &f1,  Fecha &f2) {
    if(f1.getDia() == f2.getDia() && f1.getMes() == f2.getMes() && f1.getAnio() == f2.getAnio()){
            return true;
    }
    return false;
}


///METODOS PRIVADOS

bool Fecha::esFechaValida(int dia, int mes, int anio){
    return this->esValidoDia(dia, mes) && this->esValidoMes(mes);
}

bool Fecha::esValidoDia(int dia, int mes){
    if(_meses[mes - 1] < dia){
        return false;
    } else if(dia < 1 || dia > 31){
        return false;
    }

    return true;
}

bool Fecha::esValidoMes(int mes){
    if(mes < 1 || mes > 12 ){
        return false;
    } 

    return true;
}

bool Fecha::validar()
{
    if(!esValidoDia() || !esValidoMes() || !esValidoAnio())
    {
        return false;
    }
    return true;
}

bool Fecha::esValidoDia()
{

    if(_mes == 2)
    {
        if(esBisiesto())
        {
            _meses[1] = 29;
        }
    }
    return _dia >= 1 && _dia <= _meses[_mes - 1];
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
bool Fecha::esBisiesto(int a)
{
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}
