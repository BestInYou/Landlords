#ifndef CARDS_H
#define CARDS_H
#include "card.h"

#include <QSet>

class Cards
{
public:
    enum SortType{Asc, Desc, NoSort};
    Cards();

    // 1 添加扑克牌
    void add(const Card& card);
    void add(const Cards& cards);

    // 一次性插入多个数据(操作符重载 <<)
    // 这样看起来更直观，语法更优雅；而且Qt里很多容器（比如QDebug）都用<<重载来添加内容，符合Qt编程习惯
    Cards& operator << (const Card& card);
    Cards& operator << (const Cards& cards);

    // 2 删除扑克牌
    void remove(Card& card);
    void remove(Cards& cards);

    // 3 扑克牌的数量
    int cardCount();

    // 4 是否为空
    bool isEmpty();

    // 5 清空扑克牌
    void clear();

    // 6 最大点数
    Card::CardPoint maxPoint();

    // 7 最小点数
    Card::CardPoint minPoint();

    // 8 指定点数的牌的数量
    int pointCount(Card::CardPoint point);

    // 9 某张牌是否在集合中
    bool contains(const Card& card);
    bool contains(const Cards& cards);

    // 10 随机取出一张牌
    Card takeRandomCard();

    // 11 转换函数，将QSet转换为QVector，因为QSet无序，而QVector有序
    CardList toCardList(SortType type = Desc);



private:
    QSet<Card> m_cards;
};

#endif // CARDS_H
