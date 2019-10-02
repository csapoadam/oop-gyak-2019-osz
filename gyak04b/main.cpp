// VehicleClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "vehicles.h"

int main()
{
  // Vehicle v;
  // absztrakt osztaly, nem megy!!
  Vehicle* c1 = new Car("Oliver's Ferrari");
  Vehicle* c2 = new Car("Erno's Porsche");
  Vehicle* c3 = new Car("Adam's Mercedes");
  Vehicle* mb1 = new MotorBike("Mate's Harley");

  VehiclePark vehiclepark;
  vehiclepark.addVehicle(c1);
  vehiclepark.addVehicle(c2);
  vehiclepark.addVehicle(mb1);
  vehiclepark.printVehicles();

  /*
  Tegyuk fel, hogy itt van jo sok kod.
  De hogy ellenorizzuk, ameddig jutottunk, kikommenteljuk.
  
  dsfadfadfkadkjfdajfd
  .sdfkjsadfkasdjfad
  
  */

  std::cin.get();
    return 0;
}

