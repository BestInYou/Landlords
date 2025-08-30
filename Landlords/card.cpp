#include "card.h"

Card::Card()
{

}

Card::Card(Card::CardPoint point, Card::CardSuit suit)
{
   setPoint(point);
   setSuit(suit);
}

void Card::setPoint(Card::CardPoint point)
{
    m_point = point;
}

void Card::setSuit(Card::CardSuit suit)
{
    m_suit = suit;
}

Card::CardPoint Card::point() const
{
    return m_point;
}

Card::CardSuit Card::suit() const
{
    return m_suit;
}


// 对象比较
bool lessSort(const Card &c1, const Card &c2)
{
    // 花色并不影响出牌的大小，这里对花色也进行判断是为了方便展示牌时的排序
    if(c1.point() == c2.point()){
        return c1.suit() < c2.suit();
    }
    else{
        return c1.point() < c2.point();
    }
}

bool greaterSort(const Card &c1, const Card &c2)
{
    if(c1.point() == c2.point()){
        return c1.suit() > c2.suit();
    }
    else{
        return c1.point() > c2.point();
    }
}

// 操作符重载
bool operator ==(const Card &left, const Card &right)
{
    return (left.suit()==right.suit() && left.point()==right.point());
}

// 重写
uint qHash(const Card &card)
{
    return card.point() * 100 +card.suit();
}
