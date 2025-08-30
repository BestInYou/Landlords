#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include "robot.h"
#include "userplayer.h"
#include "card.h"
#include "cards.h"

class GameControl : public QObject
{
    Q_OBJECT
public:
    // 0 内置枚举类型
    // 游戏状态
    enum GameStatus{
        DispatchCard,   // 发牌
        CallingLord,    // 叫地主
        PlayingHand     // 出牌
    };

    // 玩家状态
    enum PlayerStatus{
        ThinkingForCallLord,    // 考虑叫地主
        ThinkingForPlayHand,    // 考虑出牌
        Winning                 // 获胜
    };

    explicit GameControl(QObject *parent = nullptr);

    // 1 玩家部分
    // 初始化玩家
    void PlayerInit();

    // 得到玩家的实例对象
    Robot* getLeftRobot();
    Robot* getRightRobot();
    UserPlayer* getUserPlayer();

    // 当前玩家
    void setCurrentPlayer(Player* player);
    Player* getCurrentPlayer();

    // 得到出牌玩家和打出的牌
    Player* getPendPlayer();
    Cards getPendCards();

    // 2 扑克牌部分
    // 初始化扑克牌
    void initAllCards();

    // 每次发一张牌
    Card takeOneCard();
    // 得到最后一张牌
    Cards getSurplusCards();
    // 重置卡牌数据
    void resetCardData();

    // 3 叫地主抢地主
    // 准备叫地主
    void startLordCard();
    // 成为地主
    void becomeLord(Player* player);

    // 清空所有玩家的得分
    void clearPlayerScore();
    // 处理叫地主

    // 处理出牌

signals:

private:
    // 1 玩家部分私有变量
    Robot* m_robotLeft;
    Robot* m_robotRight;
    UserPlayer* m_user;

    Player* m_currPlayer;   // 当前玩家

    Cards m_pendCards;      // 出牌玩家和打出的牌
    Player* m_pendPlayer;

    // 扑克牌部分私有变量
    Cards m_allCards;
};

#endif // GAMECONTROL_H
