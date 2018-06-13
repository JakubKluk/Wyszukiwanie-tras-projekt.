//
// Created by Kuba on 16.05.2018.
//


#include "ciapong.hpp"

Station find_station(std::string name_to_find){
    std::fstream plik_s;                            //nazwa którą będziemy się odwoływać do pliku
    plik_s.open("stacje.txt", std::ios::in);        //otwarcie pliku
    if(plik_s.good()==false)                          //sprawdza czy plik istnieje i zwraca true/false
    {
        std::cout<<"Nie ma pliku! (ERROR EXIT)"<<std::endl;
        exit(0);                           //wyjebuje z programu jak nie może otworzyć
    }

    std::string line;                               //odczytana linijka z pliku
    int line_nr=1;                                  //licznik numeru aktualnej linii
    while(getline(plik_s,line)){                    //getline zwraca true dopóki jest linia (do końca pliku)

        if (line==name_to_find){
            Station s(line_nr/2,name_to_find);
            plik_s.close();                         //Zamyka plik
            return s;
        }
        line_nr++;
    }
    Station s(0,"");
    plik_s.close();
    return s;
}
Train find_train(std::string name_to_find){
    std::fstream plik_s;                            //nazwa którą będziemy się odwoływać do pliku
    plik_s.open("ciapongi.txt", std::ios::in);        //otwarcie pliku
    if(plik_s.good()==false)                          //sprawdza czy plik istnieje i zwraca true/false
    {
        std::cout<<"Nie ma pliku! (ERROR EXIT)"<<std::endl;
        exit(0);                           //wyjebuje z programu jak nie może otworzyć
    }

    std::string line;                               //odczytana linijka z pliku
    while(getline(plik_s,line)){                    //getline zwraca true dopóki jest linia (do końca pliku)

        if (line==name_to_find){
            auto train_found_name=line;
            getline(plik_s,line);
            getline(plik_s,line);
            int train_class=atoi(line.c_str());
            getline(plik_s,line);
            getline(plik_s,line);
            int train_days=atoi(line.c_str());
            plik_s.close();                         //Zamyka plik
            Train t(train_found_name, train_class, train_days);
            return t;
        }
    }
    Train t("",0,0000000);
    plik_s.close();
    return t;
}


int find_class(const std::string& name)
{
    std::fstream file;                                  //nazwa służąca do odwoływania się do pliku
    file.open("ciapongi.txt", std::ios::in);            //otwieramy plik
        if(file.good()==false)
    {
        std::cout<<"Nie ma pliku! (ERROR EXIT)"<<std::endl;
                 exit(0);
    }                                                   //sprawdzamy czy otwarcie przebiegło pomyślnie, jeśli nie, kończymy program
    std::string line;
    while(getline(file, line))                          //przeszukujemy każdą linijkę pliku aż do znalezienia naszej nazwy lub końca pliku
    {
        if(line==name)
        {
            getline(file, line);                        //Każdy getline przesuwa pobieranie tekstu o jedną linijkę w dół. Po znalezieniu nazwy jesteśmy na linijce "CLASS", więc musimy przesunąć się o linijkę niżej
            getline(file, line);
            int i;
            i = std::stoi(line);                        //Konwersja std::string na int przy użyciu funkcji biblioteki standardowej
            file.close();                               //zamknięcie pliku
            return i;
        }
    }
    file.close();
    std::cout<<"Nie ma takiego pociagu! (ERROR EXIT)"<<std::endl;     //jeśli nie znajdziemy nazwy naszego pociągu, zamykamy plik i kończymy program
    exit(0);
}


