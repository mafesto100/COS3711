#include "vehicle.h"
#include "passenger.h"
#include "transport.h"
#include "vehiclelist.h"

int main()
{
    /*Create Vehicles*/

    //Create a Default vehicle
    Vehicle *def = new Vehicle();
    //def->print();

    //Create a Transport vehicle
    Transport *truck = new Transport(2500, "Man TGS", 2008);
    Transport *lorry = new Transport(1500, "Kia Dyan", 2010);
    //truck->print();
    //lorry->print();

    //Create a Passenger vehicle
    Passenger *minibus = new Passenger(23, "Iveco Bus", 2014);
    Passenger *taxi = new Passenger(16, "Toyota Quantam", 2008);
    //minibus->print();
    //taxi->print();

    //Create a list of vehicles
    VehicleList *list = new VehicleList();
    list->add(def);
    list->add(truck);
    list->add(lorry);
    list->add(taxi);
    list->add(minibus);

    list->print();

    return 0;
}
