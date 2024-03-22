#ifndef MAIN_CPP_CHECKEVENT_H
#define MAIN_CPP_CHECKEVENT_H

#include "Event.h"
/**
 * @brief class for working with Event \n
 * Implemented functions:
 *  compareEvent(const Event *i1, const Event &i2)
 *  isCollisionsFree(vector<Event *> &events, Event &tmp)
 *  intersectionCheck(Event &a, Event &b)
 *  increaseCollision(vector<Event *> &events, Event &tmp)
 */
class CheckEvent {
public:
    //! compare two events by their dates
    bool static compareEvent(const Event *i1, const Event &i2);

    //! check if event could be added and set its collisions number
    bool static isCollisionsFree(vector<Event *> &events, Event &tmp);

    //! check if events times intersect
    bool static intersectionCheck(Event &a, Event &b);

    //! increase collisions numbers of existing events if intersect with "tmp"
    void static increaseCollision(vector<Event *> &events, Event &tmp);
};


#endif //MAIN_CPP_CHECKEVENT_H
