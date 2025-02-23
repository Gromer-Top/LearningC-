#include <iostream>

class Car
{
    public:
        int year;

        Car(int year)
        {
            this->year = year;
        }
};

int main()
{
    Car haval(2023);
    std::cout << haval.year;
}