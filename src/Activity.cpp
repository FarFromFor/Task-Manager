#include "Activity.h"

string Activity::getTitle() const {
    return title;
}

string Activity::getLocation() const {
    return location;
}

vector<string> Activity::getMembers() const {
    return members;
}

vector<string> Activity::getTags() const {
    return tags;
}

void Activity::printMembers(ostream &out) const {
    for (size_t i = 0; i < members.size(); ++i) {
        out << members[i];
        if (i != (members.size() - 1)) out << COMMA;
    }
    out << endl;
}

void Activity::printTags(ostream &out) const {
    out << TAGS;
    for (size_t i = 0; i < tags.size(); ++i) {
        out << TAG_SYMBOL;
        out << tags[i];
        if (i != (tags.size() - 1)) out << COMMA;
    }
    out << endl;
}

void Activity::setTitle(const string &titleIn) {
    title = titleIn;
}

void Activity::setLocation(const string &locationIn) {
    location = locationIn;
}

void Activity::writeToFile(ostream &out, int eventNumber) const {
    out << eventNumber << endl;
    out << date.getYear() << endl;
    out << date.getMonth() << endl;
    out << date.getDay() << endl;
    out << date.getHour() << endl;
    out << date.getMinute() << endl;
    out << date.getFinishTime() << endl;
    out << title << endl;
    out << location << endl;
    out << note << endl;
    for (size_t i = 0; i < members.size(); ++i) {
        out << members[i] << endl;
    }
    out << INPUT_END << endl;
    for (size_t i = 0; i < tags.size(); ++i) {
        out << tags[i] << endl;
    }
    out << INPUT_END << endl;
    if (isRecurring) {
        out << 1 << endl;
        out << getID().first << endl;
        out << getID().second << endl;
    } else out << 2 << endl;
    if (isRecurring) out << repeatingIntervalDays << endl;
    out << allowedNumberOfCollisions;
}