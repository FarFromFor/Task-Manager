#ifndef MAIN_CPP_ADDNEWEVENT_H
#define MAIN_CPP_ADDNEWEVENT_H

#include <algorithm>
#include "Meeting.h"
#include "Birthday.h"
#include "Party.h"
#include "Task.h"
#include "ShowEvents.h"
#include "Reminder.h"
#include "CheckInput.h"
#include "CheckEvent.h"
#include <random>
#include "Config.h"
/**
 * @brief class for adding new event \n
 * Implemented functions:
 * addActivity(Activity &event)
 * addMeeting(vector<Event *> &events)
 * addBirthday(vector<Event *> &events)
 * addParty(vector<Event *> &events)
 * addTask(vector<Event *> &events)
 * addReminder(vector<Event *> &events)
 * addNewEvent(vector<Event *> &events)
 * setId(Event &tmp)
 * insertAndCheck(vector<Event *> &events, Event &tmp)
 * insertThings(ActivityToPickWith &tmp)
 */
class AddNewEvent {
public:
    //! set events Activity parameters
    bool addActivity(Activity &event);

    //! set parameters and add new Meeting event
    bool addMeeting(vector<Event *> &events);

    //! set parameters and add new Birthday event
    bool addBirthday(vector<Event *> &events);

    //! set parameters and add new Party event
    bool addParty(vector<Event *> &events);

    //! set parameters and add new Task event
    bool addTask(vector<Event *> &events);

    //! set parameters and add new Reminder event
    bool addReminder(vector<Event *> &events);

    //! add new event of chosen type
    bool addNewEvent(vector<Event *> &events);


private:
    //! set events id pair
    void setId(Event &tmp);

    //! check if event could be added and if yes, increase collisions counters
    bool insertAndCheck(vector<Event *> &events, Event &tmp);

    //! add "things" to new event
    bool insertThings(ActivityToPickWith &tmp);
};


#endif //MAIN_CPP_ADDNEWEVENT_H
