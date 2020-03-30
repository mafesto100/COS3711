#include "vehicle.h"
#include "passenger.h"
#include "transport.h"
#include "vehiclelist.h"
#include "filewriter.h"

#include <QObject>
#include <QTextStream>

int main()
{
    /*Create Vehicles*/

    //Create a Default vehicle
    Vehicle *def = new Vehicle();
    //def->print();

    //Create a Transport vehicle
    Transport *truck = new Transport(2500, "Man TGS", 2008);
    Transport *lorry = new Transport(1500, "Kia Dyan", 2010);
    truck->setProperty("carryingCapacity", truck->getCarryingCapacity());
    lorry->setProperty("carryingCapacity", lorry->getCarryingCapacity());
    //truck->print();
    //lorry->print();

    //Create a Passenger vehicle
    Passenger *minibus = new Passenger(23, "Iveco Bus", 2014);
    Passenger *taxi = new Passenger(16, "Toyota Quantam", 2008);
    taxi->setProperty("passengers", taxi->getPassengers());
    minibus->setProperty("passengers", minibus->getPassengers());
    //minibus->print();
    //taxi->print();


    //Create a list of vehicles
    VehicleList* list = new VehicleList();
    list->add(def);
    list->add(truck);
    list->add(lorry);
    list->add(taxi);
    list->add(minibus);

    //Add vehicles as QObjects to the list
    QObjectList *oList = new QObjectList;
    foreach(QObject* tempList, list->getVehicles())
    {
        oList->append(tempList);
    }

    //Create a FileWriter instance
    FileWriter* fl = new FileWriter(oList, "vehicles.txt");
    int num = fl->write();

    QTextStream cout(stdout);
    cout << "Number of records printed to the console: " << num << endl;

    delete list;
    delete oList;
    delete fl;
    list = NULL;
    oList = NULL;
    fl = NULL;

    return 0;
}
