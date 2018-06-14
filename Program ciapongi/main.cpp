#include "ciapong.hpp"
#include <iostream>
#include <winnt.h>
#include <afxres.h>


int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    std::cout<< "       _____    __ __    ____  ____  _____   ______    _____    ____  ______"<<std::endl
             <<"      / /   |  / //_/   / __ \\/ __ \\/__  /  / ____/   / /   |  / __ \\/ ____/"<<std::endl
             <<" __  / / /| | / ,<     / /_/ / /_/ /  / /  / __/ __  / / /| | / / / / __/   "<<std::endl
             <<"/ /_/ / ___ |/ /| |   / ____/ _, _/  / /__/ /___/ /_/ / ___ |/ /_/ / /___   "<<std::endl
             <<"\\____/_/  |_/_/ |_|  /_/   /_/ |_|  /____/_____/\\____/_/  |_/_____/_____/   "<<std::endl;
    SetConsoleTextAttribute(hConsole, 3);
    std::cout<<std::endl<<std::endl<<"PLANER PODROZY NR. 1 NA KSIEZYCU"<<std::endl;
    std::cout<<std::endl<<"---------------------------------------------------------------"<<std::endl;

    std::string menu_option = "0";
    while (menu_option!="5")
    {
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "Co chcia\210by\230 wyszuka\206?" << std::endl;
        std::cout << "1 - Poci\245gi pomi\251dzy stacjami   --> podaj\245c: stacj\251" << std::endl;//PRAWIE GOTOWE!
        std::cout << "2 - Dost\251pne relacje poci\245g\242w   --> podaj\245c: stacj\251, oraz godziny przyjazdu/odjazdu" << std::endl;//BARDZO NIE GOTOWE!
        std::cout << "3 - Klas\251 poci\245gu               --> pod\245jac: nazw\251 poci\245gu" << std::endl; //GOTOWE!
        std::cout << "4 - Dni kursowania poci\245gu      --> podaj\245c: nazw\251 poci\245gu" << std::endl;//GOTOWE!
        std::cout << "5 - Wyj\230cie z programu" << std::endl<<std::endl;
        std::cout<<">";
        std::cin >> menu_option;
        while (menu_option!="help" and menu_option!="5") {
            if (menu_option == "1") {
                Station start_st(0, "");
                Station finish_st(0, "");
                do {
                    std::cout << "\nPodaj nazw\251 stacji pocz\245tkowej:" << std::endl;
                    std::string stacja_poczatkowa;
                    std::cin >> stacja_poczatkowa;
                    if(is_number(stacja_poczatkowa)) {
                        SetConsoleTextAttribute(hConsole, 6);
                        std::cout << "ERROR: Nie znaleziono stacji, lub jest b\210\245d w pisowni!" << std::endl;
                        SetConsoleTextAttribute(hConsole, 15);
                        continue;
                    }
                    start_st = find_station(stacja_poczatkowa);
                    if (start_st.getNumber() == 0) {
                        SetConsoleTextAttribute(hConsole, 6);
                        std::cout << "ERROR: Nie znaleziono stacji, lub jest b\210\245d w pisowni!" << std::endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                } while (start_st.getNumber() == 0);

                do {
                    std::cout << "\nPodaj nazw\251 stacji ko\344cowej:" << std::endl;
                    std::string stacja_koncowa;
                    std::cin >> stacja_koncowa;
                    if(is_number(stacja_koncowa)) {
                        SetConsoleTextAttribute(hConsole, 6);
                        std::cout << "ERROR: Nie znaleziono stacji, lub jest b\210\245d w pisowni!" << std::endl;
                        SetConsoleTextAttribute(hConsole, 15);
                        continue;
                    }
                    finish_st = find_station(stacja_koncowa);
                    if (finish_st.getNumber() == 0) {
                        SetConsoleTextAttribute(hConsole, 6);
                        std::cout << "ERROR: Nie znaleziono stacji, lub jest b\210\245d w pisowni!" << std::endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                } while (finish_st.getNumber() == 0);
                std::vector<Route> v;
                v = find_tour(start_st, finish_st);

                if(v[0].get_begin_station_number()==0){
                    SetConsoleTextAttribute(hConsole, 6);
                    std::cout<<"ERROR: Nie ma poci\245gu na zadaniej trasie!"<<std::endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    continue;
                }
                int j=0;
                for (auto i : v) {
                    auto d_h = i.get_departure_hour();
                    auto d_m = i.get_departure_minute();
                    auto a_h = i.get_arrival_hour();
                    auto a_m = i.get_arrival_minute();
                    std::cout << "\nNazwa poci\245gu: " ;
                    SetConsoleTextAttribute(hConsole, 9);
                    std::cout<< i.get_train_name() << std::endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "Ze stacji " << start_st.getNameStation() << " odjezdza o godzinie: " ;
                    SetConsoleTextAttribute(hConsole, 2);
                    std::cout<< d_h[j] << ":" << d_m[j] << std::endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    std::cout << "Na stacj\251 " << finish_st.getNameStation() << " przyjezdza o godzinie: ";
                    SetConsoleTextAttribute(hConsole, 2);
                    std::cout << a_h[a_h.size()-1] << ":" << a_m[a_m.size()-1] << std::endl;
                    SetConsoleTextAttribute(hConsole, 15);

                    std::cout << "Kursuje w dniach: " ;
                    SetConsoleTextAttribute(hConsole, 5);
                    std::cout<<human_day_representation(i.get_train_days()) << std::endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    j++;
                }
                std::cout << "" << std::endl;
            }
            if (menu_option == "2") {
                std::cout << "\nPodaj nazw\251 stacji pocz\245tkowej." << std::endl;
                std::string stacja_poczatkowa;
                std::cin >> stacja_poczatkowa;
                std::cout << "\nPodaj nazw\251 stacji ko\344cowej" << std::endl;
                std::string stacja_koncowa;
                std::cin >> stacja_koncowa;
                std::cout << "\nPodaj godzin\251 i minut\251 odjazdu" << std::endl;
                int departure_hour;
                int departure_minute;
                std::cin >> departure_hour;
                std::cin >> departure_minute;
                std::cout << "\nPodaj dzie\344 kursowania" << std::endl;
                int day;
                std::cin >> day;
                std::cout << "\nPodaj godzin\251 przyjazdu" << std::endl;
                int arrival_hour;
                int arrival_minute;
                std::cout << "\nPodaj klas\251 poci\245gu" << std::endl;
                int clasa;
                std::cin >> clasa;
                std::cin >> arrival_hour;
                std::cin >> arrival_minute;
                std::vector<Route> v;
                v = filter_out_routes(find_station(stacja_poczatkowa), find_station(stacja_koncowa), day,
                                      arrival_minute, arrival_hour, departure_minute, departure_hour, clasa);
                for (auto i : v) {
                    std::cout << i.get_train_name() << std::endl;
                }
                std::cout << "" << std::endl;
            }
            if (menu_option == "3") {
                Train t("",0,0000000);
                do {
                    std::cout << "\nPodaj nazw\251 poci\245gu:" << std::endl;
                    std::string name;
                    std::cin >> name;
                    if(is_number(name)) {
                        SetConsoleTextAttribute(hConsole, 6);
                        std::cout << "ERROR: Nie znaleziono poci\245gu, lub jest b\210\245d w pisowni!" << std::endl;
                        SetConsoleTextAttribute(hConsole, 15);
                        continue;
                    }
                    t=find_train(name);
                    if (t.getClass() == 0) {
                        SetConsoleTextAttribute(hConsole, 6);
                        std::cout << "ERROR: Nie znaleziono poci\245gu, lub jest b\210\245d w pisowni!" << std::endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                } while (t.getClass() == 0);
                std::cout << "\nPoci\245g: ";
                SetConsoleTextAttribute(hConsole, 9);
                std::cout<< t.getName() << std::endl;
                SetConsoleTextAttribute(hConsole, 15);
                std::cout << "Kursuje w klasie: ";
                SetConsoleTextAttribute(hConsole, 4);
                std::cout<< human_class_representation(t.getClass()) << std::endl;
                SetConsoleTextAttribute(hConsole, 15);
                std::cout << "" << std::endl;
            }
            if (menu_option == "4") {
                Train t("",0,0000000);
                do {
                    std::cout << "\nPodaj nazw\251 poci\245gu:" << std::endl;
                    std::string name;
                    std::cin >> name;
                    if(is_number(name)) {
                        SetConsoleTextAttribute(hConsole, 6);
                        std::cout << "ERROR: Nie znaleziono poci\245gu, lub jest b\210\245d w pisowni!" << std::endl;
                        SetConsoleTextAttribute(hConsole, 15);
                        continue;
                    }
                    t=find_train(name);
                    if (t.getClass() == 0) {
                        SetConsoleTextAttribute(hConsole, 6);
                        std::cout << "ERROR: Nie znaleziono poci\245gu, lub jest b\210\245d w pisowni!" << std::endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                } while (t.getClass() == 0);
                std::cout << "\nPoci\245g: ";
                SetConsoleTextAttribute(hConsole, 9);
                std::cout<< t.getName() << std::endl;
                SetConsoleTextAttribute(hConsole, 15);
                std::cout << "Kursuje w dniach: ";
                SetConsoleTextAttribute(hConsole, 5);
                std::cout<< human_day_representation(t.getDays()) << std::endl;
                SetConsoleTextAttribute(hConsole, 15);
                std::cout << "" << std::endl;
            }
            if(menu_option=="TEST_PRINT_TRAIN"){
                std::fstream plik_s;
                plik_s.open("ciapongi.txt", std::ios::in);
                if(!plik_s.good())
                {
                    std::cout<<"Nie ma pliku! (ERROR EXIT:find_tour1)"<<std::endl;
                    exit(0);
                }
                std::vector<std::string> train_name;
                std::string taken_line;
                while(getline(plik_s,taken_line)){
                    if(taken_line=="NAME"){
                        getline(plik_s,taken_line);
                        train_name.push_back(taken_line);
                    }
                }
                int j=0;
                for (auto i : train_name) {
                    j++;
                    std::cout<<j<<") "<<i<<std::endl;

                }

                plik_s.close();
            }
            if (menu_option != "1" and menu_option != "2" and menu_option != "3" and menu_option != "4" and
                menu_option != "5" and menu_option != "help" and menu_option!="TEST_PRINT_TRAIN") {
                SetConsoleTextAttribute(hConsole, 6);
                std::cout << "\nNieprawid\210owe dzia\210anie (opcje:1-5), potrzebujesz pomocy? Wpisz \"help\"" << std::endl;
                SetConsoleTextAttribute(hConsole, 15);
            }else{ std::cout <<"Co chcia\210bys wyszuka\206? Opcje:1-5, Potrzebujesz pomocy? Wpisz \"help\""<<std::endl;}

            std::cin>>menu_option;

        }
    }

    return 0;
}