std::vector<Route> find_tour(Station start, Station finish){
    std::string start_station=std::to_string(start.getNumber());    //konwertuje int na string z numerem stacji początkowej
    std::string finish_station=std::to_string(finish.getNumber());  //---//---

    std::fstream plik_s;                            //nazwa którą będziemy się odwoływać do pliku
    plik_s.open("ciapongi.txt", std::ios::in);        //otwarcie pliku
    if(!plik_s.good())                          //sprawdza czy plik istnieje i zwraca true/false
    {
        std::cout<<"Nie ma pliku! (ERROR EXIT)"<<std::endl;
        exit(0);                           //problem jak nie może otworzyć
    }

    std::string taken_line; //odczytana linijka z pliku

    std::vector<std::string> train_name;
    std::string temp_train_name;
    int start_found=0,end_found=0,is_route=0;

    while(getline(plik_s,taken_line)){
        if(taken_line=="NAME" ){
            getline(plik_s,taken_line);
            temp_train_name=taken_line;
            is_route=1;
        }
        while(is_route==1)
        {
            while(end_found!=1 and is_route==1) {
                if (taken_line == "END_STATION") { is_route = 0; }
                while (!(taken_line != "STATION" xor taken_line!="END_STATION")) { getline(plik_s, taken_line); }
                if(taken_line=="STATION"){getline(plik_s,taken_line);}
                if(taken_line==start_station){ start_found=1; }
                if(taken_line == finish_station and start_found==1){ end_found=1; }
            }
            if(start_found==1 and end_found==1) {
                train_name.push_back(temp_train_name);
                start_found=0;
                end_found=0;
            }
        }
    }
    plik_s.close();

    int classa;
    std::vector<Route> route_train;
    std::vector<int> _departure_hour;
    std::vector<int> _departure_minute;
    std::vector<int> _arrival_hour;
    std::vector<int> _arrival_minute;
    std::string _name;
    std::vector<Train> trains;
    int __departure_hour;
    int __arrival_hour;
    int __departure_minute;
    int __arrival_minute;
    plik_s.open("ciapongi.txt", std::ios::in);
    if(!plik_s.good())
    {
        std::cout<<"Nie ma pliku! (ERROR EXIT)"<<std::endl;
        exit(0);
    }
    std::string new_line; //odczytywana linijka tekstu
    for(auto i=0; i<train_name.size(); i++)
    {
        std::string _name = train_name[i];
        int days = find_operating_day(train_name[i]); //odczytuje dni w ktorych kursuje i zapisuje je w ciag liczb w postaci int
        while(getline(plik_s,new_line))
        {
            if(new_line == train_name[i])
            {
                getline(plik_s,new_line);
                if(new_line == "CLASS")
                {
                    getline(plik_s,new_line);
                    classa = atoi(new_line.c_str());
                    getline(plik_s,new_line);
                    if(new_line == start_station)
                    {
                        getline(plik_s,new_line);  //chyba dziala, to wczytuje godziny
                        getline(plik_s,new_line);
                        getline(plik_s,new_line);
                        getline(plik_s,new_line);
                        getline(plik_s,new_line);
                        std::string time_departure_hour;
                        time_departure_hour = new_line;
                        __departure_hour = atoi(time_departure_hour.c_str());
                        getline(plik_s,new_line);
                        std::string time_departure_minute;
                        time_departure_minute=new_line;
                        __departure_minute = atoi(time_departure_minute.c_str());
                        if(new_line == finish_station)
                        {
                            getline(plik_s,new_line);
                            std::string time_arrival_hour;
                            time_arrival_hour = new_line;
                            __arrival_hour = atoi(time_arrival_hour.c_str());
                            getline(plik_s,new_line);
                            std::string time_arrival_minute;
                            time_arrival_minute = new_line;
                            __arrival_minute = atoi(time_arrival_minute.c_str());
                            getline(plik_s,new_line);
                        }


                    }


                }
            }
        }
        _departure_hour.push_back(__departure_hour);
        _departure_minute.push_back(__departure_minute);
        _arrival_hour.push_back(__arrival_hour);
        _arrival_minute.push_back(__arrival_minute);
        Train new_train(_name, classa, days);
        Route new_route(start.getNumber(), start.getNameStation() ,finish.getNumber(), finish.getNameStation(), _departure_hour,_departure_minute,_arrival_hour,_arrival_minute,0,train_name[i], find_class(train_name[i]),days);
        route_train.push_back(new_route);
    }
    return  route_train;
}

