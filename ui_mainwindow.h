/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyCube.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    MyCube *cubeWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QFontComboBox *fontComboBox;
    QSpacerItem *horizontalSpacer_3;
    QSlider *horizontalSlider;
    QLabel *fontSizeLabel;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QProgressBar *progressBar;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout;
    QTableView *tableView1;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QTableView *tableView2;
    QWidget *page_3;
    QGridLayout *gridLayout_3;
    QTableView *tableView3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 720);
        MainWindow->setMinimumSize(QSize(1600, 720));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cubeWidget = new MyCube(widget);
        cubeWidget->setObjectName(QString::fromUtf8("cubeWidget"));
        cubeWidget->setMinimumSize(QSize(550, 550));
        cubeWidget->setMaximumSize(QSize(100000, 100000));

        verticalLayout->addWidget(cubeWidget);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        fontComboBox = new QFontComboBox(widget_2);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(fontComboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalSlider = new QSlider(widget_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(200, 0));
        horizontalSlider->setMaximumSize(QSize(200, 25));
        horizontalSlider->setMinimum(9);
        horizontalSlider->setMaximum(30);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        fontSizeLabel = new QLabel(widget_2);
        fontSizeLabel->setObjectName(QString::fromUtf8("fontSizeLabel"));
        fontSizeLabel->setMinimumSize(QSize(20, 0));
        fontSizeLabel->setMaximumSize(QSize(20, 30));

        horizontalLayout_2->addWidget(fontSizeLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximumSize(QSize(16777215, 20));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        horizontalLayout->addWidget(widget);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setCursor(QCursor(Qt::ArrowCursor));
        toolBox->setFrameShape(QFrame::Panel);
        toolBox->setMidLineWidth(2);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 786, 578));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView1 = new QTableView(page);
        tableView1->setObjectName(QString::fromUtf8("tableView1"));
        tableView1->setMinimumSize(QSize(500, 0));
        tableView1->setMaximumSize(QSize(100000, 16777215));
        tableView1->horizontalHeader()->setMinimumSectionSize(21);
        tableView1->horizontalHeader()->setDefaultSectionSize(100);

        gridLayout->addWidget(tableView1, 0, 0, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("Endpoints"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 786, 578));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView2 = new QTableView(page_2);
        tableView2->setObjectName(QString::fromUtf8("tableView2"));
        tableView2->setMinimumSize(QSize(500, 0));
        tableView2->setMaximumSize(QSize(100000, 16777215));
        tableView2->horizontalHeader()->setDefaultSectionSize(21);
        tableView2->verticalHeader()->setDefaultSectionSize(21);

        gridLayout_2->addWidget(tableView2, 0, 0, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("Sample Points (Faces acrossed)"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_3 = new QGridLayout(page_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableView3 = new QTableView(page_3);
        tableView3->setObjectName(QString::fromUtf8("tableView3"));
        tableView3->horizontalHeader()->setMinimumSectionSize(10);
        tableView3->horizontalHeader()->setDefaultSectionSize(10);
        tableView3->verticalHeader()->setMinimumSectionSize(10);
        tableView3->verticalHeader()->setDefaultSectionSize(10);

        gridLayout_3->addWidget(tableView3, 0, 0, 1, 1);

        toolBox->addItem(page_3, QString::fromUtf8("Sample Points (Inset z length)"));

        horizontalLayout->addWidget(toolBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D Cube (c) Gypsop 2021.06", nullptr));
        fontSizeLabel->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Calculation progress", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Endpoints", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Sample Points (Faces acrossed)", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "Sample Points (Inset z length)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
