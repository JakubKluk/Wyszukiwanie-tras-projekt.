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
    Train(std::string name, double amount,int days, double speedMax, double amount_members, double firstclass, double secondclass, std::string accessWIFI, std::string tours) : _name(name), _amount(amount), _days(days),  _speedMax(speedMax), _amount_members(amount_members), _firstclass(firstclass), _secondclass(secondclass), _accessWIFI(accessWIFI), _tours(tours) {}
    std::string get_name(){ return  _name;}
    double get_amount() const {return _amount;} //liczba pociagow, ktora dysponujemy
    double get_speedMax()const{return _speedMax;} //moze byc uzyte do wyznaczenia czasu trwania podrozy
    double get_amount_members()const{return _amount_members;} //ilosc doczepianych wagonow
    double get_firstclass()const{return _firstclass;} //ilosc miejsc w klasie pierwszej
    double get_secondclass()const{return _secondclass;} //ilosc miejsc w klasie drugiej
    std::string get_accessWIFI()const{return _accessWIFI;} //dostep do wifi
    std::string get_alltours()const{return _tours;} //zwraca wszystkie trasy tego pociagu(ta metode mozna zmienic jak cos)
private:
    std::string _name;
    double _amount;
    int _days;
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
/*
class Route : public Train, public Station {
public:
    Route(Station initial, Station Final, std::vector<int> departure, std::vector<int> arrival, float distance, std::string name, Train train) : _initial(initial), _final(Final), _departure(departure), _arrival(arrival), _distance(distance), _name(name), _train(Train) {}
    Station get_initial() const {return _initial;}   //Zwraca obiekt klasy 'Station' odwołujący się do stacji początkowej.
    Station get_final() const {return _final;}      //Zwraca obiekt klasy 'Station' odwołujący się do stacji końcowej.
    std::vector<int> get_departure() const {return _departure;}      //Zwraca godzinę odjazdu.
    std::vector<int> get_arrival() const {return _arrival;}      //Zwraca godzinę przyjazdu.
    float get_distance() const {return _distance;}        //Zwraca odległość.
    std::string get_name() const {return _name;}        //Zwraca nazwę pociągu.
    Train get_train() const {return _train;}        //Zwraca obiekt klasy 'train' kursujący na tej trasie.
private:
    Station _initial;
    Station _final;
    std::vector<int> _departure;
    std::vector<int> _arrival;
    std::string _distance;
    std::string _name;
    Train _train;
};
 */

void find_tour(Station _start, Station _end);//funkcja wyszukuje danej trasy za pomoca informacji o stacji poczatkowej i koncowej

#endif //PROGRAM_CIAPONGI_CIAPONG_HPP
