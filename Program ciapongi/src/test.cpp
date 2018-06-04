//
// Created by Kuba on 04.06.2018.
//

#include "ciapong.hpp"

//TESTY
// testy beda wykonuwane w main z powodu nie działania Unitestów w Clionie(brak instalacji)





//TEST find_station - funkcja wyszukuje stacje po imieniu i wzraca obiekt stacja
while(1){
    std::cout<<"Test funkcji find_station\n"<<std::endl;
    std::cout<<"...\n"<<std::endl;
    Station s = find_station("Lublin");
    if(s.getNameStation() == "Lublin")
    {
        std::cout<<"100% completed, test is passed!!!\n"<<std::endl;
    }
    else
    {
        std::cout<<"TEST is not passed\n"<<std::endl;
    }


//TEST find_class - funkcja wyszukuje rodzaj klasy pociagu po podaniu jego nazwy
    std::cout<<"Test funkcji find_class\n"<<std::endl;
    auto a = find_class("Janusz");
    if(a == 2)
    {
        std::cout<<"100% completed, test is passed!!!\n"<<std::endl;
    }
    else
    {
        std::cout<<"TEST is not passed\n"<<std::endl;
    }

//TEST find_tour - funkcja zwraca obiekt tour, do funkcji podajemy dwa obiekty stacje poczatkowa i koncowa
    std::cout<<"Test funkcji find_tour\n"<<std::endl;
    Station s1 = find_station("Lublin");
    Station s2 = find_station("Kraków");
    std::vector<Route> b = find_tour(s1,s2);
    if(b[1].get_initial() == s1) //nie wiem czemu blad
    {
        std::cout<<"100% completed, test is passed!!!\n"<<std::endl;
    }
    else
    {
        std::cout<<"TEST is not passed\n"<<std::endl;
    }

//TEST check_train -





}