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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *inputx_2;
    QLineEdit *inputy_2;
    QPushButton *shortpt;
    QVBoxLayout *verticalLayout_3;
    QToolButton *toolButton_7;
    QToolButton *toolButton_6;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QToolButton *toolButton;
    QToolButton *toolButton_5;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *inputx;
    QLineEdit *inputy;
    QPushButton *nearpt;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(858, 868);
        MainWindow->setMaximumSize(QSize(1024, 1024));
        MainWindow->setIconSize(QSize(1024, 1024));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer = new QSpacerItem(680, 680, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 2, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        listView->setMaximumSize(QSize(300, 680));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setSpacing(0);
        listView->setModelColumn(0);
        listView->setWordWrap(false);

        gridLayout->addWidget(listView, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        inputx_2 = new QLineEdit(centralwidget);
        inputx_2->setObjectName(QString::fromUtf8("inputx_2"));
        inputx_2->setMinimumSize(QSize(100, 20));
        inputx_2->setMaximumSize(QSize(150, 20));

        verticalLayout_2->addWidget(inputx_2);

        inputy_2 = new QLineEdit(centralwidget);
        inputy_2->setObjectName(QString::fromUtf8("inputy_2"));
        inputy_2->setMinimumSize(QSize(100, 20));
        inputy_2->setMaximumSize(QSize(150, 20));

        verticalLayout_2->addWidget(inputy_2);

        shortpt = new QPushButton(centralwidget);
        shortpt->setObjectName(QString::fromUtf8("shortpt"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shortpt->sizePolicy().hasHeightForWidth());
        shortpt->setSizePolicy(sizePolicy);
        shortpt->setMinimumSize(QSize(100, 20));
        shortpt->setMaximumSize(QSize(150, 20));

        verticalLayout_2->addWidget(shortpt);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toolButton_7 = new QToolButton(centralwidget);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy1);
        toolButton_7->setMinimumSize(QSize(100, 20));
        toolButton_7->setMaximumSize(QSize(150, 20));

        verticalLayout_3->addWidget(toolButton_7);

        toolButton_6 = new QToolButton(centralwidget);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        sizePolicy1.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy1);
        toolButton_6->setMinimumSize(QSize(100, 20));
        toolButton_6->setMaximumSize(QSize(150, 20));

        verticalLayout_3->addWidget(toolButton_6);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(100, 20));
        pushButton->setMaximumSize(QSize(150, 20));

        verticalLayout_3->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(150, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(150, 15));
        label_2->setMaximumSize(QSize(16777215, 10));
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_6->addWidget(label_2);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(toolButton);

        toolButton_5 = new QToolButton(centralwidget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        sizePolicy1.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(toolButton_5);

        toolButton_4 = new QToolButton(centralwidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        sizePolicy1.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(centralwidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy1.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(toolButton_3);

        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy1.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(toolButton_2);


        horizontalLayout->addLayout(verticalLayout_6);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        inputx = new QLineEdit(centralwidget);
        inputx->setObjectName(QString::fromUtf8("inputx"));
        inputx->setMinimumSize(QSize(100, 20));
        inputx->setMaximumSize(QSize(150, 20));

        verticalLayout->addWidget(inputx);

        inputy = new QLineEdit(centralwidget);
        inputy->setObjectName(QString::fromUtf8("inputy"));
        sizePolicy2.setHeightForWidth(inputy->sizePolicy().hasHeightForWidth());
        inputy->setSizePolicy(sizePolicy2);
        inputy->setMinimumSize(QSize(150, 20));
        inputy->setMaximumSize(QSize(100, 20));

        verticalLayout->addWidget(inputy);

        nearpt = new QPushButton(centralwidget);
        nearpt->setObjectName(QString::fromUtf8("nearpt"));
        nearpt->setMinimumSize(QSize(100, 20));
        nearpt->setMaximumSize(QSize(150, 20));

        verticalLayout->addWidget(nearpt);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 858, 23));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\257\274\350\210\252\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221100\344\270\252\347\202\271\346\240\207\345\217\267", nullptr));
        inputx_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\254\254\344\270\200\344\270\252\347\202\271\346\240\207\345\217\267(1-10000)", nullptr));
        inputy_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\254\254\344\272\214\344\270\252\347\202\271\346\240\207\345\217\267(1-10000)", nullptr));
        shortpt->setText(QCoreApplication::translate("MainWindow", "\350\267\235\347\246\273\346\234\200\347\237\255\350\267\257", nullptr));
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        toolButton_6->setText(QCoreApplication::translate("MainWindow", "\350\267\235\347\246\273\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\234\200\347\237\255\350\267\257", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\201\223\350\267\257\347\212\266\345\206\265", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", ">150%", nullptr));
        toolButton_5->setText(QCoreApplication::translate("MainWindow", "100%-150%", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindow", "80%-100%", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "50%-80%", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "<50%", nullptr));
        inputx->setPlaceholderText(QCoreApplication::translate("MainWindow", "x\345\235\220\346\240\207(0-32767)", nullptr));
        inputy->setPlaceholderText(QCoreApplication::translate("MainWindow", "y\345\235\220\346\240\207(0-32767)", nullptr));
        nearpt->setText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221100\344\270\252\347\202\271(\345\217\263\351\224\256\345\217\214\345\207\273)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
