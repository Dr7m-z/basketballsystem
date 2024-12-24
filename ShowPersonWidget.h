#ifndef SHOWPERSONWIDGET_H
#define SHOWPERSONWIDGET_H
#include<QStandardItemModel>
#include <QWidget>
#include<QString>
#include"Player.h"
#include"PlayerSummary.h"

//此页面用于展示运动员信息汇总表，并用于查询个人信息汇总，查询队内前三名和查询不同项目整体排名前三名
namespace Ui {
class ShowPersonWidget;
}

class ShowPersonWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowPersonWidget(QWidget *parent = nullptr);
    ~ShowPersonWidget();

    void readPlayerSummaryFromFile(const QString&filename); //从指定文件读取数据

    void savePlayerSummaryToFile(const QString&filename); //把表格中数据保存到指定文件

    void showperson();//展示指定个人信息汇总表

    void RangeTeam();//展示队内排名前三名运动员信息

    void RangeAll();//展示指定项目全体排名前三名的同学

private slots:
    void on_pushButton_released();//查询个人信息汇总

    void on_pushButton_2_released();//查询队内前三名运动员信息

    void on_ItemButton_released();//查询指定项目全体前三名同学信息（项目分数为场均分数）

    void on_returnButton_released();//返回主页面

private:
    Ui::ShowPersonWidget *ui;
    QStandardItemModel *model2;//用于初始此页面表格，展示全体汇总表和指定个人
    QStandardItemModel *model3;//用于展示队内排名
    QStandardItemModel *model4;//用于展示全体单项技术排名
    Player player;
    PlayerSummary playsummary;
    QStringList playerList;//运动员列表
    QStringList playersummaryList2;//用于展示队内排名列表
    QStringList playersummaryList3;//用于展示全体单项技术排名列表

};

#endif // SHOWPERSONWIDGET_H
