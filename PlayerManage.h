#ifndef PLAYERMANAGE_H
#define PLAYERMANAGE_H
#include "CDataStorage.h"
#include<QStandardItemModel>
class PlayerManage
{
public:
    PlayerManage();
    void addPlayer(const Player& player);//添加player存入list，存入文件
    void updatePlayer(const Player& player, QList<Player>& playerList);//根据m_isUpdateDlg，更新或者添加player,存入list和文件

    void updatePlayerSummary(const Player& player, QList<PlayerSummary>& playersummaryList);
    //更新PlayerSummary的list和文件

    //void displayPlayerSummaryTable();
    //void displayTopThreePlayersByAverage(QString technicalItem);
    //void displayTopThreePlayersInTeam(QString teamName);
private:
    CDataStorage storage;
    QList<Player>playerList;
    QList<PlayerSummary> playersummaryList;
    bool m_isUpdateDlg;
    //QStandardItemModel *m_standardModel;//model
};

#endif // PLAYERMANAGE_H
