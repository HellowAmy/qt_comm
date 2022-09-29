#ifndef QT_EDIT_H
#define QT_EDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QFont>

class qt_edit : public QLineEdit
{
    Q_OBJECT
public:
    explicit qt_edit(QWidget *parent = nullptr);

signals:


};

#endif // QT_EDIT_H
