// VehicleClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "vehicles.h"
#include "parts.h"

int main()
{
  // Vehicle v;
  // absztrakt osztaly, nem megy!!
  Vehicle* c1 = new Car("Oliver's Ferrari");
  Vehicle* c2 = new Car("Erno's Porsche");
  Vehicle* c3 = new Car("Adam's Mercedes");
  Vehicle* mb1 = new MotorBike("Mate's Harley");

  c1->addPart(new Part("Air conditioner", 2));
  c2->addPart(new Part("Engine", 6));
  c3->addPart(new Part("Piston", 7));
  c3->addPart(new Part("Spark plug", 3));

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