int find_operating_day(std::string train_name){
    int operating_day;
    std::fstream plik;
    plik.open("ciapongi.txt", std::ios::in);
    if(plik.good()==false)                          //sprawdza czy plik istnieje i zwraca true/false
    {
        std::cout<<"Nie ma pliku! (ERROR EXIT)"<<std::endl;
        exit(0);                           //wywala z programu jak nie może otworzyć
    }
    std::string line;
    while(getline(plik,line)){
        if(line==train_name){
            while (getline(plik,line))
            {
                if(line=="DAY"){
                    getline(plik,line);
                    operating_day=atoi(line.c_str());
                    plik.close();
                    return operating_day;
                }

            }
        }
    }
    std::cout<<"Brak pociagu, nie mozna znalezc dni kursowania! (ERROR EXIT)";
    plik.close();
    exit(0);
}

std::vector<Route> filter_out_routes(Station start, Station end, int day, int arrival_minute,int arrival_hour,int departure_minute, int departure_hour, int train_class )
{
    std::vector<Route> non_filtered_out=find_tour(start, end); //tworzy wektor który przechowuje nieprzefiltrowane trasy pociągów na zadanej trasie
    std::vector<Route> filtered_out;                            //tworzy wektor który przechowuje przefiltrowane trasy pociągów
    int is_satisfy_day,is_satisfy_hour,is_satisfy_class,j;                                //Weryfikacja spełnienia warunków

    for(int i=0;i<non_filtered_out.size();i++){

        is_satisfy_day= (non_filtered_out[i].get_train_days() == day) ? 1 : 0; //sprawdza czy zgadza się dzień

        std::vector<int> arriv_min_temp=non_filtered_out[i].get_arrival_minute();
        std::vector<int> arriv_hour_temp=non_filtered_out[i].get_arrival_hour();
        std::vector<int> depar_min_temp=non_filtered_out[i].get_departure_minute();
        std::vector<int> depar_hour_temp=non_filtered_out[i].get_departure_hour();

        is_satisfy_hour= (depar_min_temp[0] <= departure_hour and depar_hour_temp[0] <= departure_minute) ? 1 : 0;      //sprawdza czy zgadza się godzina

        is_satisfy_class= (non_filtered_out[i].get_train_class()==train_class) ? 1 : 0;      //sprawdza czy zgadza się klasa pociągu

        if (is_satisfy_day and is_satisfy_hour and is_satisfy_class){
            filtered_out[j]=non_filtered_out[i];
            j++;
        }
    }
    return filtered_out;
}

std::string human_day_representation(int course_days ){
    std::ostringstream oss,iss;
    iss<<course_days;
    std::string temp_str=iss.str();
    std::vector<char> s_str(temp_str.begin(), temp_str.end());

    if(s_str[0]=='1'){ oss << "pon/";}
    if(s_str[1]=='1'){ oss<<"wt/";}
    if(s_str[2]=='1'){ oss<<"sr/";}
    if(s_str[3]=='1'){ oss<<"czw/";}
    if(s_str[4]=='1'){ oss<<"pt/";}
    if(s_str[5]=='1'){ oss<<"sob/";}
    if(s_str[6]=='1'){ oss<<"nd"; }

    return oss.str();
}

std::string human_class_representation(int class_of_the_train){
    switch (class_of_the_train){
        case 1:
            return "TLK (Twoje Linie Kolejowe)";
        case 2:
            return "IC (Intercity)";
        case 3:
            return "EIC (Express Intercity)";
        case 4:
            return "EIP (Express Intercity Premium)";
    }
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}