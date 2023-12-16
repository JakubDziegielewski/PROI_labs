#include "complex_number.hpp"
#include <cmath>
#include <stdexcept>

ComplexNumber::ComplexNumber() : real_part(0.0), imaginary_part(0.0)
{

}

ComplexNumber::ComplexNumber(double real_part, double imaginary_part) : real_part(real_part), imaginary_part(imaginary_part)
{
    
}

double ComplexNumber::get_real_part() const
{
    return real_part;
}

double ComplexNumber::get_imaginary_part() const
{
    return imaginary_part;
}

void ComplexNumber::set_real_part(double real_part)
{
    this->real_part = real_part;
}

void ComplexNumber::set_imaginary_part(double imaginary_part)
{
    this->imaginary_part = imaginary_part;
}

ComplexNumber &ComplexNumber::operator++()
{
    real_part += 1;
    return *this;
}

ComplexNumber ComplexNumber::operator++(int)
{
    ComplexNumber old_value = *this;
    ++(*this); // albo po prostu można wywołać operator++(); ewentualnie jawnie wskazać, że ma być wywołany dla tego obiektu: this -> operator++();
    return old_value;
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &second_argument)
{
    real_part += second_argument.real_part;
    imaginary_part += second_argument.imaginary_part;
    return *this;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &second_argument) const
{
    ComplexNumber sum = *this;
    sum += second_argument;
    return sum;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &second_argument) const
{
    ComplexNumber temp = ComplexNumber(*this);
    double real = temp.real_part * second_argument.real_part - temp.imaginary_part * second_argument.imaginary_part;
    double imaginary = temp.real_part * second_argument.imaginary_part + temp.imaginary_part * second_argument.real_part;
    return ComplexNumber(real, imaginary);
}
ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &second_argument)
{
    *this = *this * second_argument;
    return *this;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &second_argument) const
{
    if (second_argument.real_part != 0.0 || second_argument.imaginary_part != 0.0){
    ComplexNumber temp = ComplexNumber(*this);
    double real = (temp.real_part * second_argument.real_part + temp.imaginary_part * second_argument.imaginary_part) /
                (std::pow(second_argument.real_part, 2) + std::pow(second_argument.imaginary_part, 2));
    double imaginary = (temp.imaginary_part * second_argument.real_part - temp.real_part * second_argument.imaginary_part) /
                     (std::pow(second_argument.real_part, 2) + std::pow(second_argument.imaginary_part, 2));
    return ComplexNumber(real, imaginary);
    }
    else{
        throw std::invalid_argument("Cannot divide by zero");
    }
}

ComplexNumber &ComplexNumber::operator/=(const ComplexNumber &second_argument)
{
    if (second_argument.real_part != 0.0 || second_argument.imaginary_part != 0.0){
    *this = *this * second_argument;
    return *this;
    }
    else{
        throw std::invalid_argument("Cannot divide by zero");
    }
}



bool ComplexNumber::operator==(const ComplexNumber &second_argument) const
{
    return real_part == second_argument.real_part && imaginary_part == second_argument.imaginary_part; // UWAGA: takie porównanie wartości zmiennoprzecinkowych może w ogólnym przypadku dawać nieoczekiwane wyniki ze względu na niedokładność reprezentacji - lepiej założyć pewien margines błędu
}

bool ComplexNumber::operator!=(const ComplexNumber &second_argument) const
{
    return !(*this == second_argument);
}

std::ostream &operator<<(std::ostream &os, const ComplexNumber &number)
{
    os << "(" << number.real_part << " + " << number.imaginary_part << "i)";
    return os;
}

// W tym przykładzie poniższe funkcje nie są potrzebne, całkowicie wystarczyłyby ich wersje wygenerowane przez kompilator
// Konstruktor kopiujący - tworzy nowy, zupełnie oddzielny obiekt na podstawie istniejącego (nie modyfikuje oryginału)
ComplexNumber::ComplexNumber(const ComplexNumber &source) : real_part(source.real_part), imaginary_part(source.imaginary_part)
{
   
}

// Konstruktor przesuwający - tworzy nowy obiekt na bazie źródłowego, zabierając jego zasoby i "unieważniając" oryginał
ComplexNumber::ComplexNumber(ComplexNumber &&source) : real_part(source.real_part), imaginary_part(source.imaginary_part)
{
    
    //"unieważnienie" źródłowego obiektu
    source.real_part = 0;
    source.imaginary_part = 0;
}

// Kopiujący operator przypisania - "kopiuje" do już istniejącego obiektu, oryginał jest niezależny od wyniku przypisania
ComplexNumber &ComplexNumber::operator=(const ComplexNumber &source)
{
   
    if (this != &source) // nie powinien przypisywać sam do siebie!
    {
        real_part = source.real_part;
        imaginary_part = source.imaginary_part;
    }
    return *this;
}

// Przesuwający operator przypisania - "przenosi" do już istniejącego obiektu, zabierając zasoby oryginalnego obiektu i "unieważniając" go
ComplexNumber &ComplexNumber::operator=(ComplexNumber &&source)
{
    
    if (this != &source) // nie powinien przypisywać sam do siebie!
    {
        real_part = source.real_part;
        imaginary_part = source.imaginary_part;
        //"unieważnienie" źródłowego obiektu
        source.real_part = 0;
        source.imaginary_part = 0;
    }
    return *this;
}

// Destruktor - zwalnia zasoby zajęte przez obiekt
ComplexNumber::~ComplexNumber()
{
    // zwolnienie zasobów
    // klasa ComplexNumber żadnych zasobów nie zajmowała, więc nic nie musi tu zwalniać
}