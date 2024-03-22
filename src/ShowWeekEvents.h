#ifndef MAIN_CPP_SHOWWEEKEVENTS_H
#define MAIN_CPP_SHOWWEEKEVENTS_H

#include "Event.h"
#include "ShowEvents.h"

/**
 * @brief class for printing this/chosen week events \n
 * Implemented functions:
 *  showNow (vector<Event *> &events, vector<Event *> &repeatingEvents)
 *  showAt (vector<Event *> &events, Event &tmp)
 */
class ShowWeekEvents : public ShowEvents {
    //! print events starting this week
    void showNow(vector<Event *> &events) const override;

    //! print events starting the week, chosen day belongs to
    void showAt(vector<Event *> &events, Event &tmp) const override;
};


#endif //MAIN_CPP_SHOWWEEKEVENTS_H
