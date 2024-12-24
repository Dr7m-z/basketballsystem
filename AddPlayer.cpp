#include "AddPlayer.h"
#include "ui_AddPlayer.h"
#include<QFile>
#include"ManageWidget.h"
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QMap>

//添加运动员页面
AddPlayer::AddPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddPlayer)
{
    ui->setupUi(this);
}

AddPlayer::~AddPlayer()
{
    delete ui;
}

//存储如文件
void AddPlayer::saveToFile(const QString&filename){
    //保存汇总列表至汇总文件
    QFile file2("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");
    //检查是否打开文件file2
    if(!file2.open(QIODevice::WriteOnly)){
        qInfo()<<"open failed";
    }
    else{
        qInfo()<<"open3 successful";
    }

    QTextStream stream2(&file2);

    //判断更新或新增，并将信息存入文件
    if(!same){
        for(int i=0;i<playersummaryList.size()-7;i+=8){
            stream2<<playersummaryList[i]<<","<<playersummaryList[i+1]<<","<<playersummaryList[i+2]<<","
                    <<playersummaryList[i+3]<<","<<playersummaryList[i+4]<<","<<playersummaryList[i+5]
                    <<","<<playersummaryList[i+6]<<","<<playersummaryList[i+7]<<"\n";
        }
    }
    else{
        for(int i=0;i<playersummaryList.size()-15;i+=8){
            stream2<<playersummaryList[i]<<","<<playersummaryList[i+1]<<","<<playersummaryList[i+2]<<","
                    <<playersummaryList[i+3]<<","<<playersummaryList[i+4]<<","<<playersummaryList[i+5]
                    <<","<<playersummaryList[i+6]<<","<<playersummaryList[i+7]<<"\n";
        }
    }
    qDebug()<<"完成";
    //关闭文件
    file2.close();

}


//添加运动员信息
void AddPlayer::addplayer(){

    //读取输入信息
    player.m_szName=ui->NamelineEdit->text();
    player.m_szTeam=ui->TeamlineEdit->text();
    player.m_nPointer=ui->PointerspinBox->value();
    player.m_nRebound=ui->ReboundspinBox->value();
    player.m_nDunk=ui->DunkspinBox->value();
    player.m_nSteal=ui->StealspinBox->value();
    player.m_dScores=ui->ScoresSpinBox->value();
    player.m_Date=ui->DateEdit->date();

    //打开文件
    QFile file("C:\\Qt\\Test\\BasketballPlayerManage\\Player.csv");
    //判断是否打开file
    if(!file.open(QIODevice::Append)){
        qInfo()<<"open failed";
    }
    else{
        qInfo()<<"open successful";
    }

    QTextStream stream(&file);

    stream<<player.m_szName<<","<<player.m_szTeam<<","<<player.m_nPointer<<","
           <<player.m_nRebound<<","<<player.m_nDunk<<","<<player.m_nSteal<<","
           <<player.m_dScores<<","<<player.m_Date.toString()<<"\n";

    //及时关闭文件file
    file.close();  
}

//添加运动员信息到信息汇总表
void AddPlayer::addplayersummary(){
    QFile file("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");

    //判断是否打开文件
    if(!file.open(QIODevice::ReadOnly)){
        qInfo()<<"open failed";
    }
    else{
        qInfo()<<"open2 successful";
    }

    QTextStream stream(&file);

    //循环将文件中数据读取至运动员信息汇总的列表
    while(!stream.atEnd()){
        QStringList linedata=stream.readLine().split(",");
        for(int i=0;i<linedata.size();i++){
            playersummaryList<<linedata[i];
        }

    }

    //检验读取信息是否正确（可删）
    qDebug()<<playersummaryList;

    //读取输入信息
    player.m_szName=ui->NamelineEdit->text();
    player.m_szTeam=ui->TeamlineEdit->text();
    player.m_nPointer=ui->PointerspinBox->value();
    player.m_nRebound=ui->ReboundspinBox->value();
    player.m_nDunk=ui->DunkspinBox->value();
    player.m_nSteal=ui->StealspinBox->value();
    player.m_dScores=ui->ScoresSpinBox->value();
    player.m_Date=ui->DateEdit->date();

    //将读取信息录入信息汇总列表
    playersummaryList<<player.m_szName<<player.m_szTeam<<QString::number(player.m_nPointer)
               <<QString::number(player.m_nRebound)<<QString::number(player.m_nDunk)<<
        QString::number(player.m_nSteal)<<QString::number(player.m_dScores)<<QString::number(1);

    //查看列表大小（可删）
    int r=playersummaryList.size();
    qDebug()<<r;

    //检查是否录入所输入信息
    qDebug()<<playersummaryList;

    //循环更新信息汇总表

    for(int i=0;i<r-8;i+=8){

        //假设旧列表成员姓名与新成员姓名都不同
        same=false;

        //判断是否有相同的成员
        if(playersummaryList[i]==player.m_szName){
            playersummaryList[i+2]=QString::number(playersummaryList[i+2].toInt()+player.m_nPointer);
            playersummaryList[i+3]=QString::number(playersummaryList[i+3].toInt()+player.m_nRebound);
            playersummaryList[i+4]=QString::number(playersummaryList[i+4].toInt()+player.m_nDunk);
            playersummaryList[i+5]=QString::number(playersummaryList[i+5].toInt()+player.m_nSteal);
            playersummaryList[i+6]=QString::number(playersummaryList[i+6].toDouble()+player.m_dScores);
            playersummaryList[i+7]=QString::number(playersummaryList[i+7].toInt()+1);

            //有相同成员，退出循环
            same=true;
            break;
        }

    }


    //检验是否完成更新，更新是否正确
    qDebug()<<"here2";
    qDebug()<<playersummaryList;

    saveToFile("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");
}

//确定按钮槽函数
void AddPlayer::on_comfirmButton_released()
{
    addplayer();//添加成员
    addplayersummary();//更新汇总

    //关闭页面
    this->close();

    //打开至主页面
    ManageWidget *manage=new ManageWidget;
    manage->show();
}


void AddPlayer::on_cancleButton_released()
{
    //退出该页面，回到主页面
    this->close();

    //打开至主页面
    ManageWidget *manage=new ManageWidget;
    manage->show();
}

