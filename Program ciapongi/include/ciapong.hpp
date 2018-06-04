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

class Route {
public:
    Route(int begin_number,std::string begin_name,int end_number,std::string end_name, std::vector<int>& departure_hour,std::vector<int>& departure_minute, std::vector<int>& arrival_hour, std::vector<int>& arrival_minute, float distance, std::string train_name,int train_classa) : _begin_number(begin_number),_begin_name(begin_name),_end_number(end_number),_end_name(end_name), _departure_hour(departure_hour),_departure_minute(departure_minute), _arrival_hour(arrival_hour), _arrival_minute(arrival_minute), _distance(distance), _train_name(train_name),_train_classa(train_classa) {}
    Station get_initial() const {return Station (_begin_number,_begin_name);}   //Zwraca obiekt klasy 'Station' odwołujący się do stacji początkowej.
    Station get_final() const {return Station (_end_number,_end_name);}      //Zwraca obiekt klasy 'Station' odwołujący się do stacji końcowej.
    std::vector<int> get_departure_hour() const {return _departure_hour;}      //Zwraca godzinę odjazdu.
    std::vector<int> get_departure_minute() const {return _departure_minute;}      //Zwraca minutę odjazdu.
    std::vector<int> get_arrival_hour() const {return _arrival_hour;}      //Zwraca godzinę przyjazdu.
    std::vector<int> get_arrival_minute() const {return _arrival_minute;}      //Zwraca godzinę przyjazdu.
    float get_distance() const {return _distance;}        //Zwraca odległość.
    Train get_train() const {return Train(_train_name,_train_classa);}        //Zwraca obiekt klasy 'Train' kursujący na tej trasie.
private:
    std::vector<int> _departure_hour;
    std::vector<int> _departure_minute;
    std::vector<int> _arrival_hour;
    std::vector<int> _arrival_minute;
    float _distance;
    int _begin_number;              //numer stacji początkowej
    std::string _begin_name;        //nazwa stacji początkowej
    int _end_number;                //numer stacji końcowej
    std::string _end_name;          //nazwa stacji końcowej
    std::string _train_name;
    int _train_classa;


};


std::vector<Route> find_tour(Station _start, Station _end);//funkcja wyszukuje danej trasy za pomoca informacji o stacji poczatkowej i koncowej
int find_class(const std::string& name);
void check_train(std::string start, std::string end, int day, int time, int trainclass );

#endif //PROGRAM_CIAPONGI_CIAPONG_HPP
