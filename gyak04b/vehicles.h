#pragma once

#include <string>
#include <vector>
#include "parts.h"

class Vehicle {
  std::string name;
  std::vector<Part*> parts;
public:
  Vehicle(std::string n) : name(n) {}
  virtual void print() = 0; // mivel van legalabb 1 virtualis fv ami 0, ezert absztrakt osztaly - nem peldanyosithato
  std::string getName() { return name; }
  virtual void addPart(Part* pp) { parts.push_back(pp); }
  void printParts() {
    for (Part* pp : parts) {
      pp->print();
    }
  }
  int getNumParts() {
    return parts.size();
  }
  void amortize() {
    for (Part* pp : parts) {
      pp->amortize();
    }
  }
};

class Car : public Vehicle {
public:
  Car(std::string n) : Vehicle(n) {}
  void print() { 
    std::cout << "Car named " << getName() << " with " << getNumParts() << " parts" << std::endl;
    printParts();
  }
};

class MotorBike : public Vehicle {
public:
  MotorBike(std::string n) : Vehicle(n) {}
  void print() {
    std::cout << "Motorbike named " << getName() << " with " << getNumParts() << " parts" << std::endl;
    printParts();
  }
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
  void amortize() {
    // vegig megyunk az osszes jarmu osszes alkatreszen...
    for (Vehicle* vp : vehiclepark) {
      vp->amortize();
    }
  }
};
