#include "transport.h"

Transport::Transport(int cc, QString md, int yr): Vehicle(md, yr, "Transport")
{
    carryingCapacity = cc;
}

void Transport::setCarryingCapacity(int cc)
{
    carryingCapacity = cc;
}

int Transport::getCarryingCapacity()
{
    return carryingCapacity;
}

void Transport::print()
{
    Vehicle::print();
    QTextStream cout(stdout);
    cout << "Carrying Capacity: " << getCarryingCapacity() << " kg" << endl;
}
