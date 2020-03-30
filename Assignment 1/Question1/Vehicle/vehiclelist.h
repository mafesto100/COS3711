#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "vehicle.h"
#include <QTextStream>

class VehicleList: public QList<Vehicle*>
{
    private:
        QList<Vehicle*> vehicleList;
    public:
        VehicleList();
        void add(Vehicle*);
        void print();
};

#endif // VEHICLELIST_H
