#ifndef POSITIONVELOCITY_H
#define POSITIONVELOCITY_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "MainWindow.h"
#include <QElapsedTimer>

namespace Ui {
class PositionVelocity;
}

class PositionVelocity : public QMainWindow
{
    Q_OBJECT

public:
    explicit PositionVelocity(QWidget *parent = 0);
    ~PositionVelocity();
    QElapsedTimer timer2;
    QElapsedTimer timer3;
    QTime timer;
    double abs(double value);

public slots:
    void on_sensorValues_clicked();
    void newNumber(MainWindow::data cleanData);
    void on_pause_clicked();

protected:

    void plotAxisData(int AxesDecision, double accel, double velocity, double position);

    double velocity = 0;
    double zAccelTmp = 0;
    double zPos = 0;
    int counter = 0;
    int zMax;

    double ax0 = 0;
    double ax1 = 0;
    double sx = 0;
    double sx1 = 0;
    double vx = 0;
    double vx1 = 0;
    double sumSx = 0;
    double max = 0;

    double ay0 = 0;
    double ay1 = 0;
    double sy0 = 0;
    double sy1 = 0;
    double vy0 = 0;
    double vy1 = 0;

    double vx1Total = 0;
    double vy1Total = 0;

signals:   
    void onStop();

private slots:
    void on_restart_clicked();

    void on_plot2D_clicked();

private:  
    Ui::PositionVelocity *ui;
    void setupParametars(QCustomPlot *plot);
    MainWindow mainwin;
    bool mStop;
};

#endif // POSITIONVELOCITY_H
