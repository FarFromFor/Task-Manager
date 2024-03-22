#include "DeleteEvent.h"

bool DeleteEvent::deleteEvent(vector<Event *> &events) {
    cout << WHAT_TO_DELETE << endl;
    cout << DEL_OPT1 << endl;
    cout << DEL_OPT2 << endl;
    cout << DEL_OPT3 << endl;
    cout << DEL_OPT4 << endl;
    int command;
    if (CheckInput::numberInputFail(command, 1, 4)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    if (command == 1) {
        if (!delEv(events, false)) {
            cout << EVENT_FIND_FAIL << endl;
        } else {
            cout << EVENT_ERASE_SUCCESS << endl;
        }
    }
    if (command == 2) {
        if (!delEv(events, true)) {
            cout << EVENT_FIND_FAIL << endl;
        } else {
            cout << EVENT_ERASE_SUCCESS << endl;
        }
    }
    if (command == 3) {
        if (events.empty()) {
            cout << NO_EVENTS_FAIL << endl;
            return false;
        }
        for (size_t i = 0; i < events.size(); ++i) {
            if (events[i] != nullptr) {
                delete events[i];
            }
        }
        events.clear();
        cout << EVENT_ERASE_ALL_SUCCESS << endl;
        return true;
    }
    return false;
}

bool DeleteEvent::delEv(vector<Event *> &events, bool isRequrring) {
    Meeting tmp;
    if (!tmp.setDate())return false;
    if (!tmp.setTime())return false;
    if (!isRequrring) {
        auto iter = lower_bound(events.begin(), events.end(), tmp, CheckEvent::compareEvent);
        if (iter == events.end()) {
            return false;
        }
        if (events[iter - events.begin()]->date == tmp.date) {
            for (size_t i = 0; i < events.size(); ++i) {
                if (CheckEvent::intersectionCheck(*events[i], *events[iter - events.begin()]) &&
                    (events[i]->actualNumberOfCollisions != 0))
                    events[i]->actualNumberOfCollisions--;
            }
            delete events[iter - events.begin()];
            events.erase(iter);
            return true;
        }
    } else {
        auto iter = lower_bound(events.begin(), events.end(), tmp, CheckEvent::compareEvent);
        while (true) {
            if (iter == events.end() || !(events[iter - events.begin()]->date == tmp.date)){
                return false;
            }
            if(!events[iter - events.begin()]->isRecurring){
                iter++;
                continue;
            } else{
                break;
            }
        }
        size_t id1 = events[iter - events.begin()]->getID().first;
        size_t id2 = events[iter - events.begin()]->getID().second;
        for (size_t i = 0; i < events.size(); ++i) {
            if (events[i]->getID().first == id1 && events[i]->getID().second == id2) {
                for (size_t j = 0; j < events.size(); ++j) {
                    if (CheckEvent::intersectionCheck(*events[j], *events[i]) &&
                        (events[j]->actualNumberOfCollisions != 0))
                        events[j]->actualNumberOfCollisions--;
                }
                delete events[i];
                events.erase(events.begin() + i);
                i--;
            }
        }
        return true;
    }

    return false;
}