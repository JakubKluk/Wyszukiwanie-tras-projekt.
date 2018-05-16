//
// Created by Kuba on 16.05.2018.
//

#ifndef PROGRAM_CIAPONGI_CIAPONG_HPP
#define PROGRAM_CIAPONGI_CIAPONG_HPP

#include <iostream>

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


#endif //PROGRAM_CIAPONGI_CIAPONG_HPP
