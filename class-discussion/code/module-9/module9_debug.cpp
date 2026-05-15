#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string brandName, int modelYear) : brand(brandName), year(modelYear) {}

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
}  

class Car : public Vehicle {
private:
    int doors;

public:
    Car(string brandName, int modelYear, int numDoors) : Vehicle(brandName, modelYear), doors(numDoors) {}

    void display() {
        Vehicle::display();
        cout << "Doors: " << doors << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    string type;

public:
    Motorcycle(string brandName, int modelYear, string bikeType) : Vehicle(brandName, modelYear), type(bikeType) {}

    void display() {
        Vehicle::display();
        cout << "Type: " << type << endl;
    }
};

int main() {
    Car myCar("Toyota", 2020, 4);
    Motorcycle myBike("Harley-Davidson", 2019, "Cruiser");

    myCar.display();
    myBike.display();
    myBike.getSpeed();  

    return 0;
}