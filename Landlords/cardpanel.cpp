#include "cardpanel.h"
#include <QPainter>

CardPanel::CardPanel(QWidget *parent) : QWidget(parent)
{
    m_isfront = true;
}

// 设置获取图片函数
void CardPanel::setImage(QPixmap &front, QPixmap &back)
{
    m_front = front;
    m_back = back;

    // 让绘图自动适应窗口大小
    setFixedSize(m_front.size());

    // 使用了update函数后框架就自动调用paintEvent函数
    update();
}

QPixmap CardPanel::getImage()
{
    // 拿到这张卡，想要得到的是正面，因为背面都是一样的
    return m_front;
}

// 扑克牌显示哪一面
void CardPanel::setFrontSide(bool flag)
{
    m_isfront = flag;
}

bool CardPanel::isFrontSide()
{
    return m_isfront;
}

// 记录窗口是否被选中了
void CardPanel::setSeclected(bool flag)
{
    m_isSelect = flag;
}

bool CardPanel::isSelected()
{
    return m_isSelect;
}

// 扑克牌花色以及点数
void CardPanel::setCard(Card &card)
{
    m_card = card;
}

Card CardPanel::getCard()
{
    return m_card;
}

// 扑克牌所有者
void CardPanel::setOwner(Player *player)
{
    m_owner = player;
}

Player *CardPanel::getOwner()
{
    return m_owner;
}


// 重载事件
void CardPanel::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    if(m_isfront)
    {
        p.drawPixmap(rect(),m_front);
    }
    else
    {
        p.drawPixmap(rect(),m_back);
    }
}

void CardPanel::mousePressEvent(QMouseEvent *event)
{

}
