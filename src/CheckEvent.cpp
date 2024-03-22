#include "CheckEvent.h"

bool CheckEvent::compareEvent(const Event *i1, const Event &i2) {
    if (i1->date < i2.date) return true;
    return false;
}

bool CheckEvent::isCollisionsFree(vector<Event *> &events, Event &tmp) {
    if (!tmp.potentialCollision) return true;
    for (size_t i = 0; i < events.size(); ++i) {
        if (intersectionCheck(*events[i], tmp)) {
            if (events[i]->actualNumberOfCollisions < events[i]->allowedNumberOfCollisions) {
                tmp.actualNumberOfCollisions++;
                if (tmp.actualNumberOfCollisions > tmp.allowedNumberOfCollisions) {
                    cout << COLLISIONS_FAIL << endl;
                    return false;
                }
                continue;
            }
            cout << COLLISIONS_FAIL << endl;
            return false;
        }
    }
    for (size_t i = 0; i < events.size(); ++i) {
        if (intersectionCheck(*events[i], tmp)) {
            if (events[i]->actualNumberOfCollisions == events[i]->allowedNumberOfCollisions) {
                return false;
            }
        }
    }
    return true;
}

bool CheckEvent::intersectionCheck(Event &a, Event &b) {
    if (!a.potentialCollision || !b.potentialCollision) return false;
    if ((a.date.getStartTime() >= b.date.getStartTime()) &&
        (a.date.getFinishTime()) <= b.date.getFinishTime()) {
        return true;
    }
    if ((b.date.getStartTime() >= a.date.getStartTime()) &&
        (b.date.getFinishTime()) <= a.date.getFinishTime()) {
        return true;
    }

    if ((a.date.getStartTime() <= b.date.getStartTime()) &&
        (a.date.getFinishTime() >= b.date.getStartTime()) &&
        (a.date.getFinishTime() <= b.date.getFinishTime())) {
        return true;
    }

    if ((a.date.getStartTime() >= b.date.getStartTime()) &&
        (a.date.getStartTime() <= b.date.getFinishTime()) &&
        (a.date.getFinishTime() >= b.date.getFinishTime())) {
        return true;
    }
    return false;
}

void CheckEvent::increaseCollision(vector<Event *> &events, Event &tmp) {
    for (size_t i = 0; i < events.size(); ++i) {
        if (CheckEvent::intersectionCheck(*events[i], tmp)) {
            events[i]->actualNumberOfCollisions += 1;
        }
    }
}