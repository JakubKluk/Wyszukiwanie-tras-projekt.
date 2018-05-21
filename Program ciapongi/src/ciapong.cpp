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




