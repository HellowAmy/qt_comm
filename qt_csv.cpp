#include "qt_csv.h"

qt_csv::qt_csv(QObject *parent) : QObject(parent)
{

}

bool qt_csv::vector_to_file(QVector<QString> &vec, QString filename)
{
    QFile file(filename);
    QTextStream ofs(&file);
    if(file.open(QIODevice::WriteOnly))
    {
        for(QVector<QString>::iterator it = vec.begin();it != vec.end();it++)
        {
            QString temp = (*it).toUtf8() + "\r\n";
            file.write(temp.toUtf8());
            out<<temp;
        }

        file.close();
        return true;
    }
    else return false;
}

bool qt_csv::file_to_vector(QString filename,QVector<QString> &vec)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        while(file.atEnd() == false)
        {
            QString temp = file.readLine();
            vec.push_back(temp.section("\r",0,0));
        }

        file.close();
        return true;
    }
    else return false;
}

