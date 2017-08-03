/********************************************************************************
** Form generated from reading UI file 'examplebox.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEBOX_H
#define UI_EXAMPLEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExampleBox
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *ExampleBox)
    {
        if (ExampleBox->objectName().isEmpty())
            ExampleBox->setObjectName(QStringLiteral("ExampleBox"));
        ExampleBox->resize(412, 135);
        ExampleBox->setMaximumSize(QSize(412, 135));
        verticalLayout_2 = new QVBoxLayout(ExampleBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ExampleBox);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(ExampleBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        textEdit = new QTextEdit(ExampleBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFont(font);
        textEdit->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit);


        retranslateUi(ExampleBox);

        QMetaObject::connectSlotsByName(ExampleBox);
    } // setupUi

    void retranslateUi(QWidget *ExampleBox)
    {
        ExampleBox->setWindowTitle(QApplication::translate("ExampleBox", "ExampleBox", 0));
        label->setText(QApplication::translate("ExampleBox", "This is used if you want to add more entries than the standard ones.", 0));
        label_2->setText(QApplication::translate("ExampleBox", "This should point to a text file containing the following format:", 0));
        textEdit->setHtml(QApplication::translate("ExampleBox", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The next time I see a cat</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The next time I see a dog</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The next time I see a bird</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class ExampleBox: public Ui_ExampleBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEBOX_H
