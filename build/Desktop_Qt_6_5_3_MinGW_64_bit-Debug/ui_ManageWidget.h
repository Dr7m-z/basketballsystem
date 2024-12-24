/********************************************************************************
** Form generated from reading UI file 'ManageWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEWIDGET_H
#define UI_MANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageWidget
{
public:
    QPushButton *SearchPersonButton;
    QPushButton *SaveButton;
    QPushButton *DeleteButton;
    QPushButton *AddButton;
    QTableView *tableView;
    QPushButton *CancleButton;

    void setupUi(QWidget *ManageWidget)
    {
        if (ManageWidget->objectName().isEmpty())
            ManageWidget->setObjectName("ManageWidget");
        ManageWidget->resize(750, 500);
        ManageWidget->setMinimumSize(QSize(750, 500));
        ManageWidget->setMaximumSize(QSize(750, 500));
        SearchPersonButton = new QPushButton(ManageWidget);
        SearchPersonButton->setObjectName("SearchPersonButton");
        SearchPersonButton->setGeometry(QRect(480, 440, 81, 31));
        QFont font;
        font.setPointSize(11);
        SearchPersonButton->setFont(font);
        SaveButton = new QPushButton(ManageWidget);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setGeometry(QRect(330, 440, 81, 31));
        SaveButton->setFont(font);
        DeleteButton = new QPushButton(ManageWidget);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setGeometry(QRect(180, 440, 81, 31));
        DeleteButton->setFont(font);
        AddButton = new QPushButton(ManageWidget);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(30, 440, 81, 31));
        AddButton->setFont(font);
        tableView = new QTableView(ManageWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 40, 691, 371));
        CancleButton = new QPushButton(ManageWidget);
        CancleButton->setObjectName("CancleButton");
        CancleButton->setGeometry(QRect(640, 440, 81, 31));
        CancleButton->setFont(font);

        retranslateUi(ManageWidget);

        QMetaObject::connectSlotsByName(ManageWidget);
    } // setupUi

    void retranslateUi(QWidget *ManageWidget)
    {
        ManageWidget->setWindowTitle(QCoreApplication::translate("ManageWidget", "Form", nullptr));
        SearchPersonButton->setText(QCoreApplication::translate("ManageWidget", "\346\237\245\350\257\242", nullptr));
        SaveButton->setText(QCoreApplication::translate("ManageWidget", "\344\277\235\345\255\230", nullptr));
        DeleteButton->setText(QCoreApplication::translate("ManageWidget", "\345\210\240\351\231\244", nullptr));
        AddButton->setText(QCoreApplication::translate("ManageWidget", "\346\267\273\345\212\240", nullptr));
        CancleButton->setText(QCoreApplication::translate("ManageWidget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageWidget: public Ui_ManageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEWIDGET_H
