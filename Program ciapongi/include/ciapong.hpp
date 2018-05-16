//
// Created by Kuba on 16.05.2018.
//

#ifndef PROGRAM_CIAPONGI_CIAPONG_HPP
#define PROGRAM_CIAPONGI_CIAPONG_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class Train
{
public:
    Train(std::string name, double speedMax, double liczba_czlonow, double firstclass, double secondclass, std::string accessWIFI, std::string tours) : _name(name), _speedMax(speedMax), _liczba_czlonow(liczba_czlonow), _firstclass(firstclass), _secondclass(secondclass), _accessWIFI(accessWIFI), _tours(tours) {}
    std::string get_name(){ return  _name;};
    double get_ilosc();
    double get_speedMax();
    double get_liczba_czlonow();
    double get_firstclass();
    double get_secondclass();
    std::string get_accessWIFI();
    std::string get_alltours();
private:
    std::string _name;
    double _speedMax;
    double _liczba_czlonow;
    double _firstclass;
    double _secondclass;
    std::string _accessWIFI;
    std::string _tours;
};

class Station
{
public:
    Station(int number, std::string name_s):_number(number),_name_s(name_s){} //Tworzy obiekt stacji
    int getNumber(){return _number;} //Zwraca numer staci
    std::string getNameStation(){return _name_s;} //Zwraca nazwę stacji
private:
    int _number;
    std::string _name_s;
};

Station find_station(std::string name_to_find);

class Trasa
{
public:
    Trasa(stacja poczatkowa, stacja koncowa) : _poczatkowa(poczatkowa), _koncowa(koncowa)
    {
       std::fstream plik;
       std::string stacja1;
       std::string stacja2;
       std::ostringstream oss;
       std::ostringstream oss2;
       std::string pocz;
       plik.open("Trasa - baza danych.txt", ios::in);
       if(plik.good() == true)
       {
            while(!plik.eof())
            {
                getline(plik, pocz);
                if(pocz == "Z:")
                {
                    getline(plik, stacja1);
                }
                if(stacja1 == _poczatkowa.getNameStation())
                {
                    getline(plik, pocz);
                    getline(plik, stacja2);
                    if(stacja2 == _koncowa.getNameStation())
                    {
                        getline(plik, pocz);
                        getline(plik, pocz);
                        oss << pocz << ":";
                        getline(plik, pocz);
                        oss << pocz;
                        _odjazd = oss.str();
                        getline(plik, pocz);
                        getline(plik, pocz);
                        oss2 << pocz << ":";
                        getline(plik, pocz);
                        oss2 << pocz
                        _przyjazd = oss2.str();
                        getline(plik, pocz);
                        getline(plik, pocz);
                        _odleglosc = pocz;
                        getline(plik, pocz);
                        getline(plik, pocz);
                        _nazwa_pociagu = pocz;
                    }
                }
            }
       }
    }
    std::string get_pocz() const {return _poczatkowa;}
    std::string get_konc() const {return _koncowa;}
    std::string get_odjazd() const {return _odjazd;}
    std::string get_przyjazd() const {return _przyjazd;}
    std::string get_odleglosc() const {return _odleglosc;}
    std::string get_pociag() const {return _nazwa_pociagu;}
private:
    Stacja _poczatkowa;
    Stacja _koncowa;
    std::string _odjazd;
    std::string _przyjazd;
    std::string _odleglosc;
    std::string _nazwa_pociagu;
    Train _rodzaj;
};



#endif //PROGRAM_CIAPONGI_CIAPONG_HPP
