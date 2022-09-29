#ifndef WID_CHANGE_H
#define WID_CHANGE_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QPaintEvent>
#include <QPainter>
#include <QEvent>

class wid_change : public QWidget
{
    Q_OBJECT
public:
    explicit wid_change(QWidget *parent = nullptr);

    //开启半透明窗口，
    //（参数1：鼠标进入时的透明度）（参数2：鼠标离开时的透明度）
    void open_translucent(double min=0.3, double max=0.9);

    void open_lessframe();//开启可移动的无边框窗口

    //开启圆角
    //（参数1：百分百圆角率）（参数2：设置边缘笔刷）
    void open_round(QPoint rounded=QPoint(10,10),QPen pen=QPen(Qt::NoPen));

    //开启背景图片
    //（参数1：传入背景图片）
    void open_backdrop(QString path);

signals:

protected:
    bool is_open_glass=false;//开启标记——半透明
    bool is_open_lessframe=false;//开启标记——无边框移动
    bool is_open_rounded=false;//开启标记——圆角
    bool is_open_backdrop=false;//开启标记——背景图片

    //=====开启无边框移动=====
    QPoint pos_global;//记录点击位置
    bool is_press = false;//点击移动时防止抖动
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    //=====开启无边框移动=====

    //=====开启半透明=====
    double v_min;//透明下限
    double v_max;//透明上限
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    //=====开启半透明=====

    //=====开启圆角=====
    QPoint pos_round;
    QPen v_pen;
    void paintEvent(QPaintEvent *event) override;
    //=====开启圆角=====

    //=====开启背景图片=====
    QString pic_backdrop;//背景图片
    //void paintEvent(QPaintEvent *event) override;
    //=====开启背景图片=====

};

#endif // WID_CHANGE_H
