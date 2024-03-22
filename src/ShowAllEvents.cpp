#include "ShowAllEvents.h"

void ShowAllEvents::showNow(vector<Event *> &events) const {
    for (size_t i = 0; i < events.size(); ++i) {
        cout << (*events[i]);
    }
}

void ShowAllEvents::showAt(vector<Event *> &events, Event &tmp) const {}