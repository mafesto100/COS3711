#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "vehicle.h"
#include <QString>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QMetaProperty>

class FileWriter
{
    private:
        QObjectList *list;
        QString filename;
    public:
        int write();
        FileWriter(QObjectList* list, QString fname);
};

#endif // FILEWRITER_H
