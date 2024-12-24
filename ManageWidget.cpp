#include "ManageWidget.h"
#include "ui_ManageWidget.h"
#include<QFile>
#include<QDebug>
#include<QTextStream>
#include<QStandardItemModel>
#include<QMessageBox>

//此页面为主页面，用于实现添加，删除，保存运动员信息，转入查询页面和退出系统
ManageWidget::ManageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ManageWidget)
    ,model(NULL)
    ,addplayer(NULL)
    ,showpersonwidget(NULL)
{
    //初始化
    ui->setupUi(this);
    model=new QStandardItemModel(this);
    ui->tableView->setModel(model);
    readPlayerFromFile("C:\\Qt\\Test\\BasketballPlayerManage\\Player.csv");
}

ManageWidget::~ManageWidget()
{
    delete ui;
}

//退出系统
void ManageWidget::on_CancleButton_released()
{
    //提示是否确认退出，yes退出，no不退出
    int res=QMessageBox::information(this,"提示","是否确认退出",QMessageBox::Yes|QMessageBox::No);
    if(res==QMessageBox::No) return;
    this->close();
}

//读取信息到tableview
void ManageWidget::readPlayerFromFile(const QString&filename){
    QFile file(filename);

    //判断是否正确打开文件
    if(!file.open(QIODevice::ReadOnly)){
        qInfo()<<filename<<"open failed";
    }
    else{
        qInfo()<<"open successful";
    }

    //添加表头
    QStringList headerlist;
    headerlist<<"姓名"<<"所属队伍"<<"三分球个数"<<"篮板球个数"<<"扣篮次数"<<"抢断次数"<<"得分数"<<"比赛日期";
    model->setHorizontalHeaderLabels(headerlist);

    QTextStream stream(&file);

    //读取至model
    while(!stream.atEnd()){
        QStringList linedata=stream.readLine().split(",");
        QList<QStandardItem*> players;
        for(QString data:linedata){
            players.push_back(new QStandardItem(data));
    }
    model->appendRow(players);
    }
}

//存储运动员信息至文件
void  ManageWidget::savePlayerToFile(const QString&filename){
    QFile file(filename);

    //判断是否正确打开
    if(!file.open(QIODevice::WriteOnly)){
        qInfo()<<"savePlayerToFile open failed";
    }
    QTextStream stream(&file);

    //读取总列数
    int column=model->columnCount();

    //保存数据
    for(int r=0;r<model->rowCount();r++)
    {   QString lineData;
        for(int i=0;i<column;i++){
            if(!model->item(r,i)){
                goto end;
            }
            lineData.push_back(model->item(r,i)->text());
            if(i!=column-1){
                lineData.push_back(",");
            }
        }
        stream<<lineData<<"\n";
    }
end:;
}


//实现添加运动员信息槽函数
void ManageWidget::on_AddButton_released()
{
    //提示功能
    qInfo()<<"添加运动员";

    //转入添加页面
    addplayer=new AddPlayer;
    addplayer->show();
    this->close();
}

//实现保存数据槽函数
void ManageWidget::on_SaveButton_released()
{
    //提示功能
    qInfo()<<"保存运动员";

    //保存至文件
    savePlayerToFile("C:\\Qt\\Test\\BasketballPlayerManage\\Player.csv");

    //提示保存成功
    QMessageBox::information(this,"提示","保存成功!");
}

//实现删除数据槽函数
void ManageWidget::on_DeleteButton_released()
{
    //提示功能
    qInfo()<<"删除运动员";

    //警示是否删除
    int res=QMessageBox::information(this,"提示","是否确认删除",QMessageBox::Yes|QMessageBox::No);
    if(res==QMessageBox::No) return;

    //获取当前选中删除运动员
    QModelIndex index=ui->tableView->currentIndex();
    int row=index.row();
    model->removeRow(row);

    //保存当前数据
    savePlayerToFile("C:\\Qt\\Test\\BasketballPlayerManage\\Player.csv");

}

//转入查询页面
void ManageWidget::on_SearchPersonButton_released()
{
    //提示功能
    qInfo()<<"查询运动员";

    //转入查询页面
    showpersonwidget=new ShowPersonWidget;
    showpersonwidget->show();
}



