#include "ciapong.hpp"
#include <iostream>


int main(){
std::cout<< "       _____    __ __    ____  ____  _____   ______    _____    ____  ______"<<std::endl
         <<"      / /   |  / //_/   / __ \\/ __ \\/__  /  / ____/   / /   |  / __ \\/ ____/"<<std::endl
         <<" __  / / /| | / ,<     / /_/ / /_/ /  / /  / __/ __  / / /| | / / / / __/   "<<std::endl
         <<"/ /_/ / ___ |/ /| |   / ____/ _, _/  / /__/ /___/ /_/ / ___ |/ /_/ / /___   "<<std::endl
         <<"\\____/_/  |_/_/ |_|  /_/   /_/ |_|  /____/_____/\\____/_/  |_/_____/_____/   "<<std::endl;
         std::cout<<std::endl<<std::endl<<"PLANER PODROZY NR. 1 NA KSIEZYCU"<<std::endl;
         std::cout<<std::endl<<"---------------------------------------------------------------"<<std::endl;

    int wybor = 0;
    while (wybor!=5)
    {
        std::cout << "Co chcesz zrobic?" << std::endl;
        std::cout << "1 - Znajdz wszystkie pociagi na danej trasie." << std::endl;
        std::cout << "2 - Znajdz pociagi na danej trasie o okreslonych czasach przyjazdu/odjazdu." << std::endl;
        std::cout << "3 - Znajdz klase pociagu." << std::endl;
        std::cout << "4 - Znajdz dni kursowania pociagu." << std::endl;
        std::cout << "5 - Zakoncz dzialanie programu." << std::endl;
        std::cin >> wybor;
        if (wybor == 1)
        {
            std::cout << "Podaj nazwe stacji poczatkowej." << std::endl;
            std::string stacja_poczatkowa;
            std::cin >> stacja_poczatkowa;
            std::cout << "Podaj nazwe stacji koncowej" << std::endl;
            std::string stacja_koncowa;
            std::cin >> stacja_koncowa;
            std::vector<Route> v;
            v = find_tour(find_station(stacja_poczatkowa), find_station(stacja_koncowa));
            for (auto i : v)
            {
                std::cout << i.get_train_name() << std::endl;
            }
            std::cout << "" << std::endl;
        }
        if (wybor == 2)
        {
            std::cout << "Podaj nazwe stacji poczatkowej." << std::endl;
            std::string stacja_poczatkowa;
            std::cin >> stacja_poczatkowa;
            std::cout << "Podaj nazwe stacji koncowej" << std::endl;
            std::string stacja_koncowa;
            std::cin >> stacja_koncowa;
            std::cout << "Podaj godzine i minute odjazdu" << std::endl;
            int departure_hour;
            int departure_minute;
            std::cin >> departure_hour;
            std::cin >> departure_minute;
            std::cout << "Podaj dzien kursowania" << std::endl;
            int day;
            std::cin >> day;
            std::cout << "Podaj godzine przyjazdu" << std::endl;
            int arrival_hour;
            int arrival_minute;
            std::cout << "Podaj klase pociagu" << std::endl;
            int clasa;
            std::cin >> clasa;
            std::cin >> arrival_hour;
            std::cin >> arrival_minute;
            std::vector<Route> v;
            v = filter_out_routes(find_station(stacja_poczatkowa), find_station(stacja_koncowa), day, arrival_minute, arrival_hour, departure_minute, departure_hour, clasa);
            for (auto i : v)
            {
                std::cout << i.get_train_name() << std::endl;
            }
            std::cout << "" << std::endl;
        }
        if (wybor == 3)
        {
            std::cout << "Podaj nazwe pociagu" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << find_class(name) << std::endl;
            std::cout << "" << std::endl;
        }
        if (wybor == 4)
        {
            std::cout << "Podaj nazwe pociagu" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << find_operating_day(name) << std::endl;
            std::cout << "" << std::endl;
        }
        if (wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4 && wybor!=5)
        {
            std::cout << "Nieprawidlowe dzialanie" << std::endl;
        }
    }

         return 0;
}
