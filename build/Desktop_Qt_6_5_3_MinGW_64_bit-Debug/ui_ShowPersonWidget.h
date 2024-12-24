/********************************************************************************
** Form generated from reading UI file 'ShowPersonWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPERSONWIDGET_H
#define UI_SHOWPERSONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowPersonWidget
{
public:
    QTableView *tableView;
    QLineEdit *SearchlineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *ItemButton;
    QPushButton *returnButton;

    void setupUi(QWidget *ShowPersonWidget)
    {
        if (ShowPersonWidget->objectName().isEmpty())
            ShowPersonWidget->setObjectName("ShowPersonWidget");
        ShowPersonWidget->resize(750, 500);
        ShowPersonWidget->setMinimumSize(QSize(750, 500));
        ShowPersonWidget->setMaximumSize(QSize(750, 500));
        QFont font;
        font.setPointSize(10);
        ShowPersonWidget->setFont(font);
        tableView = new QTableView(ShowPersonWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 140, 691, 321));
        SearchlineEdit = new QLineEdit(ShowPersonWidget);
        SearchlineEdit->setObjectName("SearchlineEdit");
        SearchlineEdit->setGeometry(QRect(30, 60, 341, 41));
        QFont font1;
        font1.setPointSize(11);
        SearchlineEdit->setFont(font1);
        pushButton = new QPushButton(ShowPersonWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 60, 111, 41));
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(ShowPersonWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(500, 60, 101, 41));
        pushButton_2->setFont(font1);
        ItemButton = new QPushButton(ShowPersonWidget);
        ItemButton->setObjectName("ItemButton");
        ItemButton->setGeometry(QRect(610, 60, 101, 41));
        ItemButton->setFont(font1);
        returnButton = new QPushButton(ShowPersonWidget);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(30, 20, 75, 24));
        returnButton->setFont(font1);

        retranslateUi(ShowPersonWidget);

        QMetaObject::connectSlotsByName(ShowPersonWidget);
    } // setupUi

    void retranslateUi(QWidget *ShowPersonWidget)
    {
        ShowPersonWidget->setWindowTitle(QCoreApplication::translate("ShowPersonWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ShowPersonWidget", "\346\237\245\347\234\213\344\270\252\344\272\272\346\261\207\346\200\273\350\241\250", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ShowPersonWidget", "\346\237\245\347\234\213\351\230\237\345\206\205\346\216\222\345\220\215", nullptr));
        ItemButton->setText(QCoreApplication::translate("ShowPersonWidget", "\346\237\245\347\234\213\345\215\225\351\241\271\346\216\222\345\220\215", nullptr));
        returnButton->setText(QCoreApplication::translate("ShowPersonWidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowPersonWidget: public Ui_ShowPersonWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPERSONWIDGET_H
