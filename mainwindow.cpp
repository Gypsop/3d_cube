#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Ready - Drag to start...");
    QStandardItemModel *tableView1Head = new QStandardItemModel();
    tableView1Head->setHorizontalHeaderItem(0, new QStandardItem(tr("point")));
    tableView1Head->setHorizontalHeaderItem(1, new QStandardItem(tr("x")));
    tableView1Head->setHorizontalHeaderItem(2, new QStandardItem(tr("y")));
    tableView1Head->setHorizontalHeaderItem(3, new QStandardItem(tr("z")));
    ui->tableView1->setModel(tableView1Head);

    QStandardItemModel *tableView2Head = new QStandardItemModel();
    QStandardItemModel *tableView3Head = new QStandardItemModel();
    ui->tableView2->setModel(tableView2Head);
    ui->tableView3->setModel(tableView3Head);

    //八个角点的名称（第一列）
    for (int i = 0; i < 8; ++i)
    {
        tableView1Head->setItem(i, 0, new QStandardItem(QString(char(65 + i)))); //A-H, 8个字母当做点名
    }
    ui->tableView1->setColumnWidth(0, 50);

    connect(ui->cubeWidget, &MyCube::mouseMoveSignal, this, [=]()
    {
        /*
        for (int i = 0; i < 8; ++i)
        {
            tableView1Head->setItem(i, 1, new QStandardItem(QString("...")));
            tableView1Head->setItem(i, 2, new QStandardItem(QString("...")));
            tableView1Head->setItem(i, 3, new QStandardItem(QString("...")));
        }
        for (int i = 0; i < MyCube::numSampleColumns; ++i)
        {
            for (int j = 0; j < MyCube::numSampleRows; ++j)
            {
                 tableView2Head->setItem(i, j, new QStandardItem(QString("...")));
                 tableView3Head->setItem(i, j, new QStandardItem(QString("...")));
            }
        }
        */
        ui->statusbar->showMessage(QString("Suspend - Release mouse to get new result..."));
    });

    connect(ui->cubeWidget, &MyCube::mouseReleaseSignal, this, [=](QList<QVector3D> vertex_list, int cube_width)
    {
        ui->statusbar->showMessage("Busy - Calculation in progress...");
        for (int i = 0; i < vertex_list.count(); ++i)
        {
            tableView1Head->setItem(i, 1, new QStandardItem(QString::fromStdString(std::to_string(vertex_list.at(i).x()))));
            tableView1Head->setItem(i, 2, new QStandardItem(QString::fromStdString(std::to_string(vertex_list.at(i).y()))));
            tableView1Head->setItem(i, 3, new QStandardItem(QString::fromStdString(std::to_string(vertex_list.at(i).z()))));
        }

        //构建表格来存采样点的穿过面(tableView2)以及z值(tableView3)

        for (int i = 0; i < MyCube::numSampleColumns; ++i)
        {
            tableView2Head->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(std::to_string(i + 1))));
            tableView3Head->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(std::to_string(i + 1))));
        }

        for (int i = 0; i < MyCube::numSampleColumns; ++i)
        {
            for (int j = 0; j < MyCube::numSampleRows; ++j)
            {
                tableView2Head->setItem(i, j, new QStandardItem(QString(" ")));
                tableView3Head->setItem(i, j, new QStandardItem(QString(" ")));
            }
        }

        //计算每个采样点的两个z值
        QVector<QVector<int>> elementArr_clockWise; //六个面，顺时针排点
        elementArr_clockWise = QVector<QVector<int>>{
        {0, 3, 2, 1},                                  //0 ADCB
        {5, 6, 7, 4},                                  //1 FGHE
        {0, 1, 5, 4},                                  //2 ABFE
        {1, 2, 6, 5},                                  //3 BCGF
        {2, 3, 7, 6},                                  //4 CDHG
        {7, 3, 0, 4} };                                 //5 HDAE

        //记下表格里的最大值和最小值，一会儿填颜色缩放灰度值用
        float maxBlockValue = 0.0;
        float minBlockValue = 0.0;

        for (int i = 0; i < MyCube::numSampleColumns; ++i) //单个采样点 - 列号
        {
            ui->progressBar->setValue(100 * i / MyCube::numSampleColumns);
            for (int j = 0; j < MyCube::numSampleRows; ++j) //单个采样点 - 行号
            {
                //此处S_x和S_y的计算方式对应MyCube.cpp的第207和209行（“画采样点位置”的循环条件），保证表格中的格子与画出的采样点位置对应
                float S_x = (float)(-5 * MyCube::numSampleColumns + 10 * i) * 1.0 / (float)cube_width;
                float S_y = (float)(-5 * MyCube::numSampleRows + 10 * j) * 1.0 / (float)cube_width;

                //+/-32767是NaN INF等特殊值的习惯性常用代替判别数
                //还有另一种被ANSI C采用的表示方式（更标准，但是用起来不方便）：
                //                                  if (x != x)  // x is NaN
                //把z1和z2先置NaN
                float S_z1 = -32767.0, S_z2 = -32767.0;
                int S_face1, S_face2;



                for (int k = 0; k < elementArr_clockWise.count(); ++k) //六个面
                {
                    //每个面的四个点
                    const QVector3D vt0 = vertex_list.at(elementArr_clockWise.at(k).at(0));
                    const QVector3D vt1 = vertex_list.at(elementArr_clockWise.at(k).at(1));
                    const QVector3D vt2 = vertex_list.at(elementArr_clockWise.at(k).at(2));
                    const QVector3D vt3 = vertex_list.at(elementArr_clockWise.at(k).at(3));

                    //判断，如果当前采样点（线）穿过了当前面
                    if (if_across(vt0.x(), vt0.y(), vt1.x(), vt1.y(),
                                  vt2.x(), vt2.y(), vt3.x(), vt3.y(),
                                  S_x, S_y))
                    {

                        //如果z1还没赋值，就把这次算出来的S_z给z1，否则给z2
                        if (S_z1 == -32767.0)
                        {
                            S_z1 = cal_z(vt0.x(), vt0.y(), vt0.z(),
                                         vt1.x(), vt1.y(), vt1.z(),
                                         vt2.x(), vt2.y(), vt2.z(),
                                         vt3.x(), vt3.y(), vt3.z(),
                                         S_x, S_y
                                         );
                            S_face1 = k;
                        }
                        else
                        {
                            S_z2 = cal_z(vt0.x(), vt0.y(), vt0.z(),
                                         vt1.x(), vt1.y(), vt1.z(),
                                         vt2.x(), vt2.y(), vt2.z(),
                                         vt3.x(), vt3.y(), vt3.z(),
                                         S_x, S_y
                                         );
                            S_face2 = k;
                        }
                        if (S_z2 == -32767.0) //如果只有z1有有效值，说明当前这根线正好插在边或者端点上了。但是由于if_across里写的是<=，带等号，所以这种情况貌似不会出现
                        {
                            tableView2Head->setItem(j, i, new QStandardItem(QString::fromStdString(std::to_string(S_face1))));
                            tableView3Head->setItem(j, i, new QStandardItem(QString::fromStdString(std::to_string(0))));
                        }
                        else
                        {
                            tableView2Head->setItem(j, i, new QStandardItem(QString::fromStdString(std::to_string((int)S_face1)) + QString::fromStdString(std::to_string((int)S_face2))));
                            float blockValue = std::abs(S_z1 - S_z2);

                            tableView3Head->setItem(j, i, new QStandardItem(QString::fromStdString(std::to_string(blockValue))));
                            if (blockValue > maxBlockValue)
                            {
                                maxBlockValue = blockValue;
                            }
                            if (blockValue < minBlockValue)
                            {
                                minBlockValue = blockValue;
                            }
                        }
                    }

                }
            }
        }
        ui->progressBar->setValue(100);
        ui->statusbar->showMessage(QString("Ready - Result generated. Result zoom level: x") + QString::fromStdString(std::to_string(cube_width)) + QString(".    ***If you resized the window, drag the cube again to get the new zoom level."));
        //设置三个表格只读，不允许直接在窗口改值
        //ui->tableView1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //ui->tableView2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //ui->tableView3->setEditTriggers(QAbstractItemView::NoEditTriggers);

        //给第三个表格（长度表格）做背景色可视化
        for (int i = 0; i < MyCube::numSampleColumns; ++i) //单个采样点 - 列号
        {
            for (int j = 0; j < MyCube::numSampleRows; ++j) //单个采样点 - 行号
            {
                //先拿到当前格子的值
                QModelIndex block=tableView3Head->index(j,i,QModelIndex());
                float block_value = block.data().toFloat();

                //然后给格子设色
                float grayValue = (block_value - minBlockValue) / (maxBlockValue - minBlockValue) * 255.0;
                tableView3Head->item(j, i)->setBackground(QColor(grayValue, grayValue, grayValue));
            }
        }
    });

    connect(ui->fontComboBox, &QFontComboBox::currentFontChanged, this, [=]()
    {
        ui->cubeWidget->setPainterFont(ui->fontComboBox->currentFont());
        ui->cubeWidget->setPainterFontSize(ui->horizontalSlider->value());
        ui->cubeWidget->repaint();
    });

    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [=]()
    {
        ui->cubeWidget->setPainterFontSize(ui->horizontalSlider->value());
        ui->fontSizeLabel->setText(QString::fromStdString(std::to_string(ui->horizontalSlider->value())));
        ui->cubeWidget->repaint();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
