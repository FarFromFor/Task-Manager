#ifndef MAIN_CPP_SHOWDAYEVENTS_H
#define MAIN_CPP_SHOWDAYEVENTS_H

#include "Event.h"
#include "ShowEvents.h"

/**
 * @brief class for printing this/chosen day events \n
 * Implemented functions:
 *  showNow (vector<Event *> &events, vector<Event *> &repeatingEvents)
 *  showAt (vector<Event *> &events, Event &tmp)
 */
class ShowDayEvents : public ShowEvents {
    //! print events starting this day
    void showNow(vector<Event *> &events) const override;

    //! print events starting chosen day
    void showAt(vector<Event *> &events, Event &tmp) const override;
};

#endif //MAIN_CPP_SHOWDAYEVENTS_H
