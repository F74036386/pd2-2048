/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QStringLiteral("game"));
        game->resize(542, 481);
        centralWidget = new QWidget(game);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(400, 60, 121, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 20, 121, 31));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(26);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 50, 101, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(24);
        pushButton->setFont(font1);
        pushButton->setFocusPolicy(Qt::NoFocus);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        game->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(game);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 542, 21));
        game->setMenuBar(menuBar);
        mainToolBar = new QToolBar(game);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        game->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(game);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        game->setStatusBar(statusBar);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QMainWindow *game)
    {
        game->setWindowTitle(QApplication::translate("game", "game", 0));
        label->setText(QApplication::translate("game", "score", 0));
        pushButton->setText(QApplication::translate("game", "restart", 0));
        label_2->setText(QApplication::translate("game", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
