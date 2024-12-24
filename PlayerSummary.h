#ifndef PLAYERSUMMARY_H
#define PLAYERSUMMARY_H
#include<QString>

//此类用于汇总运动员信息，查询运动员信息汇总表，队内排名表与单项排名表
class PlayerSummary
{
public:
    PlayerSummary();//初始化
    QString playerName;//运动员姓名
    int totalPointers;//三分球总个数
    int totalRebounds;//篮板球总个数
    int totalDunks;//扣篮总次数
    int totalSteals;//抢断总次数
    double totalScores;//得分总数
    int matchCount;//比赛场数
};

#endif // PLAYERSUMMARY_H
