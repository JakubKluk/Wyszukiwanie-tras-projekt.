//
// Created by Kuba on 16.05.2018.
//

#ifndef PROGRAM_CIAPONGI_CIAPONG_HPP
#define PROGRAM_CIAPONGI_CIAPONG_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

class Train
{
public:
    Train(std::string name, int classa) : _name(name), _class(classa) {}
    Train(std::string name, double amount,int days, double speedMax, double amount_members, int classa,  std::string accessWIFI, std::string tours) : _name(name), _amount(amount), _days(days),  _speedMax(speedMax), _amount_members(amount_members), _class(classa), _accessWIFI(accessWIFI), _tours(tours) {}
    std::string get_name(){ return  _name;}
    double get_amount() const {return _amount;} //liczba pociagow, ktora dysponujemy
    double get_speedMax()const{return _speedMax;} //moze byc uzyte do wyznaczenia czasu trwania podrozy
    double get_amount_members()const{return _amount_members;} //ilosc doczepianych wagonow
    double get_class()const{return _class;} //ilosc miejsc w klasie pierwszej
    std::string get_accessWIFI()const{return _accessWIFI;} //dostep do wifi
    std::string get_alltours()const{return _tours;} //zwraca wszystkie trasy tego pociagu(ta metode mozna zmienic jak cos)
private:
    std::string _name;
    double _amount;
    int _days;
    double _speedMax;
    double _amount_members;
    int _class;
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

class Route : public Train, public Station {
public:
    Route(Station initial, Station Final, std::vector<int>& departure_hour,std::vector<int>& departure_minute, std::vector<int>& arrival_hour, std::vector<int>& arrival_minute, float distance, std::string name, Train train) : _initial(initial), _final(Final), _departure_hour(departure_hour),_departure_minute(departure_minute), _arrival_hour(arrival_hour), _arrival_minute(arrival_minute), _distance(distance), _name(name), _train(Train) {}
    Station get_initial() const {return _initial;}   //Zwraca obiekt klasy 'Station' odwołujący się do stacji początkowej.
    Station get_final() const {return _final;}      //Zwraca obiekt klasy 'Station' odwołujący się do stacji końcowej.
    std::vector<int> get_departure_hour() const {return _departure_hour;}      //Zwraca godzinę odjazdu.
    std::vector<int> get_departure_minute() const {return _departure_minute;}      //Zwraca minutę odjazdu.
    std::vector<int> get_arrival_hour() const {return _arrival_hour;}      //Zwraca godzinę przyjazdu.
    std::vector<int> get_arrival_minute() const {return _arrival_minute;}      //Zwraca godzinę przyjazdu.
    float get_distance() const {return _distance;}        //Zwraca odległość.
    std::string get_name() const {return _name;}        //Zwraca nazwę pociągu.
    Train get_train() const {return _train;}        //Zwraca obiekt klasy 'train' kursujący na tej trasie.
private:
    Station _initial;
    Station _final;
    std::vector<int> _departure_hour;
    std::vector<int> _departure_minute;
    std::vector<int> _arrival_hour;
    std::vector<int> _arrival_minute;
    float _distance;
    std::string _name;
    Train _train;
};


std::vector<Route> find_tour(Station _start, Station _end);//funkcja wyszukuje danej trasy za pomoca informacji o stacji poczatkowej i koncowej
int find_class(const std::string& name);
#endif //PROGRAM_CIAPONGI_CIAPONG_HPP
