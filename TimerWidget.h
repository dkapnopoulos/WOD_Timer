#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPaintEvent>
#include <QTime>

class WOD;

class TimerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimerWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void timerUpdate();

    WOD *m_wod;
    QTimer *m_timer;
    QTime m_time;
};

#endif // TIMERWIDGET_H
