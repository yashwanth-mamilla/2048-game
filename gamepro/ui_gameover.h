/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gameover
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Gameover)
    {
        if (Gameover->objectName().isEmpty())
            Gameover->setObjectName(QString::fromUtf8("Gameover"));
        Gameover->resize(443, 326);
        Gameover->setStyleSheet(QString::fromUtf8("background: ( 247, 228, 186);"));
        widget = new QWidget(Gameover);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 40, 281, 221));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:Ridge;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-style:solid;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background: rgb(204,192,179);color: rgb(119,110,101); font: bold; border-radius: 20px; font: 17pt;border-color: rgb(136, 134, 129);border-style:solid;"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Gameover);

        QMetaObject::connectSlotsByName(Gameover);
    } // setupUi

    void retranslateUi(QDialog *Gameover)
    {
        Gameover->setWindowTitle(QApplication::translate("Gameover", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Gameover", "GAME OVER", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Gameover", "Your Score", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Gameover", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Gameover: public Ui_Gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
