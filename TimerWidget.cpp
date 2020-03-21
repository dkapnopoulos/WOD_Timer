#include "TimerWidget.h"
#include "Wod.h"

#include <QPainter>
#include <QFont>
#include <QFontMetrics>

TimerWidget::TimerWidget(QWidget *parent)
    : QWidget(parent), m_timer(nullptr)
{
    m_wod = new WOD2103;

    setFocusPolicy(Qt::StrongFocus);
}

void TimerWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::green);

    if (!m_timer)
        return;

    int total_secs_passed = m_time.secsTo(QTime::currentTime());
    int mins_passed = total_secs_passed / 60;
    int secs_passed = total_secs_passed % 60;

    QString currentExercise = m_wod->getCurrentExercise(mins_passed, secs_passed);
    QString nextExercise = m_wod->getNextExercise(mins_passed, secs_passed);
    nextExercise = QString("Next: ") + nextExercise;

    QString elapsed_time = QString("%1:%2").arg(mins_passed).arg(secs_passed, 2, 10, QChar('0'));

    QFont currentExerciseFont("Times", 50, QFont::Bold);
    painter.setFont(currentExerciseFont);
    QFontMetrics currentFontMetrics(currentExerciseFont);
    int currentExerciseWidth = currentFontMetrics.width(currentExercise);
    int currentExerciseHeight = currentFontMetrics.height();
    painter.drawText(rect().width()/2 - currentExerciseWidth/2, currentExerciseHeight + 10, currentExercise);

    QFont nextExerciseFont("Times", 20);
    QFontMetrics nextFontMetrics(nextExerciseFont);
    painter.setFont(nextExerciseFont);
    painter.drawText((2 * rect().width()) / 3, currentExerciseHeight + 50, nextExercise);

    QFont timerFont("Times", 100, QFont::Bold);
    QFontMetrics timeFontMetrics(timerFont);
    int timeWidth = timeFontMetrics.width(elapsed_time);
    int timeHeight = nextFontMetrics.height();
    painter.setFont(timerFont);
    painter.setPen(Qt::red);
    painter.drawText(rect().width()/2 - timeWidth/2, rect().height()/2 + timeHeight/2, elapsed_time);
}

void TimerWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space){
        if (m_timer){
            m_timer->stop();
            delete m_timer;
            m_timer = nullptr;
        }else{
            m_timer = new QTimer(this);
            connect(m_timer, &QTimer::timeout, this, &TimerWidget::timerUpdate);
            m_time.start();
            m_timer->start(1000);
        }
    }
}

void TimerWidget::timerUpdate()
{
    update();
}

