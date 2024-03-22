#ifndef MAIN_CPP_SHOWEVENTS_H
#define MAIN_CPP_SHOWEVENTS_H

#include "Meeting.h"
#include "Birthday.h"

/**
 * @brief parent class for ShowHourEvents, ShowDayEvents, ShowWeekEvents, ShowMonthEvents, ShowAllEvents \n
 * Added attributes:
 *  time_t now
 *  tm *nowTime
 */
class ShowEvents {
public:
    //! print events depending on now date and time
    virtual void showNow(vector<Event *> &events) const = 0;

    //! print events depending on chosen date
    virtual void showAt(vector<Event *> &events, Event &tmp) const = 0;

    //! virtual distructor
    virtual ~ShowEvents() = default;

protected:
    //! now time in seconds
    time_t now = time(nullptr);

    //! structure representing local time
    tm *nowTime = localtime(&now);
};

#endif //MAIN_CPP_SHOWEVENTS_H
