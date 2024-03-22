#ifndef MAIN_CPP_DELETEEVENT_H
#define MAIN_CPP_DELETEEVENT_H

#include <algorithm>
#include "Event.h"
#include "CheckInput.h"
#include "CheckEvent.h"
#include "Meeting.h"
#include "Birthday.h"
/**
 * @brief class for deleting events \n
 * Implemented functions:
 * deleteEvent(vector<Event *> &events)
 * delEv(vector<Event *> &events, bool isRequrring)
 */
class DeleteEvent {
public:
    //! delete event by chosen parameters
    bool deleteEvent(vector<Event *> &events);

private:
    //! delete event
    bool delEv(vector<Event *> &events, bool isRequrring);
};


#endif //MAIN_CPP_DELETEEVENT_H
