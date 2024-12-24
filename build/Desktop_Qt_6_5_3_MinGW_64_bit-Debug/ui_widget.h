/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *Titlelabel;
    QPushButton *WelcomeButton;
    QPushButton *CloseButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(750, 500);
        Widget->setMinimumSize(QSize(750, 500));
        Widget->setMaximumSize(QSize(750, 500));
        Titlelabel = new QLabel(Widget);
        Titlelabel->setObjectName("Titlelabel");
        Titlelabel->setGeometry(QRect(120, 90, 501, 61));
        WelcomeButton = new QPushButton(Widget);
        WelcomeButton->setObjectName("WelcomeButton");
        WelcomeButton->setGeometry(QRect(310, 220, 120, 51));
        WelcomeButton->setMinimumSize(QSize(120, 51));
        WelcomeButton->setMaximumSize(QSize(120, 51));
        QFont font;
        font.setPointSize(13);
        WelcomeButton->setFont(font);
        CloseButton = new QPushButton(Widget);
        CloseButton->setObjectName("CloseButton");
        CloseButton->setGeometry(QRect(310, 310, 120, 51));
        CloseButton->setMinimumSize(QSize(120, 51));
        CloseButton->setMaximumSize(QSize(120, 51));
        CloseButton->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Titlelabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\347\257\256\347\220\203\350\201\224\350\265\233\344\270\252\344\272\272\346\212\200\346\234\257\346\225\260\346\215\256\345\244\204\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        WelcomeButton->setText(QCoreApplication::translate("Widget", "\346\254\242\350\277\216\344\275\277\347\224\250", nullptr));
        CloseButton->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
