/********************************************************************************
** Form generated from reading UI file 'thegame.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEGAME_H
#define UI_THEGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thegame
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_18;
    QLabel *label;
    QPushButton *optionstab;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_19;
    QLabel *highscorelabel;
    QPushButton *undobutton;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_20;
    QMenuBar *menubar;

    void setupUi(QMainWindow *thegame)
    {
        if (thegame->objectName().isEmpty())
            thegame->setObjectName(QString::fromUtf8("thegame"));
        thegame->resize(526, 504);
        centralwidget = new QWidget(thegame);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(209, 94, 80, 37));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setStyleSheet(QString::fromUtf8("background: rgb(222, 153, 100);color: rgb(119,110,101); font: bold; font: 15pt;"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(299, 14, 216, 120));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 0, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(100, 25));
        label_18->setBaseSize(QSize(0, 0));
        label_18->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-width:1.2px;border-style:solid;"));
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_18, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(100, 25));
        label->setBaseSize(QSize(0, 0));
        label->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-width:1.2px;border-style:solid;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_4->addLayout(verticalLayout);

        optionstab = new QPushButton(layoutWidget);
        optionstab->setObjectName(QString::fromUtf8("optionstab"));
        sizePolicy.setHeightForWidth(optionstab->sizePolicy().hasHeightForWidth());
        optionstab->setSizePolicy(sizePolicy);
        optionstab->setMinimumSize(QSize(100, 40));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        optionstab->setFont(font);
        optionstab->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;"));
        optionstab->setDefault(false);
        optionstab->setFlat(true);

        verticalLayout_4->addWidget(optionstab, 0, Qt::AlignHCenter);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setMinimumSize(QSize(100, 25));
        label_19->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-width:1.2px;border-style:solid;"));
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_19, 0, Qt::AlignHCenter);

        highscorelabel = new QLabel(layoutWidget);
        highscorelabel->setObjectName(QString::fromUtf8("highscorelabel"));
        sizePolicy.setHeightForWidth(highscorelabel->sizePolicy().hasHeightForWidth());
        highscorelabel->setSizePolicy(sizePolicy);
        highscorelabel->setMinimumSize(QSize(100, 25));
        highscorelabel->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-width:1.2px;border-style:solid;"));
        highscorelabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(highscorelabel);


        verticalLayout_5->addLayout(verticalLayout_2);

        undobutton = new QPushButton(layoutWidget);
        undobutton->setObjectName(QString::fromUtf8("undobutton"));
        sizePolicy.setHeightForWidth(undobutton->sizePolicy().hasHeightForWidth());
        undobutton->setSizePolicy(sizePolicy);
        undobutton->setMinimumSize(QSize(100, 40));
        undobutton->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;"));

        verticalLayout_5->addWidget(undobutton, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_5->addLayout(verticalLayout_5);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(9, 144, 502, 331));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_1 = new QLabel(layoutWidget_2);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        sizePolicy.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy);
        label_1->setMinimumSize(QSize(120, 75));
        label_1->setMaximumSize(QSize(120, 75));
        label_1->setAutoFillBackground(false);
        label_1->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_1->setScaledContents(true);
        label_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_1);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(120, 75));
        label_2->setMaximumSize(QSize(120, 75));
        label_2->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(120, 75));
        label_3->setMaximumSize(QSize(120, 75));
        label_3->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(120, 75));
        label_4->setMaximumSize(QSize(120, 75));
        label_4->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(120, 75));
        label_9->setMaximumSize(QSize(120, 75));
        label_9->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_9);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(120, 75));
        label_10->setMaximumSize(QSize(120, 75));
        label_10->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_10);

        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(120, 75));
        label_11->setMaximumSize(QSize(120, 75));
        label_11->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_11);

        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(120, 75));
        label_12->setMaximumSize(QSize(120, 75));
        label_12->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_12);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(120, 75));
        label_5->setMaximumSize(QSize(120, 75));
        label_5->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(120, 75));
        label_6->setMaximumSize(QSize(120, 75));
        label_6->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(120, 75));
        label_7->setMaximumSize(QSize(120, 75));
        label_7->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(120, 75));
        label_8->setMaximumSize(QSize(120, 75));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_8);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(120, 75));
        label_13->setMaximumSize(QSize(120, 75));
        label_13->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_13);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setMinimumSize(QSize(120, 75));
        label_14->setMaximumSize(QSize(120, 75));
        label_14->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_14);

        label_15 = new QLabel(layoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMinimumSize(QSize(120, 75));
        label_15->setMaximumSize(QSize(120, 75));
        label_15->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_15);

        label_16 = new QLabel(layoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setMinimumSize(QSize(120, 75));
        label_16->setMaximumSize(QSize(120, 75));
        label_16->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_16);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 20, 110, 110));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setMinimumSize(QSize(110, 110));
        label_20->setAlignment(Qt::AlignCenter);
        thegame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(thegame);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 526, 24));
        thegame->setMenuBar(menubar);

        retranslateUi(thegame);

        QMetaObject::connectSlotsByName(thegame);
    } // setupUi

    void retranslateUi(QMainWindow *thegame)
    {
        thegame->setWindowTitle(QApplication::translate("thegame", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("thegame", "Reset", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("thegame", "Score", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        optionstab->setText(QApplication::translate("thegame", "Quit", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("thegame", "Best", 0, QApplication::UnicodeUTF8));
        highscorelabel->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        undobutton->setText(QApplication::translate("thegame", "undo(5)", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("thegame", "0", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("thegame", "<html><head/><body><p>P</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class thegame: public Ui_thegame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEGAME_H
