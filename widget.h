#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"ManageWidget.h"

//此页面为开头页，欢迎用户使用
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_WelcomeButton_released();//进入系统主页

    void on_CloseButton_released();//关闭系统

private:
    Ui::Widget *ui;
    ManageWidget*managewidget;//主页指针
};
#endif // WIDGET_H
