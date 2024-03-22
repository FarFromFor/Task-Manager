#include "ShowWeekEvents.h"

void ShowWeekEvents::showNow(vector<Event *> &events) const {
    int wd;
    if (nowTime->tm_wday == 0) wd = 7;
    else wd = nowTime->tm_wday;
    time_t timeTmp;
    timeTmp = time(nullptr);
    timeTmp -= ((wd - 1) * SECONDS_IN_DAY);
    timeTmp -= (nowTime->tm_hour * SECONDS_IN_HOUR);
    timeTmp -= (nowTime->tm_min * SECONDS_IN_MINUTE);
    timeTmp -= (nowTime->tm_sec);
    for (size_t i = 0; i < events.size(); ++i) {
        if ((events[i]->date.getStartTime() >= timeTmp)
            && (events[i]->date.getStartTime() < (timeTmp + (SECONDS_IN_WEEK)))) {
            cout << (*events[i]);
        }
    }
}

void ShowWeekEvents::showAt(vector<Event *> &events, Event &tmp) const {
    time_t timeTmp = tmp.date.getStartTime();
    timeTmp -= ((tmp.date.getWeekDay() - 1) * SECONDS_IN_DAY);
    timeTmp -= (tmp.date.eventStartTime.tm_hour * SECONDS_IN_HOUR);
    timeTmp -= (tmp.date.eventStartTime.tm_min * SECONDS_IN_MINUTE);
    for (size_t i = 0; i < events.size(); ++i) {
        if ((events[i]->date.getStartTime() >= timeTmp)
            && (events[i]->date.getStartTime() < (timeTmp + (SECONDS_IN_WEEK)))) {
            cout << (*events[i]);
        }
    }
}