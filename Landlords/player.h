#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "cards.h"

class Player : public QObject
{
    // 任何继承自QObject的类，如果要用信号/槽、元对象系统，都必须加上这个宏
    // Q_OBJECT会被moc处理，生成一堆隐藏的代码，支持信号槽、反射等功能
    Q_OBJECT
public:
    enum Role{Lord, Farmer};    // 角色
    enum Sex{Man, Woman};       // 性别
    enum Direction{Left,Right}; // 头像显示方位
    enum Type{Robot, User, Unknow}; // 玩家类型


    // explicit 明确的，阻止编译器进行隐式类型转换
    explicit Player(QObject *parent = nullptr);
    explicit Player(QString name, QObject *parent = nullptr);

    // 名字
    void setName(QString name);
    QString getName();

    // 角色
    void setRole(Role role);
    Role getRole();

    // 性别
    void setSex(Sex sex);
    Sex getSex();

    // 头像显示方位
    void setDirection(Direction direction);
    Direction getDirection();

    // 玩家类别
    void setType(Type type);
    Type getType();

    // 玩家分数
    void setScore(int score);
    int getScore();

    // 赢了输了
    void setWin(bool flag);
    bool isWin();

    // 提供当前对象的上家/下家对象
    void setPrevPlayer(Player* player);
    void setNextPlayer(Player* player);
    Player* getPrePlayer();
    Player* getNextPlayer();

    // 叫地主/抢地主
    void grabLordBet(int point);

    // 存储扑克牌(发牌的时候得到的)
    void storeDispatchCard(Card& card);
    void storeLordCard(Cards& cards);

    // 得到所有的牌
    Cards getCards();

    // 清空所有的牌
    void clearCards();

    // 出牌
    void playHand(Cards& cards);

    // 设置出牌的玩家已经待处理的扑克牌
    void setPendingInfo(Player* pendPlayer, Cards& pendCards);
    Player* getPendPlayer();
    Cards getPendCards();

    // 虚函数，用于实现多态
    virtual void prepareCallLord();
    virtual void preparePlayHand();

signals:

protected:
    // 受保护的成员变量，子类可以继承
    QString m_name;
    Role m_role;
    Sex m_sex;
    Direction m_direction;
    Type m_type;
    int m_score;    // 玩家分数
    bool m_isWin;   // 赢了输了

    Player* m_prevPlayer;
    Player* m_nextPlayer;

    Cards m_cards;  // 存储多张扑克牌（玩家手中的牌）

    Cards m_pendCards;  // 当前打出的牌
    Player* m_pendPlayer;   // 出牌的玩家
};

#endif // PLAYER_H
