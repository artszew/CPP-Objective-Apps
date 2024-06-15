#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <memory>
#include "../../library/include/model/Car.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/model/Rent.h"
#include "../../library/include/model/Bicycle.h"
#include "../../library/include/model/MotorVehicle.h"
#include "../../library/include/model/Moped.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"

typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<MotorVehicle> MotorVehiclePtr;
typedef std::shared_ptr<Moped> MopedPtr;
typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::weak_ptr<Client> ClientWeakPtr;
// Typ predykatu dla klasy Client
typedef std::function<bool(ClientPtr)> ClientPredicate;

// Typ predykatu dla klasy Vehicle
typedef std::function<bool(VehiclePtr)> VehiclePredicate;

// Typ predykatu dla klasy Rent
typedef std::function<bool(RentPtr)> RentPredicate;

#endif // TYPEDEFS_H
