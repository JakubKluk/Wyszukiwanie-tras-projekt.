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
#include <sstream>

class Train
{
public:
    Train(std::string name, int classa, int days) : _name(name), _classa(classa),_days(days) {}
    std::string getName(){ return  _name;}                 //Zwraca nazwę pociągu
    int getClass(){ return _classa;}                       //Zwraca klasę pociągu
    int getDays(){ return  _days;}                         //Zwraca dni kursowania pociągu w formie "0100001"
private:
    std::string _name;
    int _days;
    int _classa;
};

class Station
{
public:
    Station(int number, std::string name_s):_number(number),_name_s(name_s){} //Tworzy obiekt stacji
    int getNumber(){return _number;}                    //Zwraca numer staci
    std::string getNameStation(){return _name_s;}       //Zwraca nazwę stacji
private:
    int _number;
    std::string _name_s;
};

class Route {
public:
    Route(int begin_number,std::string begin_name,int end_number,std::string end_name, std::vector<int>& departure_hour,std::vector<int>& departure_minute, std::vector<int>& arrival_hour, std::vector<int>& arrival_minute, float distance, std::string train_name,int train_classa, int train_days) : _begin_number(begin_number),_begin_name(begin_name),_end_number(end_number),_end_name(end_name), _departure_hour(departure_hour),_departure_minute(departure_minute), _arrival_hour(arrival_hour), _arrival_minute(arrival_minute), _distance(distance), _train_name(train_name),_train_classa(train_classa),_train_days(train_days) {}
    int get_begin_station_number() const {return _begin_number;}                    //Zwraca numer stacji początkowej
    std::string get_begin_station_name() const {return _begin_name;}                //Zwraca nazwę stacji początkowej
    int get_end_station_number() const {return _end_number;}                        //Zwraca numer stacji końcowej
    std::string get_end_station_name() const {return _end_name;}                    //Zwraca nazwę stacji końcowej
    std::vector<int> get_departure_hour() const {return _departure_hour;}           //Zwraca godzinę odjazdu.
    std::vector<int> get_departure_minute() const {return _departure_minute;}       //Zwraca minutę odjazdu.
    std::vector<int> get_arrival_hour() const {return _arrival_hour;}               //Zwraca godzinę przyjazdu.
    std::vector<int> get_arrival_minute() const {return _arrival_minute;}           //Zwraca godzinę przyjazdu.
    float get_distance() const {return _distance;}                                  //Zwraca odległość.
    std::string get_train_name() const { return  _train_name;}                      //Zwraca nazwę pociągu
    int get_train_class() const {return _train_classa;}                             //Zwraca klasę pociągu
    int get_train_days() const { return _train_days;}                               //Zwraca dni kursowania pociągu
private:
    std::vector<int> _departure_hour;
    std::vector<int> _departure_minute;
    std::vector<int> _arrival_hour;
    std::vector<int> _arrival_minute;
    float _distance;
    int _begin_number;
    std::string _begin_name;
    int _end_number;
    std::string _end_name;
    std::string _train_name;
    int _train_classa;
    int _train_days;
};

Station find_station(std::string name_to_find);
/* Funkcja otrzymuje: Nazwę stacji do znalezienia w pliku
 * Działanie: Wyszukuje nazwę stacji oraz jej numer
 * Funkcja zwraca: obiekt typu "Station" który zawiera nazwę i numer znalezionej stacji,jesli nie znalazł s.getNumber=0 */

Train find_train(std::string name_to_find);
/* Funkcja otrzymuje: Nazwę pociagu do znalezienia w pliku
 * Działanie: Wyszukuje nazwę pociagu,klase oraz dni kursowania
 * Funkcja zwraca: obiekt typu "Train" zawierajacy nazwie dni kursowania i klase ,jesli nie znalazł t.getNumber=0 */

std::vector<Route> find_tour(Station _start, Station _end);
/* Funkcja otrzymuje: dwa obiekty typu "Station" (początkową i końcową)
 * Działanie: przeszukuje plik pod zadanymi warunkami stacji początkowej i końcowej(bez filtrowania)
 * Funkcja zwraca: wektor obiektów typu "Route" ze wszystkimi pociągami na przekazanej trasie */

int find_class(const std::string& name);
/* Funkcja otrzymuje: nazwę pociągu
 * Działanie: Wyszukuje w pliku jakiej klasy jest pociąg (TLK/IC/EIC/EIP)
 * Funkcja zwraca: zmienną typu "int" ze znalezioną klasą (odpowiadającą liczbę 1-TLK,2-IC,3-EIC,4-EIP) */

std::vector<Route> filter_out_routes(Station start, Station end, int day, int arrival_minute,int arrival_hour,int departure_minute, int departure_hour, int train_class );
/* Funkcja otrzymuje: Obiekty typu "Station" stacje początkową i końcową, dni w które kursuje dany pociąg w formie "1111100" typu int, minutę i godzinę przyjazdu oraz odjazdu(int-y),klasę pociągu(int)
 * Działanie: filtruje wszystkie pociągi wedłóg zadanych parametrów
 * Funkcja zwraca: wektor obiektów typu "Route" ze wszystkimi pociągami na zadanej trasie */

int find_operating_day(std::string train_name);
/* Funkcja otrzymuje: nazwę pociągu
 * Działanie: funkcja wyszukuje w pliku dni w jakich pociąg kursuje
 * Funkcja zwraca: dni w jakie pociąg kursuje w formie "0000011" typu int */

std::string human_day_representation(int course_days );
/* Funkcja otrzymuje: dni kursowania w formie "1111100"
 * Działanie: funkcja konwertuje liczby na reprezentację tekstową zrozumiałą dla człowieka
 * Funkcja zwraca: dni w jakie pociąg kursuje w formie napisu typu string */

std::string human_class_representation(int class_of_the_train);
/* Funkcja otrzymuje: klasę pociągu w formie liczby
 * Działanie: funkcja konwertuje liczby na reprezentację tekstową zrozumiałą dla człowieka
 * Funkcja zwraca: klasę pociągu w formie napisu typu string */

#endif //PROGRAM_CIAPONGI_CIAPONG_HPP
