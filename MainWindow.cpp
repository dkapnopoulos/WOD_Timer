#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_timerWidget = new TimerWidget(this);
    setCentralWidget(m_timerWidget);
}

MainWindow::~MainWindow()
{

}
