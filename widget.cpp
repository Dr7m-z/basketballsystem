#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,managewidget(NULL)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_WelcomeButton_released()
{
    managewidget=new ManageWidget;
    managewidget->show();
    this->close();
}


void Widget::on_CloseButton_released()
{
    this->close();
}
