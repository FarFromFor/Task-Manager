#include "ShowHourEvents.h"

void ShowHourEvents::showNow(vector<Event *> &events) const {
    for (size_t i = 0; i < events.size(); ++i) {
        if (((events[i]->date.getStartTime() - now) < SECONDS_IN_HOUR) &&
            ((events[i]->date.getStartTime() - now) > 0)) {
            cout << (*events[i]);
        }
    }
}

void ShowHourEvents::showAt(vector<Event *> &events, Event &tmp) const {}