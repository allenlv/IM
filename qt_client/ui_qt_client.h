/********************************************************************************
** Form generated from reading ui file 'qt_client.ui'
**
** Created: Tue Sep 16 21:19:48 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QT_CLIENT_H
#define UI_QT_CLIENT_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_clientClass
{
public:
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLabel *label;

    void setupUi(QWidget *qt_clientClass)
    {
    if (qt_clientClass->objectName().isEmpty())
        qt_clientClass->setObjectName(QString::fromUtf8("qt_clientClass"));
    qt_clientClass->resize(400, 300);
    textEdit = new QTextEdit(qt_clientClass);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));
    textEdit->setEnabled(true);
    textEdit->setGeometry(QRect(10, 10, 381, 211));
    textEdit->setReadOnly(true);
    lineEdit = new QLineEdit(qt_clientClass);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(10, 230, 291, 27));
    pushButton = new QPushButton(qt_clientClass);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(310, 230, 80, 27));
    pushButton_2 = new QPushButton(qt_clientClass);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(10, 260, 80, 27));
    lineEdit_2 = new QLineEdit(qt_clientClass);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
    lineEdit_2->setGeometry(QRect(160, 260, 113, 27));
    label = new QLabel(qt_clientClass);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(100, 270, 56, 18));

    retranslateUi(qt_clientClass);

    QMetaObject::connectSlotsByName(qt_clientClass);
    } // setupUi

    void retranslateUi(QWidget *qt_clientClass)
    {
    qt_clientClass->setWindowTitle(QApplication::translate("qt_clientClass", "qt_client", 0));
    pushButton->setText(QApplication::translate("qt_clientClass", "send", 0));
    pushButton_2->setText(QApplication::translate("qt_clientClass", "connect", 0));
    lineEdit_2->setText(QApplication::translate("qt_clientClass", "127.0.0.1", 0));
    label->setText(QApplication::translate("qt_clientClass", "ip address", 0));
    Q_UNUSED(qt_clientClass);
    } // retranslateUi

};

namespace Ui {
    class qt_clientClass: public Ui_qt_clientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_CLIENT_H
