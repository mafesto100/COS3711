#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>
#include <QTextStream>
#include <QObject>

class Vehicle: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString type READ getType WRITE setType)
    Q_PROPERTY(QString model READ getModel WRITE setModel)
    Q_PROPERTY(int year READ getYear WRITE setYear)

    private:
        int year;
        QString model;
        QString type;
    public:
        Vehicle();
        Vehicle(QString md, int yr, QString tp);
        void add(Vehicle*);
        void setYear(int yr);
        void setModel(QString md);
        void setType(QString tp);
        int getYear() const;
        QString getType() const;
        QString getModel() const;
        virtual void print();
};

#endif // VEHICLE_H
