#include "Wod.h"

WOD::WOD()
{

}

WOD::~WOD()
{

}

QString WOD2103::getCurrentExercise(int mins_passed, int secs_passed)
{
    if (mins_passed % 2 == 0){
        if (secs_passed < 45){
            return QString("High Plank");
        }else{
            return QString("Rest!");
        }
    }else{
        return QString("Squat");
    }
}

QString WOD2103::getNextExercise(int mins_passed, int secs_passed)
{
    if (mins_passed % 2 == 0){
        if (secs_passed < 45){
            return QString("Rest");
        }else{
            return QString("Squat");
        }
    }else{
        return QString("High Plank");
    }
}
