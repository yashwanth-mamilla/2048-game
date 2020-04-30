/********************************************************************************
** Form generated from reading UI file 'intro.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTRO_H
#define UI_INTRO_H

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

class Ui_intro
{
public:
    QLabel *introlabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *intro)
    {
        if (intro->objectName().isEmpty())
            intro->setObjectName(QString::fromUtf8("intro"));
        intro->resize(572, 550);
        intro->setStyleSheet(QString::fromUtf8("background: rgb( 247, 228, 186); border-radius: 10px;"));
        introlabel = new QLabel(intro);
        introlabel->setObjectName(QString::fromUtf8("introlabel"));
        introlabel->setGeometry(QRect(90, 10, 391, 321));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(introlabel->sizePolicy().hasHeightForWidth());
        introlabel->setSizePolicy(sizePolicy);
        introlabel->setMinimumSize(QSize(250, 250));
        introlabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(intro);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 350, 208, 156));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(40, 0));
        pushButton->setStyleSheet(QString::fromUtf8("background: rgb(179, 152, 121); color: rgb(36, 25, 12); font: bold; border-radius: 10px; font: 18pt;Border-width:2px;\n"
"Border-style: Ridge;"));
        pushButton->setFlat(false);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(40, 0));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: rgb(179, 152, 121); color: rgb(36, 25, 12); font: bold; border-radius: 10px; font: 18pt;Border-width:2px;\n"
"Border-style: Ridge;"));
        pushButton_2->setFlat(true);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(40, 0));
        pushButton_3->setStyleSheet(QString::fromUtf8("background: rgb(179, 152, 121); color: rgb(36, 25, 12); font: bold; border-radius: 10px; font: 18pt;Border-width:2px;\n"
"Border-style: Ridge;"));
        pushButton_3->setFlat(true);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(40, 0));
        pushButton_4->setStyleSheet(QString::fromUtf8("background: rgb(179, 152, 121); color: rgb(36, 25, 12); font: bold; border-radius: 10px; font: 18pt;Border-width:2px;\n"
"Border-style: Ridge;"));
        pushButton_4->setFlat(true);

        verticalLayout->addWidget(pushButton_4);


        retranslateUi(intro);

        QMetaObject::connectSlotsByName(intro);
    } // setupUi

    void retranslateUi(QDialog *intro)
    {
        intro->setWindowTitle(QApplication::translate("intro", "Dialog", 0, QApplication::UnicodeUTF8));
        introlabel->setText(QApplication::translate("intro", "<html><head/><body><p align=\"center\"><span style=\" font-size:72pt; font-weight:600;\">2048</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("intro", " New Game ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("intro", "Load Game", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("intro", "Instructions", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("intro", "Exit Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class intro: public Ui_intro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRO_H
