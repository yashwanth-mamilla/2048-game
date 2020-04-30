/********************************************************************************
** Form generated from reading UI file 'thegame5x5.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEGAME5X5_H
#define UI_THEGAME5X5_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thegame5x5
{
public:
    QLabel *label_26;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *optionstab;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_29;
    QLabel *highscorelabel;
    QPushButton *undobutton;
    QPushButton *pushButton_3;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;

    void setupUi(QDialog *thegame5x5)
    {
        if (thegame5x5->objectName().isEmpty())
            thegame5x5->setObjectName(QString::fromUtf8("thegame5x5"));
        thegame5x5->resize(656, 559);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(thegame5x5->sizePolicy().hasHeightForWidth());
        thegame5x5->setSizePolicy(sizePolicy);
        label_26 = new QLabel(thegame5x5);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 10, 110, 110));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setMinimumSize(QSize(110, 110));
        label_26->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(thegame5x5);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 10, 216, 120));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 0, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setMinimumSize(QSize(100, 25));
        label_27->setBaseSize(QSize(0, 0));
        label_27->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-width:1.2px;border-style:solid;"));
        label_27->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_27, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);
        label_28->setMinimumSize(QSize(100, 25));
        label_28->setBaseSize(QSize(0, 0));
        label_28->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-width:1.2px;border-style:solid;"));
        label_28->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_28, 0, Qt::AlignHCenter|Qt::AlignVCenter);


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


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setMinimumSize(QSize(100, 25));
        label_29->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-width:1.2px;border-style:solid;"));
        label_29->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_29, 0, Qt::AlignHCenter);

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


        horizontalLayout_6->addLayout(verticalLayout_5);

        pushButton_3 = new QPushButton(thegame5x5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 90, 80, 37));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setStyleSheet(QString::fromUtf8("background: rgb(222, 153, 100);color: rgb(119,110,101); font: bold; font: 15pt;"));
        layoutWidget1 = new QWidget(thegame5x5);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 140, 628, 411));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_1 = new QLabel(layoutWidget1);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setMinimumSize(QSize(120, 75));
        label_1->setMaximumSize(QSize(120, 75));
        label_1->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(120, 75));
        label_2->setMaximumSize(QSize(120, 75));
        label_2->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(120, 75));
        label_3->setMaximumSize(QSize(120, 75));
        label_3->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(120, 75));
        label_4->setMaximumSize(QSize(120, 75));
        label_4->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(120, 75));
        label_5->setMaximumSize(QSize(120, 75));
        label_5->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(120, 75));
        label_6->setMaximumSize(QSize(120, 75));
        label_6->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(120, 75));
        label_7->setMaximumSize(QSize(120, 75));
        label_7->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(120, 75));
        label_8->setMaximumSize(QSize(120, 75));
        label_8->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_8);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(120, 75));
        label_9->setMaximumSize(QSize(120, 75));
        label_9->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(120, 75));
        label_10->setMaximumSize(QSize(120, 75));
        label_10->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_10);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(120, 75));
        label_11->setMaximumSize(QSize(120, 75));
        label_11->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_11);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(120, 75));
        label_12->setMaximumSize(QSize(120, 75));
        label_12->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_12);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(120, 75));
        label_13->setMaximumSize(QSize(120, 75));
        label_13->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_13);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(120, 75));
        label_14->setMaximumSize(QSize(120, 75));
        label_14->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_14);

        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(120, 75));
        label_15->setMaximumSize(QSize(120, 75));
        label_15->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_15);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(120, 75));
        label_16->setMaximumSize(QSize(120, 75));
        label_16->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_16);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(120, 75));
        label_17->setMaximumSize(QSize(120, 75));
        label_17->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_17);

        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(120, 75));
        label_18->setMaximumSize(QSize(120, 75));
        label_18->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_18);

        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(120, 75));
        label_19->setMaximumSize(QSize(120, 75));
        label_19->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_19);

        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(120, 75));
        label_20->setMaximumSize(QSize(120, 75));
        label_20->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_20);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(120, 75));
        label_21->setMaximumSize(QSize(120, 75));
        label_21->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_21);

        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(120, 75));
        label_22->setMaximumSize(QSize(120, 75));
        label_22->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_22);

        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(120, 75));
        label_23->setMaximumSize(QSize(120, 75));
        label_23->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_23);

        label_24 = new QLabel(layoutWidget1);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(120, 75));
        label_24->setMaximumSize(QSize(120, 75));
        label_24->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_24);

        label_25 = new QLabel(layoutWidget1);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(120, 75));
        label_25->setMaximumSize(QSize(120, 75));
        label_25->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;border-color: rgb(136, 134, 129);border-width:5px;border-style:inset;"));
        label_25->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_25);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);


        retranslateUi(thegame5x5);

        QMetaObject::connectSlotsByName(thegame5x5);
    } // setupUi

    void retranslateUi(QDialog *thegame5x5)
    {
        thegame5x5->setWindowTitle(QApplication::translate("thegame5x5", "Dialog", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("thegame5x5", "<html><head/><body><p>P</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("thegame5x5", "Score", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        optionstab->setText(QApplication::translate("thegame5x5", "Quit", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("thegame5x5", "Best", 0, QApplication::UnicodeUTF8));
        highscorelabel->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        undobutton->setText(QApplication::translate("thegame5x5", "undo(5)", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("thegame5x5", "reset", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("thegame5x5", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class thegame5x5: public Ui_thegame5x5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEGAME5X5_H
