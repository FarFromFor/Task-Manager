#ifndef MAIN_CPP_SHOWMONTHEVENTS_H
#define MAIN_CPP_SHOWMONTHEVENTS_H

#include "Event.h"
#include "ShowEvents.h"

/**
 * @brief class for printing this/chosen month events \n
 * Implemented functions:
 *  showNow (vector<Event *> &events, vector<Event *> &repeatingEvents)
 *  showAt (vector<Event *> &events, Event &tmp)
 */
class ShowMonthEvents : public ShowEvents {
    //! print events starting this month
    void showNow(vector<Event *> &events) const override;

    //! print events starting the month, chosen day belongs to
    void showAt(vector<Event *> &events, Event &tmp) const override;
};


#endif //MAIN_CPP_SHOWMONTHEVENTS_H
