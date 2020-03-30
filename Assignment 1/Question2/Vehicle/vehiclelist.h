#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "vehicle.h"
#include <QTextStream>
#include <QObject>

class VehicleList: public QList<Vehicle*>
{
    private:
        QList<Vehicle*> vehicleList;
    public:
        VehicleList();
        ~VehicleList();
        void add(Vehicle*);
        void print();
        QList<Vehicle*> getVehicles() const;
};

#endif // VEHICLELIST_H
