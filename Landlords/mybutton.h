#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

// 既然是button，理所应当地继承button类
class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

    void setImage(QString normal, QString hover,QString pressed);
protected:
    // 重写鼠标事件函数
    // 鼠标按下
    void mousePressEvent(QMouseEvent *ev);
    // 鼠标释放
    void mouseReleaseEvent(QMouseEvent *ev);
    // 鼠标进入那一瞬间
    void enterEvent(QEvent *ev);
    // 鼠标离开
    void leaveEvent(QEvent *ev);
    // 绘图
    void paintEvent(QPaintEvent* ev);


signals:

private:
    QString m_normal; // 存储的是相关图片的地址
    QString m_hover;
    QString m_pressed;
    QPixmap m_pixmap;   // 通过地址将图片转换为QPixmap对象
};

#endif // MYBUTTON_H
