#include "cards.h"
#include <QRandomGenerator>

Cards::Cards()
{

}

// 1 添加扑克牌
void Cards::add(const Card &card)
{
    m_cards.insert(card);
}

void Cards::add(const Cards &cards)
{
    // 得到两个集合的并集
    m_cards.unite(cards.m_cards);
}

Cards &Cards::operator <<(const Card &card)
{
    add(card);
    return *this;
}

Cards &Cards::operator <<(const Cards &cards)
{
    add(cards);
    return *this;
}

// 2 删除扑克牌
void Cards::remove(Card &card)
{
    m_cards.remove(card);
}

void Cards::remove(Cards &cards)
{
    // 得到两个集合的差集
    m_cards.subtract(cards.m_cards);
}

// 3 扑克牌数量
int Cards::cardCount()
{
    return m_cards.size();
}

// 4 是否为空
bool Cards::isEmpty()
{
    return m_cards.isEmpty();
}

// 5 清空扑克牌
void Cards::clear()
{
    m_cards.clear();
}

// 6 最大点数
Card::CardPoint Cards::maxPoint()
{
    Card::CardPoint max = Card::Card_Begin;
    if(!m_cards.isEmpty()){
        for(auto it = m_cards.begin();it!=m_cards.end();++it)
        {
            if(it->point() > max){
                max = it->point();
            }
        }
    }

    return max;
}

// 7 最小点数
Card::CardPoint Cards::minPoint()
{
    Card::CardPoint min = Card::Card_BJ;
    if(!m_cards.isEmpty()){
        for(auto it = m_cards.begin();it!=m_cards.end();++it)
        {
            if(it->point() < min){
                min = it->point();
            }
        }
    }

    return min;
}

// 8 指定点数数量
int Cards::pointCount(Card::CardPoint point)
{
    if(!m_cards.isEmpty()){
        return 0;
    }
    int count = 0;
    for(auto it = m_cards.begin();it!=m_cards.end();it++){
        if(it->point()==point){
            ++count;
        }
    }
    return count;
}

// 9 是否存在某张牌
bool Cards::contains(const Card &card)
{
    return m_cards.contains(card);
}

bool Cards::contains(const Cards &cards)
{
    return m_cards.contains(cards.m_cards);
}

// 10 随机取出一张卡牌
Card Cards::takeRandomCard()
{
    // 生成一个随机数
    // QSet是无序集合，虽然能遍历，但顺序是不固定的。
    int num = QRandomGenerator::global()->bounded(m_cards.size());
    QSet<Card>::const_iterator it = m_cards.constBegin();
    for(int i=0;i<num;++i,++it);
    Card card = *it;
    m_cards.erase(it);
    return card;
}

// 11 转换函数
CardList Cards::toCardList(Cards::SortType type)
{
    CardList list;
    for(auto it = m_cards.begin();it!=m_cards.end();++it){
        list << *it;
    }
    if(type == Asc){
        std::sort(list.begin(),list.end(),lessSort);
    }
    else if(type == Desc){
        std::sort(list.begin(),list.end(),greaterSort);
    }
    return list;
}






