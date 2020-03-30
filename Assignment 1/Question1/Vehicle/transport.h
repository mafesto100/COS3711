#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "vehicle.h"

class Transport : public Vehicle
{
    private:
        int carryingCapacity;
    public:
        Transport(int cc, QString md, int yr);
        void setCarryingCapacity(int cc);
        int getCarryingCapacity();
        void print();
};

#endif // TRANSPORT_H
