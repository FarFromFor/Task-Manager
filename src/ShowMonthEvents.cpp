#include "ShowMonthEvents.h"

void ShowMonthEvents::showNow(vector<Event *> &events) const {
    int nowYear = nowTime->tm_year + 1900;
    int nowMonth = nowTime->tm_mon + 1;
    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i]->date.getYear() == nowYear &&
            events[i]->date.getMonth() == nowMonth) {
            cout << (*events[i]);
        }
    }
}

void ShowMonthEvents::showAt(vector<Event *> &events, Event &tmp) const {
    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i]->date.getYear() == tmp.date.getYear() &&
            events[i]->date.getMonth() == tmp.date.getMonth()) {
            cout << (*events[i]);
        }
    }
}