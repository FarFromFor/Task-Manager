#ifndef MAIN_CPP_EVENTTIME_H
#define MAIN_CPP_EVENTTIME_H

#include <ctime>
#include <iostream>
#include "Config.h"
using namespace std;

/**
 * @brief represents event date \n
 * Added attributes:
 *  tm eventStartTime
 *  tm *eventNewTime
 *  time_t startTime
 *  time_t finishTime \n
 * Implemented functions:
 *  setDate(int newDay, int newMonth, int newYear)
 *  setTime(int newHour, int newMinute)
 *  setNewFinishTime(int hours, int minutes)
 *  getYear()
 *  getMonth()
 *  getDay()
 *  getHour()
 *  getMinute()
 *  getStartTime()
 *  getFinishTime()
 *  setDuration(time_t duration)
 *  bool summerTime()
 *  int getWeekDay()
 *  void increaseTime(time_t newTime) \n
 * Operators:
 *  bool operator <
 *  bool operator ==
 *  ostream &operator<<
 */
class EventTime {
public:
    //! return true if this events start tim is earlier than anothers
    bool operator<(const EventTime &other) const;

    //! return true if events' start times are the same
    bool operator==(const EventTime &other) const;

    //! print date to out
    friend ostream &operator<<(ostream &out, const EventTime &date);

    //! set date
    void setDate(int newDay, int newMonth, int newYear);

    //! set time
    void setTime(int newHour, int newMinute);

    //! set duration
    void setNewFinishTime(time_t newFinishTime);

    //! return year event starts
    int getYear() const;

    //! return month event starts
    int getMonth() const;

    //! return day event starts
    int getDay() const;

    //! return hour event starts
    int getHour() const;

    //! return minute event starts
    int getMinute() const;

    //! return start time in seconds
    time_t getStartTime() const;

    //! return finish time in seconds
    time_t getFinishTime() const;

    //! set duration in seconds
    void setDuration(time_t duration);

    //! return true if time is summer time
    bool summerTime() const;

    //! return week day where 1 - monday... 7 - sunday
    int getWeekDay() const;

    //! increase start and finish time by newTime
    void increaseTime(time_t newTime);

    //! structure representing time event starts
    tm eventStartTime = {0};

    //! structure representing time event finishes
    tm *eventNewTime = {nullptr};
private:
    //! start time in seconds
    time_t startTime;
    //! start finish in seconds
    time_t finishTime;
};

#endif //MAIN_CPP_EVENTTIME_H
