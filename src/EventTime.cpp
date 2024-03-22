#include "EventTime.h"

bool EventTime::operator<(const EventTime &other) const {
    return startTime < other.getStartTime();
}

bool EventTime::operator==(const EventTime &other) const {
    return startTime == other.getStartTime();
}

void EventTime::setDate(int newDay, int newMonth, int newYear) {
    eventStartTime.tm_year = (newYear - 1900);
    eventStartTime.tm_mon = newMonth - 1;
    eventStartTime.tm_mday = newDay;
}

void EventTime::setTime(int newHour, int newMinute) {
    eventStartTime.tm_hour = newHour;
    if (summerTime()) eventStartTime.tm_hour -= 1;
    eventStartTime.tm_min = newMinute;
    startTime = mktime(&eventStartTime);
}

void EventTime::setNewFinishTime(time_t newFinishTime) {
    finishTime = newFinishTime;
    eventNewTime = localtime(&finishTime);
}

void EventTime::setDuration(time_t duration) {
    finishTime = startTime + duration;
    eventNewTime = localtime(&finishTime);
}

int EventTime::getYear() const {
    return eventStartTime.tm_year + 1900;
}

int EventTime::getMonth() const {
    return eventStartTime.tm_mon + 1;
}

int EventTime::getDay() const {
    return eventStartTime.tm_mday;
}

int EventTime::getHour() const {
    return eventStartTime.tm_hour;
}

int EventTime::getMinute() const {
    return eventStartTime.tm_min;
}

time_t EventTime::getStartTime() const {
    return startTime;
}

time_t EventTime::getFinishTime() const {
    return finishTime;
}

int EventTime::getWeekDay() const {
    int wd;
    if (eventStartTime.tm_wday == 0) wd = 7;
    else wd = eventStartTime.tm_wday;
    return wd;
}

void EventTime::increaseTime(time_t newTime) {
    startTime += newTime;
    finishTime += newTime;
    eventNewTime = localtime(&startTime);
    eventStartTime.tm_mon = eventNewTime->tm_mon;
    eventStartTime.tm_hour = eventNewTime->tm_hour;
    eventStartTime.tm_mday = eventNewTime->tm_mday;
    eventStartTime.tm_min = eventNewTime->tm_min;
    eventStartTime.tm_year = eventNewTime->tm_year;
    eventStartTime.tm_wday = eventNewTime->tm_wday;
    eventStartTime.tm_sec = eventNewTime->tm_sec;
    eventStartTime.tm_isdst = eventNewTime->tm_isdst;
    eventStartTime.tm_yday = eventNewTime->tm_yday;
}

ostream &operator<<(ostream &out, const EventTime &date) {
    time_t tmp1 = date.getStartTime();
    time_t tmp2 = date.getFinishTime();
    out << EVENT_START;
    out << asctime(localtime(&tmp1));
    out << EVENT_FINISH;
    out << asctime(localtime(&tmp2));
    return out;
}

bool EventTime::summerTime() const {
    if (eventStartTime.tm_mon > 2 && eventStartTime.tm_mon < 9) return true;
    if (eventStartTime.tm_mon < 2 || eventStartTime.tm_mon > 9) return false;
    if (eventStartTime.tm_mon == 2) {
        if ((7 - eventStartTime.tm_wday) > (31 - eventStartTime.tm_mday)) {
            if (eventStartTime.tm_hour > 4) return true;
            else return false;
        }
        return false;
    }
    if ((7 - eventStartTime.tm_wday) > (31 - eventStartTime.tm_mday)) { // only if month == 10
        if (eventStartTime.tm_hour > 4) return false;
        else return true;
    }
    return true;
}