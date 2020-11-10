/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QLineEdit *Countries;
    QLineEdit *Data;
    QPushButton *pb_request;
    QTextEdit *textEdit;
    QDateEdit *dateEdit;
    QLineEdit *Russia;
    QLineEdit *Moscow;
    QLCDNumber *WorldNumber;
    QLCDNumber *RussiaNumber;
    QLCDNumber *MoscowNumber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Countries = new QLineEdit(centralwidget);
        Countries->setObjectName(QString::fromUtf8("Countries"));
        Countries->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(Countries, 1, 0, 1, 1);

        Data = new QLineEdit(centralwidget);
        Data->setObjectName(QString::fromUtf8("Data"));
        Data->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(Data, 0, 0, 1, 1);

        pb_request = new QPushButton(centralwidget);
        pb_request->setObjectName(QString::fromUtf8("pb_request"));

        gridLayout_2->addWidget(pb_request, 6, 0, 1, 3);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 5, 0, 1, 3);

        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout_2->addWidget(dateEdit, 0, 1, 1, 2);

        Russia = new QLineEdit(centralwidget);
        Russia->setObjectName(QString::fromUtf8("Russia"));
        Russia->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(Russia, 3, 0, 1, 1);

        Moscow = new QLineEdit(centralwidget);
        Moscow->setObjectName(QString::fromUtf8("Moscow"));
        Moscow->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(Moscow, 4, 0, 1, 1);

        WorldNumber = new QLCDNumber(centralwidget);
        WorldNumber->setObjectName(QString::fromUtf8("WorldNumber"));

        gridLayout_2->addWidget(WorldNumber, 1, 1, 1, 2);

        RussiaNumber = new QLCDNumber(centralwidget);
        RussiaNumber->setObjectName(QString::fromUtf8("RussiaNumber"));

        gridLayout_2->addWidget(RussiaNumber, 3, 1, 1, 2);

        MoscowNumber = new QLCDNumber(centralwidget);
        MoscowNumber->setObjectName(QString::fromUtf8("MoscowNumber"));

        gridLayout_2->addWidget(MoscowNumber, 4, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Countries->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\274\320\270\321\200\321\203", nullptr));
        Data->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        pb_request->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy-MM-dd", nullptr));
        Russia->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\240\320\276\321\201\321\201\320\270\320\270", nullptr));
        Moscow->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\234\320\276\321\201\320\272\320\262\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
