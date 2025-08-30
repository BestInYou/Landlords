#include "gamecontrol.h"
#include <QRandomGenerator>

GameControl::GameControl(QObject *parent)
{

}
// 1 玩家部分
// 初始化玩家
void GameControl::PlayerInit()
{
    // 对象实例化
    m_robotLeft = new Robot("机器人A", this);
    m_robotRight = new Robot("机器人B", this);
    m_user = new UserPlayer("我自己",this);

    // 头像的显示
    m_robotLeft->setDirection(Player::Left);
    m_robotRight->setDirection(Player::Right);
    m_user->setDirection(Player::Right);

    // 性别,int可强制转换成枚举类型
    Player::Sex sex;
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_robotLeft->setSex(sex);
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_robotRight->setSex(sex);
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_user->setSex(sex);

    // 出牌顺序
    m_user->setPrevPlayer(m_robotLeft);
    m_user->setNextPlayer(m_robotRight);

    m_robotRight ->setPrevPlayer(m_user);
    m_robotRight ->setNextPlayer(m_robotLeft);

    m_robotLeft ->setPrevPlayer(m_robotRight);
    m_robotLeft ->setNextPlayer(m_user);

    // 指定当前玩家
    m_currPlayer = m_user;


}

// 得到玩家实例对象
Robot *GameControl::getLeftRobot()
{
    return m_robotLeft;
}

Robot *GameControl::getRightRobot()
{
    return m_robotRight;
}

UserPlayer *GameControl::getUserPlayer()
{
    return m_user;
}

// 当前玩家
void GameControl::setCurrentPlayer(Player *player)
{
    m_currPlayer = player;
}

Player *GameControl::getCurrentPlayer()
{
    return m_currPlayer;
}

// 得到出牌玩家和出牌
Player *GameControl::getPendPlayer()
{
    return m_pendPlayer;
}

Cards GameControl::getPendCards()
{
    return m_pendCards;
}

// 2 扑克牌部分
// 初始化扑克牌
void GameControl::initAllCards()
{
    m_allCards.clear();
//    for(Card::CardPoint p = Card::Card_Begin+1;p<Card::Card_BJ; ++p){
//        for(Card::CardSuit s = Card::Suit_Begin+1; s<Card::Suit_End; ++s){
//            Card card(p,s);
//            m_allCards.add(card);
//        }
//    }

    for(int p = Card::Card_Begin+1;p<Card::Card_BJ; ++p){
        for(int s = Card::Suit_Begin+1; s<Card::Suit_End; ++s){
            Card card(static_cast<Card::CardPoint>(p),
                      static_cast<Card::CardSuit>(p));
            m_allCards.add(card);
        }
    }

    m_allCards.add(Card(Card::Card_SJ,Card::Suit_Begin));
    m_allCards.add(Card(Card::Card_BJ,Card::Suit_Begin));
}

// 每次发一张牌
Card GameControl::takeOneCard()
{
    return m_allCards.takeRandomCard();
}

// 得到最后三张牌
Cards GameControl::getSurplusCards()
{
    return m_allCards;
}
// 重置卡牌数据
void GameControl::resetCardData()
{
    // 清空玩家手里的牌
    m_robotLeft->clearCards();
    m_robotRight->clearCards();
    m_user->clearCards();
    // 洗牌
    initAllCards();
    // 初始化出牌玩家和牌
    m_pendPlayer = nullptr;
    m_pendCards.clear();

}

// 准备叫地主
void GameControl::startLordCard()
{
    m_currPlayer->prepareCallLord();
}

// 成为地主
void GameControl::becomeLord(Player* player)
{
    player->setRole(Player::Lord);
    player->getPrePlayer()->setRole(Player::Farmer);
    player->getNextPlayer()->setRole(Player::Farmer);

    m_currPlayer = player;
    // 这里感觉逻辑不严谨，与getSurplusCards()协调的不好
    player->storeLordCard(m_allCards);

    m_currPlayer->preparePlayHand();

}

// 清空所有玩家得分
void GameControl::clearPlayerScore()
{
    m_robotLeft->setScore(0);
    m_robotRight->setScore(0);
    m_user->setScore(0);
}
