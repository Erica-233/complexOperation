/********************************************************************************
** Form generated from reading UI file '2.ui.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_2_H
#define UI_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *num1Label;
    QLineEdit *num1Edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *num2Label;
    QLineEdit *num2Edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *decimalLabel;
    QLineEdit *decimalPlacesEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addButton;
    QPushButton *subButton;
    QPushButton *mulButton;
    QPushButton *divButton;
    QLabel *resultLabel;
    QTextEdit *resultEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        num1Label = new QLabel(centralWidget);
        num1Label->setObjectName("num1Label");

        horizontalLayout->addWidget(num1Label);

        num1Edit = new QLineEdit(centralWidget);
        num1Edit->setObjectName("num1Edit");

        horizontalLayout->addWidget(num1Edit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        num2Label = new QLabel(centralWidget);
        num2Label->setObjectName("num2Label");

        horizontalLayout_2->addWidget(num2Label);

        num2Edit = new QLineEdit(centralWidget);
        num2Edit->setObjectName("num2Edit");

        horizontalLayout_2->addWidget(num2Edit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        decimalLabel = new QLabel(centralWidget);
        decimalLabel->setObjectName("decimalLabel");

        horizontalLayout_3->addWidget(decimalLabel);

        decimalPlacesEdit = new QLineEdit(centralWidget);
        decimalPlacesEdit->setObjectName("decimalPlacesEdit");

        horizontalLayout_3->addWidget(decimalPlacesEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName("addButton");

        horizontalLayout_4->addWidget(addButton);

        subButton = new QPushButton(centralWidget);
        subButton->setObjectName("subButton");

        horizontalLayout_4->addWidget(subButton);

        mulButton = new QPushButton(centralWidget);
        mulButton->setObjectName("mulButton");

        horizontalLayout_4->addWidget(mulButton);

        divButton = new QPushButton(centralWidget);
        divButton->setObjectName("divButton");

        horizontalLayout_4->addWidget(divButton);


        verticalLayout->addLayout(horizontalLayout_4);

        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName("resultLabel");

        verticalLayout->addWidget(resultLabel);

        resultEdit = new QTextEdit(centralWidget);
        resultEdit->setObjectName("resultEdit");
        resultEdit->setReadOnly(true);

        verticalLayout->addWidget(resultEdit);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        num1Label->setText(QCoreApplication::translate("MainWindow", "\347\254\254\344\270\200\344\270\252\345\244\247\346\225\260\357\274\232", nullptr));
        num2Label->setText(QCoreApplication::translate("MainWindow", "\347\254\254\344\272\214\344\270\252\345\244\247\346\225\260\357\274\232", nullptr));
        decimalLabel->setText(QCoreApplication::translate("MainWindow", "\344\277\235\347\225\231\345\260\217\346\225\260\344\275\215\346\225\260\357\274\232", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\345\212\240\346\263\225 (+)", nullptr));
        subButton->setText(QCoreApplication::translate("MainWindow", "\345\207\217\346\263\225 (-)", nullptr));
        mulButton->setText(QCoreApplication::translate("MainWindow", "\344\271\230\346\263\225 (*)", nullptr));
        divButton->setText(QCoreApplication::translate("MainWindow", "\351\231\244\346\263\225 (/)", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2_H
