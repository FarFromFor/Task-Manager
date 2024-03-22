#include "ImportEvents.h"

bool ImportEvents::importEvents(vector<Event *> &events, const string &fileName) {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<unsigned int> distribution(0, SIZE_T_MAX);
    size_t changeID = distribution(rng);
    ifstream file(fileName);
    vector<Event *> eventsTmp;
    if (file.is_open()) {
        while (!file.eof()) {
            int input;
            file >> input;
            if (file.fail() || file.eof() || CheckInput::numberFailInt(input, 1, 5)) {
                returnState(eventsTmp);
                return false;
            }
            Meeting met;
            Birthday brd;
            Party prt;
            Task tsk;
            Reminder rem;
            if (input == 1) {
                if (!readFromFile(met, file)) {
                    returnState(eventsTmp);
                    return false;
                }
                string strTmp;
                file.get();
                getline(file, strTmp);
                met.dressCode = strTmp;
                if (!file) {
                    returnState(eventsTmp);
                    return false;
                }
                if (!CheckEvent::isCollisionsFree(eventsTmp, met)) continue;
                if (!CheckEvent::isCollisionsFree(events, met)) continue;
                met.setID(met.getID().first + changeID, met.getID().second + changeID);
                eventsTmp.push_back(met.clone());
            }
            if (input == 2) {
                if (!readFromFile(brd, file)) {
                    returnState(eventsTmp);
                    return false;
                }
                if (!CheckEvent::isCollisionsFree(eventsTmp, brd)) continue;
                if (!CheckEvent::isCollisionsFree(events, brd)) continue;
                brd.setID(brd.getID().first + changeID, brd.getID().second + changeID);
                eventsTmp.push_back(brd.clone());
            }
            if (input == 3) {
                if (!readFromFile(prt, file)) {
                    returnState(eventsTmp);
                    return false;
                }
                string strTmp;
                file.get();
                getline(file, strTmp);
                int counter = 0;
                while (strTmp != INPUT_END) {
                    if (counter > MAX_ELEMENTS) {
                        returnState(eventsTmp);
                        return false;
                    }
                    counter++;
                    prt.toPickWith.push_back(strTmp);
                    getline(file, strTmp);
                }
                if (!file) {
                    returnState(eventsTmp);
                    return false;
                }
                if (!CheckEvent::isCollisionsFree(eventsTmp, prt)) continue;
                if (!CheckEvent::isCollisionsFree(events, prt)) continue;
                prt.setID(prt.getID().first + changeID, prt.getID().second + changeID);
                eventsTmp.push_back(prt.clone());
            }
            if (input == 4) {
                if (!readFromFile(tsk, file)) {
                    returnState(eventsTmp);
                    return false;
                }
                string strTmp;
                int tmpInt;
                file >> tmpInt;
                if (file.fail() || CheckInput::numberFailInt(tmpInt, 1, MAX_COMPLEXITY_LEVEL)) {
                    returnState(eventsTmp);
                    return false;
                }
                tsk.complexityLevel = tmpInt;
                file.get();
                getline(file, strTmp);
                int counter = 0;
                while (strTmp != INPUT_END) {
                    if (counter > MAX_ELEMENTS) {
                        returnState(eventsTmp);
                        return false;
                    }
                    counter++;
                    tsk.toPickWith.push_back(strTmp);
                    getline(file, strTmp);
                }
                if (!file) {
                    returnState(eventsTmp);
                    return false;
                }
                if (!CheckEvent::isCollisionsFree(eventsTmp, tsk)) continue;
                if (!CheckEvent::isCollisionsFree(events, tsk)) continue;
                tsk.setID(tsk.getID().first + changeID, tsk.getID().second + changeID);
                eventsTmp.push_back(tsk.clone());
            }
            if (input == 5) {
                int day;
                int month;
                int year;
                int hour;
                int min;
                string strTmp;
                file >> day;
                file >> month;
                file >> year;
                if (file.fail() || CheckDate::incorrectDate(day, month, year)) {
                    returnState(eventsTmp);
                    return false;
                }
                rem.date.setDate(day, month, year);
                file >> hour;
                if (file.fail() || CheckInput::numberFailInt(hour, 0, 23)) {
                    returnState(eventsTmp);
                    return false;
                }
                file >> min;
                if (file.fail() || CheckInput::numberFailInt(min, 0, 59)) {
                    returnState(eventsTmp);
                    return false;
                }
                rem.date.setTime(hour, min);
                file.get();
                getline(file, strTmp);
                rem.note = strTmp;

                if (!file) {
                    returnState(eventsTmp);
                    return false;
                }
                eventsTmp.push_back(rem.clone());
            }
        }
        if(eventsTmp.empty()) return false;
        for (size_t i = 0; i < eventsTmp.size(); ++i) {
            CheckEvent::increaseCollision(events, *eventsTmp[i]);
            auto iter = lower_bound(events.begin(), events.end(), *eventsTmp[i], CheckEvent::compareEvent);
            events.insert(iter, eventsTmp[i]);
        }
        eventsTmp.clear();
    } else {
        return false;
    }
    file.close();
    if (!file) {
        return false;
    }
    return true;
}

