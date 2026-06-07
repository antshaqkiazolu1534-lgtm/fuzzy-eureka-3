#ifndef VEHICLEOWNER_H
#define VEHICLEOWNER_H

#include "User.h"

class VehicleOwner : public User {
public:
    VehicleOwner() {}
    VehicleOwner(string n, string e, string p) : User(n, e, p) {}
};

#endif
