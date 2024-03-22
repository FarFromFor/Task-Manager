#include "AddNewEvent.h"

bool AddNewEvent::addActivity(Activity &event) {
    cout << ENTER_TITLE << endl;
    if (CheckInput::stringInputFail(event.title) || cin.eof()) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    cout << ENTER_LOCATION << endl;
    if (CheckInput::stringInputFail(event.location) || cin.eof()) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    cout << ENTER_NOTE << endl;
    if (CheckInput::stringInputFail(event.note) || cin.eof()) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    cout << ENTER_MEMBERS << endl;
    while (true) {
        bool cont = false;
        if (event.members.size() > MAX_ELEMENTS) {
            cout << TOO_MANY_MEMBERS_FAIL << endl;
            return false;
        }
        string member;
        if (CheckInput::stringInputFail(member) || cin.eof()) {
            cout << INPUT_FAIL << endl;
            return false;
        }
        if (member == INPUT_END) break;
        for (size_t i = 0; i < event.members.size(); ++i) {
            if (member == event.members[i]) {
                cont = true;
                break;
            }
        }
        if (cont) continue;
        if (!member.empty()) {
            event.members.push_back(member);
        }
    }
    cout << ENTER_TAGS << endl;
    while (true) {
        bool cont = false;
        if (event.tags.size() > MAX_ELEMENTS) {
            cout << TOO_MANY_TAGS_FAIL << endl;
            return false;
        }
        string tag;
        cout << TAG_SYMBOL;
        if (CheckInput::stringInputFail(tag) || cin.eof()) {
            cout << INPUT_FAIL << endl;
            return false;
        }
        if (tag == INPUT_END) break;
        for (size_t i = 0; i < event.tags.size(); ++i) {
            if (tag == event.tags[i]) {
                cont = true;
                break;
            }
        }
        if (cont) continue;
        if (!tag.empty()) {
            event.tags.push_back(tag);
        }
    }
    cout << MAKE_REPEATING << endl;
    cout << YES << endl;
    cout << NO << endl;
    int command;
    if (CheckInput::numberInputFail(command, 1, 2)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    if (command == 1) {
        event.isRecurring = true;
        cout << ENTER_REPEATING_INTERVAL << endl;
        if (CheckInput::numberInputFail(event.repeatingIntervalDays, 1, MAX_REPEATING_INTERVAL)) {
            cout << INPUT_FAIL << endl;
            return false;
        }

        if ((event.date.getFinishTime() - event.date.getStartTime()) >
            event.repeatingIntervalDays * SECONDS_IN_DAY) {
            cout << REPEATING_INTERVAL_FAIL << endl;
            return false;
        }
        cout << ENTER_REPETITIONS_NUMBER << endl;
        if (CheckInput::numberInputFail(event.numberOfRepetitions, 1, MAX_REPETITIONS)) {
            cout << INPUT_FAIL << endl;
            return false;
        }
    } else {
        event.isRecurring = false;
    }
    cout << ENTER_ALLOWED_CONCURRENT_EV << endl;
    if (CheckInput::numberInputFail(event.allowedNumberOfCollisions, 0, MAX_ALLOWED_COLLISIONS)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    return true;
}

bool AddNewEvent::addMeeting(vector<Event *> &events) {
    Meeting tmp;
    if (!tmp.setDate()) return false;
    if (!tmp.setTime()) return false;
    if (!tmp.setDuration()) return false;
    if (!addActivity(tmp)) return false;
    while (tmp.dressCode.empty()) {
        cout << ENTER_DRESS_CODE << endl;
        if (CheckInput::stringInputFail(tmp.dressCode)) {
            cout << INPUT_FAIL << endl;
            return false;
        }
    }
    setId(tmp);
    return insertAndCheck(events, tmp);
}

bool AddNewEvent::addBirthday(vector<Event *> &events) {
    Birthday tmp;
    if (!tmp.setDate()) return false;
    if (!tmp.setTime()) return false;
    if (!tmp.setDuration()) return false;
    if (!addActivity(tmp)) return false;
    setId(tmp);
    return insertAndCheck(events, tmp);
}

bool AddNewEvent::addParty(vector<Event *> &events) {
    Party tmp;
    if (!tmp.setDate()) return false;
    if (!tmp.setTime()) return false;
    if (!tmp.setDuration()) return false;
    if (!addActivity(tmp)) return false;
    if (!insertThings(tmp)) return false;
    setId(tmp);
    return insertAndCheck(events, tmp);
}

bool AddNewEvent::addTask(vector<Event *> &events) {
    Task tmp;
    if (!tmp.setDate()) return false;
    if (!tmp.setTime()) return false;
    if (!tmp.setDuration()) return false;
    if (!addActivity(tmp)) return false;
    cout << ENTER_COMPLEXITY << endl;
    if (CheckInput::numberInputFail(tmp.complexityLevel, 1, MAX_COMPLEXITY_LEVEL)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    if (!insertThings(tmp)) return false;
    setId(tmp);
    return insertAndCheck(events, tmp);
}

bool AddNewEvent::addReminder(vector<Event *> &events) {
    Reminder tmp;
    if (!tmp.setDate()) return false;
    if (!tmp.setTime()) return false;
    while (tmp.note.empty()) {
        cout << ENTER_NOTE << endl;
        if (CheckInput::stringInputFail(tmp.note) || cin.eof()) {
            cout << INPUT_FAIL << endl;
            return false;
        }
    }
    auto iter = lower_bound(events.begin(), events.end(), tmp, CheckEvent::compareEvent);
    events.insert(iter, tmp.clone());
    return true;
}

bool AddNewEvent::addNewEvent(vector<Event *> &events) {
    cout << WHAT_TO_ADD << endl;
    cout << ADD_OPT1 << endl;
    cout << ADD_OPT2 << endl;
    cout << ADD_OPT3 << endl;
    cout << ADD_OPT4 << endl;
    cout << ADD_OPT5 << endl;
    cout << ADD_OPT6 << endl;
    int command;
    if (CheckInput::numberInputFail(command, 1, 6)) {
        cout << INPUT_FAIL << endl;
        return false;
    }
    switch (command) {
        case 1:
            if (!addMeeting(events)) return false;
            break;
        case 2:
            if (!addBirthday(events)) return false;
            break;
        case 3:
            if (!addParty(events)) return false;
            break;
        case 4:
            if (!addTask(events)) return false;
            break;
        case 5:
            if (!addReminder(events))return false;
            break;
        case 6:
            return false;
    }
    cout<<EVENT_ADD_SUCCESS<<endl;
    return true;
}

bool AddNewEvent::insertAndCheck(vector<Event *> &events, Event &tmp) {
    for (int i = 0; i < tmp.numberOfRepetitions; ++i) {
        if (!CheckEvent::isCollisionsFree(events, tmp)) return false;
        CheckEvent::increaseCollision(events, tmp);
        auto iter = lower_bound(events.begin(), events.end(), tmp, CheckEvent::compareEvent);
        events.insert(iter, tmp.clone());
        tmp.date.increaseTime(tmp.repeatingIntervalDays * SECONDS_IN_DAY);
        tmp.actualNumberOfCollisions = 0;
    }
    return true;
}

bool AddNewEvent::insertThings(ActivityToPickWith &tmp) {
    cout << ENTER_THINGS << endl;
    while (true) {
        if (tmp.toPickWith.size() > MAX_ELEMENTS) {
            cout << TOO_MANY_THINGS_FAIL << endl;
            return false;
        }
        string thing;
        if (CheckInput::stringInputFail(thing) || cin.eof()) {
            cout << INPUT_FAIL << endl;
            return false;
        }
        if (thing == INPUT_END) break;
        if (!thing.empty()) {
            tmp.toPickWith.push_back(thing);
        }
    }
    return true;
}

void AddNewEvent::setId(Event &tmp) {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<unsigned int> distribution(0, SIZE_T_MAX);
    tmp.setID(distribution(rng), distribution(rng));
}