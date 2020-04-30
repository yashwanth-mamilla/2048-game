/********************************************************************************
** Form generated from reading UI file 'gamewin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIN_H
#define UI_GAMEWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamewin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *gamewin)
    {
        if (gamewin->objectName().isEmpty())
            gamewin->setObjectName(QString::fromUtf8("gamewin"));
        gamewin->resize(462, 341);
        layoutWidget = new QWidget(gamewin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 20, 281, 221));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:Ridge;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-style:solid;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(gamewin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 260, 100, 27));
        pushButton->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 12.5pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;"));
        pushButton_2 = new QPushButton(gamewin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 260, 100, 27));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 12.5pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;"));

        retranslateUi(gamewin);

        QMetaObject::connectSlotsByName(gamewin);
    } // setupUi

    void retranslateUi(QDialog *gamewin)
    {
        gamewin->setWindowTitle(QApplication::translate("gamewin", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("gamewin", "YOU WIN ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("gamewin", "Champion", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("gamewin", "Exit", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("gamewin", "Continue", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gamewin: public Ui_gamewin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIN_H
