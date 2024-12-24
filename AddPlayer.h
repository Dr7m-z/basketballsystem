#ifndef ADDPLAYER_H
#define ADDPLAYER_H
#include <QWidget>
#include<Player.h>
#include<PlayerSummary.h>

//此页面用于添加运动员信息到运动员列表和运动员信息汇总列表
namespace Ui {
class AddPlayer;
}

class AddPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit AddPlayer(QWidget *parent = nullptr);
    ~AddPlayer();
    void addplayer();//添加运动员到运动员列表
    void addplayersummary();//添加运动员到运动员信息汇总列表
    void saveToFile(const QString&filename);//把列表信息保存到文件中
private slots:
    void on_comfirmButton_released();//确定添加

    void on_cancleButton_released();//退出该页面

private:
    Ui::AddPlayer *ui;
    Player player;
    PlayerSummary playersummary;
    QStringList playerList;
    QStringList playersummaryList;
    bool same;//判断为新成员，true为旧列表成员，更新汇总表即可；false为新成员，表中需要添加新的成员信息

};

#endif // ADDPLAYER_H
