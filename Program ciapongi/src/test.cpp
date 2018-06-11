//
// Created by Kuba on 04.06.2018.
//

#include "ciapong.hpp"

//TESTY
// testy beda wykonuwane w main z powodu nie działania Unitestów w Clionie(brak instalacji)

int main() {


/*
//TEST find_station - funkcja wyszukuje stacje po imieniu i wzraca obiekt stacja
    while (true) {
        std::cout << "Test funkcji find_station\n" << std::endl;
        std::cout << "...\n" << std::endl;
        Station s = find_station("Lublin");
        if (s.getNameStation() == "Lublin") {
            std::cout << "100% completed, test is passed!!!\n" << std::endl;
        } else {
            std::cout << "TEST is not passed\n" << std::endl;
        }


//TEST find_class - funkcja wyszukuje rodzaj klasy pociagu po podaniu jego nazwy
        std::cout << "Test funkcji find_class\n" << std::endl;
        auto a = find_class("Janusz");
        if (a == 2) {
            std::cout << "100% completed, test is passed!!!\n" << std::endl;
        } else {
            std::cout << "TEST is not passed\n" << std::endl;
        }

//TEST find_tour - funkcja zwraca obiekt tour, do funkcji podajemy dwa obiekty stacje poczatkowa i koncowa
        std::cout << "Test funkcji find_tour\n" << std::endl;
        Station s1 = find_station("Lublin");
        Station s2 = find_station("Krakow_Glowny");
        std::vector<Route> b = find_tour(s1, s2);
        if (b[1].get_begin_station_name() == "Lublin")
        {
            std::cout << "100% completed, test is passed!!!\n" << std::endl;
        } else {
            std::cout << "TEST is not passed\n" << std::endl;
        }

//TEST filter_out_routes funkcja zwraca vector Routów

        auto a1 = find_station('Lublin');
        auto a2 = find_station('Tarnow');
        int days = 1111111;
        //godziny u minuty wpise od razu do funckji
        auto routes_filter = filter_out_routes(a1,a2,days,15,10,16,10,2);
        if(routes_filter[0].get_begin_station_name() == 'Lublib')
        {
            std::cout<<'100% completed, test is passed!!!\n'<<std::endl;
        } else{
            std::cout<<'TEST is not passed\n'<<std::endl;
        }
    }

//TEST find_operating_day

        auto b = find_operating_day('Janusz');
        if(b==1111111)
        {
            std::cout<<'100% completed, test is passed!!!\n'<<std::endl;
        }else{
            std::cout<<'TEST is not passed\n'<<std::endl;
        }

}
 */