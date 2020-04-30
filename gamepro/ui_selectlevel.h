/********************************************************************************
** Form generated from reading UI file 'selectlevel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTLEVEL_H
#define UI_SELECTLEVEL_H

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

class Ui_selectlevel
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *selectlevel)
    {
        if (selectlevel->objectName().isEmpty())
            selectlevel->setObjectName(QString::fromUtf8("selectlevel"));
        selectlevel->resize(320, 240);
        label = new QLabel(selectlevel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(85, 10, 151, 20));
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(selectlevel);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 50, 169, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;"));

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(selectlevel);

        QMetaObject::connectSlotsByName(selectlevel);
    } // setupUi

    void retranslateUi(QDialog *selectlevel)
    {
        selectlevel->setWindowTitle(QApplication::translate("selectlevel", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("selectlevel", "Choose : mode", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("selectlevel", "Classic (4x4)", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("selectlevel", "moderate (5x5)", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("selectlevel", "Expert (6x6)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class selectlevel: public Ui_selectlevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTLEVEL_H
