#include "vehiclelist.h"

VehicleList::VehicleList()
{

}

VehicleList::~VehicleList()
{
    qDeleteAll(vehicleList);
}

void VehicleList::add(Vehicle* ls)
{
    vehicleList.append(ls);
}

void VehicleList::print()
{
    QTextStream cout(stdout);

    cout << "List of Vehicles created" << endl;
    foreach(Vehicle* vehicle, vehicleList)
    {
        vehicle->print();
    }
}

QList<Vehicle*> VehicleList::getVehicles() const
{
    return vehicleList;
}
