#include "filewriter.h"

int FileWriter::write()
{
    QString allData;

    //Loop through the list of vehicles
    for(int i = 0; i < list->size(); i++)
    {
        //get the metaObject of each vehicle object in the list
        const QMetaObject* meta = list->at(i)->metaObject();
        for(int j = meta->propertyOffset(); j < meta->propertyCount(); j++)
        {
            //get the meta properties of each object in the list
            const QMetaProperty metaProperty = meta->property(j);

            QString propertyName = metaProperty.name();
            QVariant propertyValue = metaProperty.read(list->at(i));
            QString s = propertyValue.toString();

            allData.append(QString("%1: %2\n").arg(propertyName).arg(s));
        }

        for(int k = 0; k < list->at(i)->dynamicPropertyNames().size(); k++)
        {
            QString propName = QString::fromLocal8Bit(list->at(i)->dynamicPropertyNames().at(k));
            QString value = list->at(i)->property(list->at(i)->dynamicPropertyNames().at(k)).toString();

            allData.append(QString("%1: %2\n").arg(propName).arg(value));
        }

        allData.append("\n");
    }

    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream inFile(&file);
    QTextStream cout(stdout);
    cout << allData;
    inFile << allData;

    file.close();

    return list->length();
}

FileWriter::FileWriter(QObjectList* olist, QString fname)
{
    list = olist;
    filename = fname;
}
