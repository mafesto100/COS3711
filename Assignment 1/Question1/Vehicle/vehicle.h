#ifndef VEHICLE_H
#define VEHICLE_H

#include "QString"
#include <QTextStream>

class Vehicle
{
    private:
        int year;
        QString model;
        QString type;
    public:
        Vehicle();
        Vehicle(QString md, int yr, QString tp);
        void setYear(int yr);
        void setModel(QString md);
        void setType(QString tp);
        int getYear() const;
        QString getType() const;
        QString getModel() const;
        virtual void print();
};

#endif // VEHICLE_H
