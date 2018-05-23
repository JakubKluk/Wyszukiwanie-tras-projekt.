#include "ciapong.hpp"
#include <iostream>


int main() {
    //PROSTY PRZYKŁADOWY PROGRAM WYUSZKIWANIA W PLIKU STACJE.TXT,
    // WYKORZYTUJĄCY STWORZENIE KLASY, JEJ METODY I FUNKCJĘ find_station
while(0) {
    std::cout << "Podaj nazwe stacji aby znalezc ja w bazie: " << std::endl;

    std::string input_name_of_station;
    std::cin >> input_name_of_station;                    //Pobiera nazwe stacji
    Station sr_station = find_station(input_name_of_station);     //<--
    //wywołuje funkcje wyszukującą (w pliku ciapong.cpp)/i zapisuje do nowostworzonego obiektu sr_station
    if (sr_station.getNumber() == 0) {
        std::cout << "Nie ma takiej stacji" << std::endl;
    }    //Jeśli funkcja nie znalazła
    else {
        std::cout << "Znaleziono: " << std::endl
                  <<                                      //Jeśli znalazła wypisuje na ekran
                  "Numer stacji: " << sr_station.getNumber() << std::endl <<
                  "Nazwa stacjii: " << sr_station.getNameStation() << std::endl;
    }
}
while(1){
    Station start_st(2,"Lublin");
    Station finish_st(4,"Warszawa_centralna");

    find_tour(start_st,finish_st);

}
    return 0;

    //PROSTY PRZYKŁADOWY PROGRAM WYUSZKIWANIA W PLIKU STACJE.TXT,
    // WYKORZYTUJĄCY STWORZENIE KLASY, JEJ METODY I FUNKCJĘ find_station

}