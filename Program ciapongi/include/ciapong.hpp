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
    Train(std::string name, double amount, double speedMax, double amount_members, double firstclass, double secondclass, std::string accessWIFI, std::string tours) : _name(name), _amount(amount),  _speedMax(speedMax), _amount_members(amount_members), _firstclass(firstclass), _secondclass(secondclass), _accessWIFI(accessWIFI), _tours(tours) {}
    std::string get_name(){ return  _name;}
    double get_amount() {return _amount;}
    double get_speedMax(){return _speedMax;}
    double get_amount_members(){return _amount_members;}
    double get_firstclass(){return _firstclass;}
    double get_secondclass(){return _secondclass;}
    std::string get_accessWIFI(){return _accessWIFI;}
    std::string get_alltours(){return _tours;}
private:
    std::string _name;
    double _amount;
    double _speedMax;
    double _amount_members;
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

class Route
public:
    Route(Station initial, Station Final) : _initial(initial), _final(Final)
    {
       std::fstream file;
       std::string station1;
       std::string station2;
       std::ostringstream oss;
       std::ostringstream oss2;
       std::string line;
       file.open("Trasa - baza danych.txt", std::ios::in);
       if(file.good() == true)
       {
            while(!file.eof())
            {
                getline(file, line);
                if(line == "Z:")
                {
                    getline(file, station1);
                }
                if(station1 == _initial.getNameStation())
                {
                    getline(file, line);
                    getline(file, station2);
                    if(station2 == _final.getNameStation())
                    {
                        getline(file, line);
                        getline(file, line);
                        oss << line << ":";
                        getline(file, line);
                        oss << line;
                        _departure = oss.str();
                        getline(file, line);
                        getline(file, line);
                        oss2 << line << ":";
                        getline(file, line);
                        oss2 << line
                        _arrival = oss2.str();
                        getline(file, line);
                        getline(file, line);
                        _distance = line;
                        getline(file, line);
                        getline(file, line);
                        _name = line;
                    }
                }
            }
       }
    }
    std::string get_initial() const {return _initial;}
    std::string get_final() const {return _final;}
    std::string get_departure() const {return _departure;}
    std::string get_arrival() const {return _arrival;}
    std::string get_distance() const {return _distance;}
    std::string get_name() const {return _name;}
private:
    Station _initial;
    Station _final;
    std::string _departure;
    std::string _arrival;
    std::string _distance;
    std::string _name;
    Train _train;
};



#endif //PROGRAM_CIAPONGI_CIAPONG_HPP
