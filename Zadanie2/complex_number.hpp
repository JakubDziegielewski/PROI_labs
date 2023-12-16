#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP
#include <iostream>

class ComplexNumber
{
    private:
        double real_part;
        double imaginary_part;
    public:
        ComplexNumber();
        ComplexNumber(double real_part, double imaginary_part);
        double get_real_part() const;
        double get_imaginary_part() const;
        void set_real_part(double real_part);
        void set_imaginary_part(double imaginary_part);
        
        //inkrementacja - załóżmy, że zwiększa wartość liczby zespolonej o 1 (czyli o (1 + 0i))
        //wersja prefiksowa -zwraca wartość po inkrementacji
        ComplexNumber& operator++();
        //wersja postfiksowa - też inkrementuje, ale zwraca wartość przed inkrementacją
        ComplexNumber operator++(int);

        //dodawanie dwóch liczb zespolonych
        //wersja z przypisaniem
        ComplexNumber& operator+=(const ComplexNumber& second_argument);
        //wersja bez przypisywania (oryginał pozostaje bez zmian)
        ComplexNumber operator+(const ComplexNumber& second_argument) const;

        ComplexNumber operator*(const ComplexNumber& second_argument) const;
        ComplexNumber& operator*=(const ComplexNumber& second_argument);
        ComplexNumber operator/(const ComplexNumber& second_argument) const;
        ComplexNumber& operator/=(const ComplexNumber& second_argument);



        //sprawdzanie równości dwóch liczb zespolonych
        bool operator==(const ComplexNumber& second_argument) const;
        bool operator!=(const ComplexNumber& second_argument) const;

        

        //Konstruktory kopiujący i przesuwający, operatory przypisania, destruktor
        //UWAGA: tu pokazane tylko dla przykładu, nie musimy ich tworzyć, jeśli nasza klasa nie zajmuje żadnych zasobów
        //(wystarczą ich wersje wygenerowane przez kompilator)
        ComplexNumber(const ComplexNumber& source); //konstruktor kopiujący
        ComplexNumber(ComplexNumber&& source); //konstruktor przesuwający
        ComplexNumber& operator=(const ComplexNumber& source); //kopiujący operator przypisania
        ComplexNumber& operator=(ComplexNumber&& source); //przesuwający operator przypisania
        ~ComplexNumber(); //destruktor
        //Można także wymusić wygenerowanie przez kompilator powyższych funkcji oraz konstruktora domyślnego
        //np. jeśli mimo posiadania konstruktora argumentowego chcemy mieć konstruktor domyślny wygenerowany przez kompilator:
        // ComplexNumber() = default;
        //Lub można jawnie zabronić kompilatorowi generowania któregoś z powyższych
        //np. jeśli nie pozwalamy na kopiowanie obiektów naszej klasy, trzeba zabronić generowania konstruktora kopiującego i kopiującego operatora przypisania
        // ComplexNumber(const ComplexNumber&) = delete;
        // ComplexNumber& operator=(const ComplexNumber&) = delete;


        friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& number); // ta funkcja nie jest składową klasy ComplexNumber, jest z nią tylko zaprzyjaźniona (ma dostęp do jej niepublicznych składowych)

};

std::ostream& operator<<(std::ostream& os, const ComplexNumber& number);

#endif