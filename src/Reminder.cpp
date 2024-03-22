#include "Reminder.h"

Reminder::Reminder() {
    potentialCollision = false;
}

Event *Reminder::clone() const {
    return new Reminder(*this);
};

string Reminder::getTitle() const {
    string emptyStr;
    return emptyStr;
}

string Reminder::getLocation() const {
    string emptyStr;
    return emptyStr;
}

vector<string> Reminder::getMembers() const {
    vector<string> emptyVector;
    return emptyVector;
}

vector<string> Reminder::getTags() const {
    vector<string> emptyVector;
    return emptyVector;
}

void Reminder::print(ostream &out) const {
    out << ATTENTION << endl;
    out << date.getDay() << DOT << date.getMonth() << DOT << date.getYear() << AT << date.getMinute() << COLON
        << date.getHour() << SPACE << note << endl;
    out << ATTENTION << endl;
    cout << endl;
}

void Reminder::write(ostream &out) const {
    out << 5 << endl;
    out << date.getDay() << endl;
    out << date.getMonth() << endl;
    out << date.getYear() << endl;
    out << date.getHour() << endl;
    out << date.getMinute() << endl;
    out << note;
}