#ifndef MYCUBE_H
#define MYCUBE_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QtMath>
#include <QDebug>
#include <QVector3D>
#include <QMatrix4x4>

//绘制3d立方体
class MyCube : public QWidget
{
    Q_OBJECT
public:
    explicit MyCube(QWidget *parent = nullptr);
    void setPainterFont(const QFont & font) //槽函数
    {
        painterFont = font;
    }

    void setPainterFontSize(const int &size) //槽函数
    {
        painterFont.setPointSize(size);
    }

    static const int numSampleColumns = 50;
    static const int numSampleRows = 50;

signals:
    void mouseMoveSignal();
    void mouseReleaseSignal(QList<QVector3D> vertex_list, int cube_width);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QPointF getPoint(const QVector3D &vt, int w) const;


private:
    QVector<QVector3D> vertexArr;     //八个顶点
    QVector<QVector<int>> elementArr; //六个面
    QMatrix4x4 rotateMat;      //旋转矩阵
    QPoint mousePos;           //鼠标位置
    bool mousePressed = false;   //鼠标按下标志位
    QFont painterFont;
    int cube_width;

};

#endif // MYCUBE_H
