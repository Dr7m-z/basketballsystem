#include "ShowPersonWidget.h"
#include "ui_ShowPersonWidget.h"
#include <QSortFilterProxyModel>
#include <QRegularExpression>
#include<QFile>
#include<QDebug>
#include<QTextStream>
#include<QStandardItemModel>
#include<QMessageBox>

//此页面用于展示全体汇总信息学，及查询个人，队内和指定项目排名
ShowPersonWidget::ShowPersonWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ShowPersonWidget)
    ,model2(NULL)
    ,model3(NULL)
    ,model4(NULL)
{
    //初始化
    ui->setupUi(this);
    model2=new QStandardItemModel(this);
    model3=new QStandardItemModel;
    model4=new QStandardItemModel;
    ui->tableView->setModel(model2);
    readPlayerSummaryFromFile("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");
}

ShowPersonWidget::~ShowPersonWidget()
{
    delete ui;
}

//读取信息到tableview
void ShowPersonWidget::readPlayerSummaryFromFile(const QString&filename){
    QFile file(filename);

    //判断是否打开
    if(!file.open(QIODevice::ReadOnly)){
        qInfo()<<filename<<"open failed";
    }
    else{
        qInfo()<<"open successful";
    }

    //添加表头
    QStringList headerlist;
    headerlist<<"姓名"<<"所属队伍"<<"三分球总个数"<<"篮板球总个数"<<"扣篮总次数"<<"抢断总次数"<<"得分总数"<<"比赛总场数";
    model2->setHorizontalHeaderLabels(headerlist);

    QTextStream stream(&file);

    //读取信息汇总表到model2
    while(!stream.atEnd()){
        QStringList linedata=stream.readLine().split(",");
        QList<QStandardItem*> playersummary;
        for(QString data:linedata){
            playersummary.push_back(new QStandardItem(data));
        }
        model2->appendRow(playersummary);
    }
}

//保存信息到汇总表文件
void  ShowPersonWidget::savePlayerSummaryToFile(const QString&filename){
    QFile file(filename);

    //判断是否正确打开
    if(!file.open(QIODevice::WriteOnly)){
        qInfo()<<"savePlayerSummaryToFile open failed";
    }
    QTextStream stream(&file);

    //获取model2列数
    int column=model2->columnCount();

    //保存数据
    for(int r=0;r<model2->rowCount();r++)
    {   QString lineData;
        for(int i=0;i<column;i++){
            if(!model2->item(r,i)){
                goto end;
            }
            lineData.push_back(model2->item(r,i)->text());
            if(i!=column-1){
                lineData.push_back(",");
            }
        }
        stream<<lineData<<"\n";
    }
end:;
}

//利用过滤模型查询指定个人汇总表
void ShowPersonWidget::showperson(){
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model2);
    QString name=ui->SearchlineEdit->text();
    QRegularExpression reg(name);
    proxyModel->setFilterRegularExpression(reg);
    proxyModel->setFilterKeyColumn(0);
    ui->tableView->setModel(proxyModel);

}

//查询个人
void ShowPersonWidget::on_pushButton_released()
{
    showperson();
}


