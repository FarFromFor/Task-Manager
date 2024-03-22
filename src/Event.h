#ifndef MAIN_CPP_EVENT_H
#define MAIN_CPP_EVENT_H

#include <limits>
#include <vector>
#include <iostream>
#include "CheckDate.h"
#include "EventTime.h"
#include "CheckInput.h"
#include "Config.h"

/**
 * @brief Parent class for Activity and Reminder \n
 * Added attributes:
 *  bool isRecurring
 *  int allowedNumberOfCollisions
 *  int actualNumberOfCollisions
 *  int repeatingIntervalDays
 *  bool potentialCollision
 *  string note
 *  EventTime date
 *  int numberOfRepetitions
 *  pair<size_t, size_t> id \n
 * Implemented functions:
 *  setDate()
 *  setTime()
 *  setDuration()
 *  setID(size_t newID1, size_t newID2)
 *  pair<size_t, size_t> getID()
 * Operators:
 *  ostream &operator<<
 */
class Event {
public:
    //! print event to "out"
    virtual void print(ostream &out) const = 0;

    //! write event to "out"
    virtual void write(ostream &out) const = 0;

    //! returns pointer on new allocated event
    virtual Event *clone() const = 0;

    //! virtual distructor
    virtual ~Event() = default;

    //! print event to "out"
    friend ostream &operator<<(ostream &out, const Event &elem);

    //! return event title
    virtual string getTitle() const = 0;

    //! return event location
    virtual string getLocation() const = 0;

    //! returns vector of invited persons
    virtual vector<string> getMembers() const = 0;

    //! returns vector of tags
    virtual vector<string> getTags() const = 0;

    //! let user set date
    bool setDate();

    //! let user set time
    bool setTime();

    //! let user set duration
    bool setDuration();

    //! set event id pair
    void setID(size_t newID1, size_t newID2);

    //! get event id pair
    pair<size_t, size_t> getID() const;

    //! is event recurring
    bool isRecurring = false;

    //! allowed number of collisions
    int allowedNumberOfCollisions = 0;

    //! actual number of collisions
    int actualNumberOfCollisions = 0;

    //! repeating interval in days
    int repeatingIntervalDays = 1;

    //! is potential collision could happen
    bool potentialCollision = true;

    //! event note
    string note;

    //! event date
    EventTime date;

    //! number of event repetitions
    int numberOfRepetitions = 1;
private:
    //! event id pair
    pair<size_t, size_t> id;
};

#endif //MAIN_CPP_EVENT_H
