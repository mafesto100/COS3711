#include "passenger.h"

Passenger::Passenger(int ps, QString md, int yr): Vehicle(md, yr, "Passenger")
{
    passengers = ps;
}

int Passenger::getPassengers() const
{
    return passengers;
}

void Passenger::setPassengers(int ps)
{
    passengers = ps;
}

void Passenger::print()
{
    Vehicle::print();
    QTextStream cout(stdout);
    cout << "Number of Passengers: " << getPassengers() << " passengers" << endl;
}