//利用排序与过滤模型展示队内排名表
void ShowPersonWidget::RangeTeam(){
    QFile file("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");

    //判断是否正确打开
    if(!file.open(QIODevice::ReadOnly)){
        qInfo()<<"open failed";
    }
    else{
        qInfo()<<"open4 successful";
    }

    QTextStream stream(&file);

    while(!stream.atEnd()){
        QStringList linedata=stream.readLine().split(",");
        for(int i=0;i<linedata.size();i++){
            playersummaryList2<<linedata[i];
        }

    }

    //查看列表信息是否读取正确
    qDebug()<<playersummaryList2;

    //获取列表大小
    int r=playersummaryList2.size();
    qDebug()<<r;

    //利用循环根据总得分排名
    for(int i=0;i<r-8;i+=8){
        for(int j=0;j<r/8-i/8;j++){
            if(playersummaryList2[i+6].toInt()<playersummaryList2[i+6+8*j].toInt()){
                QString tempname=playersummaryList2[i+8*j];
                QString tempteam=playersummaryList2[i+8*j+1];
                QString temppointer=playersummaryList2[i+8*j+2];
                QString temprebound=playersummaryList2[i+8*j+3];
                QString tempdunk=playersummaryList2[i+8*j+4];
                QString tempsteal=playersummaryList2[i+8*j+5];
                QString tempscores=playersummaryList2[i+8*j+6];
                QString tempcount=playersummaryList2[i+8*j+7];
                playersummaryList2[i+8*j]=playersummaryList2[i];
                playersummaryList2[i+8*j+1]=playersummaryList2[i+1];
                playersummaryList2[i+8*j+2]=playersummaryList2[i+2];
                playersummaryList2[i+8*j+3]=playersummaryList2[i+3];
                playersummaryList2[i+8*j+4]=playersummaryList2[i+4];
                playersummaryList2[i+8*j+5]=playersummaryList2[i+5];
                playersummaryList2[i+8*j+6]=playersummaryList2[i+6];
                playersummaryList2[i+8*j+7]=playersummaryList2[i+7];
                playersummaryList2[i]=tempname;
                playersummaryList2[i+1]=tempteam;
                playersummaryList2[i+2]=temppointer;
                playersummaryList2[i+3]=temprebound;
                playersummaryList2[i+4]=tempdunk;
                playersummaryList2[i+5]=tempsteal;
                playersummaryList2[i+6]=tempscores;
                playersummaryList2[i+7]=tempcount;
            }

        }
    }

    //检验是否正确读取
    qDebug()<<"here4";
    qDebug()<<playersummaryList2;

    QFile file3("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummaryRangeTeam.csv");

    //检验是否正确打开
    if(!file3.open(QIODevice::WriteOnly)){
        qInfo()<<"open failed";
    }
    else{
        qInfo()<<"open3 successful";
    }

    QTextStream stream3(&file3);
    for(int i=0;i<playersummaryList2.size();i+=8){
        stream3<<playersummaryList2[i]<<","<<playersummaryList2[i+1]<<","<<playersummaryList2[i+2]<<","
                <<playersummaryList2[i+3]<<","<<playersummaryList2[i+4]<<","<<playersummaryList2[i+5]
                <<","<<playersummaryList2[i+6]<<","<<playersummaryList2[i+7]<<"\n";
    }
    file3.close();

    //检验是否正确打开
    if(!file3.open(QIODevice::ReadOnly)){
        qInfo()<<"open failed";
    }
    else{
        qInfo()<<"open5 successful";
    }
    int a=0;
    //利用循环找到排名前三运动员信息汇总
    while(a<4){
        QStringList linedata=stream3.readLine().split(",");
        QList<QStandardItem*> playersummary;
        for(QString data:linedata){
            playersummary.push_back(new QStandardItem(data));
        }
        model3->appendRow(playersummary);
        a++;
    }

    //过滤模型得到相同队伍
    QSortFilterProxyModel *proxyModel2 = new QSortFilterProxyModel(this);
    proxyModel2->setSourceModel(model3);
    QString team=ui->SearchlineEdit->text();
    QRegularExpression reg2(team);
    proxyModel2->setFilterRegularExpression(reg2);
    proxyModel2->setFilterKeyColumn(1);
    ui->tableView->setModel(proxyModel2);
}

//实现队内排名查询
void ShowPersonWidget::on_pushButton_2_released()
{
    RangeTeam();

}

