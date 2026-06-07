#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "VehicleOwner.h"
using namespace std;

class Vehicle {
private:
    string plateNumber;
    string type;
    int year;
    VehicleOwner owner;

public:
    Vehicle() {}
    Vehicle(string plate, string t, int y, VehicleOwner o)
        : plateNumber(plate), type(t), year(y), owner(o) {}

    string getPlateNumber() const { return plateNumber; }
    string getType() const { return type; }
    int getYear() const { return year; }
    VehicleOwner getOwner() const { return owner; }
};

#endif
