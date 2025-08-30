#include "player.h"

Player::Player(QObject *parent)
{

}

Player::Player(QString name, QObject *parent)
{
    m_name= name;
}

// 名字
void Player::setName(QString name)
{

}

QString Player::getName()
{

}

// 角色
void Player::setRole(Player::Role role)
{
    m_role = role;
}

Player::Role Player::getRole()
{
    return m_role;
}

// 性别
void Player::setSex(Player::Sex sex)
{
    m_sex = sex;
}

Player::Sex Player::getSex()
{
    return m_sex;
}

// 朝向
void Player::setDirection(Player::Direction direction)
{
    m_direction = direction;
}

Player::Direction Player::getDirection()
{
    return m_direction;
}

// 玩家类型
void Player::setType(Player::Type type)
{
    m_type = type;
}

Player::Type Player::getType()
{
    return m_type;
}

// 玩家分数
void Player::setScore(int score)
{
    m_score = score;
}

int Player::getScore()
{
    return m_score;
}

// 赢了输了
void Player::setWin(bool flag)
{
    m_isWin = flag;
}

bool Player::isWin()
{
    return m_isWin;
}

// 上家/下家
void Player::setPrevPlayer(Player *player)
{
    m_prevPlayer = player;
}

void Player::setNextPlayer(Player *player)
{
    m_nextPlayer = player;
}

Player *Player::getPrePlayer()
{
    return m_prevPlayer;
}

Player *Player::getNextPlayer()
{
    return m_nextPlayer;
}

// 叫地主/抢地主
void Player::grabLordBet(int point)
{

}

// 存储扑克牌
void Player::storeDispatchCard(Card &card)
{
    m_cards << card;
}

void Player::storeLordCard(Cards &cards)
{
    m_cards << cards;
}

// 得到所有的牌
Cards Player::getCards()
{
    return m_cards;
}

void Player::clearCards()
{
    m_cards.clear();
}

// 出牌
void Player::playHand(Cards &cards)
{
    m_cards.remove(cards);
}

// 设置出牌玩家和待处理的牌
void Player::setPendingInfo(Player *pendPlayer, Cards &pendCards)
{
    m_pendPlayer = pendPlayer;
    m_pendCards = pendCards;
}

Player *Player::getPendPlayer()
{
    return m_pendPlayer;
}

Cards Player::getPendCards()
{
    return m_pendCards;
}

// 多态
void Player::prepareCallLord()
{

}

void Player::preparePlayHand()
{

}


