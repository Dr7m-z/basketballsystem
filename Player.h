#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QDate>

//此类用于存储运动员信息
class Player
{
public:
    Player();//初始化运动员信息
    QString m_szName;//姓名
    QString m_szTeam;//队名
    int m_nPointer;//三分球个数
    int m_nRebound;//篮板球个数
    int m_nDunk;//扣篮成功个数
    int m_nSteal;//抢断次数
    double m_dScores;//得分
    QDate m_Date;//比赛日期
};

#endif // PLAYER_H
