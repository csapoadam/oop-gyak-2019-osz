#pragma once

#include <string>
#include <vector>

class Vehicle {
  std::string name;
public:
  Vehicle(std::string n) : name(n) {}
  virtual void print() = 0; // mivel van legalabb 1 virtualis fv ami 0, ezert absztrakt osztaly - nem peldanyosithato
  std::string getName() { return name; }
};

class Car : public Vehicle {
public:
  Car(std::string n) : Vehicle(n) {}
  void print() { std::cout << "Car named " << getName() << std::endl; }
};

class MotorBike : public Vehicle {
public:
  MotorBike(std::string n) : Vehicle(n) {}
  void print() { std::cout << "Motorbike named " << getName() << std::endl; }
};

class VehiclePark {
  std::vector<Vehicle*> vehiclepark;
public:
  VehiclePark() {}
  void addVehicle(Vehicle* vp) {
    vehiclepark.push_back(vp);
  }
  void printVehicles() {
    std::cout << "Vehicles in park are :" << std::endl;
    for (Vehicle* vp : vehiclepark) {
      vp->print();
    }
  }
};
