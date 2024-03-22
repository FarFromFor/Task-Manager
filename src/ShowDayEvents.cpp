#include "ShowDayEvents.h"

void ShowDayEvents::showNow(vector<Event *> &events) const {
    int nowYear = nowTime->tm_year + 1900;
    int nowMonth = nowTime->tm_mon + 1;
    int nowDay = nowTime->tm_mday;
    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i]->date.getYear() == nowYear &&
            events[i]->date.getMonth() == nowMonth &&
            events[i]->date.getDay() == nowDay) {
            cout << (*events[i]);
        }
    }
}

void ShowDayEvents::showAt(vector<Event *> &events, Event &tmp) const {
    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i]->date.getYear() == tmp.date.getYear() &&
            events[i]->date.getMonth() == tmp.date.getMonth() &&
            events[i]->date.getDay() == tmp.date.getDay()) {
            cout << (*events[i]);
        }
    }
}