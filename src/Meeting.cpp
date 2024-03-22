#include "Meeting.h"

Meeting::Meeting() {
    potentialCollision = true;
}

Event *Meeting::clone() const {
    return new Meeting(*this);
};

void Meeting::print(ostream &out) const {
    out << date;
    out << CUR_EV_MAX << allowedNumberOfCollisions << NOW << actualNumberOfCollisions << endl;
    out << MEETING << title << endl << NOTE << note << endl << IN << location << endl << INVITED;
    printMembers(out);
    out << DRESS_CODE << dressCode << endl;
    printTags(out);
    cout << endl;
}

void Meeting::write(ostream &out) const {
    writeToFile(out, 1);
    out << endl;
    out << dressCode;
}