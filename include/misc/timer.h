#ifndef WISCOPROS2122_MISC_TIMER_H_
#define WISCOPROS2122_MISC_TIMER_H_

#include "main/main.h"
#include "pros/rtos.hpp"

namespace timer {
    class Timer {
        int initialValue;
        int timerValue;
        bool paused;

    public:
        Timer();
        int currentTime();
        void zeroTimer();
        void stopTimer();
        void startTimer();
    };
}

#endif  // WISCOPROS2122_MISC_TIMER_H_S
