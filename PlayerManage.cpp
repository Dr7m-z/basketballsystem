#include "PlayerManage.h"

PlayerManage::PlayerManage() {}

void PlayerManage::addPlayer(const Player& player) {
    playerList.append(player);
    storage.savePlayer(player);
    storage.loadPlayer(playerList);
    m_isUpdateDlg=false;
    updatePlayer(player, playerList);
    storage.savePlayer(player);
}

void PlayerManage::updatePlayer(const Player& player, QList<Player>& playerList){
    for (auto& playerbefore : playerList) {
        if (m_isUpdateDlg){
            playerbefore.setData(player.getname(),player.getteam(),player.getpointer(),player.getrebound(),
                                 player.getdunk(),player.getsteal(),player.getscores(),player.getdate());
        }
        else{
            Player newplayer;
            newplayer.setData(player.getname(),player.getteam(),player.getpointer(),player.getrebound(),
                              player.getdunk(),player.getsteal(),player.getscores(),player.getdate());
            playerList.append(newplayer);
        }
    }

    storage.savePlayer(player);

}








void PlayerManage::updatePlayerSummary(const Player& player, QList<PlayerSummary>& playersummaryList) {
    for (auto& playersummary : playersummaryList) {
        if (playersummary.getplayername() == player.getname()) {
            playersummary.setpointers( playersummary.getpointers()+ player.getpointer());
            playersummary.setrebounds( playersummary.getrebounds()+ player.getrebound());
            playersummary.setdunks( playersummary.getdunks()+ player.getdunk());
            playersummary.setsteals( playersummary.getsteals()+ player.getsteal());
            playersummary.settscores( playersummary.gettscores()+ player.getscores());
            playersummary.setcounts(playersummary.getcounts()+1);
            return;
        }
    }
    // 如果球员不存在，则新建
    PlayerSummary newplayersummary;
    newplayersummary.setplayername( player.getname());
    newplayersummary.setpointers(player.getpointer());
    newplayersummary.setrebounds(player.getrebound());
    newplayersummary.setdunks( player.getdunk());
    newplayersummary.setsteals( player.getsteal());
    newplayersummary.settscores( player.getscores());
    newplayersummary.setcounts(1);
    playersummaryList.append(newplayersummary);
    storage.savePlayerSummary(newplayersummary);
}
