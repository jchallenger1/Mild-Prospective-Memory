/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(532, 478);
        About->setMaximumSize(QSize(532, 478));
        horizontalLayout = new QHBoxLayout(About);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        stackedWidget = new QStackedWidget(About);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(label_5);

        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        verticalLayout_2->addLayout(verticalLayout);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_3->addWidget(label_4);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(About);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0));
        label_5->setText(QApplication::translate("About", "<html><head/><body><p><br/></p></body></html>", 0));
        label->setText(QApplication::translate("About", "<html><head/><body><p>Prospective Memory/Mild Created by Grandduchy.</p><p>Source and any bug concerns can be brought out here:</p><p align=\"center\"><a href=\"https://github.com/Grandduchy/Mild-Prospective-Memory\"><span style=\" font-size:12pt; text-decoration: underline; color:#0000ff;\">Respiratory</span></a></p><p><br/></p></body></html>", 0));
        label_2->setText(QApplication::translate("About", "<hr>", 0));
        label_3->setText(QApplication::translate("About", "MIT License\n"
"\n"
"Copyright (c) 2017 Grandduchy\n"
"\n"
"Permission is hereby granted, free of charge, to any person obtaining a copy\n"
"of this software and associated documentation files (the \"Software\"), to deal\n"
"in the Software without restriction, including without limitation the rights\n"
"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
"copies of the Software, and to permit persons to whom the Software is\n"
"furnished to do so, subject to the following conditions:\n"
"\n"
"The above copyright notice and this permission notice shall be included in all\n"
"copies or substantial portions of the Software.\n"
"\n"
"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TOR"
                        "T OR OTHERWISE, ARISING FROM,\n"
"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
"SOFTWARE.\n"
"", 0));
        label_4->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Prospective Memory About Page</span></p><p><span style=\" font-size:11pt;\">A Program used to enhance Prospecive Memory by giving entries.<br/>The Program is based off of Stephen LaBerge &amp; Howard Rheingold's book:</span></p><p><span style=\" font-size:11pt; font-style:italic;\">Exploring The World Of Lucid Dreaming</span><span style=\" font-size:11pt;\"><br/>The section where the program can be used can be found on page 46-49</span></p><p><span style=\" font-size:11pt;\">Or a detailed guide can be found </span><a href=\"www.dreamviews.com/wiki/MILD-Tutorial\"><span style=\" font-size:12pt; text-decoration: underline; color:#0000ff;\">here</span></a><span style=\" font-size:11pt;\"><br/>The goal of the practice is to be able to enhance your prospective memory.</span></p><p><span style=\" font-size:11pt;\">Prospective memory involves remembering to perform a planned action or</span></p><p><span style=\" font-size:11pt;\">recall a planned"
                        " intention at some future point in time.</span></p><p><span style=\" font-size:11pt;\">Prospecive Memory is commonly applied to the MILD technique.</span></p><p><span style=\" font-size:11pt;\">All of the entries prebuilt into the program can be found </span><a href=\"https://github.com/Grandduchy/Mild-Prospective-Memory/blob/master/MILD/StandardEntries.hpp\"><span style=\" font-size:12pt; text-decoration: underline; color:#0000ff;\">here</span></a></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
