/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowClass
{
public:
    QAction *actionSettings;
    QAction *actionQuit;
    QAction *actionAbout_Prospective_Memory;
    QAction *actionAbout_Program;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WindowClass)
    {
        if (WindowClass->objectName().isEmpty())
            WindowClass->setObjectName(QStringLiteral("WindowClass"));
        WindowClass->resize(510, 286);
        actionSettings = new QAction(WindowClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Resources/Settings icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon);
        actionQuit = new QAction(WindowClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/Resources/Quit icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionAbout_Prospective_Memory = new QAction(WindowClass);
        actionAbout_Prospective_Memory->setObjectName(QStringLiteral("actionAbout_Prospective_Memory"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/Resources/Question icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Prospective_Memory->setIcon(icon2);
        actionAbout_Program = new QAction(WindowClass);
        actionAbout_Program->setObjectName(QStringLiteral("actionAbout_Program"));
        actionAbout_Program->setIcon(icon2);
        centralWidget = new QWidget(WindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setPointSize(12);
        groupBox->setFont(font1);

        verticalLayout_2->addWidget(groupBox);

        WindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 510, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        WindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menu->addAction(actionAbout_Prospective_Memory);
        menu->addAction(actionAbout_Program);

        retranslateUi(WindowClass);

        QMetaObject::connectSlotsByName(WindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *WindowClass)
    {
        WindowClass->setWindowTitle(QApplication::translate("WindowClass", "Prospective Memory", 0));
        actionSettings->setText(QApplication::translate("WindowClass", "Settings", 0));
        actionQuit->setText(QApplication::translate("WindowClass", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("WindowClass", "Q", 0));
        actionAbout_Prospective_Memory->setText(QApplication::translate("WindowClass", "About Prospective Memory", 0));
        actionAbout_Program->setText(QApplication::translate("WindowClass", "About", 0));
        label->setText(QApplication::translate("WindowClass", "Prosepctive Memory Entries", 0));
        pushButton->setText(QApplication::translate("WindowClass", "Refresh All", 0));
        groupBox->setTitle(QApplication::translate("WindowClass", "Entries", 0));
        menuFile->setTitle(QApplication::translate("WindowClass", "File", 0));
        menu->setTitle(QApplication::translate("WindowClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class WindowClass: public Ui_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
