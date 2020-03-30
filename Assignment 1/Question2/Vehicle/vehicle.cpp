#include "vehicle.h"

Vehicle::Vehicle()
{
    year = 1000;
    type = "UNKNOWN";
    model = "UNKNOWN";
}

Vehicle::Vehicle(QString md, int yr, QString tp)
{
    year = yr;
    model = md;
    type = tp;
}

void Vehicle::setYear(int yr)
{
    year = yr;
}

void Vehicle::setModel(QString md)
{
    model = md;
}

void Vehicle::setType(QString tp)
{
    type = tp;
}

int Vehicle::getYear() const
{
    return year;
}

QString Vehicle::getType() const
{
    return type;
}

QString Vehicle::getModel() const
{
    return model;
}

void Vehicle::print()
{
    QTextStream cout(stdout);

    cout << endl;
    cout << "Vehicle Details" << endl;
    cout << "=====================================" << endl;
    cout << "Model: " << getModel() << endl;
    cout << "Year: " << getYear() << endl;
    cout << "Type: " << getType() << endl;
}
