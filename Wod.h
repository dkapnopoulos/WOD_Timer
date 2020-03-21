#ifndef WOD_H
#define WOD_H

#include <QString>
#include <QTime>

class WOD
{
public:
    WOD();
    ~WOD();

    virtual QString getCurrentExercise(int mins_passed, int secs_passed) = 0;
    virtual QString getNextExercise(int mins_passed, int secs_passed) = 0;
};

class WOD2103 : public WOD
{
public:
    QString getCurrentExercise(int mins_passed, int secs_passed) override;
    QString getNextExercise(int mins_passed, int secs_passed) override;

private:
};

#endif // WOD_H
