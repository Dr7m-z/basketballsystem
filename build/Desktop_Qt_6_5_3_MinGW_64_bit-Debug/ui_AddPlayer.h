/********************************************************************************
** Form generated from reading UI file 'AddPlayer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYER_H
#define UI_ADDPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPlayer
{
public:
    QSpinBox *ReboundspinBox;
    QLabel *Reboundlabel;
    QSpinBox *DunkspinBox;
    QLabel *Namelabel;
    QSpinBox *PointerspinBox;
    QLabel *Dunklabel;
    QDateEdit *DateEdit;
    QLabel *Teamlabel;
    QDoubleSpinBox *ScoresSpinBox;
    QLineEdit *NamelineEdit;
    QLabel *Steallabel;
    QSpinBox *StealspinBox;
    QLineEdit *TeamlineEdit;
    QPushButton *cancleButton;
    QLabel *Pointerlabel;
    QPushButton *comfirmButton;
    QLabel *Datelabel;
    QLabel *Scoreslabel;

    void setupUi(QWidget *AddPlayer)
    {
        if (AddPlayer->objectName().isEmpty())
            AddPlayer->setObjectName("AddPlayer");
        AddPlayer->resize(400, 390);
        AddPlayer->setMinimumSize(QSize(400, 390));
        AddPlayer->setMaximumSize(QSize(400, 390));
        ReboundspinBox = new QSpinBox(AddPlayer);
        ReboundspinBox->setObjectName("ReboundspinBox");
        ReboundspinBox->setGeometry(QRect(120, 140, 221, 22));
        ReboundspinBox->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Reboundlabel = new QLabel(AddPlayer);
        Reboundlabel->setObjectName("Reboundlabel");
        Reboundlabel->setGeometry(QRect(40, 140, 61, 20));
        Reboundlabel->setMidLineWidth(-5);
        Reboundlabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        DunkspinBox = new QSpinBox(AddPlayer);
        DunkspinBox->setObjectName("DunkspinBox");
        DunkspinBox->setGeometry(QRect(120, 170, 221, 22));
        DunkspinBox->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Namelabel = new QLabel(AddPlayer);
        Namelabel->setObjectName("Namelabel");
        Namelabel->setGeometry(QRect(60, 50, 41, 16));
        Namelabel->setMidLineWidth(-5);
        Namelabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        PointerspinBox = new QSpinBox(AddPlayer);
        PointerspinBox->setObjectName("PointerspinBox");
        PointerspinBox->setGeometry(QRect(120, 110, 221, 22));
        PointerspinBox->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Dunklabel = new QLabel(AddPlayer);
        Dunklabel->setObjectName("Dunklabel");
        Dunklabel->setGeometry(QRect(30, 170, 71, 20));
        Dunklabel->setMidLineWidth(-5);
        Dunklabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        DateEdit = new QDateEdit(AddPlayer);
        DateEdit->setObjectName("DateEdit");
        DateEdit->setGeometry(QRect(120, 260, 221, 22));
        DateEdit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Teamlabel = new QLabel(AddPlayer);
        Teamlabel->setObjectName("Teamlabel");
        Teamlabel->setGeometry(QRect(40, 80, 61, 20));
        Teamlabel->setMidLineWidth(-5);
        Teamlabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        ScoresSpinBox = new QDoubleSpinBox(AddPlayer);
        ScoresSpinBox->setObjectName("ScoresSpinBox");
        ScoresSpinBox->setGeometry(QRect(120, 230, 221, 22));
        ScoresSpinBox->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        NamelineEdit = new QLineEdit(AddPlayer);
        NamelineEdit->setObjectName("NamelineEdit");
        NamelineEdit->setGeometry(QRect(120, 50, 221, 20));
        Steallabel = new QLabel(AddPlayer);
        Steallabel->setObjectName("Steallabel");
        Steallabel->setGeometry(QRect(40, 200, 61, 20));
        Steallabel->setMidLineWidth(-5);
        Steallabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        StealspinBox = new QSpinBox(AddPlayer);
        StealspinBox->setObjectName("StealspinBox");
        StealspinBox->setGeometry(QRect(120, 200, 221, 22));
        StealspinBox->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        TeamlineEdit = new QLineEdit(AddPlayer);
        TeamlineEdit->setObjectName("TeamlineEdit");
        TeamlineEdit->setGeometry(QRect(120, 80, 221, 20));
        cancleButton = new QPushButton(AddPlayer);
        cancleButton->setObjectName("cancleButton");
        cancleButton->setGeometry(QRect(260, 330, 75, 24));
        QFont font;
        font.setPointSize(11);
        cancleButton->setFont(font);
        Pointerlabel = new QLabel(AddPlayer);
        Pointerlabel->setObjectName("Pointerlabel");
        Pointerlabel->setGeometry(QRect(40, 110, 61, 20));
        Pointerlabel->setMidLineWidth(-5);
        Pointerlabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        comfirmButton = new QPushButton(AddPlayer);
        comfirmButton->setObjectName("comfirmButton");
        comfirmButton->setGeometry(QRect(80, 330, 75, 24));
        comfirmButton->setFont(font);
        Datelabel = new QLabel(AddPlayer);
        Datelabel->setObjectName("Datelabel");
        Datelabel->setGeometry(QRect(40, 260, 61, 20));
        Datelabel->setMidLineWidth(-5);
        Datelabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Scoreslabel = new QLabel(AddPlayer);
        Scoreslabel->setObjectName("Scoreslabel");
        Scoreslabel->setGeometry(QRect(40, 230, 61, 20));
        Scoreslabel->setMidLineWidth(-5);
        Scoreslabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        retranslateUi(AddPlayer);

        QMetaObject::connectSlotsByName(AddPlayer);
    } // setupUi

    void retranslateUi(QWidget *AddPlayer)
    {
        AddPlayer->setWindowTitle(QCoreApplication::translate("AddPlayer", "Form", nullptr));
        Reboundlabel->setText(QCoreApplication::translate("AddPlayer", "\347\257\256\346\235\277\347\220\203\344\270\252\346\225\260", nullptr));
        Namelabel->setText(QCoreApplication::translate("AddPlayer", "\345\247\223\345\220\215", nullptr));
        Dunklabel->setText(QCoreApplication::translate("AddPlayer", "\346\211\243\347\257\256\346\210\220\345\212\237\344\270\252\346\225\260", nullptr));
        Teamlabel->setText(QCoreApplication::translate("AddPlayer", "\346\211\200\345\261\236\351\230\237\344\274\215", nullptr));
        Steallabel->setText(QCoreApplication::translate("AddPlayer", "\346\212\242\346\226\255\346\254\241\346\225\260", nullptr));
        cancleButton->setText(QCoreApplication::translate("AddPlayer", "\345\217\226\346\266\210", nullptr));
        Pointerlabel->setText(QCoreApplication::translate("AddPlayer", "\344\270\211\345\210\206\347\220\203\344\270\252\346\225\260", nullptr));
        comfirmButton->setText(QCoreApplication::translate("AddPlayer", "\347\241\256\345\256\232", nullptr));
        Datelabel->setText(QCoreApplication::translate("AddPlayer", "\346\257\224\350\265\233\346\227\245\346\234\237", nullptr));
        Scoreslabel->setText(QCoreApplication::translate("AddPlayer", "\345\276\227\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPlayer: public Ui_AddPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYER_H
