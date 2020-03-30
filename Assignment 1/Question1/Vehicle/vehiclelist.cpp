#include "vehiclelist.h"

VehicleList::VehicleList()
{

}

void VehicleList::add(Vehicle* list)
{
    vehicleList.append(list);
}

void VehicleList::print()
{
    QTextStream cout(stdout);

    cout << "List of Vehicles created" << endl;
    foreach (Vehicle *vehicle, vehicleList)
    {
        vehicle->print();
    }
}