void ImportEvents::returnState(vector<Event *> &eventsTmp) {
    for (size_t i = 0; i < eventsTmp.size(); ++i) {
        if (eventsTmp[i] != nullptr) {
            delete eventsTmp[i];
        }
    }
}

bool ImportEvents::readFromFile(Activity &tmp, ifstream &file) {
    int day;
    int month;
    int year;
    int hour;
    int min;
    int tmpInt;
    time_t fTime;
    string strTmp;
    file >> year;
    file >> month;
    file >> day;
    if (file.fail() || CheckDate::incorrectDate(day, month, year)) return false;
    tmp.date.setDate(day, month, year);
    file >> hour;
    if (file.fail() || CheckInput::numberFailInt(hour, 0, 23)) return false;
    file >> min;
    if (file.fail() || CheckInput::numberFailInt(min, 0, 59)) return false;
    tmp.date.setTime(hour, min);

    file >> fTime;
    if (file.fail()) return false;
    tmp.date.setNewFinishTime(fTime);
    file.get();
    if(tmp.date.getStartTime()>tmp.date.getFinishTime()) return false;

    getline(file, strTmp);
    tmp.setTitle(strTmp);
    getline(file, strTmp);
    tmp.setLocation(strTmp);
    getline(file, strTmp);
    tmp.note = strTmp;
    getline(file, strTmp);
    int counter = 0;
    while (strTmp != INPUT_END) {
        if (counter > MAX_ELEMENTS) return false;
        counter++;
        tmp.members.push_back(strTmp);
        getline(file, strTmp);
    }
    getline(file, strTmp);
    counter = 0;
    while (strTmp != INPUT_END) {
        if (counter > MAX_ELEMENTS) return false;
        counter++;
        tmp.tags.push_back(strTmp);
        getline(file, strTmp);
    }
    file >> tmpInt;
    if (file.fail() || CheckInput::numberFailInt(tmpInt, 1, 2)) return false;
    if (tmpInt == 1) {
        size_t tmpID1;
        size_t tmpID2;
        tmp.isRecurring = true;
        file >> tmpID1;
        file >> tmpID2;
        if (file.fail() || file.eof()) return false;
        tmp.setID(tmpID1, tmpID2);
    } else tmp.isRecurring = false;
    if (tmp.isRecurring) {
        file >> tmp.repeatingIntervalDays;
        if (file.fail() || CheckInput::numberFailInt(tmp.repeatingIntervalDays, 1, MAX_REPEATING_INTERVAL)) return false;
    }
    file >> tmp.allowedNumberOfCollisions;
    if (file.fail() || CheckInput::numberFailInt(tmp.allowedNumberOfCollisions, 0, MAX_ALLOWED_COLLISIONS)) return false;
    return true;
}