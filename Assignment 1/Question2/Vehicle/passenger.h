#ifndef PASSENGER_H
#define PASSENGER_H

#include "vehicle.h"
#include <QTextStream>

class Passenger : public Vehicle
{
    private:
        int passengers;
    public:
        Passenger(int ps, QString md, int yr);
        void print();
        int getPassengers() const;
        void setPassengers(int ps);
};

#endif // PASSENGER_H
