/********************************************************************************
** Form generated from reading UI file 'qt_server.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SERVER_H
#define UI_QT_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_serverClass
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QWidget *qt_serverClass)
    {
        if (qt_serverClass->objectName().isEmpty())
            qt_serverClass->setObjectName(QStringLiteral("qt_serverClass"));
        qt_serverClass->resize(400, 268);
        pushButton = new QPushButton(qt_serverClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 230, 80, 27));
        lineEdit = new QLineEdit(qt_serverClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 230, 291, 27));
        textEdit = new QTextEdit(qt_serverClass);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 381, 211));
        textEdit->setReadOnly(true);

        retranslateUi(qt_serverClass);

        QMetaObject::connectSlotsByName(qt_serverClass);
    } // setupUi

    void retranslateUi(QWidget *qt_serverClass)
    {
        qt_serverClass->setWindowTitle(QApplication::translate("qt_serverClass", "qt_server", 0));
        pushButton->setText(QApplication::translate("qt_serverClass", "send", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_serverClass: public Ui_qt_serverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SERVER_H
