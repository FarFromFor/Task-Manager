#ifndef MAIN_CPP_SHOWALLEVENTS_H
#define MAIN_CPP_SHOWALLEVENTS_H

#include "Event.h"
#include "ShowEvents.h"

/**
 * @brief class for printing all events \n
 * Implemented functions:
 *  showNow (vector<Event *> &events, vector<Event *> &repeatingEvents)
 *  showAt (vector<Event *> &events, Event &tmp)
 */
class ShowAllEvents : public ShowEvents {
    //! print all events
    void showNow(vector<Event *> &events) const override;

    //! dont print anything
    void showAt(vector<Event *> &events, Event &tmp) const override;
};


#endif //MAIN_CPP_SHOWALLEVENTS_H
