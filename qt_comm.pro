QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qt_area_slide.cpp \
    qt_butt_friend.cpp \
    qt_button.cpp \
    qt_edit.cpp \
    qt_edit_text.cpp \
    qt_move_it.cpp \
    qt_news.cpp \
    tcp_socket.cpp \
    wid_change.cpp \
    wid_edit.cpp \
    wid_friends_list.cpp \
    wid_login.cpp \
    wid_manage.cpp \
    wid_register.cpp \
    wid_slide_list.cpp \
    wid_talk.cpp \
    widget.cpp

HEADERS += \
    c_define.h \
    qt_area_slide.h \
    qt_butt_friend.h \
    qt_button.h \
    qt_edit.h \
    qt_edit_text.h \
    qt_move_it.h \
    qt_news.h \
    tcp_socket.h \
    wid_change.h \
    wid_edit.h \
    wid_friends_list.h \
    wid_login.h \
    wid_manage.h \
    wid_register.h \
    wid_slide_list.h \
    wid_talk.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