//根据输入项目名，输出单项平均数据排名
void ShowPersonWidget::RangeAll(){
    //读取项目名
    QString item=ui->SearchlineEdit->text();

    //三分球排名（方法类似于队内排名）
    if(item=="三分球"){
        QFile file("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");
        if(!file.open(QIODevice::ReadOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open4 successful";
        }

        QTextStream stream(&file);

        while(!stream.atEnd()){
            QStringList linedata=stream.readLine().split(",");
            for(int i=0;i<linedata.size();i++){
                playersummaryList3<<linedata[i];
            }

        }

        int r2=playersummaryList3.size();
            qDebug()<<r2;
         qDebug()<<playersummaryList3;

        for(int i=0;i<r2-8;i+=8){
            for(int j=0;j<r2/8-i/8;j++){
                if((playersummaryList3[i+2].toInt()/playersummaryList3[i+7].toInt())<
                    (playersummaryList3[i+2+8*j].toInt()/playersummaryList3[i+7+8*j].toInt())){
                    QString tempname=playersummaryList3[i+8*j];
                    QString tempteam=playersummaryList3[i+8*j+1];
                    QString temppointer=playersummaryList3[i+8*j+2];
                    QString temprebound=playersummaryList3[i+8*j+3];
                    QString tempdunk=playersummaryList3[i+8*j+4];
                    QString tempsteal=playersummaryList3[i+8*j+5];
                    QString tempscores=playersummaryList3[i+8*j+6];
                    QString tempcount=playersummaryList3[i+8*j+7];
                    playersummaryList3[i+8*j]=playersummaryList3[i];
                    playersummaryList3[i+8*j+1]=playersummaryList3[i+1];
                    playersummaryList3[i+8*j+2]=playersummaryList3[i+2];
                    playersummaryList3[i+8*j+3]=playersummaryList3[i+3];
                    playersummaryList3[i+8*j+4]=playersummaryList3[i+4];
                    playersummaryList3[i+8*j+5]=playersummaryList3[i+5];
                    playersummaryList3[i+8*j+6]=playersummaryList3[i+6];
                    playersummaryList3[i+8*j+7]=playersummaryList3[i+7];
                    playersummaryList3[i]=tempname;
                    playersummaryList3[i+1]=tempteam;
                    playersummaryList3[i+2]=temppointer;
                    playersummaryList3[i+3]=temprebound;
                    playersummaryList3[i+4]=tempdunk;
                    playersummaryList3[i+5]=tempsteal;
                    playersummaryList3[i+6]=tempscores;
                    playersummaryList3[i+7]=tempcount;
                }
            }
        }

        qDebug()<<"here5";
        qDebug()<<playersummaryList3;

        QFile file4("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummaryRangeAll.csv");
        if(!file4.open(QIODevice::WriteOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open5 successful";
        }


        qDebug()<<playersummaryList3.size();
        QTextStream stream4(&file4);
        for(int i=0;i<17;i+=8){
            QString pointer=QString::number(playersummaryList3[i+2].toInt()/playersummaryList3[i+7].toInt());
            QString rebound=QString::number(playersummaryList3[i+3].toInt()/playersummaryList3[i+7].toInt());
            QString dunk=QString::number(playersummaryList3[i+4].toInt()/playersummaryList3[i+7].toInt());
            QString steal=QString::number(playersummaryList3[i+5].toInt()/playersummaryList3[i+7].toInt());
            QString scores=QString::number(playersummaryList3[i+6].toInt()/playersummaryList3[i+7].toInt());
            stream4<<playersummaryList3[i]<<","<<playersummaryList3[i+1]<<","
                    <<pointer<<","
                    <<rebound<<","
                    <<dunk<<","
                    <<steal<<","
                    <<scores<<","
                    <<playersummaryList3[i+7]<<"\n";
        }

        file4.close();


        if(!file4.open(QIODevice::ReadOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open6 successful";
        }

        while(!stream4.atEnd()){
            QStringList linedata=stream4.readLine().split(",");

            QList<QStandardItem*> pointersummary;
            for(QString data:linedata){
                pointersummary.push_back(new QStandardItem(data));
            }

            model4->appendRow(pointersummary);
            qDebug()<<"here8";
        }

        ui->tableView->setModel(model4);
    }

    //篮板球排名（方法类似于队内排名）
    else if(item=="篮板球"){
        QFile file("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");
        if(!file.open(QIODevice::ReadOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open4 successful";
        }

        QTextStream stream(&file);

        while(!stream.atEnd()){
            QStringList linedata=stream.readLine().split(",");
            for(int i=0;i<linedata.size();i++){
                playersummaryList3<<linedata[i];
            }

        }
        int r3=playersummaryList3.size();
            qDebug()<<r3;
        qDebug()<<playersummaryList3;

        for(int i=0;i<r3-8;i+=8){
            for(int j=0;j<r3/8-i/8;j++){
                if((playersummaryList3[i+3].toInt()/playersummaryList3[i+7].toInt())<
                    (playersummaryList3[i+3+8*j].toInt()/playersummaryList3[i+7+8*j].toInt())){
                    QString tempname=playersummaryList3[i+8*j];
                    QString tempteam=playersummaryList3[i+8*j+1];
                    QString temppointer=playersummaryList3[i+8*j+2];
                    QString temprebound=playersummaryList3[i+8*j+3];
                    QString tempdunk=playersummaryList3[i+8*j+4];
                    QString tempsteal=playersummaryList3[i+8*j+5];
                    QString tempscores=playersummaryList3[i+8*j+6];
                    QString tempcount=playersummaryList3[i+8*j+7];
                    playersummaryList3[i+8*j]=playersummaryList3[i];
                    playersummaryList3[i+8*j+1]=playersummaryList3[i+1];
                    playersummaryList3[i+8*j+2]=playersummaryList3[i+2];
                    playersummaryList3[i+8*j+3]=playersummaryList3[i+3];
                    playersummaryList3[i+8*j+4]=playersummaryList3[i+4];
                    playersummaryList3[i+8*j+5]=playersummaryList3[i+5];
                    playersummaryList3[i+8*j+6]=playersummaryList3[i+6];
                    playersummaryList3[i+8*j+7]=playersummaryList3[i+7];
                    playersummaryList3[i]=tempname;
                    playersummaryList3[i+1]=tempteam;
                    playersummaryList3[i+2]=temppointer;
                    playersummaryList3[i+3]=temprebound;
                    playersummaryList3[i+4]=tempdunk;
                    playersummaryList3[i+5]=tempsteal;
                    playersummaryList3[i+6]=tempscores;
                    playersummaryList3[i+7]=tempcount;
                }
            }
        }

        qDebug()<<"here6";
        qDebug()<<playersummaryList3;

        QFile file5("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummaryRangeAll.csv");
        if(!file5.open(QIODevice::WriteOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open6 successful";
        }

        qDebug()<<playersummaryList3.size();

        QTextStream stream5(&file5);

        for(int i=0;i<17;i+=8){
            QString pointer=QString::number(playersummaryList3[i+2].toInt()/playersummaryList3[i+7].toInt());
            QString rebound=QString::number(playersummaryList3[i+3].toInt()/playersummaryList3[i+7].toInt());
            QString dunk=QString::number(playersummaryList3[i+4].toInt()/playersummaryList3[i+7].toInt());
            QString steal=QString::number(playersummaryList3[i+5].toInt()/playersummaryList3[i+7].toInt());
            QString scores=QString::number(playersummaryList3[i+6].toInt()/playersummaryList3[i+7].toInt());
            stream5<<playersummaryList3[i]<<","<<playersummaryList3[i+1]<<","
                    <<pointer<<","
                    <<rebound<<","
                    <<dunk<<","
                    <<steal<<","
                    <<scores<<","
                    <<playersummaryList3[i+7]<<"\n";
        }
        file5.close();
        if(!file5.open(QIODevice::ReadOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open6 successful";
        }

        while(!stream5.atEnd()){
            QStringList linedata=stream5.readLine().split(",");

            QList<QStandardItem*> reboundsummary;
            for(QString data:linedata){
                reboundsummary.push_back(new QStandardItem(data));
            }

            model4->appendRow(reboundsummary);
            qDebug()<<"here9";
        }

        ui->tableView->setModel(model4);
    }

    //扣篮排名（方法类似于队内排名）
    else if(item=="扣篮"){
        QFile file("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");

        if(!file.open(QIODevice::ReadOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open4 successful";
        }

        QTextStream stream(&file);

        while(!stream.atEnd()){
            QStringList linedata=stream.readLine().split(",");
            for(int i=0;i<linedata.size();i++){
                playersummaryList3<<linedata[i];
            }

        }

        int r4=playersummaryList3.size();
            qDebug()<<r4;
         qDebug()<<playersummaryList3;

        for(int i=0;i<r4-8;i+=8){
            for(int j=0;j<r4/8-i/8;j++){
                if((playersummaryList3[i+4].toInt()/playersummaryList3[i+7].toInt())<
                    (playersummaryList3[i+4+8*j].toInt()/playersummaryList3[i+7+8*j].toInt())){
                    QString tempname=playersummaryList3[i+8*j];
                    QString tempteam=playersummaryList3[i+8*j+1];
                    QString temppointer=playersummaryList3[i+8*j+2];
                    QString temprebound=playersummaryList3[i+8*j+3];
                    QString tempdunk=playersummaryList3[i+8*j+4];
                    QString tempsteal=playersummaryList3[i+8*j+5];
                    QString tempscores=playersummaryList3[i+8*j+6];
                    QString tempcount=playersummaryList3[i+8*j+7];
                    playersummaryList3[i+8*j]=playersummaryList3[i];
                    playersummaryList3[i+8*j+1]=playersummaryList3[i+1];
                    playersummaryList3[i+8*j+2]=playersummaryList3[i+2];
                    playersummaryList3[i+8*j+3]=playersummaryList3[i+3];
                    playersummaryList3[i+8*j+4]=playersummaryList3[i+4];
                    playersummaryList3[i+8*j+5]=playersummaryList3[i+5];
                    playersummaryList3[i+8*j+6]=playersummaryList3[i+6];
                    playersummaryList3[i+8*j+7]=playersummaryList3[i+7];
                    playersummaryList3[i]=tempname;
                    playersummaryList3[i+1]=tempteam;
                    playersummaryList3[i+2]=temppointer;
                    playersummaryList3[i+3]=temprebound;
                    playersummaryList3[i+4]=tempdunk;
                    playersummaryList3[i+5]=tempsteal;
                    playersummaryList3[i+6]=tempscores;
                    playersummaryList3[i+7]=tempcount;
                }
            }
        }

        qDebug()<<"here6";
        qDebug()<<playersummaryList3;

        QFile file6("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummaryRangeAll.csv");

        if(!file6.open(QIODevice::WriteOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open7 successful";
        }

        qDebug()<<playersummaryList3.size();

        QTextStream stream6(&file6);

        for(int i=0;i<17;i+=8){
            QString pointer=QString::number(playersummaryList3[i+2].toInt()/playersummaryList3[i+7].toInt());
            QString rebound=QString::number(playersummaryList3[i+3].toInt()/playersummaryList3[i+7].toInt());
            QString dunk=QString::number(playersummaryList3[i+4].toInt()/playersummaryList3[i+7].toInt());
            QString steal=QString::number(playersummaryList3[i+5].toInt()/playersummaryList3[i+7].toInt());
            QString scores=QString::number(playersummaryList3[i+6].toInt()/playersummaryList3[i+7].toInt());
            stream6<<playersummaryList3[i]<<","<<playersummaryList3[i+1]<<","
                    <<pointer<<","
                    <<rebound<<","
                    <<dunk<<","
                    <<steal<<","
                    <<scores<<","
                    <<playersummaryList3[i+7]<<"\n";
        }

        file6.close();

        if(!file6.open(QIODevice::ReadOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open6 successful";
        }

        while(!stream6.atEnd()){
            QStringList linedata=stream6.readLine().split(",");

            QList<QStandardItem*> dunksummary;
            for(QString data:linedata){
                dunksummary.push_back(new QStandardItem(data));
            }

            model4->appendRow(dunksummary);
            qDebug()<<"here10";
        }

        ui->tableView->setModel(model4);
    }

    //抢断排名（方法类似于队内排名）
    else if(item=="抢断"){
        QFile file("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummary.csv");

        if(!file.open(QIODevice::ReadOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open4 successful";
        }

        QTextStream stream(&file);

        while(!stream.atEnd()){
            QStringList linedata=stream.readLine().split(",");
            for(int i=0;i<linedata.size();i++){
                playersummaryList3<<linedata[i];
            }

        }
        int r5=playersummaryList3.size();
            qDebug()<<r5;
         qDebug()<<playersummaryList3;

        for(int i=0;i<r5-8;i+=8){
            for(int j=0;j<r5/8-i/8;j++){
                if((playersummaryList3[i+5].toInt()/playersummaryList3[i+7].toInt())<
                    (playersummaryList3[i+5+8*j].toInt()/playersummaryList3[i+7+8*j].toInt())){
                    QString tempname=playersummaryList3[i+8*j];
                    QString tempteam=playersummaryList3[i+8*j+1];
                    QString temppointer=playersummaryList3[i+8*j+2];
                    QString temprebound=playersummaryList3[i+8*j+3];
                    QString tempdunk=playersummaryList3[i+8*j+4];
                    QString tempsteal=playersummaryList3[i+8*j+5];
                    QString tempscores=playersummaryList3[i+8*j+6];
                    QString tempcount=playersummaryList3[i+8*j+7];
                    playersummaryList3[i+8*j]=playersummaryList3[i];
                    playersummaryList3[i+8*j+1]=playersummaryList3[i+1];
                    playersummaryList3[i+8*j+2]=playersummaryList3[i+2];
                    playersummaryList3[i+8*j+3]=playersummaryList3[i+3];
                    playersummaryList3[i+8*j+4]=playersummaryList3[i+4];
                    playersummaryList3[i+8*j+5]=playersummaryList3[i+5];
                    playersummaryList3[i+8*j+6]=playersummaryList3[i+6];
                    playersummaryList3[i+8*j+7]=playersummaryList3[i+7];
                    playersummaryList3[i]=tempname;
                    playersummaryList3[i+1]=tempteam;
                    playersummaryList3[i+2]=temppointer;
                    playersummaryList3[i+3]=temprebound;
                    playersummaryList3[i+4]=tempdunk;
                    playersummaryList3[i+5]=tempsteal;
                    playersummaryList3[i+6]=tempscores;
                    playersummaryList3[i+7]=tempcount;
                }
            }
        }

        qDebug()<<"here7";
        qDebug()<<playersummaryList3;

        QFile file6("C:\\Qt\\Test\\BasketballPlayerManage\\PlayerSummaryRangeAll.csv");

        if(!file6.open(QIODevice::WriteOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open7 successful";
        }

        qDebug()<<playersummaryList3.size();

        QTextStream stream6(&file6);

        for(int i=0;i<17;i+=8){
            QString pointer=QString::number(playersummaryList3[i+2].toInt()/playersummaryList3[i+7].toInt());
            QString rebound=QString::number(playersummaryList3[i+3].toInt()/playersummaryList3[i+7].toInt());
            QString dunk=QString::number(playersummaryList3[i+4].toInt()/playersummaryList3[i+7].toInt());
            QString steal=QString::number(playersummaryList3[i+5].toInt()/playersummaryList3[i+7].toInt());
            QString scores=QString::number(playersummaryList3[i+6].toInt()/playersummaryList3[i+7].toInt());
            stream6<<playersummaryList3[i]<<","<<playersummaryList3[i+1]<<","
                    <<pointer<<","
                    <<rebound<<","
                    <<dunk<<","
                    <<steal<<","
                    <<scores<<","
                    <<playersummaryList3[i+7]<<"\n";
        }
        file6.close();

        if(!file6.open(QIODevice::ReadOnly)){
            qInfo()<<"open failed";
        }
        else{
            qInfo()<<"open6 successful";
        }

        while(!stream6.atEnd()){
            QStringList linedata=stream6.readLine().split(",");

            QList<QStandardItem*> stealsummary;
            for(QString data:linedata){
                stealsummary.push_back(new QStandardItem(data));
            }

            model4->appendRow(stealsummary);
            qDebug()<<"here11";
        }

        ui->tableView->setModel(model4);
    }

    //若输入其他信息则提示正确输入名称（增强代码健壮性）
    else {
        QMessageBox::information(this,"提示","请输入正确项目名称!");
    }
}

//查询单项排名
void ShowPersonWidget::on_ItemButton_released()
{
    RangeAll();
}

//返回主页面
void ShowPersonWidget::on_returnButton_released()
{
    this->close();
}

