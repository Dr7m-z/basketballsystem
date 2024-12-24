#ifndef MANAGEWIDGET_H
#define MANAGEWIDGET_H
#include<QStandardItemModel>
#include <QWidget>
#include<QString>
#include<Player.h>
#include<PlayerSummary.h>
#include"AddPlayer.h"
#include"ShowPersonWidget.h"

//此页面为主页面，实现添加，删除，保存和转入查询页面
namespace Ui {
class ManageWidget;
}

class ManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ManageWidget(QWidget *parent = nullptr);
    ~ManageWidget();

    void readPlayerFromFile(const QString&filename);//从指定文件读取数据

    void savePlayerToFile(const QString&filename); //把表格中数据保存到指定文件
private slots:

    void on_CancleButton_released();//退出系统

    void on_AddButton_released();//添加运动员

    void on_SaveButton_released();//保存当前运动员列表

    void on_DeleteButton_released();//删除点击的运动员信息

    void on_SearchPersonButton_released();//转入查询页面

private:
    Ui::ManageWidget *ui;
    QStandardItemModel *model;//用于将运动员信息写入tableview
    Player player;
    PlayerSummary playsummary;
    AddPlayer *addplayer;//用于转入添加运动员页面
    ShowPersonWidget *showpersonwidget;//用于转入查询页面
};

#endif // MANAGEWIDGET_H
