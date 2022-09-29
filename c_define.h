#ifndef C_DEFINE_H
#define C_DEFINE_H

//#include "c_define.h"

//==============================================
#define C_QT_OUT //开启QT打印
//#define C_VS_OUT//开启VS打印

//#define C_VS_FILE//开启VS打印
//#define C_QT_FILE//开启VS打印

//#define C_QT_VEC//开启QT容器
//#define C_VS_VEC//开启VS容器
//==============================================

//==========
#ifdef C_QT_OUT
#include <QDebug>
#define out qDebug()
#endif //C_QT_OUT
//==========

//==========
#ifdef C_VS_OUT
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
#endif //C_VS_OUT
//==========

//==========
#ifdef C_QT_VEC
#include <QVector>
#include <QQueue>
#include <QStack>
#include <QMap>
#include <QSet>
#include <QList>
#include <QHash>
#endif //C_QT_VEC
//==========

//==========
#ifdef C_VS_VEC
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using std::map;
using std::set;
using std::vector;
using std::queue;
using std::stack;
using std::unordered_map;
using std::unordered_set;
#endif //C_VS_VEC
//==========

//==========
#ifdef C_VS_FILE
#include <fstream>
#include <iostream>
#include <string>
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
#endif //C_VS_FILE
//==========

//==========
#ifdef C_QT_FILE
#include <QFile>
#include <QTextStream>
#endif //C_QT_FILE
//==========

#endif // C_DEFINE_H
