#ifndef MAIN_CPP_SHOWHOUREVENTS_H
#define MAIN_CPP_SHOWHOUREVENTS_H

#include "Event.h"
#include "ShowEvents.h"

/**
 * @brief class for printing next hour events \n
 * Implemented functions:
 *  showNow (vector<Event *> &events, vector<Event *> &repeatingEvents)
 *  showAt (vector<Event *> &events, Event &tmp)
 */
class ShowHourEvents : public ShowEvents {
    //! print events starting next hour
    void showNow(vector<Event *> &events) const override;

    //! dont print anything
    void showAt(vector<Event *> &events, Event &tmp) const override;
};


#endif //MAIN_CPP_SHOWHOUREVENTS_H
