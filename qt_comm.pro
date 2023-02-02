QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lab_tips.cpp \
    lib/vts/vts.cpp \
    main.cpp \
    ms_web_client.cpp \
    net_connect.cpp \
    qt_area_slide.cpp \
    qt_butt_friend.cpp \
    qt_button.cpp \
    qt_edit.cpp \
    qt_edit_text.cpp \
    qt_move_it.cpp \
    qt_news.cpp \
#    tcp_socket.cpp \
    wid_change.cpp \
    wid_edit.cpp \
    wid_friends_list.cpp \
    wid_login.cpp \
    wid_manage.cpp \
    wid_register.cpp \
    wid_register_back.cpp \
    wid_slide_list.cpp \
    wid_talk.cpp \
    widget.cpp

HEADERS += \
    c_define.h \
    lab_tips.h \
    lib/vts/vts.h \
    lib/web_sock/include/AsyncHttpClient.h \
    lib/web_sock/include/Buffer.h \
    lib/web_sock/include/Channel.h \
    lib/web_sock/include/Event.h \
    lib/web_sock/include/EventLoop.h \
    lib/web_sock/include/EventLoopThread.h \
    lib/web_sock/include/EventLoopThreadPool.h \
    lib/web_sock/include/HttpContext.h \
    lib/web_sock/include/HttpMessage.h \
    lib/web_sock/include/HttpParser.h \
    lib/web_sock/include/HttpResponseWriter.h \
    lib/web_sock/include/HttpServer.h \
    lib/web_sock/include/HttpService.h \
    lib/web_sock/include/Status.h \
    lib/web_sock/include/TcpClient.h \
    lib/web_sock/include/TcpServer.h \
    lib/web_sock/include/ThreadLocalStorage.h \
    lib/web_sock/include/UdpClient.h \
    lib/web_sock/include/UdpServer.h \
    lib/web_sock/include/WebSocketChannel.h \
    lib/web_sock/include/WebSocketClient.h \
    lib/web_sock/include/WebSocketParser.h \
    lib/web_sock/include/WebSocketServer.h \
    lib/web_sock/include/axios.h \
    lib/web_sock/include/base64.h \
    lib/web_sock/include/hasync.h \
    lib/web_sock/include/hatomic.h \
    lib/web_sock/include/hbase.h \
    lib/web_sock/include/hbuf.h \
    lib/web_sock/include/hconfig.h \
    lib/web_sock/include/hdef.h \
    lib/web_sock/include/hdir.h \
    lib/web_sock/include/hendian.h \
    lib/web_sock/include/herr.h \
    lib/web_sock/include/hexport.h \
    lib/web_sock/include/hfile.h \
    lib/web_sock/include/hlog.h \
    lib/web_sock/include/hloop.h \
    lib/web_sock/include/hmain.h \
    lib/web_sock/include/hmap.h \
    lib/web_sock/include/hmath.h \
    lib/web_sock/include/hmutex.h \
    lib/web_sock/include/hobjectpool.h \
    lib/web_sock/include/hpath.h \
    lib/web_sock/include/hplatform.h \
    lib/web_sock/include/hproc.h \
    lib/web_sock/include/hscope.h \
    lib/web_sock/include/hsocket.h \
    lib/web_sock/include/hssl.h \
    lib/web_sock/include/hstring.h \
    lib/web_sock/include/hsysinfo.h \
    lib/web_sock/include/hthread.h \
    lib/web_sock/include/hthreadpool.h \
    lib/web_sock/include/htime.h \
    lib/web_sock/include/http_client.h \
    lib/web_sock/include/http_content.h \
    lib/web_sock/include/httpdef.h \
    lib/web_sock/include/hurl.h \
    lib/web_sock/include/hv.h \
    lib/web_sock/include/hversion.h \
    lib/web_sock/include/ifconfig.h \
    lib/web_sock/include/iniparser.h \
    lib/web_sock/include/json.hpp \
    lib/web_sock/include/md5.h \
    lib/web_sock/include/nlog.h \
    lib/web_sock/include/requests.h \
    lib/web_sock/include/sha1.h \
    lib/web_sock/include/singleton.h \
    lib/web_sock/include/wsdef.h \
    lib/web_sock/inter_sock.hpp \
    ms_web_client.h \
    net_connect.h \
    protocol/ux_protocol.h \
    qt_area_slide.h \
    qt_butt_friend.h \
    qt_button.h \
    qt_edit.h \
    qt_edit_text.h \
    qt_move_it.h \
    qt_news.h \
#    tcp_socket.h \
#    vlog.h \
    wid_change.h \
    wid_edit.h \
    wid_friends_list.h \
    wid_login.h \
    wid_manage.h \
    wid_register.h \
    wid_register_back.h \
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

DISTFILES += \
    lib/web_sock/README.md \
    lib/web_sock/lib/libhv.a \
    lib/web_sock/lib/libhv.dll \
    lib/web_sock/lib/libhv.dll.a \
    lib/web_sock/lib/libhv.so \
    lib/web_sock/lib/libhv_static.a

#win32: LIBS += -L$$PWD/lib/web_sock/lib/ -llibhv.dll

#INCLUDEPATH += $$PWD/lib/web_sock/include
#DEPENDPATH += $$PWD/lib/web_sock/include

unix:!macx: LIBS += -L$$PWD/lib/web_sock/lib/ -lhv

INCLUDEPATH += $$PWD/lib/web_sock/include
DEPENDPATH += $$PWD/lib/web_sock/include
