#include <iostream>
using namespace std;

class Vehicle {
public:
    string brand;

    // Constructor to initialize the brand
    Vehicle(): brand("Ford") {}

    void honk()
    {
        cout << "Tuut, tuut! \n";
    }
};

// Derived class
class Car : public Vehicle {
public:
    string model;

    // Constructor to initialize the model
    Car(): model("Mustang") {}
};

int main() {
    Car myCar;
    myCar.honk();
    cout << myCar.brand + " " + myCar.model;
    return 0;
}