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

    int menu_option = 0;
    while (menu_option!=5)
    {
        std::cout << "Co chcialbys wyszukac?" << std::endl;
        std::cout << "1 - Pociagi pomiedzy stacjami   --> podajac: stacje" << std::endl;//PRAWIE GOTOWE!
        std::cout << "2 - Dostepne relacje pociagow   --> podajac: stacje, oraz godziny przyjazdu/odjazdu" << std::endl;//BARDZO NIE GOTOWE!
        std::cout << "3 - Klase pociagu               --> podajac: nazwe pociagu" << std::endl; //GOTOWE!
        std::cout << "4 - Dni kursowania pociagu      --> podajac: nazwe pociagu" << std::endl;//GOTOWE!
        std::cout << "5 - Wyjscie z programu" << std::endl<<std::endl;
        std::cout<<">";
        std::cin >> menu_option;
        if (menu_option == 1)
        {
            std::cout << "\nPodaj nazwe stacji poczatkowej:" << std::endl;
            std::string stacja_poczatkowa;
            std::cin >> stacja_poczatkowa;
            std::cout << "\nPodaj nazwe stacji koncowej:" << std::endl;
            std::string stacja_koncowa;
            std::cin >> stacja_koncowa;
            std::vector<Route> v;
            v = find_tour(find_station(stacja_poczatkowa), find_station(stacja_koncowa));

            for (auto i : v)
            {
                std::vector<int> d_h=i.get_departure_hour();
                auto d_m=i.get_departure_minute();
                auto a_h=i.get_arrival_hour();
                auto a_m=i.get_arrival_minute();

                std::cout <<"\nNazwa pociagu:"<< i.get_train_name() << std::endl;
                std::cout<<"Ze stacji "<<stacja_poczatkowa<<" odjezdza o godzinie: "<<d_h[0]<<":"<<d_m[0]<<std::endl;
                std::cout<<"Na stacje "<<stacja_koncowa<<" przyjezdza o godzinie: "<<a_h[a_h.size()]<<":"<<a_m[a_m.size()]<<std::endl;
                std::cout<<"Kursuje w dniach: "<<human_day_representation(i.get_train_days())<<std::endl;
            }
            std::cout << "" << std::endl;
        }
        if (menu_option == 2)
        {
            std::cout << "\nPodaj nazwe stacji poczatkowej." << std::endl;
            std::string stacja_poczatkowa;
            std::cin >> stacja_poczatkowa;
            std::cout << "\nPodaj nazwe stacji koncowej" << std::endl;
            std::string stacja_koncowa;
            std::cin >> stacja_koncowa;
            std::cout << "\nPodaj godzine i minute odjazdu" << std::endl;
            int departure_hour;
            int departure_minute;
            std::cin >> departure_hour;
            std::cin >> departure_minute;
            std::cout << "\nPodaj dzien kursowania" << std::endl;
            int day;
            std::cin >> day;
            std::cout << "\nPodaj godzine przyjazdu" << std::endl;
            int arrival_hour;
            int arrival_minute;
            std::cout << "\nPodaj klase pociagu" << std::endl;
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
        if (menu_option == 3)
        {
            std::cout << "\nPodaj nazwe pociagu:" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout <<"\nPociag: "<< name << std::endl;
            std::cout <<"Kursuje w klasie: "<< human_class_representation(find_class(name)) << std::endl;
            std::cout << "" << std::endl;
        }
        if (menu_option == 4)
        {
            std::cout << "\nPodaj nazwe pociagu" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout <<"\nPociag: "<< name << std::endl;
            std::cout <<"Kursuje w dniach: "<< human_day_representation(find_operating_day(name)) << std::endl;
            std::cout << "" << std::endl;
        }
        if (menu_option!=1 and menu_option!=2 and menu_option!=3 and menu_option!=4 and menu_option!=5)
        {
            std::cout << "\nNieprawidlowe dzialanie" << std::endl;
        }
    }

         return 0;
}
