#include "Car.h"

Car::Car(const char* brand, int year, int mileage)
{
    ctorcp(brand,year,mileage);  
}

Car::Car(const Car & car)
{
    ctorcp(car._brand,*(car._year),car._mileage);
}

Car::Car(Car && car)
{
    ctor(car);
    car.replace();
}

const Car & Car::operator=(const Car & car)
{
    if(this == &car)
        return *this;

    dtor();
    ctorcp(car._brand, *(car._year), car._mileage);
    return *this;
}

const Car & Car::operator=(Car && car)
{
    dtor();
    ctor(car);
    car.replace();

    return *this;
}

Car::~Car()
{
    dtor();
}

///////////////////////////////////////////////////////////////////

void Car::ctor(const Car & car)
{
    _brand = car._brand;
    _mileage = car._mileage;
    _year = car._year;
}

void Car::ctorcp(std::string brand,int year, int mileage)
{
    _brand = brand;
    _mileage = mileage;
    _year = new int{year}; 
}

void Car::dtor()
{
    delete _year;
}

void Car::replace()
{
    _brand = "-None-";
    _mileage = 0;
    _year = nullptr;
}

///////////////////////////////////////////////////////////////////

void Car::displayInfo() const
{
    if(_year != nullptr){
        std::cout << "Brand: " << _brand << ", Year: " << *_year << ", Mileage: " << _mileage << " km" << std::endl;
    }else{
        std::cout << "Brand: " << _brand << ", Year: " << _brand << ", Mileage: " << _brand << std::endl; 
    }

}