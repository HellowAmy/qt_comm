 #ifndef QT_CSV_H
#define QT_CSV_H

#include <QObject>
#include <QFile>
#include <QVector>
#include <QTextStream>

#include "c_define.h"

class qt_csv : public QObject
{
    Q_OBJECT
public:
    explicit qt_csv(QObject *parent = nullptr);

    static bool vector_to_file(QVector<QString> &vec,QString filename);
    static bool file_to_vector(QString filename,QVector<QString> &vec);

signals:

protected:

};

#endif // QT_CSV_H
