#include "timer.h"

namespace timer {
    Timer::Timer()
    {
        this->timerValue = 0;
        this->paused = false;
        this->initialValue = pros::c::millis();
    }

    int Timer::currentTime() {
        if (!(this->paused))
            return (pros::c::millis() - this->initialValue);
        else
            return (this->timerValue);
    }

    void Timer::zeroTimer() {
        this->timerValue = 0;
        this->initialValue = pros::c::millis();
    }

    void Timer::stopTimer() {
        if (!this->paused)
            this->timerValue = (pros::c::millis() - this->initialValue);

        this->paused = true;
    }

    void Timer::startTimer() {
        if (this->paused)
            this->initialValue = pros::c::millis() - this->timerValue;

        this->paused = false;
    }
}

