//
// Created by Kuba on 16.05.2018.
//

#include "ciapong.hpp"

Station find_station(std::string name_to_find){
    std::fstream plik_s;                            //nazwa którą będziemy się odwoływać do pliku
    plik_s.open("stacje.txt", std::ios::in);        //otwarcie pliku
    if(plik_s.good()==false)                          //sprawdza czy plik istnieje i zwraca true/false
    {
        std::cout<<"Nie ma pliku"<<std::endl;
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

int find_class(const std::string& name)
{
    std::fstream file;                                  //nazwa służąca do odwoływania się do pliku
    file.open("ciapongi.txt", std::ios::in);            //otwieramy plik
        if(file.good()==false)
    {
        std::cout<<"Nie ma pliku"<<std::endl;
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
    std::cout<<"Nie ma takiego pociągu"<<std::endl;     //jeśli nie znajdziemy nazwy naszego pociągu, zamykamy plik i kończymy program
    exit(0);
}

std::vector<Route> find_tour(Station start, Station finish){
    std::string start_station=std::to_string(start.getNumber());    //konwertuje int na string z numerem stacji początkowej
    std::string finish_station=std::to_string(finish.getNumber());  //---//---

    std::fstream plik_s;                            //nazwa którą będziemy się odwoływać do pliku
    plik_s.open("ciapongi.txt", std::ios::in);        //otwarcie pliku
    if(!plik_s.good())                          //sprawdza czy plik istnieje i zwraca true/false
    {
        std::cout<<"Nie ma pliku"<<std::endl;
        exit(0);                           //problem jak nie może otworzyć
    }

    std::string taken_line; //odczytana linijka z pliku

    std::vector<std::string> train_name;
    std::string temp_train_name;
    int i=1,j=1,k=1;
    while(getline(plik_s,taken_line)){

        if(taken_line=="NAME" ){
            getline(plik_s,taken_line);
            temp_train_name=taken_line;
            k=0;
        }
        if(k==0) {
            do {
                getline(plik_s, taken_line);
            } while (taken_line != "STATION");
            getline(plik_s, taken_line);
            if (taken_line == start_station) {
                while (i) {

                    do {
                        getline(plik_s, taken_line);
                    } while ((taken_line != "STATION") and (taken_line != "END_STATION"));

                    if (taken_line == "END_STATION") {
                        j = i = 0;
                    } else {

                        getline(plik_s, taken_line);
                        if (taken_line == finish_station) {
                            i = 0;
                            train_name.push_back(temp_train_name);
                            std::cout<<train_name[0];
                        }
                    }
                }
                /*if (j == 1) {                                   //Pojawia sie problem taki ze nazwa jest dublowana z niewadomego wzgledu dlatego jest ona umieszczonea wyzej
                   / train_name.push_back(temp_train_name);
                    std::cout<<temp_train_name<<std::endl;
                    std::cout<<train_name[0]<<std::endl;
                }*/

            } else {
                k = 0;
            }
        } getline(plik_s,taken_line);
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
        std::cout<<"Nie ma pliku"<<std::endl;
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

int find_operating_day(std::string train_name){//Do uzupełnienia
    int operating_day=0000000;
    return operating_day;
}

std::vector<Route> filter_out_routes(Station start, Station end, int day, int arrival_minute,int arrival_hour,int departure_minute, int departure_hour, int train_class )
{
    std::vector<Route> non_filtered_out=find_tour(start, end); //tworzy wektor który przechowuje nieprzefiltrowane trasy pociągów na zadanej trasie
    std::vector<Route> filtered_out;                            //tworzy wektor który przechowuje przefiltrowane trasy pociągów
    int is_satisfy_conditions=0;                                //Weryfikacja spełnienia warunków

    for(int i=0;i<non_filtered_out.size();i++){

        if(find_operating_day(non_filtered_out[i].get_train_name())==day){
            is_satisfy_conditions=1;
        }
        else is_satisfy_conditions=0;



    }
    if (is_satisfy_conditions==1){
        return filtered_out;
    }
    else{
        std::cout<<"Brak pociagu"<<std::endl;
        exit(0);
    }
}
/*std::vector<Route> filter_out_routes(Station start, Station end, std::string day, int arrival_minute,int arrival_hour,int departure_minute, int departure_hour, int train_class ) //stacja poczatkowa-koncowa, dzien, godziny i minuty przyjazdu oraz odjazdu i klasa pociągu
{
   Route _route;
    std::vector<Route> _routes = find_tour(start, end);                  // zwraca nam trasy na wyszukiwanych stacjach
    for (auto _route:_routes) {
        std::string _name = _route.get_name();                // zwraca nam nazwe pociagu na tej trasie
        int _trainclass, _time, _day, _arrivetime;             // zmienne ktore beda porownywane do tych wpisanych na poczatku
        _trainclass = find_class(_name);     // zwrocenie klasy poprzez funkcje
        if (_trainclass == trainclass)         //tutaj bedzie sprawdzenie czy klasa pociagu zgadza sie z nasza
        {
            _day = *nazwafunkcjidooczytudnikursowania * (_name);    // zwrocenie dni kursowania poprzez funkcje
            int j=0;
            int i=1;
            while((j=0) or (i<1000000))             // sprawdza na ktorym miejscu jest nasz oczekiwany dzien podrozy
            {   i=i*10;
                if((day%i)>=1)
                    j++;
            }
            if ((_day%i)==(i/10))       //tutaj bedzie sprawdzenie czy dni zgadzaja sie z naszym dniem
            {
                _time = _route.get_departure();                       // zwrocenie czasu odjazu pociagu
                if ((_time / 100) >= (time / 100))                        //tutaj bedzie sprawdzenie czy odjazd bedzie po godzinie ktora nas interesuje
                {


                    _arrivetime = _route.get_arrival();                   //zwrocenie czasu przyjazdu do stacji docelowej

                    //jesli wszystko sie bedzie zgadzalo to wyswietli sie komunikat:
                    std::cout << " Pociag z " << start << " do " << end << " w dniu " << day << " odjezdza o godz " << _time << " i na stacji docelowej bedzie o" << _arrivetime << std::endl;
                    return;
                }
            }

        }
    }
    std::cout<<" Nie ma takiego pociagu ktory spelnial by nasze oczekiwania "<<std::endl;
}*/
