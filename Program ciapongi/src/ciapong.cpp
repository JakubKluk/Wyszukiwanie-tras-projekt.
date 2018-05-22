//
// Created by Kuba on 16.05.2018.
//

#include "ciapong.hpp"

//PROSTY PRZYKŁADOWY PROGRAM WYUSZKIWANIA W PLIKU STACJE.TXT,
// WYKORZYTUJĄCY STWORZENIE KLASY, JEJ METODY I FUNKCJĘ find_station
#include <fstream>                                  //biblioteka do obsługi plików

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
    //PROSTY PRZYKŁADOWY PROGRAM WYUSZKIWANIA W PLIKU STACJE.TXT,
    // WYKORZYTUJĄCY STWORZENIE KLASY, JEJ METODY I FUNKCJĘ find_station

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
            grtline(file, line);
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


Route find_tour(std:: string start, std::string  end)//przekazujemy nazwy miast(stacji) z której chcemy jechac i gdzie dojechac
{
  auto number_start = find_station(start).getNumber();
  auto number_end = find_station(end).getNumber();

  std::fstream plik_s;
  plik_s.open("pociagi.txt", std::ios::in);
  if(plik_s.good()==false)
  {
      std::cout<<"Nie ma pliku"<<std::endl;
      exit(0);
  }
//ciag dalszy nastapi

}
