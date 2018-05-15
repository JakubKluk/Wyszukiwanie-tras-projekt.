#include <iostream>

class Train
        {
        public:
            Train(std::string name, double speedMax, double liczba_czlonow, double firstclass, double secondclass, std::string accessWIFI, std::string tours) : _name(name), _speedMax(speedMax), _liczba_czlonow(liczba_czlonow), _firstclass(firstclass), _secondclass(secondclass), _accessWIFI(accessWIFI), _tours(tours) {}
            std::string get_name();
            double get_ilosc();
            double get_speedMax();
            double get_liczba_czlonow();
            double get_firstclass();
            double get_secondclass();
            std::string get_accessWIFI();
            std::string get_alltours();
            ~Train();
        private:
            std::string _name;
            double _speedMax;
            double _liczba_czlonow;
            double _firstclass;
            double _secondclass;
            std::string _accessWIFI;
            std::string _tours;
        };

